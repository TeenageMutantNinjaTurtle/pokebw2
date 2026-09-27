#!/usr/bin/env python3
"""Set up a decomp-permuter directory for one function, which searches for source changes that make it match.

    permuter_setup.py src/ov170/tr_ai.c AICompareSpeed
    python3 permuter.py -j8 build/permuter/AICompareSpeed

This writes build/permuter/FUNCTION/ with:
- base.c: the preprocessed source file, which the permuter mutates
- target.o: the original function's bytes, with relocated bytes zeroed
- compile.sh: compiles a candidate with the project's compiler and flags
- settings.toml: points the permuter at permuter_objdump.py, since it expects arm-none-eabi-objdump

decomp-permuter: https://github.com/simonlindholm/decomp-permuter. Its Python needs pycparser, toml, capstone,
pyelftools and pyyaml.
"""
import argparse
import shlex
import subprocess
import sys
from pathlib import Path

import pycparser
import pycparser.c_generator

from compiler_probe import DEFAULT_FLAGS, VERSION_DEFINES, find_function, load_modules
from dsd_config import ROOT

WIBO = ROOT / "tools" / "wibo"


def relocated_offsets(module_dir: Path, start: int, end: int) -> set[int]:
    offsets = set()
    for line in (module_dir / "relocs.txt").read_text().splitlines():
        address = int(line.split()[0].removeprefix("from:"), 16)
        if start <= address < end:
            offsets.update(range(address - start, address - start + 4))
    return offsets


def single_function(source: str, function: str) -> str:
    """Keeps only the given function's definition, and replaces the others with their prototypes. Static data that
    refers to functions is dropped."""
    ast = pycparser.CParser().parse(source)
    generator = pycparser.c_generator.CGenerator()
    kept = []
    for node in ast.ext:
        if isinstance(node, pycparser.c_ast.FuncDef):
            if node.decl.name == function:
                kept.append(generator.visit(node))
            else:
                kept.append(generator.visit(node.decl) + ";")
        elif isinstance(node, pycparser.c_ast.Decl) and node.init is not None and "static" in node.storage:
            continue
        else:
            kept.append(generator.visit(node) + ";")
    return "\n".join(kept) + "\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("source")
    parser.add_argument("function")
    parser.add_argument("--version", default="b2_us")
    parser.add_argument("--compiler", default="1.1")
    args = parser.parse_args()

    out = ROOT / "build" / "permuter" / args.function
    out.mkdir(parents=True, exist_ok=True)

    defines = [f"-D{d}" for d in VERSION_DEFINES[args.version]]
    preprocessed = subprocess.run(["clang", "-E", "-P", "-I", str(ROOT / "include"), *defines, str(ROOT / args.source)],
                                  check=True, capture_output=True, text=True).stdout
    (out / "base.c").write_text(single_function(preprocessed, args.function))

    modules = load_modules(args.version)
    found = find_function(args.version, args.function, modules)
    if found is None:
        sys.exit(f"{args.function} is not in {args.version}'s configs")
    data, address, thumb = found
    config = ROOT / "config" / args.version / "arm9"
    module_dir = next(s.parent for s in config.rglob("symbols.txt")
                      if any(l.startswith(args.function + " ") for l in s.read_text().splitlines()))
    data = bytearray(data)
    for offset in relocated_offsets(module_dir, address, address + len(data)):
        if offset < len(data):
            data[offset] = 0
    (out / "target.bin").write_bytes(bytes(data))
    subprocess.run(["llvm-objcopy", "-I", "binary", "-O", "elf32-littlearm",
                    "--rename-section", ".data=.text,alloc,code,readonly",
                    "--add-symbol", f"{args.function}=.data:0,function,global",
                    str(out / "target.bin"), str(out / "target.o")], check=True)

    compiler = ROOT / "tools" / "mwccarm" / "dsi" / args.compiler / "mwccarm.exe"
    (out / "compile.sh").write_text(
        "#!/bin/sh\n"
        f'exec {shlex.quote(str(WIBO))} {shlex.quote(str(compiler))} {DEFAULT_FLAGS} -o "$3" "$1"\n'
    )
    (out / "compile.sh").chmod(0o755)
    objdump = ROOT / "tools" / "scripts" / "permuter_objdump.py"
    (out / "settings.toml").write_text(
        f'func_name = "{args.function}"\ncompiler_type = "mwcc"\n'
        f'objdump_command = "{sys.executable} {objdump} -drz"\n'
    )
    print(f"wrote {out.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
