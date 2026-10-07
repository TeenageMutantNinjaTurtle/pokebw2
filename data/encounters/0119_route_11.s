#include "asm/encounters.inc"

// Route 11

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SHELMET, 36, 36
    Encounter SPECIES_GOLDUCK, 36, 36
    Encounter SPECIES_GLIGAR, 37, 37
    Encounter SPECIES_MARILL, 36, 36
    Encounter SPECIES_ZANGOOSE, 38, 38
    Encounter SPECIES_SEVIPER, 38, 38
    Encounter SPECIES_AMOONGUSS, 37, 37
    Encounter SPECIES_KARRABLAST, 36, 36
    Encounter SPECIES_GLIGAR, 39, 39
    Encounter SPECIES_SHELMET, 39, 39
    Encounter SPECIES_GLIGAR, 39, 39
    Encounter SPECIES_SHELMET, 39, 39
#else
    Encounter SPECIES_KARRABLAST, 36, 36
    Encounter SPECIES_GOLDUCK, 36, 36
    Encounter SPECIES_GLIGAR, 37, 37
    Encounter SPECIES_MARILL, 36, 36
    Encounter SPECIES_ZANGOOSE, 38, 38
    Encounter SPECIES_SEVIPER, 38, 38
    Encounter SPECIES_AMOONGUSS, 37, 37
    Encounter SPECIES_SHELMET, 36, 36
    Encounter SPECIES_GLIGAR, 39, 39
    Encounter SPECIES_KARRABLAST, 39, 39
    Encounter SPECIES_GLIGAR, 39, 39
    Encounter SPECIES_KARRABLAST, 39, 39
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SHELMET, 40, 40
    Encounter SPECIES_GOLDUCK, 40, 40
    Encounter SPECIES_GLIGAR, 41, 41
    Encounter SPECIES_MARILL, 40, 40
    Encounter SPECIES_ZANGOOSE, 42, 42
    Encounter SPECIES_SEVIPER, 42, 42
    Encounter SPECIES_AMOONGUSS, 41, 41
    Encounter SPECIES_KARRABLAST, 40, 40
    Encounter SPECIES_GLIGAR, 43, 43
    Encounter SPECIES_SHELMET, 43, 43
    Encounter SPECIES_GLIGAR, 43, 43
    Encounter SPECIES_SHELMET, 43, 43
#else
    Encounter SPECIES_KARRABLAST, 40, 40
    Encounter SPECIES_GOLDUCK, 40, 40
    Encounter SPECIES_GLIGAR, 41, 41
    Encounter SPECIES_MARILL, 40, 40
    Encounter SPECIES_ZANGOOSE, 42, 42
    Encounter SPECIES_SEVIPER, 42, 42
    Encounter SPECIES_AMOONGUSS, 41, 41
    Encounter SPECIES_SHELMET, 40, 40
    Encounter SPECIES_GLIGAR, 43, 43
    Encounter SPECIES_KARRABLAST, 43, 43
    Encounter SPECIES_GLIGAR, 43, 43
    Encounter SPECIES_KARRABLAST, 43, 43
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_EMOLGA, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_AUDINO, 38, 38
    Encounter SPECIES_AUDINO, 38, 38
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_GLISCOR, 39, 39
    Encounter SPECIES_AZUMARILL, 39, 39
    Encounter SPECIES_GLISCOR, 39, 39
    Encounter SPECIES_AZUMARILL, 39, 39
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_BUIZEL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_BASCULIN, 30, 40
#else
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_BUIZEL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BUIZEL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_FLOATZEL, 30, 40
    Encounter SPECIES_FLOATZEL, 30, 40
    Encounter SPECIES_FLOATZEL, 30, 40
#else
    Encounter SPECIES_BUIZEL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_FLOATZEL, 30, 40
    Encounter SPECIES_FLOATZEL, 30, 40
    Encounter SPECIES_FLOATZEL, 30, 40
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_GOLDEEN, 50, 60
    Encounter SPECIES_GOLDEEN, 50, 60
    Encounter SPECIES_GOLDEEN, 50, 60
#else
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
#else
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
#endif
    EncountersEnd
