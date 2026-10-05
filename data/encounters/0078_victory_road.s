#include "asm/encounters.inc"

// Victory Road

    EncounterRates grass=7, dark_grass=0, shaking_grass=0, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_BANETTE, 47, 47
    Encounter SPECIES_BANETTE, 47, 47
    Encounter SPECIES_BANETTE, 48, 48
    Encounter SPECIES_GOLURK, 48, 48
    Encounter SPECIES_BANETTE, 49, 49
    Encounter SPECIES_GOLURK, 49, 49
    Encounter SPECIES_BANETTE, 50, 50
    Encounter SPECIES_GOLURK, 50, 50
    Encounter SPECIES_BANETTE, 50, 50
    Encounter SPECIES_GOLURK, 50, 50
    Encounter SPECIES_BANETTE, 50, 50
    Encounter SPECIES_GOLURK, 50, 50
    DarkGrassEncounters
    ShakingGrassEncounters
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
    Encounter SPECIES_MARILL, 35, 50
    Encounter SPECIES_BASCULIN, 35, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_AZUMARILL, 40, 50
    Encounter SPECIES_AZUMARILL, 40, 50
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
