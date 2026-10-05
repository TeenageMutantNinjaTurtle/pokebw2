#include "asm/encounters.inc"

// Victory Road

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_TRANQUILL, 47, 47
    Encounter SPECIES_TRANQUILL, 47, 47
    Encounter SPECIES_TRANQUILL, 48, 48
    Encounter SPECIES_TRANQUILL, 48, 48
    Encounter SPECIES_TRANQUILL, 49, 49
    Encounter SPECIES_ALTARIA, 49, 49
    Encounter SPECIES_TRANQUILL, 50, 50
    Encounter SPECIES_ALTARIA, 50, 50
    Encounter SPECIES_TRANQUILL, 50, 50
    Encounter SPECIES_ALTARIA, 50, 50
    Encounter SPECIES_TRANQUILL, 50, 50
    Encounter SPECIES_ALTARIA, 50, 50
    DarkGrassEncounters
    Encounter SPECIES_TRANQUILL, 52, 52
    Encounter SPECIES_TRANQUILL, 52, 52
    Encounter SPECIES_TRANQUILL, 53, 53
    Encounter SPECIES_TRANQUILL, 53, 53
    Encounter SPECIES_TRANQUILL, 54, 54
    Encounter SPECIES_ALTARIA, 54, 54
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_ALTARIA, 55, 55
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_ALTARIA, 55, 55
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_ALTARIA, 55, 55
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 47, 47
    Encounter SPECIES_AUDINO, 47, 47
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_DUNSPARCE, 49, 49
    Encounter SPECIES_AUDINO, 49, 49
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_UNFEZANT, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_UNFEZANT, 50, 50
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 35, 50
    Encounter SPECIES_BUIZEL, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
#else
    Encounter SPECIES_BASCULIN, 35, 50, form=1
    Encounter SPECIES_BUIZEL, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BUIZEL, 35, 50
    Encounter SPECIES_BASCULIN, 35, 50, form=1
    Encounter SPECIES_FLOATZEL, 40, 50
    Encounter SPECIES_FLOATZEL, 40, 50
    Encounter SPECIES_FLOATZEL, 40, 50
#else
    Encounter SPECIES_BUIZEL, 35, 50
    Encounter SPECIES_BASCULIN, 35, 50
    Encounter SPECIES_FLOATZEL, 40, 50
    Encounter SPECIES_FLOATZEL, 40, 50
    Encounter SPECIES_FLOATZEL, 40, 50
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_POLIWAG, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
#else
    Encounter SPECIES_POLIWAG, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_POLIWHIRL, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_POLIWHIRL, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
#else
    Encounter SPECIES_POLIWHIRL, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_POLIWHIRL, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
#endif
    EncountersEnd
