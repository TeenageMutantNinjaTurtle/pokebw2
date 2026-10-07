#include "asm/encounters.inc"

// Virbank Complex

    EncounterRates grass=1, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_PIDOVE, 10, 10
    Encounter SPECIES_MAGBY, 10, 10
    Encounter SPECIES_MAGNEMITE, 10, 10
    Encounter SPECIES_PATRAT, 11, 11
    Encounter SPECIES_PIDOVE, 11, 11
    Encounter SPECIES_MAGBY, 11, 11
    Encounter SPECIES_MAGNEMITE, 11, 11
    Encounter SPECIES_PATRAT, 12, 12
    Encounter SPECIES_PIDOVE, 12, 12
    Encounter SPECIES_PATRAT, 13, 13
    Encounter SPECIES_PIDOVE, 13, 13
#else
    Encounter SPECIES_PATRAT, 10, 10
    Encounter SPECIES_PIDOVE, 10, 10
    Encounter SPECIES_ELEKID, 10, 10
    Encounter SPECIES_MAGNEMITE, 10, 10
    Encounter SPECIES_PATRAT, 11, 11
    Encounter SPECIES_PIDOVE, 11, 11
    Encounter SPECIES_ELEKID, 11, 11
    Encounter SPECIES_MAGNEMITE, 11, 11
    Encounter SPECIES_PATRAT, 12, 12
    Encounter SPECIES_PIDOVE, 12, 12
    Encounter SPECIES_PATRAT, 13, 13
    Encounter SPECIES_PIDOVE, 13, 13
#endif
    DarkGrassEncounters
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
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    RipplingSurfEncounters
    Encounter SPECIES_ALOMOMOLA, 5, 15
    Encounter SPECIES_ALOMOMOLA, 5, 15
    Encounter SPECIES_ALOMOMOLA, 5, 15
    Encounter SPECIES_JELLICENT, 5, 15
    Encounter SPECIES_JELLICENT, 5, 15
    FishingEncounters
    Encounter SPECIES_FINNEON, 40, 60
    Encounter SPECIES_KRABBY, 40, 60
    Encounter SPECIES_FINNEON, 50, 70
    Encounter SPECIES_QWILFISH, 50, 70
    Encounter SPECIES_QWILFISH, 50, 70
    RipplingFishingEncounters
    Encounter SPECIES_KRABBY, 40, 60
    Encounter SPECIES_LUMINEON, 40, 60
    Encounter SPECIES_KINGLER, 50, 70
    Encounter SPECIES_KINGLER, 50, 70
    Encounter SPECIES_KINGLER, 50, 70
    EncountersEnd
