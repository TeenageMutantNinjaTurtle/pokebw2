#include "battle/btl_pokeparam.h"

// Function names from swan.
void HPAdd(BattleMon *mon, u16 amount) {
    u16 *words;

    words = (u16 *)mon;
    words[8] += amount;
    if (words[8] > words[7]) {
        words[8] = words[7];
    }
}

void HPZero(BattleMon *mon) {
    *(u16 *)((u8 *)mon + 0x10) = 0;
}
