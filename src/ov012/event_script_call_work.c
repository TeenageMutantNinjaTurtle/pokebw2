#include "field/field_script.h"
#include "field/field_script_supervisor.h"
#include "system/game_event.h"

// The event's data begins with its script work and supervisor.
struct EventScriptCallData {
    ScriptWork *work;
    FieldScriptSupervisor *supervisor;
};

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
