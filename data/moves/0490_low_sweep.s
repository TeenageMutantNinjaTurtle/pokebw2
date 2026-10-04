#include "asm/move_data.inc"

// MOVE_LOW_SWEEP
    Type TYPE_FIGHTING
    Quality 6
    Category MOVE_CATEGORY_PHYSICAL
    Power 60
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_SPEED_DOWN
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=-1, chance1=100
    Marker
    Flags 0x0049
