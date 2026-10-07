#include "asm/encounters.inc"

// Abundant Shrine

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_SWABLU, 33, 33
    Encounter SPECIES_COTTONEE, 33, 33
    Encounter SPECIES_VULPIX, 34, 34
    Encounter SPECIES_BRONZOR, 32, 32
    Encounter SPECIES_MARILL, 34, 34
    Encounter SPECIES_GOLDUCK, 34, 34
    Encounter SPECIES_COTTONEE, 35, 35
    Encounter SPECIES_BRONZOR, 32, 32
    Encounter SPECIES_COTTONEE, 35, 35
    Encounter SPECIES_ALTARIA, 36, 36
    Encounter SPECIES_COTTONEE, 35, 35
    Encounter SPECIES_ALTARIA, 36, 36
#else
    Encounter SPECIES_SWABLU, 33, 33
    Encounter SPECIES_PETILIL, 33, 33
    Encounter SPECIES_VULPIX, 34, 34
    Encounter SPECIES_BRONZOR, 32, 32
    Encounter SPECIES_MARILL, 34, 34
    Encounter SPECIES_GOLDUCK, 34, 34
    Encounter SPECIES_PETILIL, 35, 35
    Encounter SPECIES_BRONZOR, 32, 32
    Encounter SPECIES_PETILIL, 35, 35
    Encounter SPECIES_ALTARIA, 36, 36
    Encounter SPECIES_PETILIL, 35, 35
    Encounter SPECIES_ALTARIA, 36, 36
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_VULPIX, 37, 37
    Encounter SPECIES_COTTONEE, 37, 37
    Encounter SPECIES_ALTARIA, 38, 38
    Encounter SPECIES_COTTONEE, 39, 39
    Encounter SPECIES_MARILL, 38, 38
    Encounter SPECIES_GOLDUCK, 38, 38
    Encounter SPECIES_BRONZONG, 36, 36
    Encounter SPECIES_BRONZONG, 36, 36
    Encounter SPECIES_COTTONEE, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
    Encounter SPECIES_COTTONEE, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
#else
    Encounter SPECIES_VULPIX, 37, 37
    Encounter SPECIES_PETILIL, 37, 37
    Encounter SPECIES_ALTARIA, 38, 38
    Encounter SPECIES_PETILIL, 39, 39
    Encounter SPECIES_MARILL, 38, 38
    Encounter SPECIES_GOLDUCK, 38, 38
    Encounter SPECIES_BRONZONG, 36, 36
    Encounter SPECIES_BRONZONG, 36, 36
    Encounter SPECIES_PETILIL, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
    Encounter SPECIES_PETILIL, 39, 39
    Encounter SPECIES_ALTARIA, 40, 40
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_EMOLGA, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_WHIMSICOTT, 36, 36
    Encounter SPECIES_NINETALES, 36, 36
    Encounter SPECIES_WHIMSICOTT, 36, 36
    Encounter SPECIES_NINETALES, 36, 36
#else
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_AUDINO, 33, 33
    Encounter SPECIES_EMOLGA, 34, 34
    Encounter SPECIES_AUDINO, 34, 34
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 35, 35
    Encounter SPECIES_AUDINO, 36, 36
    Encounter SPECIES_AZUMARILL, 36, 36
    Encounter SPECIES_LILLIGANT, 36, 36
    Encounter SPECIES_NINETALES, 36, 36
    Encounter SPECIES_LILLIGANT, 36, 36
    Encounter SPECIES_NINETALES, 36, 36
#endif
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_BASCULIN, 30, 40
#else
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40, form=1
    Encounter SPECIES_BASCULIN, 30, 40, form=1
    Encounter SPECIES_AZUMARILL, 30, 40
    Encounter SPECIES_AZUMARILL, 30, 40
#else
    Encounter SPECIES_MARILL, 25, 40
    Encounter SPECIES_BASCULIN, 25, 40
    Encounter SPECIES_BASCULIN, 30, 40
    Encounter SPECIES_AZUMARILL, 30, 40
    Encounter SPECIES_AZUMARILL, 30, 40
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
