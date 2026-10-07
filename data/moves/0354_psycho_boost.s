#include "asm/move_data.inc"

// MOVE_PSYCHO_BOOST
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_DAMAGE_USER_STAT_CHANGE
    Category MOVE_CATEGORY_SPECIAL
    Power 140
    Accuracy 90
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_USER_SP_ATK_DOWN_2
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=-2, chance1=100
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
