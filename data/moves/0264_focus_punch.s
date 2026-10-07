#include "asm/move_data.inc"

// MOVE_FOCUS_PUNCH
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 150
    Accuracy 100
    PP 20
    Priority -3
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_HIT_LAST_WHIFF_IF_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_PUNCH
