#include "asm/move_data.inc"

// MOVE_FIRE_FANG
    Type TYPE_FIRE
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 65
    Accuracy 95
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BURN, 10, 1, 0, 0
    CritStage 0
    FlinchChance 10
    Effect BATTLE_EFFECT_FLINCH_BURN_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0049
