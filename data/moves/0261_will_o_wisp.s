#include "asm/move_data.inc"

// MOVE_WILL_O_WISP
    Type TYPE_FIRE
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 75
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BURN, 0, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STATUS_BURN
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
