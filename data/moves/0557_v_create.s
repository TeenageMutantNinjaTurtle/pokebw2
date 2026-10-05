#include "asm/move_data.inc"

// MOVE_V_CREATE
    Type TYPE_FIRE
    Quality MOVE_QUALITY_DAMAGE_USER_STAT_CHANGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 180
    Accuracy 95
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_V_CREATE
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=-1, chance1=100, stat2=BATTLEMON_DEFENSE_STAGE, stages2=-1, chance2=100, stat3=BATTLEMON_SP_DEFENSE_STAGE, stages3=-1, chance3=100
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
