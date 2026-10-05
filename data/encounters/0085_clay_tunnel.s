#include "asm/encounters.inc"

// Clay Tunnel

    EncounterRates grass=7, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1, flags=1
    GrassEncounters
    Encounter SPECIES_BOLDORE, 54, 54
    Encounter SPECIES_DURANT, 54, 54
    Encounter SPECIES_BOLDORE, 55, 55
    Encounter SPECIES_WOOBAT, 54, 54
    Encounter SPECIES_LAIRON, 55, 55
    Encounter SPECIES_NOSEPASS, 55, 55
    Encounter SPECIES_LAIRON, 57, 57
    Encounter SPECIES_NOSEPASS, 57, 57
    Encounter SPECIES_BOLDORE, 56, 56
    Encounter SPECIES_ONIX, 57, 57
    Encounter SPECIES_BOLDORE, 56, 56
    Encounter SPECIES_ONIX, 57, 57
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_EXCADRILL, 54, 54
    Encounter SPECIES_ONIX, 54, 54
    Encounter SPECIES_EXCADRILL, 55, 55
    Encounter SPECIES_EXCADRILL, 55, 55
    Encounter SPECIES_EXCADRILL, 56, 56
    Encounter SPECIES_EXCADRILL, 56, 56
    Encounter SPECIES_EXCADRILL, 57, 57
    Encounter SPECIES_EXCADRILL, 57, 57
    Encounter SPECIES_EXCADRILL, 57, 57
    Encounter SPECIES_STEELIX, 57, 57
    Encounter SPECIES_EXCADRILL, 57, 57
    Encounter SPECIES_STEELIX, 57, 57
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
