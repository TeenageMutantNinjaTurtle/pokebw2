#include "asm/encounters.inc"

// Pinwheel Forest

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_PALPITOAD, 54, 54
    Encounter SPECIES_GURDURR, 54, 54
    Encounter SPECIES_TOXICROAK, 55, 55
    Encounter SPECIES_YANMA, 55, 55
    Encounter SPECIES_GURDURR, 55, 55
    Encounter SPECIES_GURDURR, 56, 56
    Encounter SPECIES_SAWK, 55, 55
    Encounter SPECIES_SAWK, 55, 55
    Encounter SPECIES_PALPITOAD, 57, 57
    Encounter SPECIES_SAWK, 57, 57
    Encounter SPECIES_PALPITOAD, 57, 57
    Encounter SPECIES_SAWK, 57, 57
#else
    Encounter SPECIES_PALPITOAD, 54, 54
    Encounter SPECIES_GURDURR, 54, 54
    Encounter SPECIES_TOXICROAK, 55, 55
    Encounter SPECIES_YANMA, 55, 55
    Encounter SPECIES_GURDURR, 55, 55
    Encounter SPECIES_GURDURR, 56, 56
    Encounter SPECIES_THROH, 55, 55
    Encounter SPECIES_THROH, 55, 55
    Encounter SPECIES_PALPITOAD, 57, 57
    Encounter SPECIES_THROH, 57, 57
    Encounter SPECIES_PALPITOAD, 57, 57
    Encounter SPECIES_THROH, 57, 57
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_PALPITOAD, 64, 64
    Encounter SPECIES_GURDURR, 64, 64
    Encounter SPECIES_TOXICROAK, 63, 63
    Encounter SPECIES_YANMA, 63, 63
    Encounter SPECIES_GURDURR, 63, 63
    Encounter SPECIES_GURDURR, 64, 64
    Encounter SPECIES_SAWK, 63, 63
    Encounter SPECIES_SAWK, 63, 63
    Encounter SPECIES_PALPITOAD, 65, 65
    Encounter SPECIES_SAWK, 65, 65
    Encounter SPECIES_PALPITOAD, 65, 65
    Encounter SPECIES_SAWK, 65, 65
#else
    Encounter SPECIES_PALPITOAD, 64, 64
    Encounter SPECIES_GURDURR, 64, 64
    Encounter SPECIES_TOXICROAK, 63, 63
    Encounter SPECIES_YANMA, 63, 63
    Encounter SPECIES_GURDURR, 63, 63
    Encounter SPECIES_GURDURR, 64, 64
    Encounter SPECIES_THROH, 63, 63
    Encounter SPECIES_THROH, 63, 63
    Encounter SPECIES_PALPITOAD, 65, 65
    Encounter SPECIES_THROH, 65, 65
    Encounter SPECIES_PALPITOAD, 65, 65
    Encounter SPECIES_THROH, 65, 65
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_YANMEGA, 57, 57
    Encounter SPECIES_SEISMITOAD, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_THROH, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_THROH, 57, 57
#else
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 54, 54
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 55, 55
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_AUDINO, 56, 56
    Encounter SPECIES_YANMEGA, 57, 57
    Encounter SPECIES_SEISMITOAD, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_SAWK, 57, 57
    Encounter SPECIES_AUDINO, 57, 57
    Encounter SPECIES_SAWK, 57, 57
#endif
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
