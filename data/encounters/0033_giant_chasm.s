#include "asm/encounters.inc"

// Giant Chasm

    EncounterRates grass=7, dark_grass=0, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1, flags=1
    GrassEncounters
    Encounter SPECIES_SNEASEL, 44, 44
    Encounter SPECIES_PILOSWINE, 44, 44
    Encounter SPECIES_VANILLISH, 45, 45
    Encounter SPECIES_CLEFAIRY, 44, 44
    Encounter SPECIES_LUNATONE, 46, 46
    Encounter SPECIES_SOLROCK, 46, 46
    Encounter SPECIES_CLEFAIRY, 46, 46
    Encounter SPECIES_VANILLISH, 47, 47
    Encounter SPECIES_PILOSWINE, 46, 46
    Encounter SPECIES_DELIBIRD, 47, 47
    Encounter SPECIES_PILOSWINE, 46, 46
    Encounter SPECIES_DELIBIRD, 47, 47
    DarkGrassEncounters
    ShakingGrassEncounters
    Encounter SPECIES_EXCADRILL, 44, 44
    Encounter SPECIES_EXCADRILL, 44, 44
    Encounter SPECIES_EXCADRILL, 45, 45
    Encounter SPECIES_EXCADRILL, 45, 45
    Encounter SPECIES_EXCADRILL, 46, 46
    Encounter SPECIES_EXCADRILL, 46, 46
    Encounter SPECIES_EXCADRILL, 47, 47
    Encounter SPECIES_EXCADRILL, 47, 47
    Encounter SPECIES_EXCADRILL, 47, 47
    Encounter SPECIES_EXCADRILL, 47, 47
    Encounter SPECIES_EXCADRILL, 47, 47
    Encounter SPECIES_EXCADRILL, 47, 47
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 35, 50
    Encounter SPECIES_SEEL, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
    Encounter SPECIES_BASCULIN, 40, 50
#else
    Encounter SPECIES_BASCULIN, 35, 50, form=1
    Encounter SPECIES_SEEL, 35, 50
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
    Encounter SPECIES_BASCULIN, 40, 50, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_SEEL, 35, 50
    Encounter SPECIES_BASCULIN, 35, 50, form=1
    Encounter SPECIES_DEWGONG, 40, 50
    Encounter SPECIES_DEWGONG, 40, 50
    Encounter SPECIES_DEWGONG, 40, 50
#else
    Encounter SPECIES_SEEL, 35, 50
    Encounter SPECIES_BASCULIN, 35, 50
    Encounter SPECIES_DEWGONG, 40, 50
    Encounter SPECIES_DEWGONG, 40, 50
    Encounter SPECIES_DEWGONG, 40, 50
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_POLIWAG, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
#else
    Encounter SPECIES_POLIWAG, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
    Encounter SPECIES_POLIWAG, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_POLIWHIRL, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_POLIWHIRL, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
#else
    Encounter SPECIES_POLIWHIRL, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_POLIWHIRL, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
    Encounter SPECIES_POLIWRATH, 50, 70
#endif
    EncountersEnd
