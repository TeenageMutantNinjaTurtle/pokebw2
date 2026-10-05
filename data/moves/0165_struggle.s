#include "asm/move_data.inc"

// MOVE_STRUGGLE
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 50
    Accuracy 101
    PP 1
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STRUGGLE
    DrainHeal 0, -25
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT
