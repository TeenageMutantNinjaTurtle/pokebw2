# Game data

The game keeps most of its data in NARC archives under `files/a/`, one numbered file per entry. The archives that are
built from source have their entries in `data/`, one source file per entry, in archive order, assembled with the
macros in `include/asm/`. `configure.py` lists them in `ARCHIVES`; the build assembles the files, packs the archive
in their order and checks that it matches the original, so editing an entry is as easy as editing its file, and the
matching build proves that the sources say exactly what the ROM holds.

The sources go through the C preprocessor, so they use the same constants as the C code (`include/constants/`). Each
archive has a script that wrote its sources from the original, which documents the format and can write them again.

| Archive | Sources | Contents | Script |
| --- | --- | --- | --- |
| `a/0/0/2` | `data/text/system/` | System messages | `tools/scripts/text_data.py` |
| `a/0/0/3` | `data/text/script/` | Script messages | `tools/scripts/text_data.py` |
| `a/0/1/6` | `data/personal/` | Species data | `tools/scripts/personal_data.py` |
| `a/0/1/8` | `data/levelup_moves/` | Moves learned by leveling up | `tools/scripts/species_tables.py` |
| `a/0/1/9` | `data/evolutions/` | Evolutions | `tools/scripts/species_tables.py` |
| `a/0/2/1` | `data/moves/` | Move data | `tools/scripts/move_data.py` |
| `a/0/5/6` | `data/field_scripts/` | Field scripts, see [Scripts](scripts.md#field-scripts) | `tools/scripts/field_script.py` |
| `a/0/9/1`, `a/0/9/2` | `data/trainers/` | Trainers and their parties | `tools/scripts/trainer_data.py` |
| `a/1/6/9` | `data/tr_ai/` | Trainer AI scripts, see [Scripts](scripts.md) | `tools/scripts/tr_ai_script.py` |

The text archives are packed by `text_data.py` from text files rather than assembled; `configure.py` lists them in
`TEXT_ARCHIVES`.

## Text

`a/0/0/2` (system messages) and `a/0/0/3` (script messages) hold the game's text, one message file per entry. Their
sources are `data/text/system/NNNN.txt` and `data/text/script/NNNN.txt`, UTF-8, with one message per line, so the
line number (from 0) is the message's ID:

```
Listen up!\nThere's nothing wrong with making money!{be01}\nBut there are wrong ways to do it...
How serious are you willing to get\nin order to get what you want?
```

- `\n` is a line break within a message, and `\\`, `\{` and `\}` are a backslash and braces.
- `{TTTT}` or `{TTTT:a,b}` is a control code, its type in hex and its arguments: a placeholder for a name or number,
  a color, or `{be01}`, which waits for a button and scrolls.
- `\x{HHHH}` is a character that can't be shown as itself. Some messages end with `\x{ffff}`, an extra terminator that
  the original files have.
- A message that starts with `\c` is stored compressed, as the game stores trainers' names, among others.
- A last line `\pad{XX}` is not a message but the byte that fills the end of the file to a multiple of 4 bytes, which
  the original files have as leftovers rather than 0.

The game encrypts each message with a key that depends on its ID, which `text_data.py` applies when packing. The
files aren't named yet; `msgdata.py ARCHIVE FILE` prints one with its message IDs. Both versions have the same text.

## Species data

`a/0/1/6` holds one 0x4c-byte record per species and form, which `PML_PersonalGetParam` reads field by field. Its
sources are `data/personal/NNNN_name.s`, numbered by record:

- 0 is empty, and 1 to 649 are the species by national Pokédex number.
- 685 to 708 are alternate forms, such as `0685_deoxys_form1.s`. A species' `Forms` field gives the record of its
  first alternate form, the offset of its forms' sprites and its number of forms; species whose forms only differ
  in looks, such as Unown, have no records of their own.
- 650 to 684 are records that no species' `Forms` field points at, kept as `NNNN_extra.s` until their use is known.
- 709 is a table of 16-bit values, 999 for none, whose meaning isn't known yet.

```
#include "asm/personal.inc"

// SPECIES_BULBASAUR
    BaseStats 45, 49, 49, 45, 65, 65
    Types TYPE_GRASS, TYPE_POISON
    CatchRate 45
    EvolutionStage 1
    EvYields 0, 0, 0, 0, 1, 0
    HeldItems ITEM_NONE, ITEM_NONE, ITEM_NONE
    GenderRatio 31
    HatchCycles 20
    BaseFriendship 70
    GrowthRate GROWTH_MEDIUM_SLOW
    EggGroups EGG_GROUP_MONSTER, EGG_GROUP_GRASS
    Abilities ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL
    ...
    Machines TM06, TM09, TM10, ..., HM01, HM04
```

Each macro writes one field, so a file uses every macro once, in the order of `include/asm/personal.inc`, which
documents the fields. Stats are in the order HP, Attack, Defense, Speed, Sp. Atk, Sp. Def, as the record keeps them.
`Machines` lists the TMs and HMs the species can learn. The tutor moves are still bit masks, and a few flags whose
meaning isn't known yet are named after their bits (`flag12` of the effort values, `flag6` and `flag7` of the color).
Both versions have the same species data.

## Evolutions and level-up moves

`a/0/1/9` and `a/0/1/8` hold one entry per species record, so their sources in `data/evolutions/` and
`data/levelup_moves/` are numbered and named as `data/personal/`'s.

```
#include "asm/evolution.inc"

// SPECIES_EEVEE
    Evolution EVO_METHOD_LEVEL_MOSS_ROCK, 0, SPECIES_LEAFEON
    Evolution EVO_METHOD_ITEM, ITEM_THUNDERSTONE, SPECIES_JOLTEON
    Evolution EVO_METHOD_FRIENDSHIP_DAY, 0, SPECIES_ESPEON
    ...
    EvolutionsEnd
```

An evolution is a method (`EVO_METHOD_*`), its parameter, and the species it evolves into. The parameter depends on
the method: a level, an item, a move, a species, or another value such as the beauty needed. A species has at most
seven, and `EvolutionsEnd` fills the rest.

```
#include "asm/levelup_moves.inc"

// SPECIES_PIKACHU
    LevelUpMove 1, MOVE_GROWL
    LevelUpMove 1, MOVE_THUNDER_SHOCK
    LevelUpMove 5, MOVE_TAIL_WHIP
    ...
    LevelUpMovesEnd
```

The moves are in the order the game checks them, by level.

## Move data

`a/0/2/1` holds one 0x24-byte record per move, by move ID, which `PML_MoveGetParamCore` reads. Its sources are
`data/moves/NNNN_name.s`, with the macros of `include/asm/move_data.inc`, again one per field and in its order:

```
#include "asm/move_data.inc"

// MOVE_THUNDERBOLT
    Type TYPE_ELECTRIC
    Quality 4
    Category MOVE_CATEGORY_SPECIAL
    Power 95
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 10, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_PARALYZE_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0048
```

`Effect` is the battle effect the move runs (`BATTLE_EFFECT_*`), and `Inflicts` the condition it inflicts with its
chance and duration. `StatChanges` takes up to three changes as `statN=`, `stagesN=` and `chanceN=`, with the stats
of `BATTLEMON_*_STAGE`. `Quality`, `Target` and `Flags` are still numbers, until their values are named. Both
versions have the same move data.

## Trainers

A trainer is an entry of `a/0/9/1` and its party the entry of `a/0/9/2` with the same ID. Both come from one file,
`data/trainers/NNNN_name.s`, named after the trainer's ID and name: the file's `.trainer` section goes into the first
archive and its `.party` section into the second (`ARCHIVES` names the section of each).

```
#include "asm/trainer.inc"

// Elite Four Shauntal
    Trainer class=78, party=PARTY_MOVES | PARTY_ITEMS, item1=ITEM_FULL_RESTORE, ai=AI_FLAG_BASIC | AI_FLAG_EVAL_ATTACK | AI_FLAG_EXPERT, money=30
    PartyMon level=56, species=SPECIES_COFAGRIGUS, difficulty=200, ability=1, move1=MOVE_WILL_O_WISP, ...
    ...
    PartyMon level=58, species=SPECIES_CHANDELURE, difficulty=250, ability=2, item=ITEM_SITRUS_BERRY, ...
    PartyEnd
```

The macros take keyword arguments, and leave out the ones that are 0. `party` says what each party entry holds besides
the Pokémon: `PARTY_MOVES`, `PARTY_ITEMS`, both, or neither, in which case a Pokémon gets the moves of its level and
no item. `PartyEnd` counts the party for the trainer record. `style` is the battle style (`BTL_STYLE_*`), `ai` the
trainer AI scripts to run (`AI_FLAG_*`, see [Scripts](scripts.md)), `money` a multiplier of the prize money and
`reward` an item given after the battle. A Pokémon's `difficulty` sets its individual values, and `gender` and
`ability` pick them when not 0. The trainer class is still a number, with its name in the file's comment. Both
versions have the same trainers.
