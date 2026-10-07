#include "asm/move_data.inc"

// MOVE_HYPNOSIS
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 60
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_SLEEP, 0, 2, 2, 4
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_STATUS_SLEEP
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_REFLECTABLE | MOVE_FLAG_MIRROR_MOVE
