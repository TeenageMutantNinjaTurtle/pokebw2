#include "field/field_script.h"
#include "field/script_network.h"
#include "gfl/heap.h"
#include "system/dsi.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL func_ov012_02159bc0(VM *vm, void *arg) {
    FieldScriptEnv *env = arg;
    GameSystem *gsys;
    ScriptWork *work;
    GameCommSys *commSys;
    void *data;

    gsys = FieldScriptEnv_GetGameSystem(env);
    work = FieldScriptEnv_GetScriptWork(env);
    commSys = GSYS_GetGameCommSystem(gsys);
    GSYS_GetField(gsys);
    data = *ScriptWork_GetUserHeapPtr(work);
    switch (func_ov036_02180fc0(commSys)) {
    case 0:
        return FALSE;
    case 1:
        GFL_HeapFree(data);
        return TRUE;
    case 2:
        **(u16 **)data = 2;
        GFL_HeapFree(data);
        return TRUE;
    }
    return FALSE;
}

BOOL s0139_GameCommDisconnect(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    void **slot;
    u16 *result;
    void *memory;

    work = FieldScriptEnv_GetScriptWork(env);
    slot = ScriptWork_GetUserHeapPtr(work);
    result = ScriptReadVar(vm, env);
    memory = GFL_HeapAllocate(4, 4, TRUE, data_ov012_0216e254, 0x63);
    *slot = memory;
    *(u16 **)memory = result;
    *result = 0;
    VM_SetNativeCallback(vm, func_ov012_02159bc0);
    return TRUE;
}

BOOL s013B_GameCommCheckDSiWiFi(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    *result = func_02035318();
    return FALSE;
}
