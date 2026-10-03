#include "field/app_call.h"
#include "gfl/std.h"
#include "save/bag.h"
#include "system/game_data.h"
#include "system/game_system.h"

void EventFieldAppCall_ConvAppResultToEventType(u32 result, u32 *eventType) {
    switch (result) {
    case 0:
        *eventType = 0;
        break;
    case 1:
        *eventType = 1;
        break;
    case 3:
        *eventType = 3;
        break;
    case 2:
        *eventType = 2;
        break;
    case 5:
        *eventType = 5;
        break;
    default:
        break;
    }
}

void func_ov012_0215b754(FieldAppCallWork *work) {
    GameSystem *gsys = work->input->gameSystem;
    GameData *gameData = GSYS_GetGameData(gsys);
    void *data = func_0201734c(gameData);

    func_020088ec(data, 0);
}

void func_ov012_0215b76c(FieldAppCallParam *param, void *context, FieldAppCallPredicate canRetry,
                         FieldAppCallPredicate callback1, FieldAppCallPredicate callback2, void *arg) {
    sys_memset(param, 0, sizeof(FieldAppCallParam));
    param->canRetry = canRetry;
    param->callback1 = callback1;
    param->callback2 = callback2;
    param->arg = arg;
    param->context = context;
}

BOOL FieldAppCallParam_CanRetry(FieldAppCallParam *param) {
    if (param->canRetry != NULL) {
        return param->canRetry(param->context, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7a8(FieldAppCallParam *param) {
    if (param->callback1 != NULL) {
        return param->callback1(param->context, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7c0(FieldAppCallParam *param) {
    if (param->callback2 != NULL) {
        return param->callback2(param->context, param->arg);
    }
    return TRUE;
}