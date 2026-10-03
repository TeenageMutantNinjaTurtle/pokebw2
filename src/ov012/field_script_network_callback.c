#include "field/field_script.h"
#include "field/script_network.h"
#include "gfl/heap.h"
#include "system/game_system.h"

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
