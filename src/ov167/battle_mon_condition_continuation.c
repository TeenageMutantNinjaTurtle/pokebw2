#include "battle/btl_pokeparam.h"

// Function name from swan.
BattleConditionCont GetConditionContinuationParam(BattleMon *mon, u32 index) {
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    return conditions[index];
}
