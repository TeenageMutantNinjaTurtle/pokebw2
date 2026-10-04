#include "asm/move_data.inc"

// MOVE_SAND_TOMB
    Type TYPE_GROUND
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 35
    Accuracy 85
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BIND, 100, 4, 5, 6
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BIND_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0048
