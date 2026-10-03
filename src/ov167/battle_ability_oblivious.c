#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct ObliviousMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerOblivious(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 7);
}

void HandlerObliviousCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 7);
}

void HandlerObliviousActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 7);
}

void HandlerObliviousNoEffectCheck(void *context, void *flow, u32 monId) {
    ObliviousMessageWork *work;
    u32 command;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if ((u16)BattleEventVar_GetValue(0x12) == 0x1bd) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
                BattleHandler_StrSetup(&work->string, 2, 0xd2);
                BattleHandler_AddArg(&work->string, monId);
                BattleHandler_PopWork((BattleHandler *)flow, work);
                BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddOblivious(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d48;
}
