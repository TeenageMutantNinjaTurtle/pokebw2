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

u32 func_ov167_021bb408(BattleMon *mon) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (GetAdditionalConditionFlag(mon, data_ov167_021d7490[i])) {
            return data_ov167_021d7490[i];
        }
    }
    return 0x10;
}

BOOL IsSemiInvulnMove(BattleMon *mon) {
    if (func_ov167_021bb408(mon) != 0x10) {
        return TRUE;
    }
    return FALSE;
}
