#!/usr/bin/env python3
"""Write the evolutions (archive a/0/1/9) and the level-up moves (a/0/1/8) as editable sources, one file per species
record, with the macros of include/asm/evolution.inc and include/asm/levelup_moves.inc. Files are named as the species
data's (personal_data.py), which it reads for the forms. The build assembles them back and checks that they match.

    species_tables.py evolutions extract/b2_us/files/a/0/1/9 extract/b2_us/files/a/0/1/6 data/evolutions
    species_tables.py levelup extract/b2_us/files/a/0/1/8 extract/b2_us/files/a/0/1/6 data/levelup_moves
"""
import argparse
import struct
from pathlib import Path

from narc import read_narc
from personal_data import RECORD_SIZE, constant_names, name, record_names

# The kind of each evolution method's parameter, for the constant it is written with; the rest are numbers
ITEM_METHODS = {6, 8, 17, 18, 19, 20}
MOVE_METHODS = {21}
SPECIES_METHODS = {7, 22}


def write_evolutions(data: bytes, names: dict[str, dict[int, str]], title: str) -> str:
    lines = ['#include "asm/evolution.inc"', "", f"// {title}"]
    entries = [struct.unpack_from("<3H", data, 6 * i) for i in range(len(data) // 6)]
    used = [e for e in entries if any(e)]
    if entries[:len(used)] != used:
        raise ValueError(f"{title}: an empty evolution before a used one")
    for method, param, species in used:
        if method in ITEM_METHODS:
            param_name = name(names["item"], param)
        elif method in MOVE_METHODS:
            param_name = name(names["move"], param)
        elif method in SPECIES_METHODS:
            param_name = name(names["species"], param)
        else:
            param_name = str(param)
        lines.append(f"    Evolution {name(names['method'], method)}, {param_name}, {name(names['species'], species)}")
    lines += ["    EvolutionsEnd", ""]
    return "\n".join(lines)


def write_levelup(data: bytes, names: dict[str, dict[int, str]], title: str) -> str:
    lines = ['#include "asm/levelup_moves.inc"', "", f"// {title}"]
    pairs = [struct.unpack_from("<HH", data, i) for i in range(0, len(data), 4)]
    if pairs[-1] != (0xFFFF, 0xFFFF) or (0xFFFF, 0xFFFF) in pairs[:-1]:
        raise ValueError(f"{title}: not one list ending in 0xffffffff")
    for move, level in pairs[:-1]:
        lines.append(f"    LevelUpMove {level}, {name(names['move'], move)}")
    lines += ["    LevelUpMovesEnd", ""]
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("table", choices=["evolutions", "levelup"])
    parser.add_argument("archive", type=Path)
    parser.add_argument("personal", type=Path, help="the species data archive, a/0/1/6, for the forms")
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    names = {
        "species": constant_names("species.h", "SPECIES_"),
        "item": constant_names("items.h", "ITEM_"),
        "move": constant_names("moves.h", "MOVE_"),
        "method": constant_names("pokemon.h", "EVO_METHOD_"),
    }
    records = [m for m in read_narc(args.personal.read_bytes()) if len(m) == RECORD_SIZE]
    files, titles = record_names(records, names["species"])
    members = read_narc(args.archive.read_bytes())
    if len(members) != len(records):
        raise SystemExit(f"{len(members)} entries for {len(records)} species records")
    write = write_evolutions if args.table == "evolutions" else write_levelup
    args.output.mkdir(parents=True, exist_ok=True)
    for index, member in enumerate(members):
        (args.output / f"{index:04d}_{files[index]}.s").write_text(write(member, names, titles[index]))
    print(f"wrote {len(members)} files to {args.output}")


if __name__ == "__main__":
    main()
