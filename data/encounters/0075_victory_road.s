#include "asm/encounters.inc"

// Victory Road

    EncounterRates grass=7, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1, flags=1
    GrassEncounters
    Encounter SPECIES_BOLDORE, 47, 47
    Encounter SPECIES_BOLDORE, 47, 47
    Encounter SPECIES_BOLDORE, 48, 48
    Encounter SPECIES_BOLDORE, 48, 48
    Encounter SPECIES_BOLDORE, 49, 49
    Encounter SPECIES_ONIX, 49, 49
    Encounter SPECIES_BOLDORE, 50, 50
    Encounter SPECIES_ONIX, 50, 50
    Encounter SPECIES_BOLDORE, 50, 50
    Encounter SPECIES_ONIX, 50, 50
    Encounter SPECIES_BOLDORE, 50, 50
    Encounter SPECIES_ONIX, 50, 50
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_EXCADRILL, 47, 47
    Encounter SPECIES_ONIX, 47, 47
    Encounter SPECIES_EXCADRILL, 48, 48
    Encounter SPECIES_EXCADRILL, 48, 48
    Encounter SPECIES_EXCADRILL, 49, 49
    Encounter SPECIES_EXCADRILL, 49, 49
    Encounter SPECIES_EXCADRILL, 50, 50
    Encounter SPECIES_EXCADRILL, 50, 50
    Encounter SPECIES_EXCADRILL, 50, 50
    Encounter SPECIES_EXCADRILL, 50, 50
    Encounter SPECIES_EXCADRILL, 50, 50
    Encounter SPECIES_EXCADRILL, 50, 50
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 35, 50
    Encounter SPECIES_MARILL, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
#else
    Encounter SPECIES_BASCULIN, 35, 50, form=1
    Encounter SPECIES_MARILL, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 35, 60
    Encounter SPECIES_BASCULIN, 35, 60, form=1
    Encounter SPECIES_BASCULIN, 40, 70, form=1
    Encounter SPECIES_AZUMARILL, 40, 70
    Encounter SPECIES_AZUMARILL, 40, 70
#else
    Encounter SPECIES_MARILL, 35, 50
    Encounter SPECIES_BASCULIN, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_AZUMARILL, 40, 50
    Encounter SPECIES_AZUMARILL, 40, 50
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
