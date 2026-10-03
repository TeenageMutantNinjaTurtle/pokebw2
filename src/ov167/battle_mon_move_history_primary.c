#include "battle/btl_pokeparam.h"

// Function names from swan.
u16 GetConsecutiveMoveCount(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14e);
}

u16 GetPreviousMoveID(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14c);
}
