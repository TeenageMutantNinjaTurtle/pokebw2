#!/usr/bin/env python3
"""Rename symbols in every version, and keep the names across config regeneration.

Each rename is recorded in config/names.txt by module and address in the primary version, and applied to the paired
symbol of every other version through the version maps. `--apply` renames every symbol listed in names.txt, which
regenerate_configs.py runs after importing names from swan.

    rename_symbol.py func_ov035_0217ed70 ElScoreboard_Create
    rename_symbol.py --apply
"""
import argparse
import csv
import re
import sys
from pathlib import Path

from dsd_config import ROOT, SYMBOL_RE

PRIMARY = "b2_us"
OTHERS = ["w2_us"]
NAMES = ROOT / "config" / "names.txt"
MAPS = [ROOT / "build" / "version_map.tsv", ROOT / "build" / "version_map_symbols.tsv"]
SOURCE_DIRS = [ROOT / "src", ROOT / "include"]
IDENTIFIER_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def symbol_files(version: str) -> dict[str, Path]:
    """Returns the symbols.txt of every module of a version, keyed by module path."""
    arm9 = ROOT / "config" / version / "arm9"
    return {str(path.parent.relative_to(arm9)): path for path in sorted(arm9.rglob("symbols.txt"))}


def find_symbol(version: str, name: str) -> tuple[str, int] | None:
    for module, path in symbol_files(version).items():
        for line in path.read_text().splitlines():
            match = SYMBOL_RE.match(line)
            if match and match.group(1) == name:
                return module, int(match.group(4), 16)
    return None


def name_in_use(version: str, name: str) -> bool:
    return find_symbol(version, name) is not None


def load_pairs() -> dict[str, dict[tuple[str, int], int]]:
    """Returns (module, primary address) -> address in each other version."""
    pairs: dict[str, dict[tuple[str, int], int]] = {other: {} for other in OTHERS}
    for path in MAPS:
        with path.open() as f:
            for row in csv.DictReader(f, delimiter="\t"):
                for other in OTHERS:
                    key = (row["module"], int(row[f"{PRIMARY}_addr"], 16))
                    pairs[other].setdefault(key, int(row[f"{other}_addr"], 16))
    return pairs


def set_name(version: str, module: str, addr: int, name: str) -> str | None:
    """Renames the function or data symbol at an address. Returns the old name, or None if there is no symbol."""
    path = symbol_files(version).get(module)
    if path is None:
        return None
    lines = path.read_text().splitlines()
    for i, line in enumerate(lines):
        match = SYMBOL_RE.match(line)
        if match and int(match.group(4), 16) == addr and match.group(2) in ("function", "data", "bss"):
            old = match.group(1)
            lines[i] = name + line[len(old):]
            path.write_text("\n".join(lines) + "\n")
            return old
    return None


def load_names() -> list[tuple[str, int, str]]:
    names = []
    if NAMES.exists():
        for line in NAMES.read_text().splitlines():
            if line.strip() and not line.startswith("#"):
                module, addr, name = line.split()
                names.append((module, int(addr, 16), name))
    return names


def save_names(names: list[tuple[str, int, str]]):
    header = "# Names that are not in swan, applied by tools/scripts/rename_symbol.py\n# module address(b2_us) name\n"
    lines = [f"{module} {addr:#010x} {name}" for module, addr, name in sorted(names, key=lambda n: (n[0], n[1]))]
    NAMES.write_text(header + "\n".join(lines) + "\n")


def apply(module: str, addr: int, name: str, pairs) -> list[str]:
    """Renames a symbol in every version. Returns the old names."""
    old_names = []
    old = set_name(PRIMARY, module, addr, name)
    if old is None:
        sys.exit(f"{PRIMARY}: no symbol at {module} {addr:#010x}")
    old_names.append(old)
    for other in OTHERS:
        other_addr = pairs[other].get((module, addr))
        if other_addr is None:
            print(f"{other}: {name} has no counterpart, only renamed in {PRIMARY}")
            continue
        old = set_name(other, module, other_addr, name)
        if old is None:
            sys.exit(f"{other}: no symbol at {module} {other_addr:#010x}")
        old_names.append(old)
    return old_names


def rename_in_sources(old_names: list[str], new: str):
    patterns = [re.compile(rf"\b{re.escape(old)}\b") for old in set(old_names) if old != new]
    for directory in SOURCE_DIRS:
        for path in sorted(directory.rglob("*")):
            if path.suffix not in (".c", ".h", ".inc", ".s"):
                continue
            text = path.read_text()
            new_text = text
            for pattern in patterns:
                new_text = pattern.sub(new, new_text)
            if new_text != text:
                path.write_text(new_text)
                print(f"updated {path.relative_to(ROOT)}")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("old", nargs="?", help="current name in the primary version")
    parser.add_argument("new", nargs="?", help="new name")
    parser.add_argument("--apply", action="store_true", help="apply every rename in config/names.txt")
    args = parser.parse_args()

    pairs = load_pairs()
    names = load_names()

    if args.apply:
        for module, addr, name in names:
            apply(module, addr, name, pairs)
        print(f"applied {len(names)} names")
        return

    if not args.old or not args.new:
        parser.error("give the old and new names, or --apply")
    if not IDENTIFIER_RE.match(args.new):
        sys.exit(f"{args.new!r} is not a valid identifier")
    found = find_symbol(PRIMARY, args.old)
    if found is None:
        sys.exit(f"{args.old} is not a symbol in {PRIMARY}")
    for version in [PRIMARY, *OTHERS]:
        if name_in_use(version, args.new):
            sys.exit(f"{args.new} is already a symbol in {version}")

    module, addr = found
    old_names = apply(module, addr, args.new, pairs)
    names = [n for n in names if (n[0], n[1]) != (module, addr)] + [(module, addr, args.new)]
    save_names(names)
    rename_in_sources(old_names, args.new)
    print(f"{args.old} -> {args.new} ({module} {addr:#010x})")


if __name__ == "__main__":
    main()
