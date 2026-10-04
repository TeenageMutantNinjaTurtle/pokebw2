#include "asm/move_data.inc"

// MOVE_TOXIC
    Type TYPE_POISON
    Quality 1
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 90
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 0, 1, 15, 15
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STATUS_BADLY_POISON
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0058
