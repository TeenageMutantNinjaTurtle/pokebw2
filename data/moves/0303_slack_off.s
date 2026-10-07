#include "asm/move_data.inc"

// MOVE_SLACK_OFF
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_HEAL
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_RESTORE_HALF_HP
    DrainHeal 0, 50
    Target MOVE_TARGET_USER
    StatChanges
    Marker
    Flags MOVE_FLAG_SNATCH | MOVE_FLAG_HEAL
