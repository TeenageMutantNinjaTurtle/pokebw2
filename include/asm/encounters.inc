// Macros for the wild encounters in data/encounters, archive a/1/2/7: one file per encounter table, which a zone's
// header names. A file holds one table (EncData), or four, for spring, summer, autumn and winter (EncData_Load picks
// the season's). Each table is EncounterRates, then the slots of each group in this order, then EncountersEnd:
// GrassEncounters, DarkGrassEncounters and ShakingGrassEncounters with 12 slots each, then SurfEncounters,
// RipplingSurfEncounters, FishingEncounters and RipplingFishingEncounters with 5 each. The slots a group doesn't list
// are empty; listing too many is an error.

#include "constants/species.h"

    .set _enc_left, 0

    // The encounter rate of each group, 0 for none, and the table's flags (swan's flags and fishingEnable)
    .macro EncounterRates grass, dark_grass, shaking_grass, surf, rippling_surf, fishing, rippling_fishing, flags=0
    .byte \grass, \dark_grass, \shaking_grass, \surf, \rippling_surf, \fishing, \rippling_fishing, \flags
    .endm

    // Fills the rest of the previous group with empty slots, and starts a group
    .macro _EncounterGroup slots
    .if _enc_left < 0
    .error "an encounter group has too many slots"
    .endif
    .rept _enc_left
    .4byte 0
    .endr
    .set _enc_left, \slots
    .endm

    .macro GrassEncounters
    _EncounterGroup 12
    .endm
    .macro DarkGrassEncounters
    _EncounterGroup 12
    .endm
    .macro ShakingGrassEncounters
    _EncounterGroup 12
    .endm
    .macro SurfEncounters
    _EncounterGroup 5
    .endm
    .macro RipplingSurfEncounters
    _EncounterGroup 5
    .endm
    .macro FishingEncounters
    _EncounterGroup 5
    .endm
    .macro RipplingFishingEncounters
    _EncounterGroup 5
    .endm

    // A slot: a species, its levels and its form. An empty slot is SPECIES_NONE at levels 0
    .macro Encounter species, min_level, max_level, form=0
    .2byte \species | (\form << 11)
    .byte \min_level, \max_level
    .set _enc_left, _enc_left - 1
    .endm

    .macro EncountersEnd
    _EncounterGroup 0
    .endm
