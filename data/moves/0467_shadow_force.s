#include "asm/move_data.inc"

// MOVE_SHADOW_FORCE
    Type TYPE_GHOST
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 120
    Accuracy 100
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SHADOW_FORCE
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_CHARGE | MOVE_FLAG_MIRROR_MOVE
