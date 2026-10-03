#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_field.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.

struct IntimidateWork {
    u32 flags;
    u32 command;
    u8 unk08[4];
    s8 target;
    u8 unk0d;
    u8 active;
    u8 count;
    u8 mons[6];
};

const BattleEventHandlerEntry *EventAddIntimidate(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7944;
}

void HandlerIntimidateMemberIn(void *context, void *flow, u32 monId) {
    u8 *mons;
    u32 side;
    u32 count;
    u32 i;
    struct IntimidateWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        side = func_ov167_021ab840(flow, monId);
        mons = func_ov167_021abc60(flow, 6);
        count = HandlerGetAlivePartyCount((BattleHandler *)flow, (u16)(side | 0x100), mons);
        if (count != 0) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
            work->command = 1;
            work->target = -1;
            work->active = 1;
            work->count = count;
            for (i = 0; i < count; i++) {
                work->mons[i] = mons[i];
            }
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddInnerFocus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7794;
}

void HandlerInnerFocus(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

struct SteadfastWork {
    u32 flags;
    u32 count;
    u8 unk08[4];
    u8 active;
    u8 unk0d;
    u8 unk0e;
    u8 amount;
    u8 monId;
};

const BattleEventHandlerEntry *EventAddSteadfast(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7834;
}

void HandlerSteadfast(void *context, void *flow, u32 monId) {
    struct SteadfastWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(0x22) == 6) {
        if (BattleEventVar_GetValue(2) == monId) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
            work->flags |= flag << 22;
            work->count = 5;
            work->active = 1;
            work->unk0e = 0;
            work->amount = 1;
            work->monId = monId;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddThickFat(u32 *priority) {
    *priority = 1;
    return data_ov167_021d763c;
}

void HandlerThickFat(void *context, void *item, u32 monId) {
    u8 type;

    if (BattleEventVar_GetValue(4) == monId) {
        type = BattleEventVar_GetValue(0x16);
        if (type == 14 || type == 9) {
            BattleEventVar_MulValue(0x35, 2 << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddHugePower(u32 *priority) {
    *priority = 1;
    return data_ov167_021d784c;
}

void HandlerHugePower(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}

void HandlerSwiftSwim(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            BattleEventVar_MulValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddSwiftSwim(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77c4;
}

void HandlerChlorophyll(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 1) {
            BattleEventVar_MulValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddChlorophyll(u32 *priority) {
    *priority = 1;
    return data_ov167_021d765c;
}

void HandlerQuickFeet(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetBattleMonStatus(GetBattleMon(flow, monId)) != 0) {
            BattleEventVar_MulValue(0x35, 6 << 10);
            BattleEventVar_RewriteValue(0x51, 0);
        }
    }
}

const BattleEventHandlerEntry *EventAddQuickFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77cc;
}

void HandlerTangledFeet(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (CheckCondition(GetBattleMon(flow, monId), 6)) {
            BattleEventVar_MulValue(0x35, multiplier << 9);
        }
    }
}

const BattleEventHandlerEntry *EventAddTangledFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76ec;
}

void HandlerHustleAccuracy(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerHustlePower(void *context, void *item, u32 monId) {
    u32 multiplier;
    u32 value;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
            value = BattleEventVar_GetValue(0x33);
            value = fixed_round(value, multiplier << 11);
            BattleEventVar_RewriteValue(0x33, value);
        }
    }
}

const BattleEventHandlerEntry *EventAddHustle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a44;
}

void HandlerStall(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x11, 0);
    }
}

const BattleEventHandlerEntry *EventAddStall(u32 *priority) {
    *priority = numHandlersWithHandlerPri(7, 1);
    return data_ov167_021d7624;
}
