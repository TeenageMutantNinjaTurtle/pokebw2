#include "asm/encounters.inc"

// Victory Road

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COTTONEE, 47, 47
    Encounter SPECIES_COTTONEE, 47, 47
    Encounter SPECIES_COTTONEE, 48, 48
    Encounter SPECIES_ROSELIA, 48, 48
    Encounter SPECIES_COTTONEE, 49, 49
    Encounter SPECIES_ROSELIA, 49, 49
    Encounter SPECIES_COTTONEE, 50, 50
    Encounter SPECIES_ROSELIA, 50, 50
    Encounter SPECIES_COTTONEE, 50, 50
    Encounter SPECIES_ROSELIA, 50, 50
    Encounter SPECIES_COTTONEE, 50, 50
    Encounter SPECIES_ROSELIA, 50, 50
#else
    Encounter SPECIES_PETILIL, 47, 47
    Encounter SPECIES_PETILIL, 47, 47
    Encounter SPECIES_PETILIL, 48, 48
    Encounter SPECIES_ROSELIA, 48, 48
    Encounter SPECIES_PETILIL, 49, 49
    Encounter SPECIES_ROSELIA, 49, 49
    Encounter SPECIES_PETILIL, 50, 50
    Encounter SPECIES_ROSELIA, 50, 50
    Encounter SPECIES_PETILIL, 50, 50
    Encounter SPECIES_ROSELIA, 50, 50
    Encounter SPECIES_PETILIL, 50, 50
    Encounter SPECIES_ROSELIA, 50, 50
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_COTTONEE, 52, 52
    Encounter SPECIES_COTTONEE, 52, 52
    Encounter SPECIES_COTTONEE, 53, 53
    Encounter SPECIES_ROSELIA, 53, 53
    Encounter SPECIES_COTTONEE, 54, 54
    Encounter SPECIES_ROSELIA, 54, 54
    Encounter SPECIES_COTTONEE, 55, 55
    Encounter SPECIES_ROSELIA, 55, 55
    Encounter SPECIES_COTTONEE, 55, 55
    Encounter SPECIES_ROSELIA, 55, 55
    Encounter SPECIES_COTTONEE, 55, 55
    Encounter SPECIES_ROSELIA, 55, 55
#else
    Encounter SPECIES_PETILIL, 52, 52
    Encounter SPECIES_PETILIL, 52, 52
    Encounter SPECIES_PETILIL, 53, 53
    Encounter SPECIES_ROSELIA, 53, 53
    Encounter SPECIES_PETILIL, 54, 54
    Encounter SPECIES_ROSELIA, 54, 54
    Encounter SPECIES_PETILIL, 55, 55
    Encounter SPECIES_ROSELIA, 55, 55
    Encounter SPECIES_PETILIL, 55, 55
    Encounter SPECIES_ROSELIA, 55, 55
    Encounter SPECIES_PETILIL, 55, 55
    Encounter SPECIES_ROSELIA, 55, 55
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 47, 47
    Encounter SPECIES_AUDINO, 47, 47
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_DUNSPARCE, 49, 49
    Encounter SPECIES_AUDINO, 49, 49
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_WHIMSICOTT, 50, 50
    Encounter SPECIES_ROSERADE, 50, 50
    Encounter SPECIES_WHIMSICOTT, 50, 50
    Encounter SPECIES_ROSERADE, 50, 50
#else
    Encounter SPECIES_AUDINO, 47, 47
    Encounter SPECIES_AUDINO, 47, 47
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_DUNSPARCE, 49, 49
    Encounter SPECIES_AUDINO, 49, 49
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_LILLIGANT, 50, 50
    Encounter SPECIES_ROSERADE, 50, 50
    Encounter SPECIES_LILLIGANT, 50, 50
    Encounter SPECIES_ROSERADE, 50, 50
#endif
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
