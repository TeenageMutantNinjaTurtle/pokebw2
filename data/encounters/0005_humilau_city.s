#include "asm/encounters.inc"

// Humilau City

    EncounterRates grass=0, dark_grass=0, shaking_grass=0, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    DarkGrassEncounters
    ShakingGrassEncounters
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_FRILLISH, 30, 45
    Encounter SPECIES_STARYU, 30, 45
    Encounter SPECIES_BASCULIN, 35, 45
    Encounter SPECIES_FRILLISH, 35, 45
    Encounter SPECIES_FRILLISH, 35, 45
#else
    Encounter SPECIES_FRILLISH, 30, 45
    Encounter SPECIES_STARYU, 30, 45
    Encounter SPECIES_BASCULIN, 35, 45, form=1
    Encounter SPECIES_FRILLISH, 35, 45
    Encounter SPECIES_FRILLISH, 35, 45
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_JELLICENT, 35, 45
    Encounter SPECIES_CORSOLA, 35, 45
    Encounter SPECIES_BASCULIN, 35, 45, form=1
    Encounter SPECIES_STARMIE, 35, 45
    Encounter SPECIES_STARMIE, 35, 45
#else
    Encounter SPECIES_JELLICENT, 35, 45
    Encounter SPECIES_CORSOLA, 35, 45
    Encounter SPECIES_BASCULIN, 35, 45
    Encounter SPECIES_STARMIE, 35, 45
    Encounter SPECIES_STARMIE, 35, 45
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
