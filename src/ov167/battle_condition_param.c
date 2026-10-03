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
