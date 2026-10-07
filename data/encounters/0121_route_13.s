#include "asm/encounters.inc"

// Route 13

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_TANGELA, 34, 34
    Encounter SPECIES_PELIPPER, 34, 34
    Encounter SPECIES_DRIFBLIM, 34, 34
    Encounter SPECIES_LUNATONE, 36, 36
    Encounter SPECIES_SOLROCK, 36, 36
    Encounter SPECIES_ABSOL, 35, 35
    Encounter SPECIES_DRIFBLIM, 35, 35
    Encounter SPECIES_ABSOL, 37, 37
    Encounter SPECIES_TANGELA, 36, 36
    Encounter SPECIES_PELIPPER, 36, 36
    Encounter SPECIES_TANGELA, 37, 37
    Encounter SPECIES_PELIPPER, 37, 37
    DarkGrassEncounters
    Encounter SPECIES_TANGELA, 38, 38
    Encounter SPECIES_PELIPPER, 38, 38
    Encounter SPECIES_DRIFBLIM, 38, 38
    Encounter SPECIES_LUNATONE, 40, 40
    Encounter SPECIES_SOLROCK, 40, 40
    Encounter SPECIES_ABSOL, 39, 39
    Encounter SPECIES_DRIFBLIM, 39, 39
    Encounter SPECIES_ABSOL, 41, 41
    Encounter SPECIES_TANGELA, 40, 40
    Encounter SPECIES_PELIPPER, 40, 40
    Encounter SPECIES_TANGELA, 41, 41
    Encounter SPECIES_PELIPPER, 41, 41
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_EMOLGA, 35, 35
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_TANGROWTH, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_TANGROWTH, 37, 37
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_FRILLISH, 25, 40
    Encounter SPECIES_STARYU, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_FRILLISH, 30, 40
    Encounter SPECIES_FRILLISH, 30, 40
#else
    Encounter SPECIES_FRILLISH, 25, 40
    Encounter SPECIES_STARYU, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_FRILLISH, 30, 40
    Encounter SPECIES_FRILLISH, 30, 40
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_STARYU, 25, 40
    Encounter SPECIES_JELLICENT, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_STARMIE, 30, 40
    Encounter SPECIES_STARMIE, 30, 40
#else
    Encounter SPECIES_STARYU, 25, 40
    Encounter SPECIES_JELLICENT, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_STARMIE, 30, 40
    Encounter SPECIES_STARMIE, 30, 40
#endif
    FishingEncounters
    Encounter SPECIES_LUVDISC, 40, 60
    Encounter SPECIES_SHELLDER, 40, 60
    Encounter SPECIES_LUVDISC, 50, 70
    Encounter SPECIES_LUVDISC, 50, 70
    Encounter SPECIES_LUVDISC, 50, 70
    RipplingFishingEncounters
    Encounter SPECIES_SHELLDER, 40, 60
    Encounter SPECIES_LUVDISC, 40, 60
    Encounter SPECIES_SHELLDER, 50, 70
    Encounter SPECIES_CLOYSTER, 50, 70
    Encounter SPECIES_CLOYSTER, 50, 70
    EncountersEnd
