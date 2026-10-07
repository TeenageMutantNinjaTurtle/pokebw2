#include "asm/encounters.inc"

// Nature Preserve

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_NUZLEAF, 56, 56
    Encounter SPECIES_ALTARIA, 56, 56
    Encounter SPECIES_NUZLEAF, 57, 57
    Encounter SPECIES_GOLDUCK, 57, 57
    Encounter SPECIES_NOCTOWL, 58, 58
    Encounter SPECIES_GIRAFARIG, 58, 58
    Encounter SPECIES_FRAXURE, 57, 57
    Encounter SPECIES_GIRAFARIG, 59, 59
    Encounter SPECIES_FRAXURE, 59, 59
    Encounter SPECIES_KECLEON, 57, 57
    Encounter SPECIES_FRAXURE, 59, 59
    Encounter SPECIES_KECLEON, 59, 59
    DarkGrassEncounters
    Encounter SPECIES_NUZLEAF, 64, 64
    Encounter SPECIES_ALTARIA, 64, 64
    Encounter SPECIES_NUZLEAF, 65, 65
    Encounter SPECIES_GOLDUCK, 65, 65
    Encounter SPECIES_NOCTOWL, 66, 66
    Encounter SPECIES_GIRAFARIG, 66, 66
    Encounter SPECIES_FRAXURE, 65, 65
    Encounter SPECIES_GIRAFARIG, 67, 67
    Encounter SPECIES_FRAXURE, 67, 67
    Encounter SPECIES_KECLEON, 65, 65
    Encounter SPECIES_FRAXURE, 67, 67
    Encounter SPECIES_KECLEON, 67, 67
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_DUNSPARCE, 57, 57
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_SHIFTRY, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_SHIFTRY, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BUIZEL, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
#else
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BUIZEL, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BUIZEL, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_FLOATZEL, 50, 60
    Encounter SPECIES_FLOATZEL, 50, 60
#else
    Encounter SPECIES_BUIZEL, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_FLOATZEL, 50, 60
    Encounter SPECIES_FLOATZEL, 50, 60
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_MAGIKARP, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_MAGIKARP, 50, 70
    Encounter SPECIES_MAGIKARP, 50, 70
    Encounter SPECIES_MAGIKARP, 1, 100
#else
    Encounter SPECIES_MAGIKARP, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_MAGIKARP, 50, 70
    Encounter SPECIES_MAGIKARP, 50, 70
    Encounter SPECIES_MAGIKARP, 1, 100
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_MAGIKARP, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_GYARADOS, 50, 70
    Encounter SPECIES_GYARADOS, 50, 70
    Encounter SPECIES_GYARADOS, 1, 100
#else
    Encounter SPECIES_MAGIKARP, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_GYARADOS, 50, 70
    Encounter SPECIES_GYARADOS, 50, 70
    Encounter SPECIES_GYARADOS, 1, 100
#endif
    EncountersEnd
