#include "asm/move_data.inc"

// MOVE_MAGNET_RISE
    Type TYPE_ELECTRIC
    Quality MOVE_QUALITY_SPECIAL
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 5, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_GIVE_GROUND_IMMUNITY
    DrainHeal 0, 0
    Target MOVE_TARGET_USER
    StatChanges
    Marker
    Flags MOVE_FLAG_SNATCH | MOVE_FLAG_GRAVITY
