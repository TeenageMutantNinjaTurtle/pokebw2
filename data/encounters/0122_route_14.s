#include "asm/encounters.inc"

// Route 14

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_GOLDUCK, 34, 34
    Encounter SPECIES_SWABLU, 33, 33
    Encounter SPECIES_DRIFBLIM, 34, 34
    Encounter SPECIES_MIENFOO, 33, 33
    Encounter SPECIES_MIENFOO, 35, 35
    Encounter SPECIES_ABSOL, 34, 34
    Encounter SPECIES_DRIFBLIM, 35, 35
    Encounter SPECIES_ABSOL, 36, 36
    Encounter SPECIES_GOLDUCK, 35, 35
    Encounter SPECIES_ALTARIA, 36, 36
    Encounter SPECIES_GOLDUCK, 35, 35
    Encounter SPECIES_ALTARIA, 36, 36
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDUCK, 37, 37
    Encounter SPECIES_MIENFOO, 37, 37
    Encounter SPECIES_DRIFBLIM, 38, 38
    Encounter SPECIES_ALTARIA, 37, 37
    Encounter SPECIES_MIENFOO, 39, 39
    Encounter SPECIES_ABSOL, 38, 38
    Encounter SPECIES_DRIFBLIM, 39, 39
    Encounter SPECIES_ABSOL, 40, 40
    Encounter SPECIES_GOLDUCK, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
    Encounter SPECIES_GOLDUCK, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
#else
    Encounter SPECIES_GOLDUCK, 38, 38
    Encounter SPECIES_MIENFOO, 37, 37
    Encounter SPECIES_DRIFBLIM, 38, 38
    Encounter SPECIES_ALTARIA, 37, 37
    Encounter SPECIES_MIENFOO, 39, 39
    Encounter SPECIES_ABSOL, 38, 38
    Encounter SPECIES_DRIFBLIM, 39, 39
    Encounter SPECIES_ABSOL, 40, 40
    Encounter SPECIES_GOLDUCK, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
    Encounter SPECIES_GOLDUCK, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_EMOLGA, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 15, 35
    Encounter SPECIES_BUIZEL, 15, 35
    Encounter SPECIES_BASCULIN, 15, 35
    Encounter SPECIES_BASCULIN, 15, 35
    Encounter SPECIES_BASCULIN, 15, 35
#else
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_BUIZEL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BUIZEL, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40, form=1
    Encounter SPECIES_FLOATZEL, 25, 40
    Encounter SPECIES_FLOATZEL, 25, 40
    Encounter SPECIES_FLOATZEL, 25, 40
#else
    Encounter SPECIES_BUIZEL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_FLOATZEL, 30, 40
    Encounter SPECIES_FLOATZEL, 30, 40
    Encounter SPECIES_FLOATZEL, 30, 40
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
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
