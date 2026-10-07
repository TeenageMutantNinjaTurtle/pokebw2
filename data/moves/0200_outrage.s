#include "asm/move_data.inc"

// MOVE_OUTRAGE
    Type TYPE_DRAGON
    Quality MOVE_QUALITY_DAMAGE
    Category MOVE_CATEGORY_PHYSICAL
    Power 120
    Accuracy 100
    PP 10
    Priority 0
    Hits 0, 0
    Inflicts 0, 0, 0, 0, 0
    CritStage 0
    FlinchChance 0
    Effect BATTLE_EFFECT_CONTINUE_AND_CONFUSE_SELF
    DrainHeal 0, 0
    Target MOVE_TARGET_RANDOM_FOE
    StatChanges
    Marker
    Flags MOVE_FLAG_CONTACT | MOVE_FLAG_PROTECT | MOVE_FLAG_MIRROR_MOVE
