#include "asm/encounters.inc"

// Route 23

    EncounterRates grass=1, dark_grass=3, shaking_grass=1, surf=10, rippling_surf=1, fishing=50, rippling_fishing=1
    GrassEncounters
#ifdef BLACK2
    Encounter SPECIES_BOUFFALANT, 49, 49
    Encounter SPECIES_SAWK, 48, 48
    Encounter SPECIES_GLIGAR, 49, 49
    Encounter SPECIES_MIENFOO, 48, 48
    Encounter SPECIES_AMOONGUSS, 49, 49
    Encounter SPECIES_GOLDUCK, 50, 50
    Encounter SPECIES_MIENFOO, 48, 48
    Encounter SPECIES_SAWK, 49, 49
    Encounter SPECIES_VULLABY, 47, 47
    Encounter SPECIES_BOUFFALANT, 51, 51
    Encounter SPECIES_VULLABY, 47, 47
    Encounter SPECIES_BOUFFALANT, 51, 51
#else
    Encounter SPECIES_BOUFFALANT, 49, 49
    Encounter SPECIES_THROH, 48, 48
    Encounter SPECIES_GLIGAR, 49, 49
    Encounter SPECIES_MIENFOO, 48, 48
    Encounter SPECIES_AMOONGUSS, 49, 49
    Encounter SPECIES_GOLDUCK, 50, 50
    Encounter SPECIES_MIENFOO, 48, 48
    Encounter SPECIES_THROH, 49, 49
    Encounter SPECIES_RUFFLET, 47, 47
    Encounter SPECIES_BOUFFALANT, 51, 51
    Encounter SPECIES_RUFFLET, 47, 47
    Encounter SPECIES_BOUFFALANT, 51, 51
#endif
    DarkGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_BOUFFALANT, 54, 54
    Encounter SPECIES_SAWK, 53, 53
    Encounter SPECIES_GLIGAR, 54, 54
    Encounter SPECIES_MIENSHAO, 53, 53
    Encounter SPECIES_AMOONGUSS, 54, 54
    Encounter SPECIES_GOLDUCK, 55, 55
    Encounter SPECIES_MIENSHAO, 53, 53
    Encounter SPECIES_SAWK, 54, 54
    Encounter SPECIES_VULLABY, 52, 52
    Encounter SPECIES_BOUFFALANT, 56, 56
    Encounter SPECIES_VULLABY, 52, 52
    Encounter SPECIES_BOUFFALANT, 56, 56
#else
    Encounter SPECIES_BOUFFALANT, 54, 54
    Encounter SPECIES_THROH, 53, 53
    Encounter SPECIES_GLIGAR, 54, 54
    Encounter SPECIES_MIENSHAO, 53, 53
    Encounter SPECIES_AMOONGUSS, 54, 54
    Encounter SPECIES_GOLDUCK, 55, 55
    Encounter SPECIES_MIENSHAO, 53, 53
    Encounter SPECIES_THROH, 54, 54
    Encounter SPECIES_RUFFLET, 52, 52
    Encounter SPECIES_BOUFFALANT, 56, 56
    Encounter SPECIES_RUFFLET, 52, 52
    Encounter SPECIES_BOUFFALANT, 56, 56
#endif
    ShakingGrassEncounters
#ifdef BLACK2
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_EMOLGA, 49, 49
    Encounter SPECIES_AUDINO, 49, 49
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 51, 51
    Encounter SPECIES_AUDINO, 51, 51
    Encounter SPECIES_GLISCOR, 51, 51
    Encounter SPECIES_THROH, 51, 51
    Encounter SPECIES_GLISCOR, 51, 51
    Encounter SPECIES_THROH, 51, 51
#else
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_AUDINO, 48, 48
    Encounter SPECIES_EMOLGA, 49, 49
    Encounter SPECIES_AUDINO, 49, 49
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 50, 50
    Encounter SPECIES_AUDINO, 51, 51
    Encounter SPECIES_AUDINO, 51, 51
    Encounter SPECIES_GLISCOR, 51, 51
    Encounter SPECIES_SAWK, 51, 51
    Encounter SPECIES_GLISCOR, 51, 51
    Encounter SPECIES_SAWK, 51, 51
#endif
    SurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BASCULIN, 40, 55
    Encounter SPECIES_BUIZEL, 40, 55
    Encounter SPECIES_BASCULIN, 45, 55
    Encounter SPECIES_BASCULIN, 45, 55
    Encounter SPECIES_BASCULIN, 45, 55
#else
    Encounter SPECIES_BASCULIN, 40, 55, form=1
    Encounter SPECIES_BUIZEL, 40, 55
    Encounter SPECIES_BASCULIN, 45, 55, form=1
    Encounter SPECIES_BASCULIN, 45, 55, form=1
    Encounter SPECIES_BASCULIN, 45, 55, form=1
#endif
    RipplingSurfEncounters
#ifdef BLACK2
    Encounter SPECIES_BUIZEL, 40, 55
    Encounter SPECIES_BASCULIN, 40, 55, form=1
    Encounter SPECIES_FLOATZEL, 45, 55
    Encounter SPECIES_FLOATZEL, 45, 55
    Encounter SPECIES_FLOATZEL, 45, 55
#else
    Encounter SPECIES_BUIZEL, 40, 55
    Encounter SPECIES_BASCULIN, 40, 55
    Encounter SPECIES_FLOATZEL, 45, 55
    Encounter SPECIES_FLOATZEL, 45, 55
    Encounter SPECIES_FLOATZEL, 45, 55
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
