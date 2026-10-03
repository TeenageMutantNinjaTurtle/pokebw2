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

void func_ov167_021bba64(BattleMon *mon, u32 monId) {
    u32 i;
    u8 *entry;

    if (monId != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            entry = (u8 *)mon + i * 4;
            if (!func_ov167_021ce168(*(BattleCondition *)(entry + 0x1c))) {
                if (Condition_GetMonID(*(BattleCondition *)(entry + 0x1c)) == monId) {
                    *(BattleCondition *)(entry + 0x1c) = ZeroConditionTurns();
                    CureDependentCondition(mon, i);
                }
            }
        }
    }
}

struct BattleMon {
    u8 unk00[0x1c];
    BattleCondition conditions[6];
};

// Function names from swan.
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

u16 GetDisabledMove(BattleMon *mon, u32 index) {
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    switch (conditions[index].common.type) {
    case 2:
        return (conditions[index].raw << 7) >> 16;
    case 3:
        return (conditions[index].raw << 23) >> 26;
    case 4:
        return (conditions[index].raw << 17) >> 26;
    default:
        return 0;
    }
}

BattleConditionCont GetConditionContinuationParam(BattleMon *mon, u32 index) {
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    return conditions[index];
}

u8 func_ov167_021bbb1c(BattleMon *mon, u32 index) {
    return ((u8 *)mon + index)[0xac];
}
