#include "asm/encounters.inc"

// Route 3

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_WATCHOG, 55, 55
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_ZEBSTRIKA, 56, 56
    Encounter SPECIES_YANMA, 56, 56
    Encounter SPECIES_HERDIER, 57, 57
    Encounter SPECIES_PURRLOIN, 57, 57
    Encounter SPECIES_ZEBSTRIKA, 58, 58
    Encounter SPECIES_TRANQUILL, 57, 57
    Encounter SPECIES_ZEBSTRIKA, 58, 58
    Encounter SPECIES_TRANQUILL, 57, 57
    Encounter SPECIES_ZEBSTRIKA, 58, 58
    Encounter SPECIES_TRANQUILL, 57, 57
    DarkGrassEncounters
    Encounter SPECIES_WATCHOG, 63, 63
    Encounter SPECIES_TRANQUILL, 63, 63
    Encounter SPECIES_ZEBSTRIKA, 64, 64
    Encounter SPECIES_YANMA, 64, 64
    Encounter SPECIES_HERDIER, 65, 65
    Encounter SPECIES_PURRLOIN, 65, 65
    Encounter SPECIES_ZEBSTRIKA, 66, 66
    Encounter SPECIES_TRANQUILL, 65, 65
    Encounter SPECIES_ZEBSTRIKA, 66, 66
    Encounter SPECIES_TRANQUILL, 65, 65
    Encounter SPECIES_ZEBSTRIKA, 66, 66
    Encounter SPECIES_TRANQUILL, 65, 65
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_YANMEGA, 58, 58
    Encounter SPECIES_UNFEZANT, 58, 58
    Encounter SPECIES_STOUTLAND, 58, 58
    Encounter SPECIES_UNFEZANT, 58, 58
    Encounter SPECIES_STOUTLAND, 58, 58
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
    Encounter SPECIES_CORPHISH, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_CRAWDAUNT, 50, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
    Encounter SPECIES_CRAWDAUNT, 50, 60
#else
    Encounter SPECIES_CORPHISH, 45, 60
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
