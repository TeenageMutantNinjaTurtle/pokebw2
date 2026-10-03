#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.

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
