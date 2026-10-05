#include "asm/move_data.inc"

// MOVE_POISON_STING
    Type TYPE_POISON
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 15
    Accuracy 100
    PP 35
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 30, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_POISON_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0048
