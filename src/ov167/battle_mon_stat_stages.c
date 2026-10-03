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

s32 func_ov167_021bb550(BattleMon *mon, u32 stat) {
    s8 min;
    s8 max;
    s8 *stage;

    stage = func_ov167_021bb4b4(mon, stat, &min, &max);
    return max - *stage;
}

// Function name from swan.
BOOL AreStatsLowered(BattleMon *mon) {
    if (*(s8 *)((u8 *)mon + 0xfc) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0xfd) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0xfe) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0xff) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0x100) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0x101) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0x102) < 6) {
        return TRUE;
    }
    return FALSE;
}
