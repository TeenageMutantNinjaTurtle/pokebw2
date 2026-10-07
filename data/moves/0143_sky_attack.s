#include "asm/move_data.inc"

// MOVE_SKY_ATTACK
    Type TYPE_FLYING
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 140
    Accuracy 90
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 1
    FlinchChance 30
    Effect BATTLE_EFFECT_CHARGE_TURN_HIGH_CRIT_FLINCH
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CHARGE | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_DISTANT
