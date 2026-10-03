#include "battle/btl_pokeparam.h"

// Function name from swan.
BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change) {
    s8 min;
    s8 max;
    s8 *stage;

    stage = func_ov167_021bb4b4(mon, stat, &min, &max);
    if (change > 0) {
        return *stage < max;
    }
    return *stage > min;
}
