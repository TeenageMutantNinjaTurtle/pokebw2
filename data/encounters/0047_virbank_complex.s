#include "asm/encounters.inc"

// Virbank Complex

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_MAGBY, 10, 10
    Encounter SPECIES_MAGNEMITE, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_KOFFING, 10, 10
    Encounter SPECIES_GROWLITHE, 11, 11
    Encounter SPECIES_GROWLITHE, 13, 13
    Encounter SPECIES_MAGBY, 12, 12
    Encounter SPECIES_MAGNEMITE, 12, 12
    Encounter SPECIES_PATRAT, 12, 12
    Encounter SPECIES_KOFFING, 12, 12
    Encounter SPECIES_PATRAT, 13, 13
    Encounter SPECIES_KOFFING, 13, 13
#else
    Encounter SPECIES_ELEKID, 10, 10
    Encounter SPECIES_MAGNEMITE, 10, 10
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_KOFFING, 10, 10
    Encounter SPECIES_GROWLITHE, 11, 11
    Encounter SPECIES_GROWLITHE, 13, 13
    Encounter SPECIES_ELEKID, 12, 12
    Encounter SPECIES_MAGNEMITE, 12, 12
    Encounter SPECIES_PATRAT, 12, 12
    Encounter SPECIES_KOFFING, 12, 12
    Encounter SPECIES_PATRAT, 13, 13
    Encounter SPECIES_KOFFING, 13, 13
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_MAGBY, 11, 11
    Encounter SPECIES_MAGNEMITE, 11, 11
    Encounter SPECIES_PATRAT, 11, 11
    Encounter SPECIES_KOFFING, 11, 11
    Encounter SPECIES_GROWLITHE, 12, 12
    Encounter SPECIES_GROWLITHE, 14, 14
    Encounter SPECIES_MAGBY, 13, 13
    Encounter SPECIES_MAGNEMITE, 13, 13
    Encounter SPECIES_PATRAT, 13, 13
    Encounter SPECIES_KOFFING, 13, 13
    Encounter SPECIES_PATRAT, 14, 14
    Encounter SPECIES_KOFFING, 14, 14
#else
    Encounter SPECIES_ELEKID, 11, 11
    Encounter SPECIES_MAGNEMITE, 11, 11
    Encounter SPECIES_PATRAT, 11, 11
    Encounter SPECIES_KOFFING, 11, 11
    Encounter SPECIES_GROWLITHE, 12, 12
    Encounter SPECIES_GROWLITHE, 14, 14
    Encounter SPECIES_ELEKID, 13, 13
    Encounter SPECIES_MAGNEMITE, 13, 13
    Encounter SPECIES_PATRAT, 13, 13
    Encounter SPECIES_KOFFING, 13, 13
    Encounter SPECIES_PATRAT, 14, 14
    Encounter SPECIES_KOFFING, 14, 14
#endif
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 10, 10
    Encounter SPECIES_AUDINO, 10, 10
    Encounter SPECIES_AUDINO, 11, 11
    Encounter SPECIES_AUDINO, 11, 11
    Encounter SPECIES_AUDINO, 12, 12
    Encounter SPECIES_AUDINO, 12, 12
    Encounter SPECIES_AUDINO, 13, 13
    Encounter SPECIES_AUDINO, 13, 13
    Encounter SPECIES_AUDINO, 13, 13
    Encounter SPECIES_AUDINO, 13, 13
    Encounter SPECIES_AUDINO, 13, 13
    Encounter SPECIES_AUDINO, 13, 13
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
