#include "field/field_script_supervisor.h"

void FieldScriptSupervisor_SetPostEvent(FieldScriptSupervisor *supervisor, GameEvent *event) {
    supervisor->postFunc = FieldScriptTerminator_ReplaceEvent;
    supervisor->postArg = event;
}

void FieldScriptSupervisor_CallPostFunc(FieldScriptSupervisor *supervisor, GameEvent *event) {
    supervisor->postFunc(event, supervisor->postArg);
}

BOOL FieldScriptSupervisor_HasPostFunc(FieldScriptSupervisor *supervisor) {
    return supervisor->postFunc != NULL;
}
