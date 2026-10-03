#include "battle/btl_pokeparam.h"

// Function names from swan.
void ClearUsedMoveFlag(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 0; i < 4; i++) {
        func_ov167_021ba9cc(data + 0x104 + i * 14);
    }
    *(u16 *)(data + 0x14a) = 0;
    *(u16 *)(data + 0x14c) = 0;
    data[0x144] = 0x11;
    *(u16 *)(data + 0x14e) = 0;
}

void ClearCounter(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 0; i < 5; i++) {
        data[0x157 + i] = 0;
    }
}
