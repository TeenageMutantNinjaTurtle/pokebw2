#include "battle/btl_pokeparam.h"
#include "gfl/std.h"

// Function name from swan.
void ClearMoveStatusWork(BattleMon *mon, u32 flag) {
    u32 i;
    BattleCondition *conditions;

    i = 0;
    if (flag == 0) {
        i = 6;
    }
    for (; i < 0x24; i++) {
        conditions = (BattleCondition *)((u8 *)mon + 0x1c);
        ((u32 *)mon)[i + 7] = 0;
        conditions[i].raw &= ~7;
    }
    sys_memset((u8 *)mon + 0xac, 0, 0x24);
}
