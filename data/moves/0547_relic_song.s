#include "asm/move_data.inc"

// MOVE_RELIC_SONG
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_DAMAGE_INFLICT
    Category MOVE_CATEGORY_SPECIAL
    Power 75
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts CONDITION_SLEEP, 10, 2, 2, 4
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_RELIC_SONG
    DrainHeal 0, 0
    Target MOVE_TARGET_ADJACENT_FOES
    StatChanges
    Marker
    Flags MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE | MOVE_FLAG_SOUND
