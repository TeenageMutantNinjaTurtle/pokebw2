#include "battle/btl_ability.h"
#include "battle/btl_math.h"

// Function name from swan.
BOOL AbilityEvent_RollEffectChance(BattleMon *mon, u32 chance) {
    BOOL result;
    BOOL check;

    if (RollEffectChance(chance)) {
        return TRUE;
    }
    check = func_ov167_021abdf8(mon, 1);
    result = TRUE;
    if (!check) {
        result = FALSE;
    }
    return result;
}
