#include "asm/move_data.inc"

// MOVE_SMACK_DOWN
    Type TYPE_ROCK
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 50
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 65535, 100, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SMACK_DOWN
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
