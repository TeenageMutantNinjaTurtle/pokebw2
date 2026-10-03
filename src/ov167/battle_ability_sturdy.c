#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct SturdyMessageWork {
    u32 flags;
    BattleHandlerString string;
};

const BattleEventHandlerEntry *EventAddSturdy(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b84;
}
void HandlerSturdyOneshotCheck(void *context, BtlServerFlow *flow, u32 monId) {
    SturdyMessageWork *work;
    u32 command;
    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_RewriteValue(0x41, 1)) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, 0xd2);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        }
    }
}
void HandlerSturdyEndureCheck(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 value;
    value = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (IsMonFullHP(GetBattleMon(flow, monId))) {
            *result = BattleEventVar_RewriteValue(0x3a, value);
        } else {
            *result = 0;
        }
    }
}
void HandlerSturdySurvive(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    SturdyMessageWork *work;
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, 0x202);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            *active = 0;
        }
    }
}
