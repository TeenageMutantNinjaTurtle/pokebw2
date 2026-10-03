#include "battle/btl_pokeparam.h"

// Function name from swan.
BOOL Move_IsPPFull(BattleMon *mon, u8 index, BOOL current) {
    u8 *move;

    if (current != 0) {
        move = (u8 *)mon + 0x104 + index * 14;
    } else {
        move = (u8 *)mon + 0x10a + index * 14;
    }
    if (*(u16 *)move != 0 && move[2] == move[3]) {
        return TRUE;
    }
    return FALSE;
}
