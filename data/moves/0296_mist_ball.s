#include "asm/move_data.inc"

// MOVE_MIST_BALL
    Type TYPE_PSYCHIC
    Quality MOVE_QUALITY_DAMAGE_LOWER_TARGET_STATS
    Category MOVE_CATEGORY_SPECIAL
    Power 70
    Accuracy 100
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SP_ATK_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=-1, chance1=50
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
