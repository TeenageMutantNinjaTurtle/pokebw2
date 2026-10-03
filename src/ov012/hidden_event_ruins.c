#include "field/field.h"
#include "field/field_script.h"
#include "field/hidden_event.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEventReturnCode EventRuinsStrengthCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;
    HeapID heapId;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    heapId = Field_GetHeapID(GSYS_GetField(work->gsys));
    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x271e, NULL, NULL, heapId);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        EventScriptCall_Replace(event, 0x28ed, 0, 0);
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventRuinsStrengthCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    event = GameEvent_Create(context->gsys, NULL, EventRuinsStrengthCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventRuinsFlash_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;
    HeapID heapId;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    heapId = Field_GetHeapID(GSYS_GetField(work->gsys));
    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x271d, NULL, NULL, heapId);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        EventScriptCall_Replace(event, 0x28ec, 0, 0);
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventRuinsFlash_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    event = GameEvent_Create(context->gsys, NULL, EventRuinsFlash_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}
