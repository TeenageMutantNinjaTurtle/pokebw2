#include "field/field_script.h"
#include "field/field_script_supervisor.h"
#include "system/game_event.h"
#include "system/vm.h"

// The event's data begins with its script work and supervisor.
struct EventScriptCallData {
    ScriptWork *work;
    FieldScriptSupervisor *supervisor;
};

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
