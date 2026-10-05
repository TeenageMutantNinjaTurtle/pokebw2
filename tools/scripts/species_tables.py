#!/usr/bin/env python3
"""Write the tables that go with the species data as editable sources: the evolutions (archive a/0/1/9), the level-up
moves (a/0/1/8) and the baby species (a/0/2/0), one file per species record, named as the species data's
(personal_data.py), which it reads for the forms; and the experience tables of the growth rates (a/0/1/7), one file
per rate. The macros are in include/asm/. The build assembles them back and checks that they match.

    species_tables.py evolutions extract/b2_us/files/a/0/1/9 extract/b2_us/files/a/0/1/6 data/evolutions
    species_tables.py levelup extract/b2_us/files/a/0/1/8 extract/b2_us/files/a/0/1/6 data/levelup_moves
    species_tables.py babies extract/b2_us/files/a/0/2/0 extract/b2_us/files/a/0/1/6 data/baby_species
    species_tables.py growth extract/b2_us/files/a/0/1/7 extract/b2_us/files/a/0/1/6 data/growth_rates
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


def write_baby(data: bytes, names: dict[str, dict[int, str]], title: str) -> str:
    species = struct.unpack("<H", data)[0]
    return "\n".join(['#include "asm/baby_species.inc"', "", f"// {title}",
                      f"    BabySpecies {name(names['species'], species)}", ""])


def write_growth(data: bytes, title: str) -> str:
    exp = struct.unpack(f"<{len(data) // 4}I", data)
    lines = ['#include "asm/growth_rates.inc"', "", f"// {title}"]
    lines += [f"    Level {level}, {value}" for level, value in enumerate(exp)]
    lines += ["    ExpTableEnd", ""]
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("table", choices=["evolutions", "levelup", "babies", "growth"])
    parser.add_argument("archive", type=Path)
    parser.add_argument("personal", type=Path, help="the species data archive, a/0/1/6, for the forms")
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    names = {
        "species": constant_names("species.h", "SPECIES_"),
        "item": constant_names("items.h", "ITEM_"),
        "move": constant_names("moves.h", "MOVE_"),
        "method": constant_names("pokemon.h", "EVO_METHOD_"),
        "growth": constant_names("pokemon.h", "GROWTH_"),
    }
    records = [m for m in read_narc(args.personal.read_bytes()) if len(m) == RECORD_SIZE]
    files, titles = record_names(records, names["species"])
    members = read_narc(args.archive.read_bytes())
    args.output.mkdir(parents=True, exist_ok=True)
    if args.table == "growth":
        # One table per growth rate; the ones after the rates are copies of the first that nothing names
        for index, member in enumerate(members):
            rate = names["growth"].get(index)
            stem = rate.removeprefix("GROWTH_").lower() if rate else "extra"
            title = rate or "A copy of GROWTH_MEDIUM_FAST's table, after the growth rates"
            (args.output / f"{index:04d}_{stem}.s").write_text(write_growth(member, title))
        print(f"wrote {len(members)} files to {args.output}")
        return
    # The baby species stop before the last forms
    if len(members) > len(records):
        raise SystemExit(f"{len(members)} entries for {len(records)} species records")
    write = {"evolutions": write_evolutions, "levelup": write_levelup, "babies": write_baby}[args.table]
    for index, member in enumerate(members):
        (args.output / f"{index:04d}_{files[index]}.s").write_text(write(member, names, titles[index]))
    print(f"wrote {len(members)} files to {args.output}")


if __name__ == "__main__":
    main()
