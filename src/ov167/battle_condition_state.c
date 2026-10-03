#include "battle/btl_pokeparam.h"

// Function names from swan.
u16 Condition_GetParam(BattleCondition condition) {
    if (condition.common.type == 1) {
        return (u16)((condition.raw << 7) >> 16);
    }
    if (condition.common.type == 3) {
        return (u16)((condition.raw << 7) >> 16);
    }
    if (condition.common.type == 4) {
        return (u16)((condition.raw << 1) >> 16);
    }
    if (condition.common.type == 2) {
        return (u16)((condition.raw << 7) >> 16);
    }
    return 0;
}

void SetConditionFlag(BattleCondition *condition, u32 flag) {
    if (condition->common.type == 1) {
        condition->one.flag = flag;
        return;
    }
    if (condition->common.type == 3) {
        condition->one.flag = flag;
        return;
    }
    if (condition->common.type == 4) {
        condition->four.flag = flag;
        return;
    }
    if (condition->common.type == 2) {
        condition->one.flag = flag;
    }
}

u32 func_ov167_021ce464(BattleCondition condition) {
    if (condition.common.type == 1) {
        return condition.one.flag;
    }
    if (condition.common.type == 3) {
        return condition.one.flag;
    }
    if (condition.common.type == 4) {
        return condition.four.flag;
    }
    if (condition.common.type == 2) {
        return condition.one.flag;
    }
    return 0;
}

void IncrementTurn(BattleCondition *condition, u32 amount) {
    if (condition->common.type == 2 && condition->common.turns < 8) {
        condition->common.turns += amount;
    }
    if (condition->common.type == 4 && condition->common.turns < 8) {
        condition->common.turns += amount;
    }
}

void SetTurns(BattleCondition *condition, u32 turns) {
    if (condition->common.type == 2 && condition->common.turns < 8) {
        condition->common.turns = turns;
    }
    if (condition->common.type == 4 && condition->common.turns < 8) {
        condition->common.turns = turns;
    }
}
