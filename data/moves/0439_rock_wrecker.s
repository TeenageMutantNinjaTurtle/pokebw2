#include "asm/move_data.inc"

// MOVE_ROCK_WRECKER
    Type TYPE_ROCK
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 150
    Accuracy 90
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_RECHARGE_AFTER
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_RECHARGE | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
