#include "field/event_mapchange.h"
#include "field/field_script.h"
#include "field/hidden_event.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

u32 EventDigCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 7) != 0) {
        if (func_ov012_02159440(context) != 0)
            return 3;
        return 0;
    }
    return 1;
}

GameEvent *EventDigCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    func_ov012_0216002c(0x5b);
    event = GameEvent_Create(context->gsys, NULL, EventDigCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventDigCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;

    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x271a, NULL, NULL, 0x15);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        GameEvent_Replace(event, EventMapChangeDig_Create(work->gsys));
        break;
    }
    return GAMEEVENT_CONTINUE;
}

u32 EventTeleportCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 6) != 0) {
        if (func_ov012_02159440(context) != 0)
            return 3;
        return 0;
    }
    return 1;
}

GameEvent *EventTeleportCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    func_ov012_0216002c(0x64);
    event = GameEvent_Create(context->gsys, NULL, EventTeleportCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventTeleportCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;

    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x2719, NULL, NULL, 0x15);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        GameEvent_Replace(event, EventMapChangeTeleport_Create(work->gsys));
        break;
    }
    return GAMEEVENT_CONTINUE;
}

u32 EventDivingCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 10) != 0) {
        if (func_ov012_02159440(context) != 0)
            return 3;
        return 0;
    }
    return 1;
}

GameEvent *EventDivingCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    event = GameEvent_Create(context->gsys, NULL, EventDivingCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventDivingCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x271c, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}
