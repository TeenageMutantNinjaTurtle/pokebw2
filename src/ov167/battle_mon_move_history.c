#include "battle/btl_pokeparam.h"

// Function names from swan.
u16 GetConsecutiveMoveCount(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14e);
}

u16 GetPreviousMoveID(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14c);
}

u8 func_ov167_021bbfb0(BattleMon *mon) {
    return *((u8 *)mon + 0x144);
}

u16 GetPreviousMoveUsed(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14a);
}

u8 GetPrevTargetPos(BattleMon *mon) {
    return *((u8 *)mon + 0x152);
}
