#include "field/field_script.h"
#include "gfl/random.h"

BOOL s00CB_Random(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 range = ScriptReadAny(vm, env);
    *value = GFL_RandomLC(range);
    return FALSE;
}

BOOL s00CC_RTGetTextFile(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    *value = GetFieldScriptMsgFileNo(env);
    return FALSE;
}
