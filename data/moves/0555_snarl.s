#include "asm/move_data.inc"

// MOVE_SNARL
    Type TYPE_DARK
    Quality 6
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
    Target 5
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=-1, chance1=100
    Marker
    Flags 0x0148
