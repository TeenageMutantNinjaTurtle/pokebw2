#include "asm/encounters.inc"

// Striaton City

    EncounterRates grass=0, dark_grass=0, shaking_grass=0, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    DarkGrassEncounters
    ShakingGrassEncounters
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_CORPHISH, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
#else
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_CORPHISH, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_CRAWDAUNT, 50, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
#else
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
#else
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
#else
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
#endif
    EncountersEnd
