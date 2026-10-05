#include "asm/move_data.inc"

// MOVE_BLIZZARD
    Type TYPE_ICE
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 120
    Accuracy 70
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_FREEZE, 10, 1, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_BLIZZARD
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
