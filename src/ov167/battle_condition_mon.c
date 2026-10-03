#include "battle/btl_pokeparam.h"

// Function names from swan.
BOOL Condition_IsBadlyPoisoned(BattleConditionCont cont) {
    u32 turns;
    u32 type;

    turns = cont.common.turns;
    type = cont.common.type;
    return type == 1 && turns == 15;
}

u8 Condition_GetMonID(BattleCondition condition) {
    u32 type;
    u32 mon1;
    u32 mon2;

    type = condition.common.type;
    mon1 = condition.common.turns;
    mon2 = condition.mon.monId;
    if (type == 3) {
        return mon1;
    }
    if (type == 4) {
        return mon2;
    }
    return 31;
}
