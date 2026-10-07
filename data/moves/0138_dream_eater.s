#include "asm/move_data.inc"

// MOVE_DREAM_EATER
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_DAMAGE_DRAIN
    Category MOVE_CATEGORY_SPECIAL
    Power 100
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_RECOVER_DAMAGE_SLEEP
    DrainHeal 50, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
