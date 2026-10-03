#include "field/field_script.h"
#include "gfl/heap.h"
#include "system/game_system.h"
#include "system/vm.h"

void CreateScrCmdOverlayProcess(VM *vm, FieldScriptEnv *env, s32 overlayId, const GameProcFunctions *functions,
                                void *resource, void (*cleanup)(ScriptOverlayWork *), void *data) {
    GameSystem *gsys;
    ScriptWork *scriptWork;
    void **heapPtr;
    ScriptOverlayWork *work;

    gsys = FieldScriptEnv_GetGameSystem(env);
    scriptWork = FieldScriptEnv_GetScriptWork(env);
    heapPtr = ScriptWork_GetUserHeapPtr(scriptWork);
    work = GFL_HeapAllocate(4, sizeof(ScriptOverlayWork), TRUE, data_ov012_0216e208, 0x8b);
    work->resource = resource;
    work->data = data;
    work->cleanup = cleanup;
    GSYS_QueueProc(gsys, overlayId, functions, resource);
    *heapPtr = work;
    VM_SetNativeCallback(vm, (VMCommand)func_ov012_02157554);
}

BOOL func_ov012_02157554(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    ScriptWork *scriptWork;
    ScriptOverlayWork *work;

    gsys = FieldScriptEnv_GetGameSystem(env);
    scriptWork = FieldScriptEnv_GetScriptWork(env);
    work = ScriptWork_GetUserHeap(scriptWork);
    if (GSYS_GetProcMgrState(gsys) != 0) {
        return FALSE;
    }
    if (work->cleanup != NULL) {
        work->cleanup(work);
    } else {
        if (work->resource != NULL) {
            GFL_HeapFree(work->resource);
        }
        if (work->data != NULL) {
            GFL_HeapFree(work->data);
        }
    }
    ScriptWork_FreeUserHeap(scriptWork);
    return TRUE;
}

BOOL s014C_RTFreeUserHeap(VM *vm, FieldScriptEnv *env) {
    ScriptWork_FreeUserHeap(FieldScriptEnv_GetScriptWork(env));
    return TRUE;
}

typedef struct BagScriptResult {
    u16 *hasSelection;
    u16 *item;
} BagScriptResult;

typedef struct BagProcessData {
    u8 padding[0x44];
    void *selection;
    u32 item;
} BagProcessData;

void func_ov012_021575b8(ScriptOverlayWork *work) {
    BagProcessData *bag = work->resource;
    BagScriptResult *result = work->data;
    if (bag->selection == NULL) {
        *result->hasSelection = FALSE;
    } else {
        *result->hasSelection = TRUE;
    }
    *result->item = bag->item;
    GFL_HeapFree(work->data);
    GFL_HeapFree(work->resource);
}
