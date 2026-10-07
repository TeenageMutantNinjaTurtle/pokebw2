#include "asm/encounters.inc"

// Route 16

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_GOTHITA, 21, 21
    Encounter SPECIES_MINCCINO, 21, 21
    Encounter SPECIES_TRUBBISH, 21, 21
    Encounter SPECIES_TRUBBISH, 23, 23
    Encounter SPECIES_LIEPARD, 22, 22
    Encounter SPECIES_LIEPARD, 24, 24
    Encounter SPECIES_MINCCINO, 22, 22
    Encounter SPECIES_GOTHITA, 22, 22
    Encounter SPECIES_MINCCINO, 23, 23
    Encounter SPECIES_GOTHITA, 23, 23
    Encounter SPECIES_MINCCINO, 24, 24
    Encounter SPECIES_GOTHITA, 24, 24
#else
    Encounter SPECIES_SOLOSIS, 21, 21
    Encounter SPECIES_MINCCINO, 21, 21
    Encounter SPECIES_TRUBBISH, 21, 21
    Encounter SPECIES_MINCCINO, 23, 23
    Encounter SPECIES_LIEPARD, 22, 22
    Encounter SPECIES_LIEPARD, 24, 24
    Encounter SPECIES_TRUBBISH, 22, 22
    Encounter SPECIES_SOLOSIS, 22, 22
    Encounter SPECIES_TRUBBISH, 23, 23
    Encounter SPECIES_SOLOSIS, 23, 23
    Encounter SPECIES_TRUBBISH, 24, 24
    Encounter SPECIES_SOLOSIS, 24, 24
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_GOTHITA, 23, 23
    Encounter SPECIES_MINCCINO, 23, 23
    Encounter SPECIES_TRUBBISH, 23, 23
    Encounter SPECIES_TRUBBISH, 25, 25
    Encounter SPECIES_LIEPARD, 24, 24
    Encounter SPECIES_LIEPARD, 26, 26
    Encounter SPECIES_MINCCINO, 24, 24
    Encounter SPECIES_GOTHITA, 24, 24
    Encounter SPECIES_MINCCINO, 25, 25
    Encounter SPECIES_GOTHITA, 25, 25
    Encounter SPECIES_MINCCINO, 26, 26
    Encounter SPECIES_GOTHITA, 26, 26
#else
    Encounter SPECIES_SOLOSIS, 23, 23
    Encounter SPECIES_MINCCINO, 23, 23
    Encounter SPECIES_TRUBBISH, 23, 23
    Encounter SPECIES_MINCCINO, 25, 25
    Encounter SPECIES_LIEPARD, 24, 24
    Encounter SPECIES_LIEPARD, 26, 26
    Encounter SPECIES_TRUBBISH, 24, 24
    Encounter SPECIES_SOLOSIS, 24, 24
    Encounter SPECIES_TRUBBISH, 25, 25
    Encounter SPECIES_SOLOSIS, 25, 25
    Encounter SPECIES_TRUBBISH, 26, 26
    Encounter SPECIES_SOLOSIS, 26, 26
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 21, 21
    Encounter SPECIES_AUDINO, 21, 21
    Encounter SPECIES_EMOLGA, 22, 22
    Encounter SPECIES_AUDINO, 22, 22
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_AUDINO, 23, 23
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_CINCCINO, 24, 24
    Encounter SPECIES_AUDINO, 24, 24
    Encounter SPECIES_CINCCINO, 24, 24
    Encounter SPECIES_AUDINO, 24, 24
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
