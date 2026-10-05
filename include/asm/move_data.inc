// Macros for the move data in data/moves, archive a/0/2/1. Each file is one move, a 0x24-byte record that
// PML_MoveGetParamCore reads; the macros write its fields, so a file uses each of them once, in this order. Fields
// whose meaning isn't known yet are named after what they hold.

#include "constants/battle.h"
#include "constants/move_effects.h"
#include "constants/types.h"

    // 0x00
    .macro Type type
    .byte \type
    .endm

    // 0x01: the class of the move's effect, MOVE_QUALITY_*
    .macro Quality quality
    .byte \quality
    .endm

    // 0x02: MOVE_CATEGORY_*
    .macro Category category
    .byte \category
    .endm

    // 0x03
    .macro Power power
    .byte \power
    .endm

    // 0x04: in percent, or 101 for a move that never misses
    .macro Accuracy accuracy
    .byte \accuracy
    .endm

    // 0x05
    .macro PP pp
    .byte \pp
    .endm

    // 0x06
    .macro Priority priority
    .byte \priority
    .endm

    // 0x07: the number of hits of a multi-hit move, 0 for one
    .macro Hits min, max
    .byte \min | (\max << 4)
    .endm

    // 0x08: the condition the move inflicts (CONDITION_*), its chance in percent, and the turns it lasts: a kind of
    // duration and a range of turns
    .macro Inflicts condition, chance, duration, min_turns, max_turns
    .2byte \condition
    .byte \chance, \duration, \min_turns, \max_turns
    .endm

    // 0x0e: the critical hit stage, 6 for a move that always lands a critical hit
    .macro CritStage stage
    .byte \stage
    .endm

    // 0x0f: in percent
    .macro FlinchChance chance
    .byte \chance
    .endm

    // 0x10: BATTLE_EFFECT_*
    .macro Effect effect
    .2byte \effect
    .endm

    // 0x12: the share of the damage the user drains (positive) or takes as recoil (negative), and of its HP it heals,
    // in percent
    .macro DrainHeal drain, heal
    .byte \drain, \heal
    .endm

    // 0x14: which Pokémon the move targets, MOVE_TARGET_*
    .macro Target target
    .byte \target
    .endm

    // 0x15: up to three stat changes, each a stat (BATTLEMON_*_STAGE), the stages it changes by, and its chance in
    // percent
    .macro StatChanges stat1=0, stages1=0, chance1=0, stat2=0, stages2=0, chance2=0, stat3=0, stages3=0, chance3=0
    .byte \stat1, \stat2, \stat3
    .byte \stages1, \stages2, \stages3
    .byte \chance1, \chance2, \chance3
    .endm

    // 0x1e: every move has "SS" here
    .macro Marker
    .ascii "SS"
    .endm

    // 0x20: the move's flags, MOVE_FLAG_* OR'ed together
    .macro Flags flags
    .4byte \flags
    .endm
