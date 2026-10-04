#include "types.h"
#include "field/app_call.h"
#include "field/player_action.h"
#include "gfl/std.h"
#include "save/bag.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *EventFieldAppCall_Create(FieldAppCallInput *input, u16 code) {
    GameEvent *event = GameEvent_Create(input->gameSystem, input->parent, EventFieldAppCall_Callback, sizeof(FieldAppCallWork));
    FieldAppCallWork *work = GameEvent_GetData(event);

    sys_memset(work, 0, sizeof(FieldAppCallWork));
    work->code = code;
    work->input = input;
    work->unk10 = 4;
    work->event = event;
    work->appId = input->appId;
    work->unk08 = input->appId;
    work->unk0C = input->appId;
    work->flag68 = 0;
    work->value6A = 0;
    work->unk70 = 0;
    func_ov012_0215b76c(&work->params, work->input, work->input->canRetry, work->input->callback1,
                          work->input->callback2, work->input->arg);
    PlayerActionPerms_Create(&work->perms, work->input->gameSystem, work->input->field);
    CalcPlayerActionPossibilities(work->input->field, &work->action);
    return event;
}

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

void func_ov012_0215b76c(FieldAppCallParam *param, FieldAppCallInput *input, FieldAppCallPredicate canRetry,
                         FieldAppCallPredicate callback1, FieldAppCallPredicate callback2, void *arg) {
    sys_memset(param, 0, sizeof(FieldAppCallParam));
    param->canRetry = canRetry;
    param->callback1 = callback1;
    param->callback2 = callback2;
    param->arg = arg;
    param->input = input;
}

BOOL FieldAppCallParam_CanRetry(FieldAppCallParam *param) {
    if (param->canRetry != NULL) {
        return param->canRetry(param->input, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7a8(FieldAppCallParam *param) {
    if (param->callback1 != NULL) {
        return param->callback1(param->input, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7c0(FieldAppCallParam *param) {
    if (param->callback2 != NULL) {
        return param->callback2(param->input, param->arg);
    }
    return TRUE;
}
