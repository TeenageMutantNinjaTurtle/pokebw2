#include "asm/move_data.inc"

// MOVE_BOLT_STRIKE
    Type TYPE_ELECTRIC
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 130
    Accuracy 85
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 20, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_PARALYZE_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
