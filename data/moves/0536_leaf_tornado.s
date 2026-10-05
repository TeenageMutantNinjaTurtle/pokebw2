#include "asm/move_data.inc"

// MOVE_LEAF_TORNADO
    Type TYPE_GRASS
    Quality 6
    Category MOVE_CATEGORY_SPECIAL
    Power 65
    Accuracy 90
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_ACCURACY_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_ACCURACY_STAGE, stages1=-1, chance1=50
    Marker
    Flags 0x0048
