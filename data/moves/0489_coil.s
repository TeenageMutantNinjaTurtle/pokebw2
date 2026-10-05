#include "asm/move_data.inc"

// MOVE_COIL
    Type TYPE_POISON
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
    Effect BATTLE_EFFECT_COIL
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges stat1=BATTLEMON_ATTACK_STAGE, stages1=1, chance1=0, stat2=BATTLEMON_DEFENSE_STAGE, stages2=1, chance2=0, stat3=BATTLEMON_ACCURACY_STAGE, stages3=1, chance3=0
    Marker
    Flags MOVE_FLAG_SNATCH
