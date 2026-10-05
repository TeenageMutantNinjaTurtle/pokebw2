#include "asm/move_data.inc"

// MOVE_MIRACLE_EYE
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 40
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_FORESIGHT, 0, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_IGNORE_EVATION_REMOVE_DARK_IMMUNE
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_BYPASS_SUBSTITUTE
