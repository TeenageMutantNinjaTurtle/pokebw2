#include "asm/move_data.inc"

// MOVE_BIND
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 15
    Accuracy 85
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_BIND, 100, 4, 5, 6
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BIND_HIT
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
