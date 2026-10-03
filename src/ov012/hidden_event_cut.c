#include "field/field_script.h"
#include "field/hidden_event.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

BOOL CheckAllowHidenEvent(u32 kind, HiddenEventContext *context) {
    HiddenCheckFunc check = GetHidenEventCheckFunc(context, kind);
    if (check == NULL) {
        return TRUE;
    }
    return check(context);
}

void func_ov012_02159418(HiddenEventArgs *args, u16 x, u16 z, GameSystem *gsys) {
    args->x = x;
    args->z = z;
    args->gsys = gsys;
}

GameEvent *CreateHidenEvent(u32 kind, GameSystem *gsys, HiddenEventContext *context) {
    HiddenCtorFunc ctor = GetHidenEventCtorFunc(context, kind);
    if (ctor == NULL) {
        return NULL;
    }
    return ctor(gsys, context);
}

BOOL func_ov012_02159440(HiddenEventContext *args) {
    return GameData_CheckPairFlag(GSYS_GetGameData(args->gsys));
}

BOOL EventCutCall_Check(HiddenEventContext *context) {
    u32 result = FALSE;
    if (func_ov012_02159b5c(context, 0) == 0) {
        result = TRUE;
    }
    return result;
}

GameEvent *EventCutCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventCutCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventCutCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2715, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}
