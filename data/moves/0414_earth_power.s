#include "asm/move_data.inc"

// MOVE_EARTH_POWER
    Type TYPE_GROUND
    Quality 6
    Category MOVE_CATEGORY_SPECIAL
    Power 90
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SP_DEF_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_SP_DEFENSE_STAGE, stages1=-1, chance1=10
    Marker
    Flags 0x0048
