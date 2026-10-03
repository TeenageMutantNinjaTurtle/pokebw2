#include "types.h"
#include "field/event_3d_demo.h"
#include "field/event_battle_video.h"
#include "field/event_wifibattlematch.h"
#include "field/field_event.h"
#include "field/field_script.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "pml/move_reminder.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/vm.h"

struct BagScriptResult {
    u16 *hasSelection;
    u16 *item;
};

struct BagProcessData {
    u8 padding[0x44];
    void *selection;
    u32 item;
};

struct MailboxProcessData {
    u32 unk00;
    u32 result;
};

BOOL s014A_FieldOpen(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    ScriptWork_CallEvent(work, EventFieldOpen_CreateHeadless(gsys));
    return TRUE;
}

BOOL s014B_FieldClose(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    ScriptWork_CallEvent(work, CreateFieldCloseEvent(gsys, field));
    return TRUE;
}

void CreateScrCmdOverlayProcess(VM *vm, FieldScriptEnv *env, s32 overlayId, const GameProcFunctions *functions,
                                void *resource, void (*cleanup)(ScriptOverlayWork *), void *data) {
    GameSystem *gsys;
    ScriptWork *scriptWork;
    void **heapPtr;
    ScriptOverlayWork *work;

    gsys = FieldScriptEnv_GetGameSystem(env);
    scriptWork = FieldScriptEnv_GetScriptWork(env);
    heapPtr = ScriptWork_GetUserHeapPtr(scriptWork);
    work = GFL_HeapAllocate(4, sizeof(ScriptOverlayWork), TRUE, "scrcmd_proc.c", 0x8b);
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

void func_ov012_0215767c(ScriptOverlayWork *work) {
    MailboxProcessData *mailbox = work->resource;

    if (mailbox->result == 1) {
        *(u16 *)work->data = TRUE;
    } else {
        *(u16 *)work->data = FALSE;
    }
    GFL_HeapFree(work->resource);
}

void func_ov012_02157728(ScriptOverlayWork *work) {
    MoveReminderProcessData *data;
    u16 result;

    data = work->resource;
    switch (data->status) {
    case 0:
    default:
        result = FALSE;
        break;
    case 1:
        result = TRUE;
        break;
    }
    *(u16 *)work->data = result;
    GFL_HeapFree(((MoveReminderProcessData *)work->resource)->moves);
    func_ov012_02169ca4(work->resource);
}

BOOL s0154_Call3DDemo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 demoId;
    u16 param;
    GameEvent *parent;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    demoId = ScriptReadAny(vm, env);
    param = ScriptReadAny(vm, env);
    parent = ScriptWork_GetEvent(work);
    event = Event3DDemo_Create(gsys, parent, demoId, param, 0);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

BOOL func_ov012_02157a78(VM *vm, FieldScriptEnv *env) {
    FieldScriptEnv_GetScriptWork(env);
    FieldScriptEnv_GetGameSystem(env);
    return TRUE;
}

BOOL s0160_NetConnectWiFiBattle(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 battleType;
    u16 mode;
    u32 type;
    u32 option;
    EventWifiBattleMatchArgs args;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    battleType = ScriptReadAny(vm, env);
    mode = ScriptReadAny(vm, env);
    switch (battleType) {
    case 15:
        type = 0;
        break;
    case 16:
        type = 1;
        break;
    case 17:
        type = 2;
        break;
    case 18:
        type = 3;
        break;
    case 19:
        type = 4;
        break;
    }
    switch (mode) {
    case 0:
        option = 0;
        break;
    case 1:
        option = 1;
        break;
    }
    args.field = GSYS_GetField(gsys);
    args.unk4 = 1;
    args.unk8 = option;
    args.unkC = type;
    event = GameEvent_CreateOverlayDelegate(gsys, OVERLAY_ID(2), EventWifiBattleMatch_CreateFromArgs, &args);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

BOOL s0161_NetConnectBattleVideo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 mode;
    EventBattleVideoArgs args;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    mode = ScriptReadAny(vm, env);
    if (mode == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    args.field = GSYS_GetField(gsys);
    args.mode = mode;
    event = GameEvent_CreateOverlayDelegate(gsys, OVERLAY_ID(3), EventBattleVideo_CreateFromArgs, &args);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}
