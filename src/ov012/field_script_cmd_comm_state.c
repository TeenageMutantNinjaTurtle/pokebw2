#include "field/field_script.h"
#include "system/game_comm.h"
#include "system/game_system.h"

BOOL func_ov012_02159c80(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;

    gsys = FieldScriptEnv_GetGameSystem(env);
    GSYS_TryBootGameComm(gsys);
    return TRUE;
}

BOOL func_ov012_02159c90(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    GameCommSys *commSys;

    gsys = FieldScriptEnv_GetGameSystem(env);
    commSys = GSYS_GetGameCommSystem(gsys);
    switch (GameCommSys_BootCheck(commSys)) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
    case 2:
    case 5:
        GameCommSys_ExitReq(commSys);
        break;
    }
    func_02016b24(gsys, 1);
    FieldScriptSubEvent_Register(11);
    return TRUE;
}

BOOL func_ov012_02159cd8(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;

    gsys = FieldScriptEnv_GetGameSystem(env);
    func_02016b24(gsys, 0);
    GSYS_TryBootGameComm(gsys);
    FieldScriptSubEvent_Unregister(11);
    return TRUE;
}

BOOL func_ov012_02159cf8(GameSystem **gsysPtr) {
    GameSystem *gsys;

    gsys = *gsysPtr;
    func_02016b24(gsys, 0);
    GSYS_TryBootGameComm(gsys);
    return TRUE;
}

BOOL func_ov012_02159d10(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 *value;

    gsys = FieldScriptEnv_GetGameSystem(env);
    value = ScriptReadVar(vm, env);
    *value = func_02016b34(gsys);
    return FALSE;
}
