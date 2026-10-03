#include "battle/btl_pokeparam.h"

// Function names from swan.
void Move_UpdateID(BattleMon *mon, u8 index, u16 move, u8 maxPP, BOOL updateCurrent) {
    MoveWork_UpdateNumber((BattleMoveWork *)((u8 *)mon + 0x104 + index * 14), move, maxPP, updateCurrent);
}

BOOL MoveIsUsable(BattleMon *mon, u16 move) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (*(u16 *)((u8 *)mon + 0x10a + i * 14) == move) {
            return TRUE;
        }
    }
    return FALSE;
}
