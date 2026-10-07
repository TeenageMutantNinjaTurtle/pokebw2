#include "asm/move_data.inc"

// MOVE_POISON_POWDER
    Type TYPE_POISON
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 75
    PP 35
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 0, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STATUS_POISON
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
