#include "asm/move_data.inc"

// MOVE_CROSS_POISON
    Type TYPE_POISON
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 70
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 10, 1, 0, 0
    CritStage 1
    FlinchChance 0
    Effect BATTLE_EFFECT_HIGH_CRITICAL_POISON_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0049
