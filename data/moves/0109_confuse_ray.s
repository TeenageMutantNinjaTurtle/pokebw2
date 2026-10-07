#include "asm/move_data.inc"

// MOVE_CONFUSE_RAY
    Type TYPE_GHOST
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 0, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STATUS_CONFUSE
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
