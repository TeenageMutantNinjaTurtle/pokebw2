#include "field/field_script_supervisor.h"
#include "system/game_event.h"

void FieldScriptTerminator_ReplaceEvent(GameEvent *event, void *arg) {
    GameEvent_Replace(event, arg);
}
