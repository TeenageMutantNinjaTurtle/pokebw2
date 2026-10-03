#include "field/field_script.h"
#include "field/hidden_event.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

u32 EventSurfCall_Check(HiddenEventContext *context) {
    u32 state = context->unk04;
    if (state == 2) {
        return 4;
    }
    if (state == 3) {
        return 1;
    }
    if (func_ov012_02159b5c(context, 1) != 0) {
        if (func_ov012_02159440(context) != 0) {
            return 3;
        }
        return 0;
    }
    return 1;
}

GameEvent *EventSurfCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventSurfCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventSurfCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2713, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}

u32 EventWaterfallCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 2) != 0) {
        if (func_ov012_02159440(context) != 0) {
            return 3;
        }
        return 0;
    }
    return 1;
}

GameEvent *EventWaterfallCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventWaterfallCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventWaterfallCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2717, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}
