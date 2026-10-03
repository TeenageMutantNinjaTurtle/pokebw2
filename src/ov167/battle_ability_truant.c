#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
void HandlerTruant(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (state[0] != 0) {
            state[1] = BattleEventVar_RewriteValue(0x22, 0x13);
            state[0] = 0;
        } else {
            state[0] = 1;
        }
    }
}

void HandlerTruantGet(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetTurnFlag(GetBattleMon(flow, monId), 0)) {
            *result = 1;
        }
    }
}

struct TruantMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerTruantFailed(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    struct TruantMessageWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        if (state[1] != 0) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            work->flags |= 4 << 21;
            BattleHandler_StrSetup(&work->string, 2, 0x1bd);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            state[1] = 0;
        }
    }
}

void HandlerTruantEndAction(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0xc) == 7) {
            *result = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddTruant(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c18;
}
