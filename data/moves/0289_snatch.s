#include "asm/move_data.inc"

// MOVE_SNATCH
    Type TYPE_DARK
    Quality MOVE_QUALITY_SPECIAL
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 10
    Priority 4
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STEAL_STATUS_MOVE
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges
    Marker
    Flags MOVE_FLAG_BYPASS_SUBSTITUTE
