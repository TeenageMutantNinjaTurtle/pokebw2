#include "asm/move_data.inc"

// MOVE_FLATTER
    Type TYPE_DARK
    Quality MOVE_QUALITY_INFLICT_STAT_CHANGE
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 0, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SP_ATK_UP_CAUSE_CONFUSION
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=1, chance1=0
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
