#include "asm/move_data.inc"

// MOVE_HELPING_HAND
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_SPECIAL
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 20
    Priority 5
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BOOST_ALLY_POWER_BY_50_PERCENT
    DrainHeal 0, 0
    Target MOVE_TARGET_ALLY
    StatChanges
    Marker
    Flags MOVE_FLAG_BYPASS_SUBSTITUTE
