#include "asm/move_data.inc"

// MOVE_WATER_PULSE
    Type TYPE_WATER
    Quality 4
    Category MOVE_CATEGORY_SPECIAL
    Power 60
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 20, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CONFUSE_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0848
