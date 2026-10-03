#include "battle/btl_pokeparam.h"

// Function names from swan.
u32 GetTurnFlag(BattleMon *mon, u32 flag) {
    u32 bit;
    u8 mask;
    u8 *data;
    u32 result;

    bit = flag & 7;
    mask = (u8)(1 << bit);
    flag = (flag << 21) >> 24;
    data = (u8 *)mon + flag;
    result = TRUE;
    if ((data[0x153] & mask) == 0) {
        result = FALSE;
    }
    return result;
}

u32 GetAdditionalConditionFlag(BattleMon *mon, u32 flag) {
    u32 bit;
    u8 mask;
    u8 *data;
    u32 result;

    bit = flag & 7;
    mask = (u8)(1 << bit);
    flag = (flag << 21) >> 24;
    data = (u8 *)mon + flag;
    result = TRUE;
    if ((data[0x155] & mask) == 0) {
        result = FALSE;
    }
    return result;
}
