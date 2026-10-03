#include "battle/btl_pokeparam.h"

struct BattleMon {
    u8 unk00[0x1c];
    BattleCondition conditions[6];
};

// Function name from swan.
u32 GetBattleMonStatus(BattleMon *mon) {
    u32 i;

    for (i = 1; i < 6; i++) {
        if (mon->conditions[i].common.type != 0) {
            return i;
        }
    }
    return 0;
}

BOOL CheckCondition(BattleMon *mon, u32 index) {
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    return conditions[index].common.type != 0;
}
