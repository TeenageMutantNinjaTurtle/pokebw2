#include "asm/encounters.inc"

// Castelia City

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=0, rippling_surf=0, fishing=0, rippling_fishing=0
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_RATTATA, 15, 15
    Encounter SPECIES_COTTONEE, 15, 15
    Encounter SPECIES_PIDOVE, 15, 15
    Encounter SPECIES_BUNEARY, 15, 15
    Encounter SPECIES_RATTATA, 16, 16
    Encounter SPECIES_COTTONEE, 16, 16
    Encounter SPECIES_PIDOVE, 16, 16
    Encounter SPECIES_BUNEARY, 16, 16
    Encounter SPECIES_COTTONEE, 17, 17
    Encounter SPECIES_EEVEE, 18, 18
    Encounter SPECIES_COTTONEE, 17, 17
    Encounter SPECIES_EEVEE, 18, 18
#else
    Encounter SPECIES_RATTATA, 15, 15
    Encounter SPECIES_PETILIL, 15, 15
    Encounter SPECIES_PIDOVE, 15, 15
    Encounter SPECIES_SKITTY, 15, 15
    Encounter SPECIES_RATTATA, 16, 16
    Encounter SPECIES_PETILIL, 16, 16
    Encounter SPECIES_PIDOVE, 16, 16
    Encounter SPECIES_SKITTY, 16, 16
    Encounter SPECIES_PETILIL, 17, 17
    Encounter SPECIES_EEVEE, 18, 18
    Encounter SPECIES_PETILIL, 17, 17
    Encounter SPECIES_EEVEE, 18, 18
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_RATTATA, 16, 16
    Encounter SPECIES_COTTONEE, 16, 16
    Encounter SPECIES_PIDOVE, 16, 16
    Encounter SPECIES_BUNEARY, 16, 16
    Encounter SPECIES_RATTATA, 17, 17
    Encounter SPECIES_COTTONEE, 17, 17
    Encounter SPECIES_PIDOVE, 17, 17
    Encounter SPECIES_BUNEARY, 17, 17
    Encounter SPECIES_COTTONEE, 18, 18
    Encounter SPECIES_EEVEE, 19, 19
    Encounter SPECIES_COTTONEE, 18, 18
    Encounter SPECIES_EEVEE, 19, 19
#else
    Encounter SPECIES_RATTATA, 16, 16
    Encounter SPECIES_PETILIL, 16, 16
    Encounter SPECIES_PIDOVE, 16, 16
    Encounter SPECIES_SKITTY, 16, 16
    Encounter SPECIES_RATTATA, 17, 17
    Encounter SPECIES_PETILIL, 17, 17
    Encounter SPECIES_PIDOVE, 17, 17
    Encounter SPECIES_SKITTY, 17, 17
    Encounter SPECIES_PETILIL, 18, 18
    Encounter SPECIES_EEVEE, 19, 19
    Encounter SPECIES_PETILIL, 18, 18
    Encounter SPECIES_EEVEE, 19, 19
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 15, 15
    Encounter SPECIES_AUDINO, 15, 15
    Encounter SPECIES_AUDINO, 16, 16
    Encounter SPECIES_AUDINO, 16, 16
    Encounter SPECIES_AUDINO, 17, 17
    Encounter SPECIES_AUDINO, 17, 17
    Encounter SPECIES_AUDINO, 18, 18
    Encounter SPECIES_AUDINO, 18, 18
    Encounter SPECIES_LOPUNNY, 18, 18
    Encounter SPECIES_WHIMSICOTT, 18, 18
    Encounter SPECIES_LOPUNNY, 18, 18
    Encounter SPECIES_WHIMSICOTT, 18, 18
#else
    Encounter SPECIES_AUDINO, 15, 15
    Encounter SPECIES_AUDINO, 15, 15
    Encounter SPECIES_AUDINO, 16, 16
    Encounter SPECIES_AUDINO, 16, 16
    Encounter SPECIES_AUDINO, 17, 17
    Encounter SPECIES_AUDINO, 17, 17
    Encounter SPECIES_AUDINO, 18, 18
    Encounter SPECIES_AUDINO, 18, 18
    Encounter SPECIES_DELCATTY, 18, 18
    Encounter SPECIES_LILLIGANT, 18, 18
    Encounter SPECIES_DELCATTY, 18, 18
    Encounter SPECIES_LILLIGANT, 18, 18
#endif
    SurfEncounters
    RipplingSurfEncounters
    FishingEncounters
    RipplingFishingEncounters
    EncountersEnd
