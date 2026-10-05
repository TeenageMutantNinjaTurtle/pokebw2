#include "asm/move_data.inc"

// MOVE_FIRE_SPIN
    Type TYPE_FIRE
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
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
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
