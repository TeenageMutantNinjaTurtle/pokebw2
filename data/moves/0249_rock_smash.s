#include "asm/move_data.inc"

// MOVE_ROCK_SMASH
    Type TYPE_FIGHTING
    Quality 6
    Category MOVE_CATEGORY_PHYSICAL
    Power 40
    Accuracy 100
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_DEFENSE_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_DEFENSE_STAGE, stages1=-1, chance1=50
    Marker
    Flags 0x0049
