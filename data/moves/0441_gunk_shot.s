#include "asm/move_data.inc"

// MOVE_GUNK_SHOT
    Type TYPE_POISON
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 120
    Accuracy 70
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_POISON, 30, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_POISON_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
