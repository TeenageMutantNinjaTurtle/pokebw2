#!/usr/bin/env python3
"""Set the destination module of relocations in every version, such as to resolve an ambiguous overlay.

Relocations are given by their source address in the primary version. The address in the other versions is found
through the function containing it, which must be paired in the version map.
"""
import argparse
import csv
import re
import sys
from pathlib import Path

from dsd_config import ROOT, load_modules

PRIMARY = "b2_us"
OTHERS = ["w2_us"]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("module", help="module path in the config, e.g. overlays/ov035")
    parser.add_argument("destination", help="new destination module, e.g. overlay(12)")
    parser.add_argument("sources", nargs="+", help="source addresses of the relocations in the primary version")
    parser.add_argument("--map", type=Path, default=ROOT / "build" / "version_map.tsv")
    args = parser.parse_args()

    sources = [int(source, 16) for source in args.sources]
    functions = load_modules(PRIMARY)[args.module].functions()

    pairs: dict[str, dict[int, int]] = {other: {} for other in OTHERS}
    with args.map.open() as f:
        for row in csv.DictReader(f, delimiter="\t"):
            if row["module"] == args.module:
                for other in OTHERS:
                    pairs[other][int(row[f"{PRIMARY}_addr"], 16)] = int(row[f"{other}_addr"], 16)

    addresses = {PRIMARY: sources}
    for other in OTHERS:
        addresses[other] = []
        for source in sources:
            function = next((f for f in functions if f.addr <= source < f.addr + (f.size or 0)), None)
            if function is None or function.addr not in pairs[other]:
                sys.exit(f"{source:#010x} is not in a paired function")
            addresses[other].append(pairs[other][function.addr] + source - function.addr)

    for version, version_sources in addresses.items():
        relocs = ROOT / "config" / version / "arm9" / args.module / "relocs.txt"
        lines = relocs.read_text().splitlines()
        wanted = {f"from:{source:#010x} " for source in version_sources}
        changed = 0
        for i, line in enumerate(lines):
            if any(line.startswith(prefix) for prefix in wanted):
                lines[i] = re.sub(r"module:\S+", f"module:{args.destination}", line)
                changed += 1
        if changed != len(version_sources):
            sys.exit(f"{version}: found {changed} of {len(version_sources)} relocations")
        relocs.write_text("\n".join(lines) + "\n")
        print(f"{version}: set {changed} relocations to {args.destination}")


if __name__ == "__main__":
    main()
