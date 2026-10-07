#include "asm/encounters.inc"

// Undella Town

    EncounterRates grass=0, dark_grass=0, shaking_grass=0, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    DarkGrassEncounters
    ShakingGrassEncounters
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
