#include "asm/move_data.inc"

// MOVE_CHARGE_BEAM
    Type TYPE_ELECTRIC
    Quality 7
    Category MOVE_CATEGORY_SPECIAL
    Power 50
    Accuracy 90
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_RAISE_SP_ATK_HIT
    DrainHeal 0, 0
    Target 0
    StatChanges stat1=BATTLEMON_SP_ATTACK_STAGE, stages1=1, chance1=70
    Marker
    Flags 0x0048
