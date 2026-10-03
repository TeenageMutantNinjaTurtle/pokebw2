#include "battle/btl_pokeparam.h"

// Function names from swan.
BattleCondition SetConditionTurns(u32 turns) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 2;
    condition.common.turns = turns;
    condition.timed.param = 0;
    return condition;
}

BattleCondition AddTurnCondition(u32 turns, u16 param) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 2;
    condition.common.turns = turns;
    condition.timed.param = param;
    return condition;
}

BattleCondition func_ov167_021ce1dc(u32 turns) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 3;
    condition.common.turns = turns;
    return condition;
}

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
