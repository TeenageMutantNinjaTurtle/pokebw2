#include "asm/encounters.inc"

// Route 15

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SANDSLASH, 54, 54
    Encounter SPECIES_GLIGAR, 55, 55
    Encounter SPECIES_SANDSLASH, 56, 56
    Encounter SPECIES_SCRAFTY, 55, 55
    Encounter SPECIES_SAWK, 55, 55
    Encounter SPECIES_PUPITAR, 55, 55
    Encounter SPECIES_SAWK, 56, 56
    Encounter SPECIES_SAWK, 57, 57
    Encounter SPECIES_PUPITAR, 57, 57
    Encounter SPECIES_GLIGAR, 57, 57
    Encounter SPECIES_PUPITAR, 57, 57
    Encounter SPECIES_GLIGAR, 57, 57
#else
    Encounter SPECIES_SANDSLASH, 54, 54
    Encounter SPECIES_GLIGAR, 55, 55
    Encounter SPECIES_SANDSLASH, 56, 56
    Encounter SPECIES_SCRAFTY, 55, 55
    Encounter SPECIES_THROH, 55, 55
    Encounter SPECIES_PUPITAR, 55, 55
    Encounter SPECIES_THROH, 56, 56
    Encounter SPECIES_THROH, 57, 57
    Encounter SPECIES_PUPITAR, 57, 57
    Encounter SPECIES_GLIGAR, 57, 57
    Encounter SPECIES_PUPITAR, 57, 57
    Encounter SPECIES_GLIGAR, 57, 57
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SANDSLASH, 62, 62
    Encounter SPECIES_GLIGAR, 63, 63
    Encounter SPECIES_SANDSLASH, 64, 64
    Encounter SPECIES_SCRAFTY, 63, 63
    Encounter SPECIES_SAWK, 63, 63
    Encounter SPECIES_PUPITAR, 63, 63
    Encounter SPECIES_SAWK, 64, 64
    Encounter SPECIES_SAWK, 65, 65
    Encounter SPECIES_PUPITAR, 65, 65
    Encounter SPECIES_GLIGAR, 65, 65
    Encounter SPECIES_PUPITAR, 65, 65
    Encounter SPECIES_GLIGAR, 65, 65
#else
    Encounter SPECIES_SANDSLASH, 62, 62
    Encounter SPECIES_GLIGAR, 63, 63
    Encounter SPECIES_SANDSLASH, 64, 64
    Encounter SPECIES_SCRAFTY, 63, 63
    Encounter SPECIES_THROH, 63, 63
    Encounter SPECIES_PUPITAR, 63, 63
    Encounter SPECIES_THROH, 64, 64
    Encounter SPECIES_THROH, 65, 65
    Encounter SPECIES_PUPITAR, 65, 65
    Encounter SPECIES_GLIGAR, 65, 65
    Encounter SPECIES_PUPITAR, 65, 65
    Encounter SPECIES_GLIGAR, 65, 65
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_EMOLGA, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_THROH, 57, 57
    Encounter SPECIES_GLISCOR, 57, 57
    Encounter SPECIES_TYRANITAR, 57, 57
    Encounter SPECIES_GLISCOR, 57, 57
    Encounter SPECIES_TYRANITAR, 57, 57
#else
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_EMOLGA, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_SAWK, 57, 57
    Encounter SPECIES_GLISCOR, 57, 57
    Encounter SPECIES_TYRANITAR, 57, 57
    Encounter SPECIES_GLISCOR, 57, 57
    Encounter SPECIES_TYRANITAR, 57, 57
#endif
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
