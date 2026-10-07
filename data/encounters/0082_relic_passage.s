#include "asm/encounters.inc"

// Relic Passage

    EncounterRates grass=7, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1, flags=1
    GrassEncounters
    Encounter SPECIES_BOLDORE, 27, 27
    Encounter SPECIES_WOOBAT, 27, 27
    Encounter SPECIES_BOLDORE, 28, 28
    Encounter SPECIES_WOOBAT, 28, 28
    Encounter SPECIES_GURDURR, 28, 28
    Encounter SPECIES_GURDURR, 30, 30
    Encounter SPECIES_RATICATE, 29, 29
    Encounter SPECIES_RATICATE, 29, 29
    Encounter SPECIES_BOLDORE, 30, 30
    Encounter SPECIES_ONIX, 30, 30
    Encounter SPECIES_WOOBAT, 30, 30
    Encounter SPECIES_ONIX, 30, 30
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_DRILBUR, 27, 27
    Encounter SPECIES_ONIX, 27, 27
    Encounter SPECIES_DRILBUR, 28, 28
    Encounter SPECIES_DRILBUR, 28, 28
    Encounter SPECIES_DRILBUR, 29, 29
    Encounter SPECIES_DRILBUR, 29, 29
    Encounter SPECIES_DRILBUR, 30, 30
    Encounter SPECIES_DRILBUR, 30, 30
    Encounter SPECIES_DRILBUR, 30, 30
    Encounter SPECIES_DRILBUR, 30, 30
    Encounter SPECIES_DRILBUR, 30, 30
    Encounter SPECIES_DRILBUR, 30, 30
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 10, 30
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30
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
    Encounter SPECIES_MARILL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30
    Encounter SPECIES_AZUMARILL, 10, 30
    Encounter SPECIES_AZUMARILL, 10, 30
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
    Encounter SPECIES_POLIWRATH, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
#else
    Encounter SPECIES_POLIWHIRL, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_POLIWHIRL, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
#endif
    EncountersEnd
