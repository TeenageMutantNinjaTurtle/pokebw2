#include "asm/move_data.inc"

// MOVE_SLUDGE
    Type TYPE_POISON
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 65
    Accuracy 100
    PP 20
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
