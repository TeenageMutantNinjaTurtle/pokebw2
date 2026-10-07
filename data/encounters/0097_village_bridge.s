#include "asm/encounters.inc"

// Village Bridge

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_GOLDUCK, 36, 36
    Encounter SPECIES_MARILL, 36, 36
    Encounter SPECIES_ZANGOOSE, 37, 37
    Encounter SPECIES_SEVIPER, 37, 37
    Encounter SPECIES_GOLDUCK, 37, 37
    Encounter SPECIES_MARILL, 37, 37
    Encounter SPECIES_GOLDUCK, 38, 38
    Encounter SPECIES_MARILL, 38, 38
    Encounter SPECIES_ZANGOOSE, 39, 39
    Encounter SPECIES_SEVIPER, 39, 39
    Encounter SPECIES_ZANGOOSE, 39, 39
    Encounter SPECIES_SEVIPER, 39, 39
    DarkGrassEncounters
    Encounter SPECIES_GOLDUCK, 40, 40
    Encounter SPECIES_MARILL, 40, 40
    Encounter SPECIES_ZANGOOSE, 41, 41
    Encounter SPECIES_SEVIPER, 41, 41
    Encounter SPECIES_GOLDUCK, 41, 41
    Encounter SPECIES_MARILL, 41, 41
    Encounter SPECIES_GOLDUCK, 42, 42
    Encounter SPECIES_MARILL, 42, 42
    Encounter SPECIES_ZANGOOSE, 43, 43
    Encounter SPECIES_SEVIPER, 43, 43
    Encounter SPECIES_ZANGOOSE, 43, 43
    Encounter SPECIES_SEVIPER, 43, 43
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_EMOLGA, 37, 37
    Encounter SPECIES_DUNSPARCE, 37, 37
    Encounter SPECIES_AUDINO, 38, 38
    Encounter SPECIES_AUDINO, 38, 38
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AZUMARILL, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AZUMARILL, 39, 39
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_BASCULIN, 30, 40
#else
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_AZUMARILL, 30, 40
    Encounter SPECIES_LAPRAS, 30, 40
    Encounter SPECIES_LAPRAS, 30, 40
#else
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_AZUMARILL, 30, 40
    Encounter SPECIES_LAPRAS, 30, 40
    Encounter SPECIES_LAPRAS, 30, 40
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_CARVANHA, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_CARVANHA, 50, 70
    Encounter SPECIES_CARVANHA, 50, 70
    Encounter SPECIES_CARVANHA, 50, 70
#else
    Encounter SPECIES_CARVANHA, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_CARVANHA, 50, 70
    Encounter SPECIES_CARVANHA, 50, 70
    Encounter SPECIES_CARVANHA, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_CARVANHA, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_SHARPEDO, 50, 70
    Encounter SPECIES_SHARPEDO, 50, 70
    Encounter SPECIES_SHARPEDO, 50, 70
#else
    Encounter SPECIES_CARVANHA, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_SHARPEDO, 50, 70
    Encounter SPECIES_SHARPEDO, 50, 70
    Encounter SPECIES_SHARPEDO, 50, 70
#endif
    EncountersEnd
