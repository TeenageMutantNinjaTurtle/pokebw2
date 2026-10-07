#include "asm/encounters.inc"

// Pinwheel Forest

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COTTONEE, 54, 54
    Encounter SPECIES_SWADLOON, 54, 54
    Encounter SPECIES_COTTONEE, 55, 55
    Encounter SPECIES_VIGOROTH, 55, 55
    Encounter SPECIES_COTTONEE, 56, 56
    Encounter SPECIES_WHIRLIPEDE, 55, 55
    Encounter SPECIES_VIGOROTH, 57, 57
    Encounter SPECIES_WHIRLIPEDE, 57, 57
    Encounter SPECIES_COTTONEE, 57, 57
    Encounter SPECIES_SWADLOON, 56, 56
    Encounter SPECIES_COTTONEE, 57, 57
    Encounter SPECIES_SWADLOON, 56, 56
#else
    Encounter SPECIES_PETILIL, 54, 54
    Encounter SPECIES_SWADLOON, 54, 54
    Encounter SPECIES_PETILIL, 55, 55
    Encounter SPECIES_VIGOROTH, 55, 55
    Encounter SPECIES_PETILIL, 56, 56
    Encounter SPECIES_WHIRLIPEDE, 55, 55
    Encounter SPECIES_VIGOROTH, 57, 57
    Encounter SPECIES_WHIRLIPEDE, 57, 57
    Encounter SPECIES_PETILIL, 57, 57
    Encounter SPECIES_SWADLOON, 56, 56
    Encounter SPECIES_PETILIL, 57, 57
    Encounter SPECIES_SWADLOON, 56, 56
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COTTONEE, 62, 62
    Encounter SPECIES_SWADLOON, 62, 62
    Encounter SPECIES_COTTONEE, 63, 63
    Encounter SPECIES_VIGOROTH, 63, 63
    Encounter SPECIES_COTTONEE, 64, 64
    Encounter SPECIES_WHIRLIPEDE, 63, 63
    Encounter SPECIES_VIGOROTH, 65, 65
    Encounter SPECIES_WHIRLIPEDE, 65, 65
    Encounter SPECIES_COTTONEE, 65, 65
    Encounter SPECIES_SWADLOON, 64, 64
    Encounter SPECIES_COTTONEE, 65, 65
    Encounter SPECIES_SWADLOON, 64, 64
#else
    Encounter SPECIES_PETILIL, 62, 62
    Encounter SPECIES_SWADLOON, 62, 62
    Encounter SPECIES_PETILIL, 63, 63
    Encounter SPECIES_VIGOROTH, 63, 63
    Encounter SPECIES_PETILIL, 64, 64
    Encounter SPECIES_WHIRLIPEDE, 63, 63
    Encounter SPECIES_VIGOROTH, 65, 65
    Encounter SPECIES_WHIRLIPEDE, 65, 65
    Encounter SPECIES_PETILIL, 65, 65
    Encounter SPECIES_SWADLOON, 64, 64
    Encounter SPECIES_PETILIL, 65, 65
    Encounter SPECIES_SWADLOON, 64, 64
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 64, 64
    Encounter SPECIES_PANSAGE, 55, 55
    Encounter SPECIES_PANSEAR, 55, 55
    Encounter SPECIES_PANPOUR, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_SCOLIPEDE, 57, 57
    Encounter SPECIES_SLAKING, 57, 57
    Encounter SPECIES_WHIMSICOTT, 57, 57
    Encounter SPECIES_SLAKING, 57, 57
    Encounter SPECIES_WHIMSICOTT, 57, 57
#else
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_PANSAGE, 55, 55
    Encounter SPECIES_PANSEAR, 55, 55
    Encounter SPECIES_PANPOUR, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_SCOLIPEDE, 57, 57
    Encounter SPECIES_SLAKING, 57, 57
    Encounter SPECIES_LILLIGANT, 57, 57
    Encounter SPECIES_SLAKING, 57, 57
    Encounter SPECIES_LILLIGANT, 57, 57
#endif
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_MARILL, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_BASCULIN, 50, 60
#else
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_MARILL, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60, form=1
    Encounter SPECIES_BASCULIN, 50, 60, form=1
    Encounter SPECIES_AZUMARILL, 50, 60
    Encounter SPECIES_AZUMARILL, 50, 60
#else
    Encounter SPECIES_MARILL, 45, 60
    Encounter SPECIES_BASCULIN, 45, 60
    Encounter SPECIES_BASCULIN, 50, 60
    Encounter SPECIES_AZUMARILL, 50, 60
    Encounter SPECIES_AZUMARILL, 50, 60
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
    Encounter SPECIES_GOLDEEN, 35, 60
    Encounter SPECIES_BASCULIN, 35, 60, form=1
    Encounter SPECIES_SEAKING, 35, 70
    Encounter SPECIES_SEAKING, 45, 70
    Encounter SPECIES_SEAKING, 45, 70
#else
    Encounter SPECIES_GOLDEEN, 35, 60
    Encounter SPECIES_BASCULIN, 35, 60
    Encounter SPECIES_SEAKING, 35, 70
    Encounter SPECIES_SEAKING, 45, 70
    Encounter SPECIES_SEAKING, 45, 70
#endif
    EncountersEnd
