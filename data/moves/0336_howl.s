#include "asm/move_data.inc"

// MOVE_HOWL
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_STAT_CHANGE
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 40
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_ATK_UP
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges stat1=BATTLEMON_ATTACK_STAGE, stages1=1, chance1=0
    Marker
    Flags MOVE_FLAG_SNATCH
