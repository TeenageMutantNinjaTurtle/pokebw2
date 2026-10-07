#include "asm/encounters.inc"

// Reversal Mountain

    EncounterRates grass=1, dark_grass=4, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SKORUPI, 31, 31
    Encounter SPECIES_SPOINK, 31, 31
    Encounter SPECIES_TRAPINCH, 32, 32
    Encounter SPECIES_SKORUPI, 33, 33
    Encounter SPECIES_DRIFBLIM, 32, 32
    Encounter SPECIES_DRIFBLIM, 33, 33
    Encounter SPECIES_SKARMORY, 34, 34
    Encounter SPECIES_GRUMPIG, 33, 33
    Encounter SPECIES_TRAPINCH, 34, 34
    Encounter SPECIES_GRUMPIG, 33, 33
    Encounter SPECIES_TRAPINCH, 34, 34
    Encounter SPECIES_GRUMPIG, 33, 33
#else
    Encounter SPECIES_SKORUPI, 31, 31
    Encounter SPECIES_NUMEL, 31, 31
    Encounter SPECIES_TRAPINCH, 32, 32
    Encounter SPECIES_SKORUPI, 33, 33
    Encounter SPECIES_DRIFBLIM, 32, 32
    Encounter SPECIES_DRIFBLIM, 33, 33
    Encounter SPECIES_SKARMORY, 34, 34
    Encounter SPECIES_CAMERUPT, 33, 33
    Encounter SPECIES_TRAPINCH, 34, 34
    Encounter SPECIES_CAMERUPT, 33, 33
    Encounter SPECIES_TRAPINCH, 34, 34
    Encounter SPECIES_CAMERUPT, 33, 33
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SKORUPI, 35, 35
    Encounter SPECIES_GRUMPIG, 35, 35
    Encounter SPECIES_SKARMORY, 36, 36
    Encounter SPECIES_SKORUPI, 37, 37
    Encounter SPECIES_DRIFBLIM, 36, 36
    Encounter SPECIES_DRIFBLIM, 37, 37
    Encounter SPECIES_SKARMORY, 38, 38
    Encounter SPECIES_GRUMPIG, 37, 37
    Encounter SPECIES_VIBRAVA, 38, 38
    Encounter SPECIES_GRUMPIG, 37, 37
    Encounter SPECIES_VIBRAVA, 38, 38
    Encounter SPECIES_GRUMPIG, 37, 37
#else
    Encounter SPECIES_SKORUPI, 35, 35
    Encounter SPECIES_CAMERUPT, 35, 35
    Encounter SPECIES_SKARMORY, 36, 36
    Encounter SPECIES_SKORUPI, 37, 37
    Encounter SPECIES_DRIFBLIM, 36, 36
    Encounter SPECIES_DRIFBLIM, 37, 37
    Encounter SPECIES_SKARMORY, 38, 38
    Encounter SPECIES_CAMERUPT, 37, 37
    Encounter SPECIES_VIBRAVA, 38, 38
    Encounter SPECIES_CAMERUPT, 37, 37
    Encounter SPECIES_VIBRAVA, 38, 38
    Encounter SPECIES_CAMERUPT, 37, 37
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 31, 31
    Encounter SPECIES_AUDINO, 31, 31
    Encounter SPECIES_AUDINO, 32, 32
    Encounter SPECIES_AUDINO, 32, 32
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
