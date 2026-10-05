#include "asm/move_data.inc"

// MOVE_MUD_SHOT
    Type TYPE_GROUND
    Quality 6
    Category MOVE_CATEGORY_SPECIAL
    Power 55
    Accuracy 95
    PP 15
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SPEED_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=-1, chance1=100
    Marker
    Flags 0x0048
