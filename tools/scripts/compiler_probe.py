#!/usr/bin/env python3
"""Compile a C file with several CodeWarrior versions and compare each function against the original game code.

Relocated bytes (calls and pointers) are ignored, since the probe objects are not linked.
"""
import argparse
import re
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path

import capstone
import yaml
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parents[2]
TOOLS = ROOT / "tools"
DEFAULT_FLAGS = (
    "-O4,p -proc arm946e -thumb -interworking -enum int -char signed -fp soft -lang=c99 -Cpp_exceptions off -gccext,on -gccinc "
    "-inline on,noauto -ipa file -requireprotos -nolink -msgstyle gcc -w off"
)
# Preprocessor defines of each game version, as in configure.py
VERSION_DEFINES = {"b2_us": ["BLACK2"], "w2_us": ["WHITE2"]}
SYMBOL_RE = re.compile(r"^(\S+) kind:function\((\w+),size=(0x[0-9a-f]+)[^)]*\) addr:(0x[0-9a-f]+)")


def load_modules(version: str) -> dict[str, tuple[Path, int]]:
    """Returns the binary and base address of every module, keyed by its config directory."""
    extract = ROOT / "extract" / version
    config = ROOT / "config" / version / "arm9"
    arm9 = yaml.safe_load((extract / "arm9" / "arm9.yaml").read_text())
    modules = {str(config): (extract / "arm9" / "arm9.bin", arm9["base_address"])}
    for name in ("itcm", "dtcm"):
        info = yaml.safe_load((extract / "arm9" / f"{name}.yaml").read_text())
        modules[str(config / name)] = (extract / "arm9" / f"{name}.bin", info["base_address"])
    overlays = yaml.safe_load((extract / "arm9_overlays" / "overlays.yaml").read_text())["overlays"]
    for overlay in overlays:
        path = extract / "arm9_overlays" / overlay["file_name"]
        modules[str(config / "overlays" / f"ov{overlay['id']:03d}")] = (path, overlay["base_address"])
    return modules


def find_function(version: str, name: str, modules) -> tuple[bytes, int, bool] | None:
    """Returns the original bytes, address and Thumb flag of a function."""
    config = ROOT / "config" / version / "arm9"
    for symbols in config.rglob("symbols.txt"):
        for line in symbols.read_text().splitlines():
            if not line.startswith(name + " "):
                continue
            match = SYMBOL_RE.match(line)
            if not match:
                continue
            mode, size, addr = match.group(2), int(match.group(3), 16), int(match.group(4), 16)
            binary, base = modules[str(symbols.parent)]
            data = binary.read_bytes()[addr - base : addr - base + size]
            return data, addr, mode == "thumb"
    return None


def compiled_functions(obj: Path) -> dict[str, tuple[bytes, set[int]]]:
    """Returns the bytes and relocated offsets of every function in a compiled object."""
    functions = {}
    with obj.open("rb") as f:
        elf = ELFFile(f)
        relocated: dict[int, set[int]] = {}
        for section in elf.iter_sections():
            if isinstance(section, RelocationSection):
                target = section["sh_info"]
                offsets = relocated.setdefault(target, set())
                for reloc in section.iter_relocations():
                    offsets.update(range(reloc["r_offset"], reloc["r_offset"] + 4))
        symtab = elf.get_section_by_name(".symtab")
        for symbol in symtab.iter_symbols():
            if symbol["st_info"]["type"] != "STT_FUNC" or symbol["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            if symbol.name.startswith("$"):
                continue
            section = elf.get_section(symbol["st_shndx"])
            start = symbol["st_value"] & ~1
            size = symbol["st_size"]
            data = section.data()[start : start + size]
            masked = {o - start for o in relocated.get(symbol["st_shndx"], set()) if start <= o < start + size}
            functions[symbol.name] = (data, masked)
    return functions


def disassemble(data: bytes, address: int, thumb: bool) -> list[str]:
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    return [f"{i.address:08x}: {i.mnemonic} {i.op_str}" for i in md.disasm(data, address)]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("--version", default="b2_us", help="game version")
    parser.add_argument(
        "--compilers",
        default="all",
        help="comma-separated dsi compiler versions, or 'all'; "
        "other builds by their directory under tools/mwccarm, as in 2.0/sp2p2",
    )
    parser.add_argument("--flags", default=DEFAULT_FLAGS)
    parser.add_argument("--extra-flags", default="", help="flags appended to --flags")
    parser.add_argument("--opt", help="optimization flags replacing -O4,p, e.g. -O4,s")
    parser.add_argument("--show-diff", help="compiler version to show a disassembly diff for")
    args = parser.parse_args()

    if args.opt:
        args.flags = args.flags.replace("-O4,p", args.opt)
    compilers_dir = TOOLS / "mwccarm" / "dsi"
    compilers = sorted(p.name for p in compilers_dir.iterdir()) if args.compilers == "all" else args.compilers.split(",")
    modules = load_modules(args.version)

    results: dict[str, dict[str, str]] = {}
    with tempfile.TemporaryDirectory() as tmp:
        for compiler in compilers:
            obj = Path(tmp) / f"{compiler.replace('/', '_')}.o"
            command = [
                str(TOOLS / "wibo"),
                str((TOOLS / "mwccarm" / compiler if "/" in compiler else compilers_dir / compiler) / "mwccarm.exe"),
                *shlex.split(args.flags),
                *shlex.split(args.extra_flags),
                *(arg for define in VERSION_DEFINES.get(args.version, []) for arg in ("-d", define)),
                "-i", str(ROOT / "include"),
                "-o", str(obj),
                str(args.source),
            ]
            proc = subprocess.run(command, capture_output=True, text=True)
            if proc.returncode != 0:
                print(f"{compiler}: compile failed\n{proc.stdout}{proc.stderr}")
                continue
            for name, (data, masked) in compiled_functions(obj).items():
                original = find_function(args.version, name, modules)
                if original is None:
                    results.setdefault(name, {})[compiler] = "unknown"
                    continue
                orig_data, addr, thumb = original
                if len(orig_data) != len(data):
                    status = f"size {len(data):#x}/{len(orig_data):#x}"
                else:
                    diffs = sum(1 for i in range(len(data)) if i not in masked and data[i] != orig_data[i])
                    status = "MATCH" if diffs == 0 else f"{diffs} bytes"
                results.setdefault(name, {})[compiler] = status

                if args.show_diff == compiler and status != "MATCH":
                    ours = disassemble(data, addr, thumb)
                    theirs = disassemble(orig_data, addr, thumb)
                    print(f"--- {name} ({compiler}): ours | original")
                    for i in range(max(len(ours), len(theirs))):
                        a = ours[i] if i < len(ours) else ""
                        b = theirs[i] if i < len(theirs) else ""
                        mark = " " if a.split(":", 1)[-1] == b.split(":", 1)[-1] else "*"
                        print(f"{mark} {a:45s} | {b}")

    width = max((len(n) for n in results), default=8)
    print(f"{'function':{width}s}  " + "  ".join(f"{c:>12s}" for c in compilers))
    for name, row in results.items():
        print(f"{name:{width}s}  " + "  ".join(f"{row.get(c, '-'):>12s}" for c in compilers))


if __name__ == "__main__":
    sys.exit(main())
