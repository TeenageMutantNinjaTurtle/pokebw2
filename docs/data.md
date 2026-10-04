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
| `a/0/1/6` | `data/personal/` | Species data | `tools/scripts/personal_data.py` |
| `a/0/2/1` | `data/moves/` | Move data | `tools/scripts/move_data.py` |
| `a/0/5/6` | `data/field_scripts/` | Field scripts, see [Scripts](scripts.md#field-scripts) | `tools/scripts/field_script.py` |
| `a/1/6/9` | `data/tr_ai/` | Trainer AI scripts, see [Scripts](scripts.md) | `tools/scripts/tr_ai_script.py` |

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
