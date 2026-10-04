#!/usr/bin/env python3
"""Generates build.ninja for the Pokémon Black 2 decompilation.

Run this once after cloning (and again after adding source files), then run `ninja`.
"""
import argparse
import io
import json
import shlex
import shutil
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
# decomp.me name of the dsi/1.1p1 compiler (build 1024), for objdiff's scratch button
DECOMP_ME_COMPILER = "mwcc_40_1024"
MWCCARM_URL = "http://decomp.aetias.com/files/mwccarm.zip"
# Compiler for decompiled code. The game code needs dsi/1.1p1 or later: after a store to a field, dsi/1.1 reuses the
# stored register where the game reloads the field. dsi/1.1p1 to dsi/1.3p1 generate identical code for everything
# tested so far, while dsi/1.6 does not match the game.
MWCC_VERSION = "dsi/1.1p1"
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
    "-requireprotos",      # Calling an undeclared function is an error, instead of an implicit declaration
    "-nolink",
    "-msgstyle gcc",
]

# Nintendo's SPL particle library was built apart from the game, with an older compiler, as ARM code and without
# interprocedural analysis. Sources under each directory here are compiled with its compiler and flags
LIB_COMPILERS = {
    "src/spl/": ("1.2/base", [
        "-O4,p",
        "-proc arm946e",
        "-nothumb",
        "-interworking",
        "-enum int",
        "-char signed",
        "-fp soft",
        "-lang=c99",
        "-Cpp_exceptions off",
        "-gccext,on",
        "-gccinc",
        "-sym on",
        "-requireprotos",
        "-nolink",
        "-msgstyle gcc",
    ]),
}

# Archives built from source, which replace their extracted counterparts in the ROM. Each maps its path under files/ to
# the directory of its members, one assembly file each, in archive order.
ARCHIVES = {
    "a/0/5/6": "data/field_scripts",  # Field scripts, see tools/scripts/field_script.py
    "a/1/6/9": "data/tr_ai",  # Trainer AI scripts, see tools/scripts/tr_ai_script.py
}

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

    def build(self, outputs, rule, inputs=(), implicit=(), variables=None, implicit_outputs=(), order_only=()):
        def esc(paths):
            return " ".join(str(p).replace("$", "$$").replace(" ", "$ ").replace(":", "$:") for p in paths)

        line = f"build {esc(outputs)}"
        if implicit_outputs:
            line += f" | {esc(implicit_outputs)}"
        line += f": {rule} {esc(inputs)}"
        if implicit:
            line += f" | {esc(implicit)}"
        if order_only:
            line += f" || {esc(order_only)}"
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
        versions = ("mwccarm/dsi/", *(f"mwccarm/{compiler}/" for compiler, _ in LIB_COMPILERS.values()))
        members = [m for m in archive.namelist() if m.startswith(versions)]
        archive.extractall(tools_dir, members)


def add_version(n: Writer, version: str, dsd: Path, bugfix: bool) -> tuple[list[Path], list[str]]:
    """Adds the build steps of one version. Returns its check targets and dsd config files. A build with the bugs fixed
    does not match, so its only targets are the ROM and its archives."""
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

    # Source files are listed in delinks.txt by their path. Complete files are linked from the compiled object, and
    # incomplete ones are still compiled so objdiff can compare them.
    version_defines = VERSIONS[version]["defines"] + (["BUGFIX"] if bugfix else [])
    defines = " ".join(f"-d {define}" for define in version_defines)
    as_defines = " ".join(f"-D{define}" for define in version_defines)
    objects = []
    compiled = []
    for f in files:
        source = Path(f["name"])
        if source.suffix in (".c", ".cpp") and source.exists():
            obj = build_dir / source.with_suffix(".o")
            rule = next((f"mwcc_{i}" for i, lib in enumerate(LIB_COMPILERS) if str(source).startswith(lib)), "mwcc")
            n.build([obj], rule, [source], variables={"defines": defines, "dep": obj.with_suffix(".d")})
            compiled.append(obj)
        objects.append(f["object_to_link"])

    arm9_o = build_dir / "arm9.o"
    n.build([arm9_o], "mwld", objects, implicit=[lcf_file, objects_file],
            variables={"objects": objects_file, "lcf": lcf_file})

    # The ROM's file system is the extracted one, with the archives built from source in place of the extracted ones.
    # The tree is made first, so that no archive is written through a link into extract/.
    files_dir = build_dir / "files"
    files_ok = stamp_dir / "files.ok"
    n.build([files_ok], "files_tree", [], implicit=[extract_dir / "config.yaml", "tools/scripts/files_tree.py"],
            variables={"source": str(extract_dir / "files"), "output": str(files_dir), "built": " ".join(ARCHIVES)})
    archives = []
    checks = []
    for path, source_dir in ARCHIVES.items():
        members = []
        for source in sorted(Path(source_dir).glob("*.s")):
            obj = build_dir / source.with_suffix(".o")
            n.build([obj], "as", [source], variables={"dep": obj.with_suffix(".d"), "defines": as_defines})
            n.build([obj.with_suffix(".bin")], "objcopy_bin", [obj])
            members.append(obj.with_suffix(".bin"))
        archive = files_dir / path
        n.build([archive], "narc", members, implicit=["tools/scripts/narc.py"], order_only=[files_ok])
        archive_ok = stamp_dir / "files" / f"{path.replace('/', '_')}.ok"
        n.build([archive_ok], "check_file", [archive], implicit=[extract_dir / "config.yaml"],
                variables={"original": str(extract_dir / "files" / path)})
        archives.append(archive)
        checks.append(archive)
        if not bugfix:
            checks.append(archive_ok)

    rom_config = build_dir / "build" / "rom_config.yaml"
    n.build([rom_config], "rom_config", [arm9_o], variables={"config": str(arm9_config)})
    n.build([rom], "rom_build", [rom_config], implicit=[files_ok, *archives])

    modules_ok = stamp_dir / "modules.ok"
    n.build([modules_ok], "check_modules", [rom_config], variables={"config": str(arm9_config)})
    rom_ok = stamp_dir / "rom.ok"
    n.build([rom_ok], "sha1", [sha1_file], implicit=[rom], variables={"rom": str(rom)})
    n.build([version], "phony", [rom] if bugfix else [modules_ok, rom_ok])

    # Context files for decomp.me scratches, made by objdiff
    for obj in compiled:
        source = obj.relative_to(build_dir).with_suffix(".c")
        n.build([obj.with_suffix(f".ctx{source.suffix}")], "ctx", [source], variables={"defines": defines})

    # Progress report, compares every delinked object with its compiled counterpart
    report = build_dir / "report.json"
    n.build([report], "report", [], implicit=["objdiff.json", *compiled, *delink_outputs])
    n.build([f"{version}_progress"], "progress", [report])
    if bugfix:
        return [rom, *checks], dsd_configs
    return [modules_ok, rom_ok, *checks], dsd_configs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("versions", nargs="*", choices=[[], *VERSIONS],
                        help="versions to build, defaults to every version with a base ROM in orig/")
    parser.add_argument("--dsd", type=Path, default=ROOT / "tools" / "dsd", help="path to the dsd executable")
    parser.add_argument("--wine", default=None, help="run the Metrowerks tools with this instead of wibo")
    parser.add_argument("--no-download", action="store_true", help="do not download missing tools")
    parser.add_argument("--bugfix", action="store_true",
                        help="fix the game's bugs that are marked with BUGFIX in the source; the ROMs no longer match")
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
    clang = shutil.which("clang")
    llvm_objcopy = shutil.which("llvm-objcopy")
    if not clang or not llvm_objcopy:
        sys.exit("clang and llvm-objcopy not found, see README.md")
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
    # mwccarm writes the dependency file next to the object, with Windows paths that fix_depfile.py converts
    n.rule("mwcc", f"mkdir -p $$(dirname $out) && $wine {shlex.quote(str(mwcc))} {' '.join(CC_FLAGS)} $defines "
           "-gccdep -MD -i include -o $out $in && $python tools/scripts/fix_depfile.py $dep", "Compiling $in",
           depfile="$dep", deps="gcc")
    for i, (compiler, flags) in enumerate(LIB_COMPILERS.values()):
        lib_mwcc = tools_dir / "mwccarm" / compiler / "mwccarm.exe"
        n.rule(f"mwcc_{i}", f"mkdir -p $$(dirname $out) && $wine {shlex.quote(str(lib_mwcc))} {' '.join(flags)} "
               "$defines -gccdep -MD -i include -o $out $in && $python tools/scripts/fix_depfile.py $dep",
               "Compiling $in", depfile="$dep", deps="gcc")
    n.rule("mwld", f"$wine {shlex.quote(str(mwld))} {' '.join(LD_FLAGS)} @$objects $lcf -o $out", "Linking $out")
    # Scripts go through the C preprocessor, so that they can include the constant headers
    n.rule("as", f"{shlex.quote(clang)} --target=armv5te-none-eabi -x assembler-with-cpp -c -I include $defines "
           "-MD -MF $dep -o $out $in", "Assembling $in", depfile="$dep", deps="gcc")
    n.rule("objcopy_bin", f"{shlex.quote(llvm_objcopy)} -O binary $in $out", "Converting $in")
    n.rule("narc", "$python tools/scripts/narc.py pack $out $in", "Packing $out")
    n.rule("check_file", "cmp $in $original && mkdir -p $$(dirname $out) && touch $out", "Checking $in")
    n.rule("files_tree", "$python tools/scripts/files_tree.py $source $output $built --stamp $out",
           "Linking the files of $output")
    # dsd points the ROM at the extracted files, and the build's own file system replaces them
    n.rule("rom_config", "$dsd rom config --elf $in --config $config && sed -i 's|^files_dir: .*|files_dir: ../files|' "
           "$out", "Configuring ROM for $config")
    n.rule("rom_build", "$dsd rom build --config $in --rom $out", "Building $out")
    n.rule("check_modules", "$dsd check modules --config-path $config --fail && touch $out", "Checking modules")
    n.rule("sha1", "sha1sum --quiet -c $in && touch $out", "Checking $rom")
    n.rule("ctx", f"$wine {shlex.quote(str(mwcc))} -EP -lang=c99 -gccinc $defines -i include $in "
           "| grep -v -e '^#line' -e 'prepdump' > $out", "Preprocessing $in")
    n.rule("objdiff_config", f"$python tools/scripts/objdiff_config.py $version --dsd $dsd "
           f"--compiler {DECOMP_ME_COMPILER} --c-flags '{' '.join(CC_FLAGS)}' -o $out", "Writing $out")
    n.rule("report", f"{tools_dir / 'objdiff-cli'} report generate -p . -o $out", "Generating $out")
    n.rule("progress", "$python tools/scripts/progress.py $in", "Progress")
    configure_args = [*args.versions, *(["--bugfix"] if args.bugfix else [])]
    n.rule("configure", f"$python configure.py {' '.join(configure_args)}", "Reconfiguring", generator="1")
    # Formats the sources and headers in place with clang-format and .clang-format
    n.rule("format", "clang-format -i $in", "Formatting")

    checks, configs = [], []
    for version in versions:
        version_checks, version_configs = add_version(n, version, dsd, args.bugfix)
        checks += version_checks
        configs += version_configs

    # objdiff.json covers one version, the primary one if it is being built
    objdiff_version = versions[0]
    n.build(["objdiff.json"], "objdiff_config", configs, implicit=["tools/scripts/objdiff_config.py"],
            variables={"version": objdiff_version})
    n.build(["report"], "phony", [Path("build") / objdiff_version / "report.json"])
    n.build(["progress"], "phony", [f"{objdiff_version}_progress"])

    n.build(["build.ninja"], "configure", ["configure.py"], implicit=configs)
    sources = sorted(str(p.relative_to(ROOT)) for p in [*ROOT.glob("src/**/*.c"), *ROOT.glob("include/**/*.h")])
    n.build(["format"], "format", sources)
    n.build(["check"], "phony", checks)
    n.default(["check", "objdiff.json"])

    (ROOT / "build.ninja").write_text(n.out.getvalue())
    fixes = ", with the bugs fixed" if args.bugfix else ""
    print(f"Wrote build.ninja for {', '.join(versions)}{fixes}, now run ninja")


if __name__ == "__main__":
    main()
