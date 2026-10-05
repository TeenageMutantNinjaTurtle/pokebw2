#include "asm/encounters.inc"

// Route 22

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
    Encounter SPECIES_AMOONGUSS, 39, 39
    Encounter SPECIES_MIENFOO, 39, 39
    Encounter SPECIES_PELIPPER, 40, 40
    Encounter SPECIES_GOLDUCK, 40, 40
    Encounter SPECIES_LUNATONE, 41, 41
    Encounter SPECIES_SOLROCK, 41, 41
    Encounter SPECIES_MARILL, 40, 40
    Encounter SPECIES_MARILL, 42, 42
    Encounter SPECIES_MIENFOO, 42, 42
    Encounter SPECIES_DELIBIRD, 39, 39
    Encounter SPECIES_MIENFOO, 42, 42
    Encounter SPECIES_DELIBIRD, 39, 39
    DarkGrassEncounters
    Encounter SPECIES_AMOONGUSS, 44, 44
    Encounter SPECIES_MIENFOO, 44, 44
    Encounter SPECIES_PELIPPER, 45, 45
    Encounter SPECIES_GOLDUCK, 45, 45
    Encounter SPECIES_LUNATONE, 46, 46
    Encounter SPECIES_SOLROCK, 46, 46
    Encounter SPECIES_MARILL, 45, 45
    Encounter SPECIES_MARILL, 47, 47
    Encounter SPECIES_MIENFOO, 47, 47
    Encounter SPECIES_DELIBIRD, 44, 44
    Encounter SPECIES_MIENFOO, 47, 47
    Encounter SPECIES_DELIBIRD, 44, 44
    ShakingGrassEncounters
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_AUDINO, 39, 39
    Encounter SPECIES_EMOLGA, 40, 40
    Encounter SPECIES_AUDINO, 40, 40
    Encounter SPECIES_AUDINO, 41, 41
    Encounter SPECIES_AUDINO, 41, 41
    Encounter SPECIES_AUDINO, 42, 42
    Encounter SPECIES_AUDINO, 42, 42
    Encounter SPECIES_AUDINO, 42, 42
    Encounter SPECIES_AZUMARILL, 42, 42
    Encounter SPECIES_AUDINO, 42, 42
    Encounter SPECIES_AZUMARILL, 42, 42
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 15, 40
    Encounter SPECIES_MARILL, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40
#else
    Encounter SPECIES_BASCULIN, 15, 40, form=1
    Encounter SPECIES_MARILL, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40, form=1
    Encounter SPECIES_BASCULIN, 15, 40, form=1
    Encounter SPECIES_BASCULIN, 15, 40, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40, form=1
    Encounter SPECIES_BASCULIN, 25, 45, form=1
    Encounter SPECIES_AZUMARILL, 25, 45
    Encounter SPECIES_AZUMARILL, 25, 45
#else
    Encounter SPECIES_MARILL, 15, 40
    Encounter SPECIES_BASCULIN, 15, 40
    Encounter SPECIES_BASCULIN, 25, 45
    Encounter SPECIES_AZUMARILL, 25, 45
    Encounter SPECIES_AZUMARILL, 25, 45
#endif
    FishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
#else
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
    Encounter SPECIES_GOLDEEN, 50, 70
#endif
    RipplingFishingEncounters
#ifdef BLACK2
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60, form=1
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
#else
    Encounter SPECIES_GOLDEEN, 40, 60
    Encounter SPECIES_BASCULIN, 40, 60
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
    Encounter SPECIES_SEAKING, 50, 70
#endif
    EncountersEnd
