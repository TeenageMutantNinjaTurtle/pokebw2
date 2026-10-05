#include "asm/move_data.inc"

// MOVE_FIRE_PUNCH
    Type TYPE_FIRE
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 75
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BURN, 10, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BURN_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x00c9
