#include "battle/btl_pokeparam.h"

// Function names from swan.
BOOL IsIllusionEnabled(BattleMon *mon) {
    return ((u32)((u8 *)mon)[0x1b] << 25) >> 31;
}

void IllusionBreak(BattleMon *mon) {
    struct {
        u8 unused : 6;
        u8 illusion : 1;
        u8 high : 1;
    } *flags;

    flags = (void *)((u8 *)mon + 0x1b);
    flags->illusion = 0;
    *(u32 *)((u8 *)mon + 4) = 0;
}
