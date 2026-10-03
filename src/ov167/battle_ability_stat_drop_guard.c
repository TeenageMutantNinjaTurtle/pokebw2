#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
const BattleEventHandlerEntry *EventAddHyperCutter(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7904;
}

void HandlerHyperCutterCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 1);
}

void HandlerHyperCutterGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xc9);
}

const BattleEventHandlerEntry *EventAddKeenEye(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7914;
}

void HandlerKeenEyeCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 6);
}

void HandlerKeenEyeGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xcf);
}

const BattleEventHandlerEntry *EventAddClearBody(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7924;
}

void HandlerClearBodyCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 8);
}

void HandlerClearBodyGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xc6);
}

void CommonStatDropGuardCheck(void *flow, u32 monId, u32 *result, u32 stat) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (stat == 8 || BattleEventVar_GetValue(0x1f) == stat) {
                if ((s32)BattleEventVar_GetValue(0x20) < 0) {
                    *result = BattleEventVar_RewriteValue(0x41, 1);
                }
            }
        }
    }
}

struct StatDropGuardMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void CommonStatDropGuardFixed(void *flow, u32 monId, u32 *result, u16 message) {
    u32 source;
    StatDropGuardMessageWork *work;

    if (BattleEventVar_GetValue(2) == monId && result[0]) {
        source = BattleEventVar_GetValue(0x19);
        if (source == 0 || result[1] != source) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            result[1] = source;
        }
        result[0] = 0;
    }
}
