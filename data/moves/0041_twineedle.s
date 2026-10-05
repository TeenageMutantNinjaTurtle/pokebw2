#include "asm/move_data.inc"

// MOVE_TWINEEDLE
    Type TYPE_BUG
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 25
    Accuracy 100
    PP 20
    Priority 0
    Hits 2, 2
    Inflicts CONDITION_POISON, 20, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_POISON_MULTI_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0048
