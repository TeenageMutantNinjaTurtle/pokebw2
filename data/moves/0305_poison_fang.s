#include "asm/move_data.inc"

// MOVE_POISON_FANG
    Type TYPE_POISON
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 50
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 30, 1, 15, 15
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BADLY_POISON_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0049
