#include "asm/move_data.inc"

// MOVE_FORCE_PALM
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 60
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 30, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_PARALYZE_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
