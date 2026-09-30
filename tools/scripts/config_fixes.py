#!/usr/bin/env python3
"""Fix relocations and symbols that dsd's analysis gets wrong, in every version, and keep the fixes across config
regeneration.

Each fix is recorded in config/fixes.txt by module and address in the primary version. The address in the other
versions is found through the function containing it, which must be paired in the version map, or else by its offset
from the start of its section, which must have the same size in every version. regenerate_configs.py runs `apply`
after importing names from swan.

    config_fixes.py reloc-module overlays/ov035 'overlay(12)' 0x0217c9e8    # an ambiguous destination module
    config_fixes.py overlay-id overlays/ov035 279 0x0217cbe4                 # a literal that is an overlay ID
    config_fixes.py remove-reloc overlays/ov035 0x0217f540                   # a relocation that is not one
    config_fixes.py remove-symbol overlays/ov005 0x0214f5fd                  # a symbol that is not one
    config_fixes.py add-label . _ll_mul 0x0208d60c                           # a second name for a function
    config_fixes.py apply
"""
import argparse
import csv
import re
import sys
from pathlib import Path

from dsd_config import ROOT, load_modules, parse_sections

PRIMARY = "b2_us"
OTHERS = ["w2_us"]
FIXES = ROOT / "config" / "fixes.txt"
MAP = ROOT / "build" / "version_map.tsv"
HEADER = (
    "# Fixes to dsd's analysis, applied by tools/scripts/config_fixes.py\n"
    "# module address(b2_us) action [argument]\n"
)
RELOC_RE = re.compile(r"^from:(0x[0-9a-f]+) ")
SYMBOL_ADDR_RE = re.compile(r" addr:(0x[0-9a-f]+)")


class AddressMapper:
    """Maps an address in the primary version to the other versions."""

    def __init__(self):
        self.pairs: dict[str, dict[tuple[str, int], int]] = {other: {} for other in OTHERS}
        with MAP.open() as f:
            for row in csv.DictReader(f, delimiter="\t"):
                for other in OTHERS:
                    key = (row["module"], int(row[f"{PRIMARY}_addr"], 16))
                    self.pairs[other][key] = int(row[f"{other}_addr"], 16)
        self.functions = {name: module.functions() for name, module in load_modules(PRIMARY).items()}

    def map(self, module: str, addr: int, other: str) -> int:
        function = next((f for f in self.functions[module] if f.addr <= addr < f.addr + (f.size or 0)), None)
        if function is not None:
            if (module, function.addr) not in self.pairs[other]:
                sys.exit(f"{module} {addr:#010x}: function {function.name} is not paired with {other}")
            return self.pairs[other][(module, function.addr)] + addr - function.addr
        primary_sections = parse_sections(config_dir(PRIMARY, module) / "delinks.txt")
        other_sections = parse_sections(config_dir(other, module) / "delinks.txt")
        for name, (start, end) in primary_sections.items():
            if start <= addr < end:
                other_start, other_end = other_sections[name]
                if end - start != other_end - other_start:
                    sys.exit(f"{module} {addr:#010x}: {name} has different sizes in {PRIMARY} and {other}")
                return other_start + addr - start
        sys.exit(f"{module} {addr:#010x} is in no section")


def config_dir(version: str, module: str) -> Path:
    return ROOT / "config" / version / "arm9" / module


def load_fixes() -> list[tuple[str, int, str, str]]:
    fixes = []
    if FIXES.exists():
        for line in FIXES.read_text().splitlines():
            if line.strip() and not line.startswith("#"):
                module, addr, action, *argument = line.split()
                fixes.append((module, int(addr, 16), action, argument[0] if argument else ""))
    return fixes


def save_fixes(fixes: list[tuple[str, int, str, str]]):
    def key(fix):
        module, addr, _, _ = fix
        # Main first, then the modules in numeric order
        number = re.search(r"(\d+)$", module)
        return (module != ".", int(number.group(1)) if number else 0, module, addr)

    lines = [f"{m} {a:#010x} {act} {arg}".rstrip() for m, a, act, arg in sorted(set(fixes), key=key)]
    FIXES.write_text(HEADER + "\n".join(lines) + "\n")


def apply_fix(version: str, module: str, addr: int, action: str, argument: str):
    """Applies a fix to one version's config. Applying a fix again changes nothing."""
    if action == "remove_symbol":
        path = config_dir(version, module) / "symbols.txt"
        lines = path.read_text().splitlines()
        kept = [line for line in lines if not (m := SYMBOL_ADDR_RE.search(line)) or int(m.group(1), 16) != addr]
        path.write_text("\n".join(kept) + "\n")
        return
    if action == "add_label":
        # A label with the instruction mode of the function at the address, for code that the compiler calls by
        # two names, such as the runtime's _ll_mul and _ull_mul
        path = config_dir(version, module) / "symbols.txt"
        lines = path.read_text().splitlines()
        at = [i for i, line in enumerate(lines) if (m := SYMBOL_ADDR_RE.search(line)) and int(m.group(1), 16) == addr]
        if any(lines[i].split()[0] == argument for i in at):
            return
        mode = next((m.group(1) for i in at if (m := re.search(r"kind:function\((arm|thumb)", lines[i]))), None)
        if mode is None:
            sys.exit(f"{version}: no function at {module} {addr:#010x}")
        lines.insert(at[-1] + 1, f"{argument} kind:label({mode}) addr:{addr:#010x}")
        path.write_text("\n".join(lines) + "\n")
        return

    path = config_dir(version, module) / "relocs.txt"
    lines = path.read_text().splitlines()
    index = next((i for i, line in enumerate(lines) if int(RELOC_RE.match(line).group(1), 16) == addr), None)
    if action == "reloc_module":
        if index is None:
            sys.exit(f"{version}: no relocation at {module} {addr:#010x}")
        lines[index] = re.sub(r"module:\S+", f"module:{argument}", lines[index])
    elif action == "overlay_id":
        line = f"from:{addr:#010x} kind:overlay_id to:{argument}"
        if index is not None:
            if lines[index] != line:
                sys.exit(f"{version}: {module} {addr:#010x} already has another relocation: {lines[index]}")
        else:
            position = next((i for i, l in enumerate(lines) if int(RELOC_RE.match(l).group(1), 16) > addr), len(lines))
            lines.insert(position, line)
    elif action == "remove_reloc":
        if index is not None:
            del lines[index]
    else:
        sys.exit(f"unknown action {action!r}")
    path.write_text("\n".join(lines) + "\n")


def apply_everywhere(mapper: AddressMapper, module: str, addr: int, action: str, argument: str):
    apply_fix(PRIMARY, module, addr, action, argument)
    for other in OTHERS:
        apply_fix(other, module, mapper.map(module, addr, other), action, argument)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    commands = parser.add_subparsers(dest="command", required=True)
    command = commands.add_parser("reloc-module", help="set the destination module of relocations")
    command.add_argument("module", help="module path in the config, e.g. overlays/ov035")
    command.add_argument("destination", help="destination module, e.g. overlay(12)")
    command.add_argument("addresses", nargs="+")
    command = commands.add_parser("overlay-id", help="mark literals as overlay IDs")
    command.add_argument("module")
    command.add_argument("overlay", type=int)
    command.add_argument("addresses", nargs="+")
    command = commands.add_parser("remove-reloc", help="remove relocations")
    command.add_argument("module")
    command.add_argument("addresses", nargs="+")
    command = commands.add_parser("remove-symbol", help="remove symbols")
    command.add_argument("module")
    command.add_argument("addresses", nargs="+")
    command = commands.add_parser("add-label", help="give a function a second name")
    command.add_argument("module")
    command.add_argument("name")
    command.add_argument("addresses", nargs="+")
    commands.add_parser("apply", help="apply every fix in config/fixes.txt")
    args = parser.parse_args()

    mapper = AddressMapper()
    fixes = load_fixes()
    if args.command == "apply":
        for fix in fixes:
            apply_everywhere(mapper, *fix)
        print(f"applied {len(fixes)} fixes")
        return

    action = args.command.replace("-", "_")
    argument = {"reloc_module": getattr(args, "destination", ""), "overlay_id": str(getattr(args, "overlay", "")),
                "add_label": getattr(args, "name", "")}
    argument = argument.get(action, "")
    for address in args.addresses:
        addr = int(address, 16)
        apply_everywhere(mapper, args.module, addr, action, argument)
        fixes = [f for f in fixes if (f[0], f[1]) != (args.module, addr)] + [(args.module, addr, action, argument)]
        print(f"{action} {args.module} {addr:#010x} {argument}".rstrip())
    save_fixes(fixes)


if __name__ == "__main__":
    main()
