#include "asm/move_data.inc"

// MOVE_LUSTER_PURGE
    Type TYPE_PSYCHIC
    Quality 6
    Category MOVE_CATEGORY_SPECIAL
    Power 70
    Accuracy 100
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SP_DEF_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_SP_DEFENSE_STAGE, stages1=-1, chance1=50
    Marker
    Flags 0x0048
