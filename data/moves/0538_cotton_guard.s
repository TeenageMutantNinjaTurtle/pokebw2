#include "asm/move_data.inc"

// MOVE_COTTON_GUARD
    Type TYPE_GRASS
    Quality MOVE_QUALITY_STAT_CHANGE
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_COTTON_GUARD
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges stat1=BATTLEMON_DEFENSE_STAGE, stages1=3, chance1=0
    Marker
    Flags MOVE_FLAG_SNATCH
