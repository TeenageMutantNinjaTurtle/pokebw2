#include "field/field_script.h"

BOOL s0119_PokePartyIsFromWhiteForest(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    u16 city = ScriptReadAny(vm, env);
    u16 metLocation = GetScrPokeStat(env, index, 0x95);
    if (metLocation == data_ov012_0216ca04[city]) {
        *result = TRUE;
    } else {
        *result = FALSE;
    }
    return FALSE;
}
