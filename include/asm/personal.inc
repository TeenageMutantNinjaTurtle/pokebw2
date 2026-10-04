// Macros for the species data ("personal" data) in data/personal, archive a/0/1/6. Each file is one species or form,
// a 0x4c-byte record that PML_PersonalGetParam reads; the macros write its fields, so a file uses each of them once,
// in this order. Fields whose meaning isn't known yet are named after their place.

#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/types.h"

    // 0x00
    .macro BaseStats hp, attack, defense, speed, sp_attack, sp_defense
    .byte \hp, \attack, \defense, \speed, \sp_attack, \sp_defense
    .endm

    // 0x06
    .macro Types type1, type2
    .byte \type1, \type2
    .endm

    // 0x08
    .macro CatchRate rate
    .byte \rate
    .endm

    // 0x09: 1 for a species that doesn't evolve from another, then 2 and 3 along its evolutions
    .macro EvolutionStage stage
    .byte \stage
    .endm

    // 0x0a: the effort values a defeated Pokémon of the species gives, 0 to 3 each, and a flag in bit 12
    .macro EvYields hp, attack, defense, speed, sp_attack, sp_defense, flag12=0
    .2byte \hp | (\attack << 2) | (\defense << 4) | (\speed << 6) | (\sp_attack << 8) | (\sp_defense << 10) | (\flag12 << 12)
    .endm

    // 0x0c: the items wild Pokémon of the species hold, from the most to the least common
    .macro HeldItems common, rare, very_rare
    .2byte \common, \rare, \very_rare
    .endm

    // 0x12: the chance of female out of 254, or GENDER_RATIO_*
    .macro GenderRatio ratio
    .byte \ratio
    .endm

    // 0x13
    .macro HatchCycles cycles
    .byte \cycles
    .endm

    // 0x14
    .macro BaseFriendship friendship
    .byte \friendship
    .endm

    // 0x15: GROWTH_*
    .macro GrowthRate rate
    .byte \rate
    .endm

    // 0x16
    .macro EggGroups group1, group2
    .byte \group1, \group2
    .endm

    // 0x18
    .macro Abilities ability1, ability2, hidden
    .byte \ability1, \ability2, \hidden
    .endm

    // 0x1b
    .macro FleeRate rate
    .byte \rate
    .endm

    // 0x1c: the record of the species' first alternate form, the offset of its forms' sprites, and its number of forms
    .macro Forms first_record, sprite_offset, count
    .2byte \first_record, \sprite_offset
    .byte \count
    .endm

    // 0x21: COLOR_*, and the flags in bits 6 and 7
    .macro Color color, flag6=0, flag7=0
    .byte \color | (\flag6 << 6) | (\flag7 << 7)
    .endm

    // 0x22: the base of the experience that defeating a Pokémon of the species gives
    .macro BaseExp exp
    .2byte \exp
    .endm

    // 0x24: in tenths of a meter and tenths of a kilogram
    .macro HeightWeight height, weight
    .2byte \height, \weight
    .endm

    // 0x28: the TMs and HMs the species can learn: TM01 to TM95, then HM01 to HM06
    .macro Machines machines:vararg
    .set _machines0, 0
    .set _machines1, 0
    .set _machines2, 0
    .set _machines3, 0
    .irp machine, \machines
    .ifnb \machine
    .if (\machine) < 32
    .set _machines0, _machines0 | (1 << (\machine))
    .elseif (\machine) < 64
    .set _machines1, _machines1 | (1 << ((\machine) - 32))
    .elseif (\machine) < 96
    .set _machines2, _machines2 | (1 << ((\machine) - 64))
    .else
    .set _machines3, _machines3 | (1 << ((\machine) - 96))
    .endif
    .endif
    .endr
    .4byte _machines0, _machines1, _machines2, _machines3
    .endm

    // 0x38: the bits of the moves the species learns from the type move tutor, and of the four move tutors
    .macro Tutors type_tutor, tutor1, tutor2, tutor3, tutor4
    .4byte \type_tutor, \tutor1, \tutor2, \tutor3, \tutor4
    .endm

    // Machine numbers for Machines
    .irp n, 1, 2, 3, 4, 5, 6, 7, 8, 9
    .set TM0\n, \n - 1
    .endr
    .irp n, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95
    .set TM\n, \n - 1
    .endr
    .irp n, 1, 2, 3, 4, 5, 6
    .set HM0\n, \n + 94
    .endr
