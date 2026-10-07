#include "asm/encounters.inc"

// Route 18

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SCRAFTY, 57, 57
    Encounter SPECIES_CRUSTLE, 57, 57
    Encounter SPECIES_WATCHOG, 56, 56
    Encounter SPECIES_TROPIUS, 58, 58
    Encounter SPECIES_SAWK, 57, 57
    Encounter SPECIES_CARNIVINE, 58, 58
    Encounter SPECIES_SCRAFTY, 58, 58
    Encounter SPECIES_SAWK, 59, 59
    Encounter SPECIES_SCRAFTY, 58, 58
    Encounter SPECIES_SAWK, 59, 59
    Encounter SPECIES_SCRAFTY, 58, 58
    Encounter SPECIES_SAWK, 59, 59
#else
    Encounter SPECIES_SCRAFTY, 57, 57
    Encounter SPECIES_CRUSTLE, 57, 57
    Encounter SPECIES_WATCHOG, 56, 56
    Encounter SPECIES_TROPIUS, 58, 58
    Encounter SPECIES_THROH, 57, 57
    Encounter SPECIES_CARNIVINE, 58, 58
    Encounter SPECIES_SCRAFTY, 58, 58
    Encounter SPECIES_THROH, 59, 59
    Encounter SPECIES_SCRAFTY, 58, 58
    Encounter SPECIES_THROH, 59, 59
    Encounter SPECIES_SCRAFTY, 58, 58
    Encounter SPECIES_THROH, 59, 59
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SCRAFTY, 65, 65
    Encounter SPECIES_CRUSTLE, 65, 65
    Encounter SPECIES_WATCHOG, 64, 64
    Encounter SPECIES_TROPIUS, 66, 66
    Encounter SPECIES_SAWK, 65, 65
    Encounter SPECIES_CARNIVINE, 66, 66
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_SAWK, 67, 67
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_SAWK, 67, 67
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_SAWK, 67, 67
#else
    Encounter SPECIES_SCRAFTY, 65, 65
    Encounter SPECIES_CRUSTLE, 65, 65
    Encounter SPECIES_WATCHOG, 64, 64
    Encounter SPECIES_TROPIUS, 66, 66
    Encounter SPECIES_THROH, 65, 65
    Encounter SPECIES_CARNIVINE, 66, 66
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_THROH, 67, 67
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_THROH, 67, 67
    Encounter SPECIES_SCRAFTY, 66, 66
    Encounter SPECIES_THROH, 67, 67
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_DUNSPARCE, 57, 57
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_THROH, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_THROH, 59, 59
#else
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_DUNSPARCE, 57, 57
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 58, 58
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_SAWK, 59, 59
    Encounter SPECIES_AUDINO, 59, 59
    Encounter SPECIES_SAWK, 59, 59
#endif
    SurfEncounters
    Encounter SPECIES_FRILLISH, 45, 60
    Encounter SPECIES_FRILLISH, 45, 60
    Encounter SPECIES_FRILLISH, 50, 60
    Encounter SPECIES_FRILLISH, 50, 60
    Encounter SPECIES_FRILLISH, 50, 60
    RipplingSurfEncounters
    Encounter SPECIES_ALOMOMOLA, 45, 60
    Encounter SPECIES_ALOMOMOLA, 45, 60
    Encounter SPECIES_ALOMOMOLA, 50, 60
    Encounter SPECIES_JELLICENT, 50, 60
    Encounter SPECIES_JELLICENT, 50, 60
    FishingEncounters
    Encounter SPECIES_FINNEON, 50, 60
    Encounter SPECIES_HORSEA, 50, 60
    Encounter SPECIES_FINNEON, 60, 70
    Encounter SPECIES_CORSOLA, 60, 70
    Encounter SPECIES_CORSOLA, 60, 70
    RipplingFishingEncounters
    Encounter SPECIES_HORSEA, 50, 60
    Encounter SPECIES_LUMINEON, 50, 60
    Encounter SPECIES_SEADRA, 60, 70
    Encounter SPECIES_KINGDRA, 60, 70
    Encounter SPECIES_KINGDRA, 60, 70
    EncountersEnd
