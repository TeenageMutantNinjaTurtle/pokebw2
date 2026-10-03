#include "battle/btl_pokeparam.h"

// Function names from swan.
void CureCondition(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 1; i < 6; i++) {
        *(BattleCondition *)(data + 0x1c + i * 4) = ZeroConditionTurns();
        data[0xac + i] = 0;
        CureDependentCondition(mon, i);
    }
}

void CureDependentCondition(BattleMon *mon, u32 condition) {
    u8 *data;

    data = (u8 *)mon;
    if (condition == 2) {
        *(BattleCondition *)(data + 0x40) = ZeroConditionTurns();
        data[0xb5] = 0;
    }
}

void CureMoveCondition(BattleMon *mon, u32 condition) {
    u8 *data;
    u8 *count;

    data = (u8 *)mon;
    if (IsBasicStatus(condition)) {
        CureCondition(mon);
    } else {
        *(BattleCondition *)(data + 0x1c + condition * 4) = ZeroConditionTurns();
        count = data + condition;
        count[0xac] = 0;
    }
}
