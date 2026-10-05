#include "asm/move_data.inc"

// MOVE_GRASS_PLEDGE
    Type TYPE_GRASS
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_SPECIAL
    Power 50
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_GRASS_PLEDGE
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
