#include "asm/move_data.inc"

// MOVE_BLAZE_KICK
    Type TYPE_FIRE
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 85
    Accuracy 90
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BURN, 10, 1, 0, 0
    CritStage 1
    FlinchChance 0
    Effect BATTLE_EFFECT_HIGH_CRITICAL_BURN_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
