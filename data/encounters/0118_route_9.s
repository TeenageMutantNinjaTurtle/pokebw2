#include "asm/encounters.inc"

// Route 9

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_GOTHORITA, 37, 37
    Encounter SPECIES_MINCCINO, 37, 37
    Encounter SPECIES_GARBODOR, 38, 38
    Encounter SPECIES_MINCCINO, 39, 39
    Encounter SPECIES_PAWNIARD, 38, 38
    Encounter SPECIES_LIEPARD, 40, 40
    Encounter SPECIES_PAWNIARD, 40, 40
    Encounter SPECIES_MUK, 40, 40
    Encounter SPECIES_GOTHORITA, 39, 39
    Encounter SPECIES_GARBODOR, 40, 40
    Encounter SPECIES_GOTHORITA, 39, 39
    Encounter SPECIES_GARBODOR, 40, 40
#else
    Encounter SPECIES_DUOSION, 37, 37
    Encounter SPECIES_MINCCINO, 37, 37
    Encounter SPECIES_GARBODOR, 38, 38
    Encounter SPECIES_MINCCINO, 39, 39
    Encounter SPECIES_PAWNIARD, 38, 38
    Encounter SPECIES_LIEPARD, 40, 40
    Encounter SPECIES_PAWNIARD, 40, 40
    Encounter SPECIES_MUK, 40, 40
    Encounter SPECIES_DUOSION, 39, 39
    Encounter SPECIES_GARBODOR, 40, 40
    Encounter SPECIES_DUOSION, 39, 39
    Encounter SPECIES_GARBODOR, 40, 40
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_GOTHORITA, 41, 41
    Encounter SPECIES_MINCCINO, 41, 41
    Encounter SPECIES_GARBODOR, 42, 42
    Encounter SPECIES_MINCCINO, 43, 43
    Encounter SPECIES_PAWNIARD, 42, 42
    Encounter SPECIES_LIEPARD, 44, 44
    Encounter SPECIES_PAWNIARD, 44, 44
    Encounter SPECIES_MUK, 44, 44
    Encounter SPECIES_GOTHORITA, 43, 43
    Encounter SPECIES_GARBODOR, 44, 44
    Encounter SPECIES_GOTHORITA, 43, 43
    Encounter SPECIES_GARBODOR, 44, 44
#else
    Encounter SPECIES_DUOSION, 41, 41
    Encounter SPECIES_MINCCINO, 41, 41
    Encounter SPECIES_GARBODOR, 42, 42
    Encounter SPECIES_MINCCINO, 43, 43
    Encounter SPECIES_PAWNIARD, 42, 42
    Encounter SPECIES_LIEPARD, 44, 44
    Encounter SPECIES_PAWNIARD, 44, 44
    Encounter SPECIES_MUK, 44, 44
    Encounter SPECIES_DUOSION, 43, 43
    Encounter SPECIES_GARBODOR, 44, 44
    Encounter SPECIES_DUOSION, 43, 43
    Encounter SPECIES_GARBODOR, 44, 44
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_EMOLGA, 38, 38
    Encounter SPECIES_AUDINO, 38, 38
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 40, 40
    Encounter SPECIES_AUDINO, 40, 40
    Encounter SPECIES_CINCCINO, 40, 40
    Encounter SPECIES_GOTHITELLE, 40, 40
    Encounter SPECIES_CINCCINO, 40, 40
    Encounter SPECIES_GOTHITELLE, 40, 40
#else
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_AUDINO, 37, 37
    Encounter SPECIES_EMOLGA, 38, 38
    Encounter SPECIES_AUDINO, 38, 38
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 40, 40
    Encounter SPECIES_AUDINO, 40, 40
    Encounter SPECIES_CINCCINO, 40, 40
    Encounter SPECIES_REUNICLUS, 40, 40
    Encounter SPECIES_CINCCINO, 40, 40
    Encounter SPECIES_REUNICLUS, 40, 40
#endif
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
