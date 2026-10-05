#include "asm/move_data.inc"

// MOVE_HEAT_WAVE
    Type TYPE_FIRE
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 100
    Accuracy 90
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BURN, 10, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BURN_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
