#include "asm/move_data.inc"

// MOVE_POISON_GAS
    Type TYPE_POISON
    Quality 1
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 80
    PP 40
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 0, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STATUS_POISON
    DrainHeal 0, 0
    Target 5
    StatChanges
    Marker
    Flags 0x0058
