#include "field/field_script.h"

BOOL s00E0_GameGetVersion(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
#if defined(BLACK2)
    *value = 23;
#else
    *value = 22;
#endif
    return FALSE;
}
