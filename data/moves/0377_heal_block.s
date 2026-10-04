#include "asm/move_data.inc"

// MOVE_HEAL_BLOCK
    Type TYPE_PSYCHIC
    Quality 1
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_HEAL_BLOCK, 0, 2, 5, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_PREVENT_HEALING
    DrainHeal 0, 0
    Target 5
    StatChanges
    Marker
    Flags 0x0058
