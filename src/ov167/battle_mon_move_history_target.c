#include "battle/btl_pokeparam.h"

// Function names from swan.
u16 GetPreviousMoveUsed(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14a);
}

u8 GetPrevTargetPos(BattleMon *mon) {
    return *((u8 *)mon + 0x152);
}
