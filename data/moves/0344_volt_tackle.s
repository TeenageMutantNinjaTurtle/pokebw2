#include "asm/move_data.inc"

// MOVE_VOLT_TACKLE
    Type TYPE_ELECTRIC
    Quality 4
    Category MOVE_CATEGORY_PHYSICAL
    Power 120
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 10, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_RECOIL_PARALYZE_HIT
    DrainHeal -33, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0049
