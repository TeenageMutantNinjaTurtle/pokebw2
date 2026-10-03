#include "field/field_script.h"
#include "field/script_network.h"
#include "gfl/heap.h"
#include "system/dsi.h"
#include "system/vm.h"

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
