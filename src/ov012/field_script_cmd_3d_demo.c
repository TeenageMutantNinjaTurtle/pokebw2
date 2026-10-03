#include "field/event_3d_demo.h"
#include "field/field_script.h"

BOOL s0154_Call3DDemo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 demoId;
    u16 param;
    GameEvent *parent;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    demoId = ScriptReadAny(vm, env);
    param = ScriptReadAny(vm, env);
    parent = ScriptWork_GetEvent(work);
    event = Event3DDemo_Create(gsys, parent, demoId, param, 0);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}
