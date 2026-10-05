#include "asm/move_data.inc"

// MOVE_SHOCK_WAVE
    Type TYPE_ELECTRIC
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_SPECIAL
    Power 60
    Accuracy 101
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BYPASS_ACCURACY
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
