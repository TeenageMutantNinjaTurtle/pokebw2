#!/usr/bin/env python3
"""Generates build.ninja for the Pokémon Black 2 decompilation.

Run this once after cloning (and again after adding source files), then run `ninja`.
"""
import argparse
import io
import json
import shlex
import stat
import subprocess
import sys
import urllib.request
import zipfile
from pathlib import Path

ROOT = Path(__file__).parent.resolve()

VERSIONS = {
    "b2_us": {"sha1": "e51e6dfb8678a3d19dcd2a10691b96a569ca0abb", "rom": "pokeblack2_us.nds", "defines": ["BLACK2"]},
    "w2_us": {"sha1": "b5d7490be7b415b8f1e672a53e978a9cc667e56a", "rom": "pokewhite2_us.nds", "defines": ["WHITE2"]},
}

WIBO_VERSION = "1.2.0"
OBJDIFF_VERSION = "v3.8.1"
# decomp.me name of the dsi/1.1 compiler, for objdiff's scratch button
DECOMP_ME_COMPILER = "mwcc_40_1018"
MWCCARM_URL = "http://decomp.aetias.com/files/mwccarm.zip"
# Compiler for decompiled code. dsi/1.1 to dsi/1.3p1 generate identical code for everything tested so far,
# while dsi/1.6 does not match the game.
MWCC_VERSION = "dsi/1.1"
# The linker only places delinked objects, so its version does not affect matching
MWLD_VERSION = "dsi/1.1"

CC_FLAGS = [
    "-O4,p",               # Optimize for speed
    "-proc arm946e",       # ARM9 processor
    "-thumb",              # Most game code is Thumb
    "-interworking",       # ARM/Thumb interworking
    "-enum int",           # Enums are int-sized
    "-char signed",        # char is signed
    "-fp soft",            # Software floating point
    "-lang=c99",
    "-Cpp_exceptions off", # No exception tables
    "-gccext,on",          # GCC extensions
    "-gccinc",             # #include "..." and <...> search the same paths
    "-inline on,noauto",   # Only inline functions marked inline
    "-ipa file",           # Interprocedural analysis within each file
    "-sym on",             # Debug info for objdiff
    "-nolink",
    "-msgstyle gcc",
]

LD_FLAGS = [
    "-proc arm946e",
    "-nodead",             # Dead-stripping is on by default and would drop unreferenced delinked objects
    "-nostdlib",
    "-interworking",
    "-map closure,unused",
    "-msgstyle gcc",
    "-m Entry",
]


class Writer:
    """Minimal ninja file writer."""

    def __init__(self):
        self.out = io.StringIO()

    def comment(self, text):
        self.out.write(f"# {text}\n")

    def variable(self, key, value):
        self.out.write(f"{key} = {value}\n")

    def rule(self, name, command, description=None, **kwargs):
        self.out.write(f"rule {name}\n  command = {command}\n")
        if description:
            self.out.write(f"  description = {description}\n")
        for key, value in kwargs.items():
            self.out.write(f"  {key} = {value}\n")
        self.out.write("\n")

    def build(self, outputs, rule, inputs=(), implicit=(), variables=None, implicit_outputs=()):
        def esc(paths):
            return " ".join(str(p).replace("$", "$$").replace(" ", "$ ").replace(":", "$:") for p in paths)

        line = f"build {esc(outputs)}"
        if implicit_outputs:
            line += f" | {esc(implicit_outputs)}"
        line += f": {rule} {esc(inputs)}"
        if implicit:
            line += f" | {esc(implicit)}"
        self.out.write(line + "\n")
        for key, value in (variables or {}).items():
            self.out.write(f"  {key} = {value}\n")
        self.out.write("\n")

    def default(self, targets):
        self.out.write(f"default {' '.join(str(t) for t in targets)}\n")


def download_tools(tools_dir: Path):
    wibo = tools_dir / "wibo"
    if not wibo.exists():
        print(f"Downloading wibo {WIBO_VERSION}")
        url = f"https://github.com/decompals/wibo/releases/download/{WIBO_VERSION}/wibo-x86_64"
        urllib.request.urlretrieve(url, wibo)
        wibo.chmod(wibo.stat().st_mode | stat.S_IEXEC)

    objdiff = tools_dir / "objdiff-cli"
    if not objdiff.exists():
        print(f"Downloading objdiff-cli {OBJDIFF_VERSION}")
        url = f"https://github.com/encounter/objdiff/releases/download/{OBJDIFF_VERSION}/objdiff-cli-linux-x86_64"
        urllib.request.urlretrieve(url, objdiff)
        objdiff.chmod(objdiff.stat().st_mode | stat.S_IEXEC)

    mwccarm = tools_dir / "mwccarm"
    if not mwccarm.exists():
        print("Downloading mwccarm")
        with urllib.request.urlopen(MWCCARM_URL) as response:
            archive = zipfile.ZipFile(io.BytesIO(response.read()))
        members = [m for m in archive.namelist() if m.startswith("mwccarm/dsi/")]
        archive.extractall(tools_dir, members)


def add_version(n: Writer, version: str, dsd: Path) -> tuple[list[Path], list[str]]:
    """Adds the build steps of one version. Returns its check targets and dsd config files."""
    baserom = Path("orig") / f"baserom_{version}.nds"
    extract_dir = Path("extract") / version
    config_dir = Path("config") / version
    build_dir = Path("build") / version
    arm9_config = config_dir / "arm9" / "config.yaml"
    rom = Path("build") / VERSIONS[version]["rom"]
    sha1_file = Path(f"{version}.sha1")
    sha1_file.write_text(f"{VERSIONS[version]['sha1']}  {rom}\n")

    dsd_configs = sorted(str(p) for p in config_dir.rglob("*.txt")) + [str(arm9_config)]

    # The delink targets are known ahead of time from the configs
    result = subprocess.run(
        [str(dsd), "json", "delinks", "--config-path", str(arm9_config)],
        capture_output=True,
        text=True,
        cwd=ROOT,
    )
    if result.returncode != 0:
        sys.exit(f"dsd json delinks failed for {version}:\n{result.stderr}")
    delinks = json.loads(result.stdout)
    files = delinks["files"]
    lcf_file = delinks["arm9_lcf_file"]
    objects_file = delinks["arm9_objects_file"]

    n.comment(version)
    stamp_dir = build_dir / "stamps"
    baserom_ok = stamp_dir / "baserom.ok"
    n.build([baserom_ok], "check_baserom", [baserom], variables={"sha1": VERSIONS[version]["sha1"]})
    n.build([extract_dir / "config.yaml"], "extract", [baserom], implicit=[baserom_ok],
            variables={"extract_dir": str(extract_dir)})

    delink_outputs = sorted({f["delink_file"] for f in files})
    n.build(delink_outputs, "delink", dsd_configs, implicit=[extract_dir / "config.yaml"],
            variables={"config": str(arm9_config)})
    n.build([lcf_file, objects_file], "lcf", dsd_configs, variables={"config": str(arm9_config)})

    # Files marked complete in delinks.txt are named after their source file and linked from the compiled object
    defines = " ".join(f"-d {define}" for define in VERSIONS[version]["defines"])
    objects = []
    for f in files:
        obj = f["object_to_link"]
        if obj != f["delink_file"]:
            n.build([obj], "mwcc", [f["name"]], variables={"defines": defines})
        objects.append(obj)

    arm9_o = build_dir / "arm9.o"
    n.build([arm9_o], "mwld", objects, implicit=[lcf_file, objects_file],
            variables={"objects": objects_file, "lcf": lcf_file})
    rom_config = build_dir / "build" / "rom_config.yaml"
    n.build([rom_config], "rom_config", [arm9_o], variables={"config": str(arm9_config)})
    n.build([rom], "rom_build", [rom_config])

    modules_ok = stamp_dir / "modules.ok"
    n.build([modules_ok], "check_modules", [rom_config], variables={"config": str(arm9_config)})
    rom_ok = stamp_dir / "rom.ok"
    n.build([rom_ok], "sha1", [sha1_file], implicit=[rom], variables={"rom": str(rom)})
    n.build([version], "phony", [modules_ok, rom_ok])

    # Context files for decomp.me scratches, made by objdiff
    for f in files:
        obj = f["object_to_link"]
        if obj != f["delink_file"]:
            source = Path(f["name"])
            n.build([Path(obj).with_suffix(f".ctx{source.suffix}")], "ctx", [source], variables={"defines": defines})

    # Progress report, compares every delinked object with its compiled counterpart
    report = build_dir / "report.json"
    n.build([report], "report", [], implicit=["objdiff.json", *objects, *delink_outputs])
    n.build([f"{version}_progress"], "progress", [report])
    return [modules_ok, rom_ok], dsd_configs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("versions", nargs="*", choices=[[], *VERSIONS],
                        help="versions to build, defaults to every version with a base ROM in orig/")
    parser.add_argument("--dsd", type=Path, default=ROOT / "tools" / "dsd", help="path to the dsd executable")
    parser.add_argument("--wine", default=None, help="run the Metrowerks tools with this instead of wibo")
    parser.add_argument("--no-download", action="store_true", help="do not download missing tools")
    args = parser.parse_args()

    versions = args.versions or [v for v in VERSIONS if (ROOT / "orig" / f"baserom_{v}.nds").exists()]
    if not versions:
        sys.exit("no base ROMs found in orig/, see README.md")
    dsd = args.dsd.resolve()
    if not dsd.exists():
        sys.exit(f"dsd not found at {dsd}, see README.md for how to build it")

    tools_dir = ROOT / "tools"
    if not args.no_download:
        download_tools(tools_dir)
    wine = args.wine or str(tools_dir / "wibo")
    mwcc = tools_dir / "mwccarm" / MWCC_VERSION / "mwccarm.exe"
    mwld = tools_dir / "mwccarm" / MWLD_VERSION / "mwldarm.exe"

    n = Writer()
    n.comment(f"Generated by configure.py for {', '.join(versions)}, do not edit")
    n.variable("dsd", shlex.quote(str(dsd)))
    n.variable("wine", shlex.quote(wine))
    n.variable("python", shlex.quote(sys.executable))
    n.out.write("\n")

    n.rule("check_baserom", "echo '$sha1  $in' | sha1sum --quiet -c - && touch $out", "Checking base ROM $in")
    n.rule("extract", "$dsd rom extract --rom $in --output-path $extract_dir", "Extracting $in")
    n.rule("delink", "$dsd delink --config-path $config", "Delinking $config")
    n.rule("lcf", "$dsd lcf --config-path $config", "Generating linker script for $config")
    n.rule("mwcc", f"mkdir -p $$(dirname $out) && $wine {shlex.quote(str(mwcc))} {' '.join(CC_FLAGS)} $defines "
           "-i include -o $out $in", "Compiling $in")
    n.rule("mwld", f"$wine {shlex.quote(str(mwld))} {' '.join(LD_FLAGS)} @$objects $lcf -o $out", "Linking $out")
    n.rule("rom_config", "$dsd rom config --elf $in --config $config", "Configuring ROM for $config")
    n.rule("rom_build", "$dsd rom build --config $in --rom $out", "Building $out")
    n.rule("check_modules", "$dsd check modules --config-path $config --fail && touch $out", "Checking modules")
    n.rule("sha1", "sha1sum --quiet -c $in && touch $out", "Checking $rom")
    n.rule("ctx", f"$wine {shlex.quote(str(mwcc))} -EP -lang=c99 -gccinc $defines -i include $in "
           "| grep -v -e '^#line' -e 'prepdump' > $out", "Preprocessing $in")
    n.rule("objdiff_config", f"$python tools/scripts/objdiff_config.py $version --dsd $dsd "
           f"--compiler {DECOMP_ME_COMPILER} --c-flags '{' '.join(CC_FLAGS)}' -o $out", "Writing $out")
    n.rule("report", f"{tools_dir / 'objdiff-cli'} report generate -p . -o $out", "Generating $out")
    n.rule("progress", "$python tools/scripts/progress.py $in", "Progress")
    n.rule("configure", f"$python configure.py {' '.join(args.versions)}", "Reconfiguring", generator="1")

    checks, configs = [], []
    for version in versions:
        version_checks, version_configs = add_version(n, version, dsd)
        checks += version_checks
        configs += version_configs

    # objdiff.json covers one version, the primary one if it is being built
    objdiff_version = versions[0]
    n.build(["objdiff.json"], "objdiff_config", configs, implicit=["tools/scripts/objdiff_config.py"],
            variables={"version": objdiff_version})
    n.build(["report"], "phony", [Path("build") / objdiff_version / "report.json"])
    n.build(["progress"], "phony", [f"{objdiff_version}_progress"])

    n.build(["build.ninja"], "configure", ["configure.py"], implicit=configs)
    n.build(["check"], "phony", checks)
    n.default(["check", "objdiff.json"])

    (ROOT / "build.ninja").write_text(n.out.getvalue())
    print(f"Wrote build.ninja for {', '.join(versions)}, now run ninja")


if __name__ == "__main__":
    main()
