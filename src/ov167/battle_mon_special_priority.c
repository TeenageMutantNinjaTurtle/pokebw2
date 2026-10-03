#include "battle/btl_pokeparam.h"

// Function names from swan.
void func_ov167_021bc55c(BattleMon *mon, u16 value) {
    *(u16 *)((u8 *)mon + 0x1f2) = value;
    CureMoveCondition(mon, 8);
}

void ResetSpActPriority(BattleMon *mon) {
    *(u16 *)((u8 *)mon + 0x1f2) = 0;
}

BOOL IsSubstituteActive(BattleMon *mon) {
    if (*(u16 *)((u8 *)mon + 0x1f2) != 0) {
        return TRUE;
    }
    return FALSE;
}
