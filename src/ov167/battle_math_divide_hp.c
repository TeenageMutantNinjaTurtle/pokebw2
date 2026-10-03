#include "battle/btl_pokeparam.h"

// Function names from swan.
u32 DivideMaxHp(BattleMon *mon, u32 divisor) {
    return GetBattleMonStat(mon, 14) / divisor;
}

u32 DivideMaxHPZeroCheck(BattleMon *mon, u32 divisor) {
    u32 result;

    result = GetBattleMonStat(mon, 14) / divisor;
    if (result == 0) {
        result = 1;
    }
    return result;
}
