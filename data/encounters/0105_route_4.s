#include "asm/encounters.inc"

// Route 4

    EncounterRates grass=9, dark_grass=0, shaking_grass=0, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SANDILE, 14, 14
    Encounter SPECIES_DARUMAKA, 14, 14
    Encounter SPECIES_SANDILE, 15, 15
    Encounter SPECIES_DARUMAKA, 15, 15
    Encounter SPECIES_TRUBBISH, 15, 15
    Encounter SPECIES_TRUBBISH, 14, 14
    Encounter SPECIES_SCRAGGY, 17, 17
    Encounter SPECIES_TRUBBISH, 17, 17
    Encounter SPECIES_SANDILE, 16, 16
    Encounter SPECIES_DARUMAKA, 16, 16
    Encounter SPECIES_SANDILE, 17, 17
    Encounter SPECIES_DARUMAKA, 17, 17
#else
    Encounter SPECIES_SANDILE, 14, 14
    Encounter SPECIES_DARUMAKA, 14, 14
    Encounter SPECIES_SANDILE, 15, 15
    Encounter SPECIES_DARUMAKA, 15, 15
    Encounter SPECIES_MINCCINO, 15, 15
    Encounter SPECIES_MINCCINO, 14, 14
    Encounter SPECIES_SCRAGGY, 17, 17
    Encounter SPECIES_MINCCINO, 17, 17
    Encounter SPECIES_SANDILE, 16, 16
    Encounter SPECIES_DARUMAKA, 16, 16
    Encounter SPECIES_SANDILE, 17, 17
    Encounter SPECIES_DARUMAKA, 17, 17
#endif
    DarkGrassEncounters
    ShakingGrassEncounters
    SurfEncounters
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    Encounter SPECIES_FRILLISH, 5, 15
    RipplingSurfEncounters
    Encounter SPECIES_ALOMOMOLA, 5, 20
    Encounter SPECIES_ALOMOMOLA, 5, 20
    Encounter SPECIES_ALOMOMOLA, 5, 20
    Encounter SPECIES_JELLICENT, 5, 20
    Encounter SPECIES_JELLICENT, 5, 20
    FishingEncounters
    Encounter SPECIES_FINNEON, 40, 60
    Encounter SPECIES_CLAMPERL, 40, 60
    Encounter SPECIES_FINNEON, 50, 70
    Encounter SPECIES_QWILFISH, 50, 70
    Encounter SPECIES_QWILFISH, 50, 70
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_LUMINEON, 40, 60
    Encounter SPECIES_QWILFISH, 40, 60
    Encounter SPECIES_RELICANTH, 50, 70
    Encounter SPECIES_HUNTAIL, 50, 70
    Encounter SPECIES_HUNTAIL, 50, 70
#else
    Encounter SPECIES_LUMINEON, 40, 60
    Encounter SPECIES_QWILFISH, 40, 60
    Encounter SPECIES_RELICANTH, 50, 70
    Encounter SPECIES_GOREBYSS, 50, 70
    Encounter SPECIES_GOREBYSS, 50, 70
#endif
    EncountersEnd
