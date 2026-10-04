#include "asm/move_data.inc"

// MOVE_SAND_ATTACK
    Type TYPE_GROUND
    Quality 2
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_ACC_DOWN
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_ACCURACY_STAGE, stages1=-1, chance1=0
    Marker
    Flags 0x0058
