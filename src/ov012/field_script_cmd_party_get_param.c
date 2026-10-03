#include "field/field_script.h"

BOOL s0110_PokePartyGetParam(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    u16 param = ScriptReadAny(vm, env);
    u32 i;

    for (i = 0; i < 20; i++) {
        if (param == data_ov012_0216ca06[i]) {
            *result = GetScrPokeStat(env, index, param);
            return FALSE;
        }
    }
    *result = 0;
    return FALSE;
}
