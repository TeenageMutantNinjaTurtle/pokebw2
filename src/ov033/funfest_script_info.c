#include "field/festival.h"
#include "field/field_script.h"
#include "field/funfest_scripts.h"
#include "system/game_system.h"

BOOL s027B_FunfestGetItemExchangeInfo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    u16 arg0 = ScriptReadAny(vm, env);
    u16 arg1 = ScriptReadAny(vm, env);
    u16 *out0 = ScriptReadVar(vm, env);
    u16 *out1 = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *(volatile u16 *)out1 = 0x11;
        *out0 = *(volatile u16 *)out1;
        return TRUE;
    }
    func_ov072_021e8d08(gimmick, ScriptWork_GetParentActor(scriptWork), arg0, arg1, out0, out1);
    return TRUE;
}

BOOL s027C_FunfestGetItemSaleInfo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    u16 *out0 = ScriptReadVar(vm, env);
    u16 *out1 = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *out0 = 0x11;
        *out1 = 0x270f;
        return TRUE;
    }
    func_ov072_021e8d70(gimmick, ScriptWork_GetParentActor(scriptWork), out0, out1);
    return TRUE;
}

BOOL s027D_FunfestGetPokemonQuizInfo(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    void *gimmick;
    u16 *out0;
    u16 *out1;
    u16 *out2;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    out0 = ScriptReadVar(vm, env);
    out1 = ScriptReadVar(vm, env);
    out2 = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *out0 = 1;
        *(volatile u16 *)out2 = 0;
        *out1 = *(volatile u16 *)out2;
        return TRUE;
    }
    func_ov072_021e8ddc(gimmick, out0, out1, out2);
    return TRUE;
}

BOOL s027E_FunfestGetPokemonQuizSpecies(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    void *gimmick;
    u16 index;
    u16 *result;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    index = ScriptReadAny(vm, env);
    result = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *result = 0x1f8 + index;
        return TRUE;
    }
    *result = func_ov072_021e8ee8(gimmick, (u8)index);
    return TRUE;
}

BOOL s027F_FunfestGetPokemonQuizBogusSpecies(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    void *gimmick;
    u16 index;
    u16 *result;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    index = ScriptReadAny(vm, env);
    result = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *result = 0x1f8 + index;
        return TRUE;
    }
    *result = func_ov072_021e8ef4(gimmick, (u8)index);
    return TRUE;
}
