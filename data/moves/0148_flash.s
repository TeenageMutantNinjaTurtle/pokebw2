#include "asm/move_data.inc"

// MOVE_FLASH
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_STAT_CHANGE
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_ACC_DOWN
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_ACCURACY_STAGE, stages1=-1, chance1=0
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
