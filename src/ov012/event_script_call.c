#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_script_supervisor.h"
#include "system/game_event.h"
#include "system/vm.h"

struct EventScriptCallData {
    ScriptWork *work;
    FieldScriptSupervisor *supervisor;
};

GameEventReturnCode EventScriptCall_Callback(GameEvent *event, u32 *state, void *arg) {
    EventScriptCallData *data = arg;
    ScriptWork *work;
    FieldScriptSupervisor *supervisor;

    supervisor = data->supervisor;
    work = data->work;
    if (FieldScriptSupervisor_Update(supervisor) == 1) {
        return FALSE;
    }
    ScriptWork_Free(work);
    if (FieldScriptSupervisor_HasPostFunc(supervisor) == 1) {
        FieldScriptSupervisor_CallPostFunc(supervisor, event);
        FieldScriptSupervisor_Free(supervisor);
        return FALSE;
    }
    FieldScriptSupervisor_Free(supervisor);
    return TRUE;
}

GameEvent *EventScriptCall_CreateCore(GameSystem *gsys, HeapID heapId, u16 scriptId, FieldActor *actor, u32 param) {
    GameEvent *event;
    EventScriptCallData *data;
    u16 zoneId;

    event = GameEvent_Create(gsys, NULL, EventScriptCall_Callback, sizeof(EventScriptCallData));
    data = GameEvent_GetData(event);
    data->supervisor = FieldScriptSupervisor_Create(4);
    data->work = ScriptWork_Create(4, gsys, event, scriptId, param, 0);
    ScriptWork_SetParentActor(data->work, actor);
    zoneId = FieldScript_GetZoneIDFromGSys(gsys);
    ScriptWork_AddVM(data->work, zoneId, scriptId);
    return event;
}

void ScriptWork_CallEvent(ScriptWork *work, GameEvent *event) {
    GameEvent_ChainNext(ScriptWork_GetEvent(work), event);
}

void ScriptWork_SetPostEvent(ScriptWork *work, GameEvent *event) {
    FieldScriptSupervisor *supervisor = ScriptWork_GetSupervisor(work);

    if (supervisor != NULL) {
        FieldScriptSupervisor_SetPostEvent(supervisor, event);
    }
}

u32 ScriptWork_AddVM(ScriptWork *work, u16 zoneId, u16 scriptId) {
    FieldScriptSupervisor *supervisor;
    VM *vm;

    supervisor = ScriptWork_GetSupervisor(work);
    if (supervisor != NULL) {
        vm = FieldScript_CreateVM(supervisor->heapId, work, zoneId, scriptId, 0);
        return FieldScriptSupervisor_AddVM(supervisor, vm);
    }
    return 3;
}

ScriptWork *EventScriptCall_GetWork(GameEvent *event) {
    EventScriptCallData *data = GameEvent_GetData(event);

    return data->work;
}

FieldScriptSupervisor *ScriptWork_GetSupervisor(ScriptWork *work) {
    GameEvent *event = ScriptWork_GetEvent(work);

    if (event == NULL) {
        return NULL;
    }
    return ((EventScriptCallData *)GameEvent_GetData(event))->supervisor;
}
