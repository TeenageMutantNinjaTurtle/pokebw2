#include "asm/move_data.inc"

// MOVE_ROCK_SMASH
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE_LOWER_TARGET_STATS
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
    Target MOVE_TARGET_SELECTED
    StatChanges stat1=BATTLEMON_DEFENSE_STAGE, stages1=-1, chance1=50
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
