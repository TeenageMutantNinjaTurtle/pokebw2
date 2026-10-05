#include "asm/move_data.inc"

// MOVE_NIGHT_DAZE
    Type TYPE_DARK
    Quality MOVE_QUALITY_DAMAGE_LOWER_TARGET_STATS
    Category MOVE_CATEGORY_SPECIAL
    Power 85
    Accuracy 95
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_LOWER_ACCURACY_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_ACCURACY_STAGE, stages1=-1, chance1=40
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
