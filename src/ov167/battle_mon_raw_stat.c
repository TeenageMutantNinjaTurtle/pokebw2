#include "battle/btl_pokeparam.h"

// Function name from swan.
u32 RawBattleMonStat(BattleMon *mon, u32 stat) {
    stat = func_ov167_021bb07c(mon, stat);
    switch (stat) {
    case 8:
        return *(u16 *)((u8 *)mon + 0xee);
    case 9:
        return *(u16 *)((u8 *)mon + 0xf0);
    case 10:
        return *(u16 *)((u8 *)mon + 0xf2);
    case 11:
        return *(u16 *)((u8 *)mon + 0xf4);
    case 12:
        return *(u16 *)((u8 *)mon + 0xf6);
    case 6:
        return 6;
    case 7:
        return 6;
    default:
        return GetBattleMonStat(mon, stat);
    }
}
