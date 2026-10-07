#include "asm/encounters.inc"

// Dragonspiral Tower

// Spring
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_SAWSBUCK, 55, 55
    Encounter SPECIES_MIENSHAO, 56, 56
    Encounter SPECIES_SAWSBUCK, 57, 57
    Encounter SPECIES_MIENSHAO, 57, 57
    Encounter SPECIES_TRANQUILL, 57, 57
    Encounter SPECIES_MIENSHAO, 58, 58
    Encounter SPECIES_TRANQUILL, 58, 58
    Encounter SPECIES_SAWSBUCK, 58, 58
    Encounter SPECIES_DRUDDIGON, 58, 58
    Encounter SPECIES_SAWSBUCK, 58, 58
    Encounter SPECIES_DRUDDIGON, 58, 58
    DarkGrassEncounters
    Encounter SPECIES_TRANQUILL, 63, 63
    Encounter SPECIES_SAWSBUCK, 63, 63
    Encounter SPECIES_MIENSHAO, 64, 64
    Encounter SPECIES_SAWSBUCK, 65, 65
    Encounter SPECIES_MIENSHAO, 65, 65
    Encounter SPECIES_TRANQUILL, 65, 65
    Encounter SPECIES_MIENSHAO, 66, 66
    Encounter SPECIES_TRANQUILL, 66, 66
    Encounter SPECIES_SAWSBUCK, 66, 66
    Encounter SPECIES_DRUDDIGON, 66, 66
    Encounter SPECIES_SAWSBUCK, 66, 66
    Encounter SPECIES_DRUDDIGON, 66, 66
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_EMOLGA, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_UNFEZANT, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_UNFEZANT, 57, 57
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
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#endif
    EncountersEnd

// Summer
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_SAWSBUCK, 55, 55, form=1
    Encounter SPECIES_MIENSHAO, 56, 56
    Encounter SPECIES_SAWSBUCK, 57, 57, form=1
    Encounter SPECIES_MIENSHAO, 57, 57
    Encounter SPECIES_TRANQUILL, 57, 57
    Encounter SPECIES_MIENSHAO, 58, 58
    Encounter SPECIES_TRANQUILL, 58, 58
    Encounter SPECIES_SAWSBUCK, 58, 58, form=1
    Encounter SPECIES_DRUDDIGON, 58, 58
    Encounter SPECIES_SAWSBUCK, 58, 58, form=1
    Encounter SPECIES_DRUDDIGON, 58, 58
    DarkGrassEncounters
    Encounter SPECIES_TRANQUILL, 63, 63
    Encounter SPECIES_SAWSBUCK, 63, 63, form=1
    Encounter SPECIES_MIENSHAO, 64, 64
    Encounter SPECIES_SAWSBUCK, 65, 65, form=1
    Encounter SPECIES_MIENSHAO, 65, 65
    Encounter SPECIES_TRANQUILL, 65, 65
    Encounter SPECIES_MIENSHAO, 66, 66
    Encounter SPECIES_TRANQUILL, 66, 66
    Encounter SPECIES_SAWSBUCK, 66, 66, form=1
    Encounter SPECIES_DRUDDIGON, 66, 66
    Encounter SPECIES_SAWSBUCK, 66, 66, form=1
    Encounter SPECIES_DRUDDIGON, 66, 66
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_EMOLGA, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_UNFEZANT, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_UNFEZANT, 57, 57
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
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#endif
    EncountersEnd

// Autumn
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_TRANQUILL, 55, 55
    Encounter SPECIES_SAWSBUCK, 55, 55, form=2
    Encounter SPECIES_MIENSHAO, 56, 56
    Encounter SPECIES_SAWSBUCK, 57, 57, form=2
    Encounter SPECIES_MIENSHAO, 57, 57
    Encounter SPECIES_TRANQUILL, 57, 57
    Encounter SPECIES_MIENSHAO, 58, 58
    Encounter SPECIES_TRANQUILL, 58, 58
    Encounter SPECIES_SAWSBUCK, 58, 58, form=2
    Encounter SPECIES_DRUDDIGON, 58, 58
    Encounter SPECIES_SAWSBUCK, 58, 58, form=2
    Encounter SPECIES_DRUDDIGON, 58, 58
    DarkGrassEncounters
    Encounter SPECIES_TRANQUILL, 63, 63
    Encounter SPECIES_SAWSBUCK, 63, 63, form=2
    Encounter SPECIES_MIENSHAO, 64, 64
    Encounter SPECIES_SAWSBUCK, 65, 65, form=2
    Encounter SPECIES_MIENSHAO, 65, 65
    Encounter SPECIES_TRANQUILL, 65, 65
    Encounter SPECIES_MIENSHAO, 66, 66
    Encounter SPECIES_TRANQUILL, 66, 66
    Encounter SPECIES_SAWSBUCK, 66, 66, form=2
    Encounter SPECIES_DRUDDIGON, 66, 66
    Encounter SPECIES_SAWSBUCK, 66, 66, form=2
    Encounter SPECIES_DRUDDIGON, 66, 66
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_EMOLGA, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_UNFEZANT, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_UNFEZANT, 57, 57
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
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#endif
    EncountersEnd

// Winter
    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_VANILLISH, 55, 55
    Encounter SPECIES_SAWSBUCK, 55, 55, form=3
    Encounter SPECIES_MIENSHAO, 56, 56
    Encounter SPECIES_SAWSBUCK, 57, 57, form=3
    Encounter SPECIES_MIENSHAO, 57, 57
    Encounter SPECIES_BEARTIC, 57, 57
    Encounter SPECIES_MIENSHAO, 58, 58
    Encounter SPECIES_VANILLISH, 57, 57
    Encounter SPECIES_BEARTIC, 58, 58
    Encounter SPECIES_DRUDDIGON, 58, 58
    Encounter SPECIES_BEARTIC, 58, 58
    Encounter SPECIES_DRUDDIGON, 58, 58
    DarkGrassEncounters
    Encounter SPECIES_VANILLISH, 63, 63
    Encounter SPECIES_SAWSBUCK, 63, 63, form=3
    Encounter SPECIES_MIENSHAO, 64, 64
    Encounter SPECIES_SAWSBUCK, 65, 65, form=3
    Encounter SPECIES_MIENSHAO, 65, 65
    Encounter SPECIES_BEARTIC, 65, 65
    Encounter SPECIES_MIENSHAO, 66, 66
    Encounter SPECIES_VANILLISH, 65, 65
    Encounter SPECIES_BEARTIC, 66, 66
    Encounter SPECIES_DRUDDIGON, 66, 66
    Encounter SPECIES_BEARTIC, 66, 66
    Encounter SPECIES_DRUDDIGON, 66, 66
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_EMOLGA, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_VANILLUXE, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_VANILLUXE, 57, 57
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
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
    Encounter SPECIES_DRATINI, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#else
    Encounter SPECIES_DRATINI, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONAIR, 50, 70
    Encounter SPECIES_DRAGONITE, 50, 70
#endif
    EncountersEnd
