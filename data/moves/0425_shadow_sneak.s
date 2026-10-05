#include "asm/move_data.inc"

// MOVE_SHADOW_SNEAK
    Type TYPE_GHOST
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 40
    Accuracy 100
    PP 30
    Priority 1
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_PRIORITY_1
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
