#!/usr/bin/env python3
"""Disassemble and describe the trainer AI scripts, archive 169 (files/a/1/6/9).

Each AI flag has a script file, which runs once per usable move with the move's score. A command is a 16-bit ID
followed by 32-bit arguments; the argument layout of every command comes from its handler in src/ov170/tr_ai.c.

    tr_ai_script.py inc include/asm/tr_ai.inc      # write the assembler macros
    tr_ai_script.py disasm ARCHIVE data/tr_ai      # write one .s file per script

The .s files go through the C preprocessor, so that they can use the constants in include/constants, and assemble
back to the original bytes.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from narc import read_narc  # noqa: E402

# Argument kinds:
#   value   a 32-bit value
#   result  a value compared with the result, written as the kind of value that the result holds
#   jump    a jump target, relative to the end of this argument, which ends the command
#   list    a list of values ending with 0xffffffff, relative to the end of this argument
#   table   a jump table indexed by the move's effect, relative to the end of this argument
# and the kinds in CONSTANTS, which are values written as constants.
#
# The result is the value that every load_ command sets, and that if_equal and the other result comparisons read.
COMMANDS = [
    ("if_random_less_than", ["value", "jump"], "AIGreaterThanRandom: jumps if a random number below 256 is less than value"),
    ("if_random_greater_than", ["value", "jump"], "AILessThanRandom"),
    ("if_random_equal", ["value", "jump"], "AIEqualToRandom"),
    ("if_random_not_equal", ["value", "jump"], "AINotEqualToRandom"),
    ("add_to_score", ["value"], "AIIncrementScore: adds a signed value to the move's score, which stays at least 0"),
    ("if_hp_less_than", ["side", "value", "jump"], "AIIsHPLessThan: compares the HP percentage"),
    ("if_hp_greater_than", ["side", "value", "jump"], "AIIsHPGreaterThan"),
    ("if_hp_equal", ["side", "value", "jump"], "AIIsHPEqualTo"),
    ("if_hp_not_equal", ["side", "value", "jump"], "AIIsHPNotEqualTo"),
    ("if_status", ["side", "jump"], "AIHasStatus: jumps if the Pokemon has a status"),
    ("if_no_status", ["side", "jump"], "AIDoesNotHaveStatus"),
    ("if_condition", ["side", "value", "jump"], "AIHasCondition"),
    ("if_not_condition", ["side", "value", "jump"], "AIDoesNotHaveCondition"),
    ("if_badly_poisoned", ["side", "jump"], "AIIsBadlyPoisoned"),
    ("if_not_badly_poisoned", ["side", "jump"], "AIIsNotBadlyPoisoned"),
    ("if_condition_flag", ["side", "value", "jump"], "AIHasConditionFlag"),
    ("if_not_condition_flag", ["side", "value", "jump"], "AIDoesNotHaveConditionFlag"),
    ("if_side_effect", ["side", "value", "jump"], "AIIfSideEffect"),
    ("if_not_side_effect", ["side", "value", "jump"], "AIIfNotSideEffect"),
    ("if_less_than", ["value", "jump"], "AIIfLessThan: compares the result"),
    ("if_greater_than", ["value", "jump"], "AIIfGreaterThan"),
    ("if_equal", ["result", "jump"], "AIIfEqual"),
    ("if_not_equal", ["result", "jump"], "AIIfNotEqual"),
    ("if_bits_set", ["value", "jump"], "AIIfBit: jumps if the result has any of the bits"),
    ("if_bits_clear", ["value", "jump"], "AIIfNotBit"),
    ("if_move", ["move", "jump"], "AIIfMove: compares the move being scored"),
    ("if_not_move", ["move", "jump"], "AIIfNotMove"),
    ("if_in_list", ["list", "jump"], "AIIfResultInList"),
    ("if_not_in_list", ["list", "jump"], "AIIfResultNotInList"),
    ("if_has_damaging_move", ["jump"], "AIHasDamagingMove: jumps if the attacker has a move with power"),
    ("if_no_damaging_move", ["jump"], "AIDoesNotHaveDamagingMove"),
    ("load_turn_count", [], "AIGetTurnCount"),
    ("load_type", ["type_of"], "AIGetType"),
    ("load_power", [], "AIGetBasePower: the base power of the move being scored"),
    ("load_damage_rank", ["value"], "AIGetHighestDamagingMove: 0 if the move deals no damage, 1 if another move deals "
     "more, 2 otherwise"),
    ("load_last_move", ["side"], "AIGetPreviousMove"),
    ("if_equal_2", ["result", "jump"], "AIIfEqual, a second ID"),
    ("if_not_equal_2", ["result", "jump"], "AIIfNotEqual, a second ID"),
    ("if_speed_compare", ["value", "jump"], "AICompareSpeed: 0 jumps if the attacker is faster, 1 if slower, 2 if equal"),
    ("load_able_party_count", ["side"], "AICheckTeamCount: the party's Pokemon that aren't in battle and can battle"),
    ("load_move", [], "AICheckMoveID: the move being scored"),
    ("load_move_effect", [], "AICheckMoveEffect"),
    ("load_known_ability", ["side"], "AICheckAbility: the ability the AI knows or guesses"),
    ("nop_43", [], "AINop43"),
    ("if_effectiveness", ["effectiveness", "jump"], "AIIfTypeEffectiveness: of the move being scored"),
    ("if_party_member_no_status", ["side", "jump"], "AIIfStatusInParty: jumps if a party member that isn't in battle "
     "has no status"),
    ("if_party_member_status", ["side", "jump"], "AIIfStatusNotInParty"),
    ("load_weather", [], "AIGetWeather"),
    ("if_move_effect", ["value", "jump"], "AIHasMoveID: compares the effect of the move being scored"),
    ("if_not_move_effect", ["value", "jump"], "AIDoesNotHaveMoveID"),
    ("if_stat_stage_less_than", ["side", "value", "value", "jump"], "AIStatStageLessThan: stat, then stage"),
    ("if_stat_stage_greater_than", ["side", "value", "value", "jump"], "AIStatStageGreaterThan"),
    ("if_stat_stage_equal", ["side", "value", "value", "jump"], "AIStatStageEqual"),
    ("if_stat_stage_not_equal", ["side", "value", "value", "jump"], "AIStatStageNotEqual"),
    ("if_can_faint", ["value", "jump"], "AIIfCanFaint: the first argument is unused"),
    ("if_cannot_faint", ["value", "jump"], "AIIfCannotFaint"),
    ("if_knows_move", ["side", "move", "jump"], "AIIfHasMove: for the defender, only the moves it was seen to use"),
    ("if_not_knows_move", ["side", "move", "jump"], "AIIfDoesNotHaveMove"),
    ("if_knows_move_effect", ["side", "value", "jump"], "AIIfHasMoveWithEffect"),
    ("if_not_knows_move_effect", ["side", "value", "jump"], "AIIfDoesNotHaveMoveWithEffect"),
    ("nop_60", [], "AINop60"),
    ("flee", [], "AIFlee"),
    ("nop_62", [], "AINop62"),
    ("nop_63", [], "AINop63"),
    ("load_held_item", ["side"], "AIGetHeldItem"),
    ("load_held_item_effect", ["side"], "AIGetItemEffect: item parameter 1"),
    ("load_gender", ["side"], "AIGetGender"),
    ("load_fake_out_active", ["side"], "AIIsFakeOutActive: TRUE if condition flag 0 is clear"),
    ("load_stockpile_count", ["side"], "AIGetStockpileCount"),
    ("load_battle_style", [], "AIGetBattleStyle"),
    ("load_battle_type", [], "AIGetBattleType"),
    ("load_consumed_item", ["side"], "AIGetConsumedItem"),
    ("nop_72", [], "AINop72"),
    ("load_result_power", [], "AIGetMovePower: replaces the result, a move, with its power"),
    ("load_result_effect", [], "AIGetMoveID: replaces the result, a move, with its effect"),
    ("load_protect_count", ["side"], "AIGetProtectCount"),
    ("jump", ["jump"], "AIJump"),
    ("end", [], "AIEnd: ends the script for this move"),
    ("if_level_compare", ["value", "jump"], "AICompareLevel: 0 jumps if the attacker's level is higher, 1 if lower, 2 "
     "if equal"),
    ("if_taunted", ["jump"], "AIIfTaunted: the defender"),
    ("if_not_taunted", ["jump"], "AIIfNotTaunted"),
    ("if_target_is_ally", ["jump"], "AIIfTargetIsAlly"),
    ("load_has_type", ["side", "type"], "AIDoesMonHaveType"),
    ("load_known_ability_is", ["side", "ability"], "AIGuessAbility"),
    ("if_flash_fire", ["side", "jump"], "AIIfFlashFireIsActive"),
    ("if_held_item", ["side", "item", "jump"], "AIIfHasItem"),
    ("if_field_effect", ["value", "jump"], "AIIfFieldEffect"),
    ("load_side_effect", ["side", "value"], "AIGetSideEffect"),
    ("if_party_member_damaged", ["side", "jump"], "AIIfPartyMemberDamaged"),
    ("if_party_member_used_pp", ["side", "jump"], "AIIfPartyMemberUsedPP"),
    ("load_fling_power", ["side"], "AIGetFlingPower"),
    ("load_move_pp", [], "AIGetMovePP"),
    ("if_can_use_last_resort", ["side", "jump"], "AIIfCanUseLastResort"),
    ("load_move_category", [], "AIGetMoveCategory"),
    ("load_last_move_category", [], "AIGetLastMoveCategory: the defender's last move"),
    ("load_speed_order", ["side"], "AIGetOrderInTurn"),
    ("load_unk_96", ["side"], "func_ov170_0218119c"),
    ("if_party_member_deals_more_damage", ["value", "jump"], "AIIfPartyMemberDealsMoreDamage"),
    ("if_has_super_effective_move", ["jump"], "AIIfHasSuperEffectiveMove"),
    ("if_last_move_deals_more_damage", ["side", "value", "jump"], "AIIfLastMoveDealsMoreDamage"),
    ("load_positive_stat_stage_total", ["side"], "AIGetPositiveStatStageTotal"),
    ("load_stat_stage_difference", ["side", "value"], "AIGetStatStageDifference"),
    ("nop_102", [], "AINop102"),
    ("nop_103", [], "AINop103"),
    ("nop_104", [], "AINop104"),
    ("load_damage_rank_with_partners", ["value"], "AIGetHighestDamagingMoveWithPartners"),
    ("if_fainted", ["side", "jump"], "AIIsFainted"),
    ("if_not_fainted", ["side", "jump"], "AIIsNotFainted"),
    ("load_ability", ["side"], "AIGetAbility: battle Pokemon value 17"),
    ("if_substitute", ["side", "jump"], "AIIfSubstitute"),
    ("load_species", ["side"], "AIGetSpecies"),
    ("if_turn_random_less_than", ["value", "jump"], "AIGreaterThanTurnRandom: compares the random number of the turn"),
    ("if_turn_random_greater_than", ["value", "jump"], "AILessThanTurnRandom"),
    ("if_turn_random_equal", ["value", "jump"], "AIEqualToTurnRandom"),
    ("if_turn_random_not_equal", ["value", "jump"], "AINotEqualToTurnRandom"),
    ("jump_by_move_effect", ["value", "value", "table"], "AIJumpByMoveEffect: mode, the highest effect, table"),
    ("unk_cmd_116", ["side", "jump"], "func_ov170_02181734"),
    ("if_attack_less_than_sp_attack", ["side", "jump"], "AIIsAtkLessThanSpAtk: the original compares the position with "
     "the special attack"),
    ("if_attack_greater_than_sp_attack", ["side", "jump"], "AIIsAtkGreaterThanSpAtk"),
    ("if_attack_equal_sp_attack", ["side", "jump"], "AIIsAtkEqualToSpAtk"),
]

INCLUDE = Path(__file__).resolve().parent.parent.parent / "include"
# The headers that the scripts include, and the prefix of the constants for each kind of value
CONSTANTS = {
    "side": ("constants/tr_ai.h", "TRAI_SIDE_"),
    "type_of": ("constants/tr_ai.h", "TRAI_TYPE_"),
    "move": ("constants/moves.h", "MOVE_"),
    "ability": ("constants/abilities.h", "ABILITY_"),
    "item": ("constants/items.h", "ITEM_"),
    "species": ("constants/species.h", "SPECIES_"),
    "type": ("constants/types.h", "TYPE_"),
    "effectiveness": ("constants/battle.h", "TYPE_EFFECTIVENESS_"),
    "battle_style": ("constants/battle.h", "BTL_STYLE_"),
}
# The kind of value that load_ commands put in the result, where it is one of the kinds in CONSTANTS
RESULTS = {
    "load_type": "type",
    "load_last_move": "move",
    "load_move": "move",
    "load_known_ability": "ability",
    "load_held_item": "item",
    "load_battle_style": "battle_style",
    "load_consumed_item": "item",
    "load_ability": "ability",
    "load_species": "species",
}
# Commands after which the script doesn't continue: jump, end and jump_by_move_effect
NO_FALLTHROUGH = {76, 77, 115}
REFERENCES = ("jump", "list", "table")
LIST_END = 0xFFFFFFFF


def load_constants() -> dict[str, dict[int, str]]:
    constants = {}
    for kind, (header, prefix) in CONSTANTS.items():
        names = {}
        for match in re.finditer(rf"^#define ({prefix}\w+) (\d+)$", (INCLUDE / header).read_text(), re.MULTILINE):
            names.setdefault(int(match[2]), match[1])
        constants[kind] = names
    return constants


def write_inc(path: Path):
    headers = sorted({header for header, _ in CONSTANTS.values()})
    lines = [
        "@ Macros for the trainer AI scripts, written by tools/scripts/tr_ai_script.py inc",
        "",
        *(f'#include "{header}"' for header in headers),
        "",
        "    .macro ai_cmd id",
        "    .2byte \\id",
        "    .endm",
        "",
        "    .macro list_end",
        f"    .4byte {LIST_END:#x}",
        "    .endm",
        "",
    ]
    for cmd_id, (name, args, doc) in enumerate(COMMANDS):
        params = [f"a{i}" for i in range(len(args))]
        lines.append(f"    @ {doc}")
        lines.append(f"    .macro {name}{' ' if params else ''}{', '.join(params)}")
        lines.append(f"    ai_cmd {cmd_id}")
        for param, kind in zip(params, args):
            if kind in REFERENCES:
                lines.append(f"    .4byte \\{param} - (. + 4)")
            else:
                lines.append(f"    .4byte \\{param}")
        lines.append("    .endm")
        lines.append("")
    path.write_text("\n".join(lines))


def s32(value: int) -> int:
    return value - (1 << 32) if value & 0x80000000 else value


class Script:
    def __init__(self, data: bytes, label_prefix: str, constants: dict[str, dict[int, str]] | None = None):
        self.data = data
        self.prefix = label_prefix
        self.constants = constants or {}
        self.instructions: dict[int, tuple[int, list[tuple[str, int]], int]] = {}
        self.labels: set[int] = {0}
        self.lists: dict[int, int] = {}  # start -> end
        self.tables: dict[int, int] = {}  # start -> entry count

    def label(self, offset: int) -> str:
        return f"{self.prefix}_{offset:04X}"

    def decode(self, pc: int):
        if pc + 2 > len(self.data):
            return None
        cmd_id = struct.unpack_from("<H", self.data, pc)[0]
        if cmd_id >= len(COMMANDS):
            return None
        _, kinds, _ = COMMANDS[cmd_id]
        end = pc + 2 + 4 * len(kinds)
        if end > len(self.data):
            return None
        args = []
        for i, kind in enumerate(kinds):
            field = pc + 2 + 4 * i
            value = struct.unpack_from("<I", self.data, field)[0]
            if kind in REFERENCES:
                target = field + 4 + s32(value)
                # A target outside the file means these bytes aren't this command
                if not 0 <= target < len(self.data):
                    return None
                args.append((kind, target))
            else:
                args.append((kind, value))
        return cmd_id, args, end

    def trace(self):
        pending = [0]
        while pending:
            pc = pending.pop()
            while pc not in self.instructions:
                decoded = self.decode(pc)
                if decoded is None:
                    break
                cmd_id, args, end = decoded
                self.instructions[pc] = decoded
                for kind, target in args:
                    if kind == "jump":
                        self.labels.add(target)
                        pending.append(target)
                    elif kind == "list":
                        self.labels.add(target)
                        self.trace_list(target)
                    elif kind == "table":
                        self.labels.add(target)
                        mode, highest = args[0][1], args[1][1]
                        if mode == 0:
                            self.tables[target] = highest + 1
                            for i in range(highest + 1):
                                entry = struct.unpack_from("<I", self.data, target + 4 * i)[0]
                                self.labels.add(target + entry)
                                pending.append(target + entry)
                if cmd_id in NO_FALLTHROUGH:
                    break
                pc = end

    def trace_list(self, start: int):
        pc = start
        while pc + 4 <= len(self.data):
            value = struct.unpack_from("<I", self.data, pc)[0]
            pc += 4
            if value == LIST_END:
                break
        self.lists[start] = pc

    def fill_gaps(self):
        """Decodes what no path reaches. Each gap is taken in order: commands where they trace cleanly from the next
        undecoded offset, lists where the values end with 0xffffffff, and raw bytes for the rest."""
        for gap_start, gap_end in self.gaps():
            pos = gap_start
            while pos < gap_end:
                if self.try_code(pos, gap_end) or self.try_list(pos, gap_end):
                    covered = self.covered()
                    while pos < gap_end and pos in covered:
                        pos += 1
                else:
                    break

    def gaps(self) -> list[tuple[int, int]]:
        covered = self.covered()
        gaps = []
        pc = 0
        while pc < len(self.data):
            if pc in covered:
                pc += 1
                continue
            start = pc
            while pc < len(self.data) and pc not in covered:
                pc += 1
            gaps.append((start, pc))
        return gaps

    def try_code(self, start: int, gap_end: int) -> bool:
        """Traces from start, keeping the result only if it stays inside the gap and its jumps land on the starts
        of commands."""
        trial = Script(self.data, self.prefix)
        trial.instructions = dict(self.instructions)
        trial.lists = dict(self.lists)
        trial.tables = dict(self.tables)
        trial.labels = set(self.labels)
        covered = self.covered()
        pending = [start]
        while pending:
            pc = pending.pop()
            while pc not in trial.instructions:
                if not start <= pc < gap_end or pc in covered:
                    return False
                decoded = trial.decode(pc)
                if decoded is None or any(o in covered for o in range(pc, decoded[2])):
                    return False
                cmd_id, args, end = decoded
                trial.instructions[pc] = decoded
                for kind, target in args:
                    trial.labels.add(target)
                    if kind == "jump":
                        pending.append(target)
                    elif kind == "list":
                        if target not in trial.lists:
                            trial.trace_list(target)
                    elif kind == "table":
                        return False
                if cmd_id in NO_FALLTHROUGH:
                    break
                pc = end
        if any(not start <= o < gap_end for o in trial.covered() - covered):
            return False
        starts = set(trial.instructions)
        for pc, (_, args, _) in trial.instructions.items():
            if pc not in self.instructions:
                if any(kind == "jump" and target not in starts for kind, target in args):
                    return False
        self.instructions, self.lists, self.labels = trial.instructions, trial.lists, trial.labels
        return True

    def try_list(self, start: int, gap_end: int) -> bool:
        """Takes 32-bit values up to and including a 0xffffffff inside the gap as a list."""
        pc = start
        while pc + 4 <= gap_end:
            value = struct.unpack_from("<I", self.data, pc)[0]
            pc += 4
            if value == LIST_END:
                self.lists[start] = pc
                return True
        return False

    def covered(self) -> set[int]:
        covered = set()
        for pc, (_, _, end) in self.instructions.items():
            covered.update(range(pc, end))
        for start, end in self.lists.items():
            covered.update(range(start, end))
        for start, count in self.tables.items():
            covered.update(range(start, start + 4 * count))
        return covered

    def boundaries(self) -> set[int]:
        """The offsets where a label can go: the start of each command, list or table entry and raw byte."""
        covered = self.covered()
        starts = set(self.instructions)
        for start, end in self.lists.items():
            starts.update(range(start, end, 4))
        for start, count in self.tables.items():
            starts.update(range(start, start + 4 * count, 4))
        starts.update(o for o in range(len(self.data)) if o not in covered)
        starts.add(len(self.data))
        return starts

    def successors(self, pc: int) -> list[int]:
        cmd_id, args, end = self.instructions[pc]
        targets = [target for kind, target in args if kind == "jump"]
        for kind, table in args:
            if kind == "table" and table in self.tables:
                targets += [table + struct.unpack_from("<I", self.data, table + 4 * i)[0]
                            for i in range(self.tables[table])]
        if cmd_id not in NO_FALLTHROUGH:
            targets.append(end)
        return [target for target in targets if target in self.instructions]

    def result_kinds(self) -> dict[int, str | None]:
        """Returns the kind of value in the result when each command runs, where every way to the command agrees."""
        predecessors = {pc: [] for pc in self.instructions}
        for pc in self.instructions:
            for target in self.successors(pc):
                predecessors[target].append(pc)
        before = {pc: None for pc, sources in predecessors.items() if pc == 0 or not sources}
        pending = list(before)
        while pending:
            pc = pending.pop()
            name = COMMANDS[self.instructions[pc][0]][0]
            after = RESULTS.get(name) if name.startswith("load_") else before[pc]
            for target in self.successors(pc):
                if target not in before:
                    before[target] = after
                elif before[target] != after and before[target] is not None:
                    before[target] = None
                else:
                    continue
                pending.append(target)
        return before

    def format_arg(self, kind: str, value: int) -> str:
        if kind in REFERENCES:
            if value not in self.placeable:
                # The target is inside another command, so give it as an offset from this argument's end
                return f". + 4 + {value - self.current_field - 4}"
            return self.label(value)
        if kind == "result":
            kind = self.current_result
        name = self.constants.get(kind, {}).get(value)
        if name is not None:
            return name
        signed = s32(value)
        return str(signed) if -0x10000 < signed < 0x10000 else f"{value:#x}"

    def disassemble(self) -> str:
        self.trace()
        self.fill_gaps()
        self.labels.update(self.lists)
        self.placeable = self.boundaries()
        results = self.result_kinds()
        # A list holds the kind of value that the result holds where the list is used, if that is always the same
        list_kinds = {}
        for pc, (cmd_id, args, _) in self.instructions.items():
            for kind, target in args:
                if kind == "list":
                    list_kinds.setdefault(target, set()).add(results.get(pc))
        # The files are padded with zeros to a multiple of 4 bytes
        covered = self.covered()
        padded = len(self.data)
        size = max(covered) + 1 if covered else 0
        if not (0 < padded - size < 4 and padded % 4 == 0 and all(o in covered for o in range(size))
                and not any(self.data[size:])):
            size = padded
        out = []
        pc = 0
        while pc < size:
            if pc in self.instructions:
                self.emit_label(out, pc)
                cmd_id, args, end = self.instructions[pc]
                self.current_result = results.get(pc)
                parts = []
                for i, (kind, value) in enumerate(args):
                    self.current_field = pc + 2 + 4 * i
                    parts.append(self.format_arg(kind, value))
                text = ", ".join(parts)
                out.append(f"    {COMMANDS[cmd_id][0]}{' ' if text else ''}{text}")
                pc = end
            elif pc in self.lists:
                kinds = list_kinds.get(pc, set())
                self.current_result = next(iter(kinds)) if len(kinds) == 1 else None
                for element in range(pc, self.lists[pc], 4):
                    self.emit_label(out, element)
                    value = struct.unpack_from("<I", self.data, element)[0]
                    out.append("    list_end" if value == LIST_END else f"    .4byte {self.format_arg('result', value)}")
                pc = self.lists[pc]
            elif pc in self.tables:
                table = pc
                for entry in range(table, table + 4 * self.tables[table], 4):
                    self.emit_label(out, entry)
                    target = table + struct.unpack_from("<I", self.data, entry)[0]
                    out.append(f"    .4byte {self.label(target)} - {self.label(table)}")
                pc = table + 4 * self.tables[table]
            else:
                self.emit_label(out, pc)
                out.append(f"    .byte {self.data[pc]:#04x}")
                pc += 1
        if size < padded:
            out.append("    .balign 4")
        self.emit_label(out, len(self.data))
        return "\n".join(out) + "\n"

    def emit_label(self, out: list[str], offset: int):
        if offset in self.labels:
            out.append(f"{self.label(offset)}:")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    commands = parser.add_subparsers(dest="command", required=True)
    inc = commands.add_parser("inc")
    inc.add_argument("output", type=Path)
    disasm = commands.add_parser("disasm")
    disasm.add_argument("archive", type=Path)
    disasm.add_argument("output", type=Path)
    args = parser.parse_args()

    if args.command == "inc":
        args.output.parent.mkdir(parents=True, exist_ok=True)
        write_inc(args.output)
    else:
        args.output.mkdir(parents=True, exist_ok=True)
        constants = load_constants()
        for i, data in enumerate(read_narc(args.archive.read_bytes())):
            script = Script(data, f"TrAI{i:02d}", constants)
            text = f'#include "asm/tr_ai.inc"\n\n{script.disassemble()}'
            (args.output / f"tr_ai_{i:02d}.s").write_text(text)


if __name__ == "__main__":
    main()
