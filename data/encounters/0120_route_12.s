#include "asm/encounters.inc"

// Route 12

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COMBEE, 35, 35
    Encounter SPECIES_ROSELIA, 35, 35
    Encounter SPECIES_SEWADDLE, 36, 36
    Encounter SPECIES_TRANQUILL, 37, 37
    Encounter SPECIES_HERACROSS, 36, 36
    Encounter SPECIES_TRANQUILL, 36, 36
    Encounter SPECIES_HERACROSS, 38, 38
    Encounter SPECIES_SEWADDLE, 38, 38
    Encounter SPECIES_ROSELIA, 37, 37
    Encounter SPECIES_TRANQUILL, 38, 38
    Encounter SPECIES_ROSELIA, 37, 37
    Encounter SPECIES_TRANQUILL, 38, 38
#else
    Encounter SPECIES_COMBEE, 35, 35
    Encounter SPECIES_ROSELIA, 35, 35
    Encounter SPECIES_SEWADDLE, 36, 36
    Encounter SPECIES_TRANQUILL, 37, 37
    Encounter SPECIES_PINSIR, 36, 36
    Encounter SPECIES_TRANQUILL, 36, 36
    Encounter SPECIES_PINSIR, 38, 38
    Encounter SPECIES_SEWADDLE, 38, 38
    Encounter SPECIES_ROSELIA, 37, 37
    Encounter SPECIES_TRANQUILL, 38, 38
    Encounter SPECIES_ROSELIA, 37, 37
    Encounter SPECIES_TRANQUILL, 38, 38
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COMBEE, 39, 39
    Encounter SPECIES_ROSELIA, 39, 39
    Encounter SPECIES_SEWADDLE, 40, 40
    Encounter SPECIES_TRANQUILL, 41, 41
    Encounter SPECIES_HERACROSS, 40, 40
    Encounter SPECIES_TRANQUILL, 40, 40
    Encounter SPECIES_HERACROSS, 42, 42
    Encounter SPECIES_SEWADDLE, 42, 42
    Encounter SPECIES_ROSELIA, 41, 41
    Encounter SPECIES_TRANQUILL, 42, 42
    Encounter SPECIES_ROSELIA, 41, 41
    Encounter SPECIES_TRANQUILL, 42, 42
#else
    Encounter SPECIES_COMBEE, 39, 39
    Encounter SPECIES_ROSELIA, 39, 39
    Encounter SPECIES_SEWADDLE, 40, 40
    Encounter SPECIES_TRANQUILL, 41, 41
    Encounter SPECIES_PINSIR, 40, 40
    Encounter SPECIES_TRANQUILL, 40, 40
    Encounter SPECIES_PINSIR, 42, 42
    Encounter SPECIES_SEWADDLE, 42, 42
    Encounter SPECIES_ROSELIA, 41, 41
    Encounter SPECIES_TRANQUILL, 42, 42
    Encounter SPECIES_ROSELIA, 41, 41
    Encounter SPECIES_TRANQUILL, 42, 42
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_EMOLGA, 36, 36
    Encounter SPECIES_DUNSPARCE, 36, 36
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_UNFEZANT, 38, 38
    Encounter SPECIES_LEAVANNY, 38, 38
    Encounter SPECIES_VESPIQUEN, 38, 38
    Encounter SPECIES_ROSERADE, 38, 38
    Encounter SPECIES_VESPIQUEN, 38, 38
    Encounter SPECIES_ROSERADE, 38, 38
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
