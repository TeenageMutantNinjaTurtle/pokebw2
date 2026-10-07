#include "asm/move_data.inc"

// MOVE_TEETER_DANCE
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 0, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CONFUSE_ALL
    DrainHeal 0, 0
    Target MOVE_TARGET_ALL_ADJACENT
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
