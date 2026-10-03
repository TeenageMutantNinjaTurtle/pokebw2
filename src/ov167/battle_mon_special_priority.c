#include "battle/btl_pokeparam.h"

// Function names from swan.
void ResetSpActPriority(BattleMon *mon) {
    *(u16 *)((u8 *)mon + 0x1f2) = 0;
}

BOOL IsSubstituteActive(BattleMon *mon) {
    if (*(u16 *)((u8 *)mon + 0x1f2) != 0) {
        return TRUE;
    }
    return FALSE;
}
