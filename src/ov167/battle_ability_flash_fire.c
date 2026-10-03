#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct FlashFireRemoveWork {
    u32 flags;
    u32 condition;
    u8 monId;
};

struct FlashFireMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerFlashFirePower(void *context, BtlServerFlow *flow, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetAdditionalConditionFlag(GetBattleMon(flow, monId), 0xd)) {
            if (BattleEventVar_GetValue(0x16) == 9) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

void HandlerFlashFireRemove(void *context, BtlServerFlow *flow, u32 monId) {
    FlashFireRemoveWork *work;
    u32 condition;

    if (BattleEventVar_GetValue(2) == monId) {
        condition = 0xd;
        if (GetAdditionalConditionFlag(GetBattleMon(flow, monId), condition)) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 0x18, (void *)monId);
            work->monId = monId;
            work->condition = condition;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

void HandlerFlashFireCheckNoEffect(void *context, BtlServerFlow *flow, u32 monId) {
    FlashFireMessageWork *message;
    FlashFireRemoveWork *work;
    u32 condition;

    if (CommonDamageRecoverCheck(flow, monId, 9)) {
        BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
        condition = 0xd;
        if (!GetAdditionalConditionFlag(GetBattleMon(flow, monId), condition)) {
            message = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            BattleHandler_StrSetup(&message->string, 2, 0x1ab);
            BattleHandler_AddArg(&message->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, message);
            work = BattleHandler_PushWork((BattleHandler *)flow, 0x17, (void *)monId);
            work->monId = monId;
            work->condition = condition;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        } else {
            message = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            BattleHandler_StrSetup(&message->string, 2, 0xd2);
            BattleHandler_AddArg(&message->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, message);
        }
        BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
    }
}

const BattleEventHandlerEntry *EventAddFlashFire(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7aac;
}
