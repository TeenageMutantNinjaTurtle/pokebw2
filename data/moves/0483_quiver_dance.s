#include "asm/move_data.inc"

// MOVE_QUIVER_DANCE
    Type TYPE_BUG
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
    Effect BATTLE_EFFECT_QUIVER_DANCE
    DrainHeal 0, 0
    Target 7
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=1, chance1=0, stat2=BATTLEMON_SP_DEFENSE_STAGE, stages2=1, chance2=0, stat3=BATTLEMON_SPEED_STAGE, stages3=1, chance3=0
    Marker
    Flags 0x0020
