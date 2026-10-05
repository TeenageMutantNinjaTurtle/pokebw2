#include "asm/encounters.inc"

// Route 1

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_WATCHOG, 56, 56
    Encounter SPECIES_HERDIER, 56, 56
    Encounter SPECIES_JIGGLYPUFF, 57, 57
    Encounter SPECIES_HERDIER, 57, 57
    Encounter SPECIES_WATCHOG, 58, 58
    Encounter SPECIES_HERDIER, 58, 58
    Encounter SPECIES_WATCHOG, 59, 59
    Encounter SPECIES_HERDIER, 59, 59
    Encounter SPECIES_WATCHOG, 59, 59
    Encounter SPECIES_HERDIER, 59, 59
    Encounter SPECIES_WATCHOG, 59, 59
    Encounter SPECIES_HERDIER, 59, 59
    DarkGrassEncounters
    Encounter SPECIES_WATCHOG, 64, 64
    Encounter SPECIES_HERDIER, 64, 64
    Encounter SPECIES_JIGGLYPUFF, 65, 65
    Encounter SPECIES_HERDIER, 65, 65
    Encounter SPECIES_WATCHOG, 66, 66
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_WATCHOG, 67, 67
    Encounter SPECIES_HERDIER, 67, 67
    Encounter SPECIES_WATCHOG, 67, 67
    Encounter SPECIES_HERDIER, 67, 67
    Encounter SPECIES_WATCHOG, 67, 67
    Encounter SPECIES_SCRAFTY, 67, 67
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_DUNSPARCE, 57, 57
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_STOUTLAND, 59, 59
    Encounter SPECIES_WIGGLYTUFF, 59, 59
    Encounter SPECIES_STOUTLAND, 59, 59
    Encounter SPECIES_WIGGLYTUFF, 59, 59
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
#else
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
#else
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_BASCULIN, 50, 70
    Encounter SPECIES_FEEBAS, 50, 70
    Encounter SPECIES_FEEBAS, 50, 70
#else
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 70, form=1
    Encounter SPECIES_FEEBAS, 50, 70
    Encounter SPECIES_FEEBAS, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_FEEBAS, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_FEEBAS, 50, 70
    Encounter SPECIES_MILOTIC, 50, 70
    Encounter SPECIES_MILOTIC, 50, 70
#else
    Encounter SPECIES_FEEBAS, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_FEEBAS, 50, 70
    Encounter SPECIES_MILOTIC, 50, 70
    Encounter SPECIES_MILOTIC, 50, 70
#endif
    EncountersEnd
