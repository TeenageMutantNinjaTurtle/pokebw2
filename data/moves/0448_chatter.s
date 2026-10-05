#include "asm/move_data.inc"

// MOVE_CHATTER
    Type TYPE_FLYING
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 60
    Accuracy 100
    PP 20
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_CONFUSION, 0, 2, 2, 5
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CHATTER
    DrainHeal 0, 0
    Target MOVE_TARGET_SELECTED
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_SOUND | MOVE_FLAG_DISTANT
