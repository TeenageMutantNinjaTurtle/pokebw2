#include "battle/btl_pokeparam.h"

// Function names from swan.
BattleCondition MakeConditionPermanent(void) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 1;
    return condition;
}

BattleCondition MakeConditionParamPermanent(u16 param) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 1;
    condition.timed.param = param;
    return condition;
}
