#include "asm/encounters.inc"

// Floccesy Ranch

    EncounterRates grass=2, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_LILLIPUP, 4, 4
    Encounter SPECIES_AZURILL, 5, 5
    Encounter SPECIES_PATRAT, 5, 5
    Encounter SPECIES_MAREEP, 5, 5
    Encounter SPECIES_LILLIPUP, 5, 5
    Encounter SPECIES_PSYDUCK, 5, 5
    Encounter SPECIES_LILLIPUP, 6, 6
    Encounter SPECIES_PIDOVE, 7, 7
    Encounter SPECIES_RIOLU, 5, 5
    Encounter SPECIES_LILLIPUP, 7, 7
    Encounter SPECIES_RIOLU, 7, 7
    Encounter SPECIES_LILLIPUP, 7, 7
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 4, 4
    Encounter SPECIES_AUDINO, 5, 5
    Encounter SPECIES_DUNSPARCE, 5, 5
    Encounter SPECIES_AUDINO, 6, 6
    Encounter SPECIES_AUDINO, 6, 6
    Encounter SPECIES_AUDINO, 7, 7
    Encounter SPECIES_AUDINO, 7, 7
    Encounter SPECIES_AUDINO, 7, 7
    Encounter SPECIES_AUDINO, 7, 7
    Encounter SPECIES_AUDINO, 7, 7
    Encounter SPECIES_AUDINO, 7, 7
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
