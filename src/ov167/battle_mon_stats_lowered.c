#include "battle/btl_pokeparam.h"

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
