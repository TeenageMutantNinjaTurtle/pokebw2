#include "battle/btl_pokeparam.h"

// Function name from swan.
void SetBaseStatus(BattleMon *mon, u32 stat, u16 value) {
    switch (func_ov167_021bb07c(mon, stat)) {
    case 8:
        *(u16 *)((u8 *)mon + 0xee) = value;
        break;
    case 9:
        *(u16 *)((u8 *)mon + 0xf0) = value;
        break;
    case 10:
        *(u16 *)((u8 *)mon + 0xf2) = value;
        break;
    case 11:
        *(u16 *)((u8 *)mon + 0xf4) = value;
        break;
    case 12:
        *(u16 *)((u8 *)mon + 0xf6) = value;
        break;
    }
}
