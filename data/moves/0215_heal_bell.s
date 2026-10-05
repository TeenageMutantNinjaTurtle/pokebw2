#include "asm/move_data.inc"

// MOVE_HEAL_BELL
    Type TYPE_NORMAL
    Quality MOVE_QUALITY_SPECIAL
    Category MOVE_CATEGORY_STATUS
    Power 0
    Accuracy 101
    PP 5
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CURE_PARTY_STATUS
    DrainHeal 0, 0
    Target MOVE_TARGET_USER_PARTY
    StatChanges
    Marker
    Flags MOVE_FLAG_SNATCH | MOVE_FLAG_SOUND
