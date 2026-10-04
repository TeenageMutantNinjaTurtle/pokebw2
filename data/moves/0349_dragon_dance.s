#include "asm/move_data.inc"

// MOVE_DRAGON_DANCE
    Type TYPE_DRAGON
    Quality 2
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_ATK_SPD_UP
    DrainHeal 0, 0
    Target 7
    StatChanges stat1=BATTLEMON_ATTACK_STAGE, stages1=1, chance1=0, stat2=BATTLEMON_SPEED_STAGE, stages2=1, chance2=0
    Marker
    Flags 0x0020
