#include "asm/move_data.inc"

// MOVE_DRAGON_BREATH
    Type TYPE_DRAGON
    Quality 4
    Category MOVE_CATEGORY_SPECIAL
    Power 60
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 30, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_PARALYZE_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges
    Marker
    Flags 0x0048
