#include "asm/encounters.inc"

// Route 6

// Spring
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 23, 23
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
#else
    Encounter SPECIES_DEERLING, 23, 23
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
#else
    Encounter SPECIES_DEERLING, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_EMOLGA, 24, 24
    Encounter SPECIES_EMOLGA, 25, 25
    Encounter SPECIES_AUDINO, 25, 25
    Encounter SPECIES_DUNSPARCE, 25, 25
    Encounter SPECIES_AZUMARILL, 26, 26
    Encounter SPECIES_CASTFORM, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_MARILL, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
#else
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_AZUMARILL, 10, 30
    Encounter SPECIES_AZUMARILL, 10, 30
#else
    Encounter SPECIES_MARILL, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
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

// Summer
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 23, 23, form=1
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25, form=1
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
#else
    Encounter SPECIES_DEERLING, 23, 23, form=1
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25, form=1
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 26, 26, form=1
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28, form=1
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
#else
    Encounter SPECIES_DEERLING, 26, 26, form=1
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28, form=1
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_EMOLGA, 24, 24
    Encounter SPECIES_EMOLGA, 25, 25
    Encounter SPECIES_AUDINO, 25, 25
    Encounter SPECIES_DUNSPARCE, 25, 25
    Encounter SPECIES_AZUMARILL, 26, 26
    Encounter SPECIES_CASTFORM, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_MARILL, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
#else
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_AZUMARILL, 10, 30
    Encounter SPECIES_AZUMARILL, 10, 30
#else
    Encounter SPECIES_MARILL, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
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

// Autumn
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 23, 23, form=2
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25, form=2
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
#else
    Encounter SPECIES_DEERLING, 23, 23, form=2
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25, form=2
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 26, 26, form=2
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28, form=2
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
#else
    Encounter SPECIES_DEERLING, 26, 26, form=2
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28, form=2
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_EMOLGA, 24, 24
    Encounter SPECIES_EMOLGA, 25, 25
    Encounter SPECIES_AUDINO, 25, 25
    Encounter SPECIES_DUNSPARCE, 25, 25
    Encounter SPECIES_AZUMARILL, 26, 26
    Encounter SPECIES_CASTFORM, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_MARILL, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
#else
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_AZUMARILL, 10, 30
    Encounter SPECIES_AZUMARILL, 10, 30
#else
    Encounter SPECIES_MARILL, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
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

// Winter
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 23, 23, form=3
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25, form=3
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_SHELMET, 26, 26
#else
    Encounter SPECIES_DEERLING, 23, 23, form=3
    Encounter SPECIES_KARRABLAST, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_FOONGUS, 26, 26
    Encounter SPECIES_DEERLING, 25, 25, form=3
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_MARILL, 25, 25
    Encounter SPECIES_SHELMET, 23, 23
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 26, 26
    Encounter SPECIES_KARRABLAST, 26, 26
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_DEERLING, 26, 26, form=3
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28, form=3
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_SHELMET, 29, 29
#else
    Encounter SPECIES_DEERLING, 26, 26, form=3
    Encounter SPECIES_KARRABLAST, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_FOONGUS, 29, 29
    Encounter SPECIES_DEERLING, 28, 28, form=3
    Encounter SPECIES_SWADLOON, 29, 29
    Encounter SPECIES_MARILL, 28, 28
    Encounter SPECIES_SHELMET, 26, 26
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
    Encounter SPECIES_TRANQUILL, 29, 29
    Encounter SPECIES_KARRABLAST, 29, 29
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_EMOLGA, 24, 24
    Encounter SPECIES_EMOLGA, 25, 25
    Encounter SPECIES_AUDINO, 25, 25
    Encounter SPECIES_DUNSPARCE, 25, 25
    Encounter SPECIES_AZUMARILL, 26, 26
    Encounter SPECIES_CASTFORM, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    Encounter SPECIES_UNFEZANT, 26, 26
    Encounter SPECIES_LEAVANNY, 26, 26
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_MARILL, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
#else
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_AZUMARILL, 10, 30
    Encounter SPECIES_AZUMARILL, 10, 30
#else
    Encounter SPECIES_MARILL, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_BASCULIN, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
    Encounter SPECIES_AZUMARILL, 10, 35
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
