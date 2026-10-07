#include "asm/move_data.inc"

// MOVE_COUNTER
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 1
    Accuracy 100
    PP 20
    Priority -5
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_COUNTER
    DrainHeal 0, 0
    Target MOVE_TARGET_DEPENDS
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT
