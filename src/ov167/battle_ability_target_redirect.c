#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct LightningRodMessageWork {
    u32 flags;
    BattleHandlerString string;
};

const BattleEventHandlerEntry *EventAddStormDrain(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7adc;
}

void HandlerStormDrain(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    *result = CommonMoveTargetChangeToMe(flow, monId, result, 10);
}

void HandlerStormDrainCheckNoEffect(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeNoEffectRankUp(flow, monId, 3, 1);
    }
}

const BattleEventHandlerEntry *EventAddLightningRod(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7af4;
}

void HandlerLightningRod(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    *result = CommonMoveTargetChangeToMe(flow, monId, result, 12);
}

void HandlerLightningRodStart(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    LightningRodMessageWork *work;
    u32 flags;
    if (*active) {
        if (func_ov167_021cde38(monId)) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            flags = 4;
            work->flags |= flags << 21;
            BattleHandler_StrSetup(&work->string, 2, 7 << 6);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
        *active = 0;
    }
}

void HandlerLightningRodCheckNoEffect(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeNoEffectRankUp(flow, monId, 3, 1);
    }
}
