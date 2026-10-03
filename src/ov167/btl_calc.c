#include "types.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_setup.h"

// Function name from swan.
BOOL RollEffectChance(u32 chance) {
    if (BattleRandom(100) < chance) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
u32 fixed_round(u32 value, u32 ratio) {
    u32 fraction;

    value *= ratio;
    fraction = value & 0xfff;
    value >>= 12;
    if (fraction > 0x800) {
        value++;
    }
    return value;
}


// Function name from swan.
u32 GetRatioOverZero(u32 value, u32 ratio) {
    u32 result;

    result = fixed_round(value, ratio);
    if (result == 0) {
        result = 1;
    }
    return result;
}

u32 MultiplyValueByRatio(u32 value, u32 ratio) {
    u32 remainder;
    u32 result;

    value *= ratio;
    remainder = value % 100;
    value /= 100;
    if (remainder >= 50) {
        value++;
    }
    return value;
}


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

// Function name from swan.
u32 GetNumMonsOnField(u32 battleType, u32 count) {
    if (battleType == 3) {
        count = 3;
    }
    return count;
}
