#include "asm/move_data.inc"

// MOVE_HAMMER_ARM
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE_USER_STAT_CHANGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 100
    Accuracy 90
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SPEED_DOWN_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=-1, chance1=100
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_PUNCH
