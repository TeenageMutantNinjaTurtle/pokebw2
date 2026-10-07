#include "asm/encounters.inc"

// Wellspring Cave

    EncounterRates grass=7, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1, flags=1
    GrassEncounters
    Encounter SPECIES_BOLDORE, 55, 55
    Encounter SPECIES_WOOBAT, 55, 55
    Encounter SPECIES_BOLDORE, 56, 56
    Encounter SPECIES_WOOBAT, 56, 56
    Encounter SPECIES_BOLDORE, 57, 57
    Encounter SPECIES_WOOBAT, 57, 57
    Encounter SPECIES_BOLDORE, 58, 58
    Encounter SPECIES_WOOBAT, 58, 58
    Encounter SPECIES_BOLDORE, 58, 58
    Encounter SPECIES_WOOBAT, 58, 58
    Encounter SPECIES_BOLDORE, 58, 58
    Encounter SPECIES_WOOBAT, 58, 58
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_EXCADRILL, 55, 55
    Encounter SPECIES_EXCADRILL, 55, 55
    Encounter SPECIES_EXCADRILL, 56, 56
    Encounter SPECIES_EXCADRILL, 56, 56
    Encounter SPECIES_EXCADRILL, 57, 57
    Encounter SPECIES_EXCADRILL, 57, 57
    Encounter SPECIES_EXCADRILL, 58, 58
    Encounter SPECIES_EXCADRILL, 58, 58
    Encounter SPECIES_EXCADRILL, 58, 58
    Encounter SPECIES_EXCADRILL, 58, 58
    Encounter SPECIES_EXCADRILL, 58, 58
    Encounter SPECIES_EXCADRILL, 58, 58
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
    Encounter SPECIES_POLIWAG, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_POLIWAG, 60, 70
    Encounter SPECIES_POLIWAG, 60, 70
    Encounter SPECIES_POLIWAG, 60, 70
#else
    Encounter SPECIES_POLIWAG, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_POLIWAG, 60, 70
    Encounter SPECIES_POLIWAG, 60, 70
    Encounter SPECIES_POLIWAG, 60, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_POLIWHIRL, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_POLIWHIRL, 60, 60
    Encounter SPECIES_POLIWRATH, 60, 60
    Encounter SPECIES_POLIWRATH, 60, 60
#else
    Encounter SPECIES_POLIWHIRL, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_POLIWHIRL, 60, 60
    Encounter SPECIES_POLIWRATH, 60, 60
    Encounter SPECIES_POLIWRATH, 60, 60
#endif
    EncountersEnd
