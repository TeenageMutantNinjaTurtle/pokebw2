#include "asm/move_data.inc"

// MOVE_RAZOR_WIND
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_SPECIAL
    Power 80
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 1
    FlinchChance 0
    Effect BATTLE_EFFECT_CHARGE_TURN_HIGH_CRIT
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges
    Marker
    Flags MOVE_FLAG_CHARGE | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
