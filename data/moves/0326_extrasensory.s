#include "asm/move_data.inc"

// MOVE_EXTRASENSORY
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_SPECIAL
    Power 80
    Accuracy 100
    PP 30
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 10
    Effect BATTLE_EFFECT_FLINCH_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
