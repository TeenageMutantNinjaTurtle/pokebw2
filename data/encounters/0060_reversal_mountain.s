#include "asm/encounters.inc"

// Reversal Mountain

    EncounterRates grass=7, dark_grass=0, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0, flags=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SPOINK, 31, 31
    Encounter SPECIES_WOOBAT, 32, 32
    Encounter SPECIES_BOLDORE, 32, 32
    Encounter SPECIES_SKORUPI, 33, 33
    Encounter SPECIES_BOLDORE, 34, 34
    Encounter SPECIES_WOOBAT, 34, 34
    Encounter SPECIES_GRUMPIG, 35, 35
    Encounter SPECIES_SKORUPI, 35, 35
    Encounter SPECIES_WOOBAT, 35, 35
    Encounter SPECIES_BOLDORE, 35, 35
    Encounter SPECIES_WOOBAT, 35, 35
    Encounter SPECIES_BOLDORE, 35, 35
#else
    Encounter SPECIES_NUMEL, 31, 31
    Encounter SPECIES_WOOBAT, 32, 32
    Encounter SPECIES_BOLDORE, 32, 32
    Encounter SPECIES_SKORUPI, 33, 33
    Encounter SPECIES_BOLDORE, 34, 34
    Encounter SPECIES_WOOBAT, 34, 34
    Encounter SPECIES_CAMERUPT, 35, 35
    Encounter SPECIES_SKORUPI, 35, 35
    Encounter SPECIES_WOOBAT, 35, 35
    Encounter SPECIES_BOLDORE, 35, 35
    Encounter SPECIES_WOOBAT, 35, 35
    Encounter SPECIES_BOLDORE, 35, 35
#endif
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_EXCADRILL, 32, 32
    Encounter SPECIES_EXCADRILL, 32, 32
    Encounter SPECIES_EXCADRILL, 33, 33
    Encounter SPECIES_EXCADRILL, 33, 33
    Encounter SPECIES_EXCADRILL, 34, 34
    Encounter SPECIES_EXCADRILL, 34, 34
    Encounter SPECIES_EXCADRILL, 35, 35
    Encounter SPECIES_EXCADRILL, 35, 35
    Encounter SPECIES_EXCADRILL, 35, 35
    Encounter SPECIES_EXCADRILL, 35, 35
    Encounter SPECIES_EXCADRILL, 35, 35
    Encounter SPECIES_EXCADRILL, 35, 35
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
