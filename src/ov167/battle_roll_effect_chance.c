#include "battle/btl_math.h"

// Function name from swan.
BOOL RollEffectChance(u32 chance) {
    if (BattleRandom(100) < chance) {
        return TRUE;
    }
    return FALSE;
}
