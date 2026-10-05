#include "asm/move_data.inc"

// MOVE_PIN_MISSILE
    Type TYPE_BUG
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 14
    Accuracy 85
    PP 20
    Priority 0
    Hits 2, 5
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_MULTI_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
