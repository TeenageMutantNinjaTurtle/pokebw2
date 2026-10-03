#include "battle/btl_pokeparam.h"

// Function name from swan.
void SetMoveCondition(BattleMon *mon, u32 condition, BattleCondition value) {
    u8 *data;
    u8 *count;

    data = (u8 *)mon;
    if (IsBasicStatus(condition)) {
        CureCondition(mon);
    }
    *(BattleCondition *)(data + 0x1c + condition * 4) = value;
    count = data + condition;
    count[0xac] = 0;
}
