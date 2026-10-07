#include "asm/move_data.inc"

// MOVE_BUBBLE
    Type TYPE_WATER
    Quality MOVE_QUALITY_DAMAGE_LOWER_TARGET_STATS
    Category MOVE_CATEGORY_SPECIAL
    Power 20
    Accuracy 100
    PP 30
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_SPEED_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges stat1=BATTLEMON_SPEED_STAGE, stages1=-1, chance1=10
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
