#include "asm/encounters.inc"

// Route 19

    EncounterRates grass=1, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_PATRAT, 2, 2
    Encounter SPECIES_PURRLOIN, 2, 2
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PURRLOIN, 3, 3
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PURRLOIN, 4, 4
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_PATRAT, 2, 2
    Encounter SPECIES_PATRAT, 2, 2
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PATRAT, 3, 3
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    Encounter SPECIES_PATRAT, 4, 4
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
#else
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
    Encounter SPECIES_BASCULIN, 5, 15, form=1
#else
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
    Encounter SPECIES_BASCULIN, 5, 15
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
