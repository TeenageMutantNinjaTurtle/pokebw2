#include "asm/move_data.inc"

// MOVE_DEFOG
    Type TYPE_FLYING
    Quality MOVE_QUALITY_SPECIAL
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_REMOVE_HAZARDS_SCREENS_EVA_DOWN
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_BYPASS_SUBSTITUTE
