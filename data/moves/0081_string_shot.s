#include "asm/move_data.inc"

// MOVE_STRING_SHOT
    Type TYPE_BUG
    Quality MOVE_QUALITY_STAT_CHANGE
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 95
    PP 40
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SPEED_DOWN
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=-1, chance1=0
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
