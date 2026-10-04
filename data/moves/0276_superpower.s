#include "asm/move_data.inc"

// MOVE_SUPERPOWER
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
    Effect BATTLE_EFFECT_LOWER_OWN_ATK_AND_DEF
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_ATTACK_STAGE, stages1=-1, chance1=100, stat2=BATTLEMON_DEFENSE_STAGE, stages2=-1, chance2=100
    Marker
    Flags 0x0049
