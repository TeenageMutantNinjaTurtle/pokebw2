#include "asm/encounters.inc"

// Route 20

// Spring
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_PIDOVE, 2, 2
    Encounter SPECIES_SEWADDLE, 2, 2
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PURRLOIN, 3, 3
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_SEWADDLE, 3, 3
    Encounter SPECIES_PIDOVE, 4, 4
    Encounter SPECIES_SEWADDLE, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    DarkGrassEncounters
    Encounter SPECIES_PIDOVE, 9, 9
    Encounter SPECIES_VENIPEDE, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_PURRLOIN, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_SEWADDLE, 11, 11
    Encounter SPECIES_PIDOVE, 10, 10
    Encounter SPECIES_SEWADDLE, 10, 10
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 3, 3
    Encounter SPECIES_DUNSPARCE, 3, 3
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
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
    EncounterRates grass=2, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_SUNKERN, 2, 2
    Encounter SPECIES_SEWADDLE, 2, 2
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PURRLOIN, 3, 3
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_SEWADDLE, 3, 3
    Encounter SPECIES_PIDOVE, 4, 4
    Encounter SPECIES_SEWADDLE, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 3, 3
    Encounter SPECIES_SUNKERN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    DarkGrassEncounters
    Encounter SPECIES_SUNKERN, 9, 9
    Encounter SPECIES_VENIPEDE, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_PURRLOIN, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_SEWADDLE, 11, 11
    Encounter SPECIES_PIDOVE, 10, 10
    Encounter SPECIES_SEWADDLE, 10, 10
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 10, 10
    Encounter SPECIES_SUNKERN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 3, 3
    Encounter SPECIES_DUNSPARCE, 3, 3
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
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
    EncounterRates grass=2, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_PIDOVE, 2, 2
    Encounter SPECIES_SEWADDLE, 2, 2
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PURRLOIN, 3, 3
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_SEWADDLE, 3, 3
    Encounter SPECIES_PIDOVE, 4, 4
    Encounter SPECIES_SEWADDLE, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    DarkGrassEncounters
    Encounter SPECIES_PIDOVE, 9, 9
    Encounter SPECIES_VENIPEDE, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_PURRLOIN, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_SEWADDLE, 11, 11
    Encounter SPECIES_PIDOVE, 10, 10
    Encounter SPECIES_SEWADDLE, 10, 10
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 3, 3
    Encounter SPECIES_DUNSPARCE, 3, 3
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
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
    EncounterRates grass=2, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_PIDOVE, 2, 2
    Encounter SPECIES_SEWADDLE, 2, 2
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PURRLOIN, 3, 3
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_SEWADDLE, 3, 3
    Encounter SPECIES_PIDOVE, 4, 4
    Encounter SPECIES_SEWADDLE, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_SUNKERN, 4, 4
    DarkGrassEncounters
    Encounter SPECIES_PIDOVE, 9, 9
    Encounter SPECIES_VENIPEDE, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_PURRLOIN, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_SEWADDLE, 11, 11
    Encounter SPECIES_PIDOVE, 10, 10
    Encounter SPECIES_SEWADDLE, 10, 10
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    Encounter SPECIES_PURRLOIN, 11, 11
    Encounter SPECIES_SUNKERN, 11, 11
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 2, 2
    Encounter SPECIES_AUDINO, 3, 3
    Encounter SPECIES_DUNSPARCE, 3, 3
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZURILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_MARILL, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
    Encounter SPECIES_AZUMARILL, 5, 15
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
