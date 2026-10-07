#include "asm/move_data.inc"

// MOVE_THUNDER
    Type TYPE_ELECTRIC
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 120
    Accuracy 70
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 30, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_THUNDER
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
