#include "asm/move_data.inc"

// MOVE_DYNAMIC_PUNCH
    Type TYPE_FIGHTING
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 100
    Accuracy 50
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 100, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CONFUSE_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_PUNCH
