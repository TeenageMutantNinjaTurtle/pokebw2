#include "asm/move_data.inc"

// MOVE_RETURN
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 1
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_POWER_BASED_ON_FRIENDSHIP
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
