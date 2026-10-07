#include "asm/move_data.inc"

// MOVE_HURRICANE
    Type TYPE_FLYING
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 120
    Accuracy 70
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 30, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_HURRICANE
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_DISTANT
