#include "asm/move_data.inc"

// MOVE_CLOSE_COMBAT
    Type TYPE_FIGHTING
    Quality 7
    Category MOVE_CATEGORY_PHYSICAL
    Power 120
    Accuracy 100
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_DEF_SPD_DOWN_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_DEFENSE_STAGE, stages1=-1, chance1=100, stat2=BATTLEMON_SP_DEFENSE_STAGE, stages2=-1, chance2=100
    Marker
    Flags 0x0049
