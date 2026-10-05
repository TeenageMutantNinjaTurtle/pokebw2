#include "asm/move_data.inc"

// MOVE_SNARL
    Type TYPE_DARK
    Quality MOVE_QUALITY_DAMAGE_LOWER_TARGET_STATS
    Category MOVE_CATEGORY_SPECIAL
    Power 55
    Accuracy 95
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SP_ATK_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=-1, chance1=100
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_SOUND
