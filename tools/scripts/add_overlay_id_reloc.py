#!/usr/bin/env python3
"""Add overlay_id relocations in every version, for literals that are overlay IDs such as in GFL_OvlLoad(OVERLAY_N_ID).

Relocations are given by their source address in the primary version, which is mapped to the other versions like in
set_reloc_module.py.
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
    parser.add_argument("overlay", type=int, help="overlay ID the literal refers to")
    parser.add_argument("sources", nargs="+", help="source addresses of the literals in the primary version")
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
        for source in version_sources:
            if any(line.startswith(f"from:{source:#010x} ") for line in lines):
                sys.exit(f"{version}: {source:#010x} already has a relocation")
            index = next(
                (i for i, line in enumerate(lines) if int(re.match(r"from:(0x[0-9a-f]+)", line).group(1), 16) > source),
                len(lines),
            )
            lines.insert(index, f"from:{source:#010x} kind:overlay_id to:{args.overlay}")
        relocs.write_text("\n".join(lines) + "\n")
        print(f"{version}: added " + ", ".join(f"{s:#010x}" for s in version_sources))


if __name__ == "__main__":
    main()
