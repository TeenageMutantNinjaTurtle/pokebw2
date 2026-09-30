#include "types.h"
#include "field/field_script.h"
#include "field/ov113.h"
#include "system/vm.h"

// Script plugin 15 (overlay 67), commands from 1000, of zones 463, 465 and 474, whose gimmick is overlay 113

static BOOL func_ov067_021e5800(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    u16 x = ScriptReadAny(vm, env);
    u16 y = ScriptReadAny(vm, env);
    u16 z = ScriptReadAny(vm, env);

    func_ov113_021eecd8(gsys, x, y, z);
    return FALSE;
}

static BOOL func_ov067_021e5840(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    u16 actorId = ScriptReadAny(vm, env);
    u16 x = ScriptReadAny(vm, env);
    u16 z = ScriptReadAny(vm, env);
    u16 a4 = ScriptReadAny(vm, env);
    GameEvent *event = func_ov113_021eed38(gsys, actorId, x, z, a4);

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

const FieldScriptCommand PLUGIN_15_SCRIPT_COMMANDS[] = {
    func_ov067_021e5800,
    func_ov067_021e5840,
    (FieldScriptCommand)0xFFFFFFFF,
};
