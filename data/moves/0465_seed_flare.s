#include "asm/move_data.inc"

// MOVE_SEED_FLARE
    Type TYPE_GRASS
    Quality 6
    Category MOVE_CATEGORY_SPECIAL
    Power 120
    Accuracy 85
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SP_DEF_2_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_SP_DEFENSE_STAGE, stages1=-2, chance1=40
    Marker
    Flags 0x0048
