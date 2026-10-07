#include "asm/move_data.inc"

// MOVE_AMNESIA
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_STAT_CHANGE
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SP_DEF_UP_2
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges stat1=BATTLEMON_SP_DEFENSE_STAGE, stages1=2, chance1=0
    Marker
    Flags MOVE_FLAG_SNATCH
