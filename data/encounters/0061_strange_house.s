#include "asm/encounters.inc"

// Strange House

    EncounterRates grass=7, dark_grass=0, shaking_grass=0, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_LITWICK, 31, 31
    Encounter SPECIES_GOTHITA, 31, 31
    Encounter SPECIES_RATICATE, 32, 32
    Encounter SPECIES_GOLBAT, 32, 32
    Encounter SPECIES_LITWICK, 33, 33
    Encounter SPECIES_BANETTE, 32, 32
    Encounter SPECIES_RATICATE, 33, 33
    Encounter SPECIES_GOLBAT, 33, 33
    Encounter SPECIES_BANETTE, 34, 34
    Encounter SPECIES_GOTHORITA, 34, 34
    Encounter SPECIES_BANETTE, 34, 34
    Encounter SPECIES_GOTHORITA, 34, 34
#else
    Encounter SPECIES_LITWICK, 31, 31
    Encounter SPECIES_SOLOSIS, 31, 31
    Encounter SPECIES_RATICATE, 32, 32
    Encounter SPECIES_GOLBAT, 32, 32
    Encounter SPECIES_LITWICK, 33, 33
    Encounter SPECIES_BANETTE, 32, 32
    Encounter SPECIES_RATICATE, 33, 33
    Encounter SPECIES_GOLBAT, 33, 33
    Encounter SPECIES_BANETTE, 34, 34
    Encounter SPECIES_DUOSION, 34, 34
    Encounter SPECIES_BANETTE, 34, 34
    Encounter SPECIES_DUOSION, 34, 34
#endif
    DarkGrassEncounters
    ShakingGrassEncounters
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
