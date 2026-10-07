#include "asm/move_data.inc"

// MOVE_INGRAIN
    Type TYPE_GRASS
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_INGRAIN, 0, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_GROUND_TRAP_USER_CONTINUOUS_HEAL
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges
    Marker
    Flags MOVE_FLAG_SNATCH
