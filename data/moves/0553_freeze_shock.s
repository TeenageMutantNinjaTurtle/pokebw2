#include "asm/move_data.inc"

// MOVE_FREEZE_SHOCK
    Type TYPE_ICE
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_PHYSICAL
    Power 140
    Accuracy 90
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_PARALYSIS, 30, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_FREEZE_SHOCK
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_CHARGE | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
