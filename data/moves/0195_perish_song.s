#include "asm/move_data.inc"

// MOVE_PERISH_SONG
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_INFLICT
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PERISH_SONG, 0, 2, 4, 4
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_ALL_FAINT_3_TURNS
    DrainHeal 0, 0
    Target MOVE_TARGET_ALL
    StatChanges
    Marker
    Flags MOVE_FLAG_SOUND | MOVE_FLAG_DISTANT | MOVE_FLAG_BYPASS_SUBSTITUTE
