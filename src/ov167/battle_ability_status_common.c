#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
BOOL HandlerCommonGuardStatus(void *flow, u32 monId, u32 status) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x1d) == status) {
            return BattleEventVar_RewriteValue(0x41, 1);
        }
    }
    return FALSE;
}

struct StatusFailedMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void CommonAddStatusFailed(void *context, void *flow, u32 monId, u32 *result, u16 message) {
    StatusFailedMessageWork *work;
    u32 command;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (*result == 1) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            *result = 0;
        }
    }
}

void HandlerAddStatusFailedCommon(void *context, void *flow, u32 monId, u32 *result) {
    CommonAddStatusFailed(context, flow, monId, result, 0xd2);
}

void CommonAbilityCureStatus(void *flow, u32 monId, u32 status) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonAbilityCureStatusCore(flow, monId, status);
    }
}

struct AbilityCureStatusWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void CommonAbilityCureStatusCore(void *flow, u32 monId, u32 status) {
    BattleMon *mon;
    AbilityCureStatusWork *work;

    mon = GetBattleMon(flow, monId);
    if (CheckCondition(mon, status)) {
        BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
        work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
        work->status = status;
        work->active = 1;
        work->monId = monId;
        BattleHandler_PopWork((BattleHandler *)flow, work);
        BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
    }
}
