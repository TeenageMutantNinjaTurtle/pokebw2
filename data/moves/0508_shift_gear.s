#include "asm/move_data.inc"

// MOVE_SHIFT_GEAR
    Type TYPE_STEEL
    Quality 2
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SHIFT_GEAR
    DrainHeal 0, 0
    Target 7
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=2, chance1=0, stat2=BATTLEMON_ATTACK_STAGE, stages2=1, chance2=0
    Marker
    Flags 0x0020
