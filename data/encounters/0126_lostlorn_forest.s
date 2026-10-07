#include "asm/encounters.inc"

// Lostlorn Forest

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COTTONEE, 21, 21
    Encounter SPECIES_SWADLOON, 21, 21
    Encounter SPECIES_COMBEE, 22, 22
    Encounter SPECIES_VENIPEDE, 21, 21
    Encounter SPECIES_ROSELIA, 23, 23
    Encounter SPECIES_VENIPEDE, 21, 21
    Encounter SPECIES_ROSELIA, 24, 24
    Encounter SPECIES_HERACROSS, 24, 24
    Encounter SPECIES_COTTONEE, 23, 23
    Encounter SPECIES_SWADLOON, 24, 24
    Encounter SPECIES_COTTONEE, 24, 24
    Encounter SPECIES_SWADLOON, 24, 24
#else
    Encounter SPECIES_PETILIL, 21, 21
    Encounter SPECIES_SWADLOON, 21, 21
    Encounter SPECIES_COMBEE, 22, 22
    Encounter SPECIES_VENIPEDE, 21, 21
    Encounter SPECIES_ROSELIA, 23, 23
    Encounter SPECIES_VENIPEDE, 21, 21
    Encounter SPECIES_ROSELIA, 24, 24
    Encounter SPECIES_PINSIR, 24, 24
    Encounter SPECIES_PETILIL, 23, 23
    Encounter SPECIES_SWADLOON, 24, 24
    Encounter SPECIES_PETILIL, 24, 24
    Encounter SPECIES_SWADLOON, 24, 24
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COTTONEE, 23, 23
    Encounter SPECIES_SWADLOON, 23, 23
    Encounter SPECIES_COMBEE, 24, 24
    Encounter SPECIES_WHIRLIPEDE, 23, 23
    Encounter SPECIES_ROSELIA, 25, 25
    Encounter SPECIES_WHIRLIPEDE, 23, 23
    Encounter SPECIES_ROSELIA, 26, 26
    Encounter SPECIES_HERACROSS, 26, 26
    Encounter SPECIES_COTTONEE, 25, 25
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_COTTONEE, 26, 26
    Encounter SPECIES_SWADLOON, 26, 26
#else
    Encounter SPECIES_PETILIL, 23, 23
    Encounter SPECIES_SWADLOON, 23, 23
    Encounter SPECIES_COMBEE, 24, 24
    Encounter SPECIES_WHIRLIPEDE, 23, 23
    Encounter SPECIES_ROSELIA, 25, 25
    Encounter SPECIES_WHIRLIPEDE, 23, 23
    Encounter SPECIES_ROSELIA, 26, 26
    Encounter SPECIES_PINSIR, 26, 26
    Encounter SPECIES_PETILIL, 25, 25
    Encounter SPECIES_SWADLOON, 26, 26
    Encounter SPECIES_PETILIL, 26, 26
    Encounter SPECIES_SWADLOON, 26, 26
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 21, 21
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_EMOLGA, 22, 22
    Encounter SPECIES_PANSAGE, 22, 22
    Encounter SPECIES_PANSEAR, 22, 22
    Encounter SPECIES_PANPOUR, 22, 22
    Encounter SPECIES_VESPIQUEN, 24, 24
    Encounter SPECIES_ROSERADE, 24, 24
    Encounter SPECIES_LEAVANNY, 24, 24
    Encounter SPECIES_WHIMSICOTT, 24, 24
    Encounter SPECIES_LEAVANNY, 24, 24
    Encounter SPECIES_WHIMSICOTT, 24, 24
#else
    Encounter SPECIES_AUDINO, 21, 21
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_EMOLGA, 22, 22
    Encounter SPECIES_PANSAGE, 22, 22
    Encounter SPECIES_PANSEAR, 22, 22
    Encounter SPECIES_PANPOUR, 22, 22
    Encounter SPECIES_VESPIQUEN, 24, 24
    Encounter SPECIES_ROSERADE, 24, 24
    Encounter SPECIES_LEAVANNY, 24, 24
    Encounter SPECIES_LILLIGANT, 24, 24
    Encounter SPECIES_LEAVANNY, 24, 24
    Encounter SPECIES_LILLIGANT, 24, 24
#endif
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BUIZEL, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25
#else
    Encounter SPECIES_BASCULIN, 10, 25, form=1
    Encounter SPECIES_BUIZEL, 10, 25
    Encounter SPECIES_BASCULIN, 10, 25, form=1
    Encounter SPECIES_BASCULIN, 10, 25, form=1
    Encounter SPECIES_BASCULIN, 10, 25, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BUIZEL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30, form=1
    Encounter SPECIES_FLOATZEL, 10, 30
    Encounter SPECIES_FLOATZEL, 10, 30
    Encounter SPECIES_FLOATZEL, 10, 30
#else
    Encounter SPECIES_BUIZEL, 10, 30
    Encounter SPECIES_BASCULIN, 10, 30
    Encounter SPECIES_FLOATZEL, 10, 30
    Encounter SPECIES_FLOATZEL, 10, 30
    Encounter SPECIES_FLOATZEL, 10, 30
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
    Encounter SPECIES_POLITOED, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
#else
    Encounter SPECIES_POLIWHIRL, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_POLIWHIRL, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
    Encounter SPECIES_POLITOED, 50, 70
#endif
    EncountersEnd
