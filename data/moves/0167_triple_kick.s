#include "asm/move_data.inc"

// MOVE_TRIPLE_KICK
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 10
    Accuracy 90
    PP 10
    Priority 0
    Hits 3, 3
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_HIT_THREE_TIMES
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
