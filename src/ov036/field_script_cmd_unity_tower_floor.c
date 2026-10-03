#include "field/field_script.h"
#include "field/unity_tower.h"

BOOL s02DB_UnityTowerSetFloor(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 floor;
    u16 value;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    floor = ScriptReadAny(vm, env);
    value = ScriptReadAny(vm, env);
    func_ov033_0217aa1c(gsys, floor, value);
    return FALSE;
}
