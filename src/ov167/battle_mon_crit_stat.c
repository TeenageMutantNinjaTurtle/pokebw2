#include "battle/btl_pokeparam.h"

// Function name from swan.
u32 CritAtkDefLevel(BattleMon *mon, u32 stat) {
    BOOL useRaw;

    useRaw = FALSE;
    switch (func_ov167_021bb07c(mon, stat)) {
    case 8:
        if (*(s8 *)((u8 *)mon + 0xfc) < 6) {
            useRaw = TRUE;
        }
        break;
    case 10:
        if (*(s8 *)((u8 *)mon + 0xfe) < 6) {
            useRaw = TRUE;
        }
        break;
    case 9:
        if (*(s8 *)((u8 *)mon + 0xfd) > 6) {
            useRaw = TRUE;
        }
        break;
    case 11:
        if (*(s8 *)((u8 *)mon + 0xff) > 6) {
            useRaw = TRUE;
        }
        break;
    }
    if (useRaw) {
        return RawBattleMonStat(mon, stat);
    }
    return GetBattleMonStat(mon, stat);
}
