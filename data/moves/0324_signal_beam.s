#include "asm/move_data.inc"

// MOVE_SIGNAL_BEAM
    Type TYPE_BUG
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 75
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 10, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CONFUSE_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
