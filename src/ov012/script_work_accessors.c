#include "field/field_actor.h"
#include "field/field_script.h"
#include "gfl/std.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"

GameEvent *ScriptWork_GetEvent(ScriptWork *work) {
    return work->event;
}

GameSystem *ScriptWork_GetGameSystem(ScriptWork *work) {
    return work->gsys;
}

void *ScriptWork_GetFieldWork(ScriptWork *work) {
    UpdateScriptFieldWk(work->fieldWork, work->gsys);
    return work->fieldWork;
}

void *ScriptWork_GetSubwork(ScriptWork *work) {
    return work->subwork;
}

WordSet *ScriptWork_GetWordSet(ScriptWork *work) {
    return work->wordSet;
}

StrBuf *ScriptWork_GetMainStrBuf(ScriptWork *work) {
    return work->mainStrBuf;
}

StrBuf *ScriptWork_GetAltStrBuf(ScriptWork *work) {
    return work->altStrBuf;
}

void func_ov012_02153ed0(ScriptWork *work, void *value) {
    work->unk38 = value;
}

void *func_ov012_02153ed4(ScriptWork *work) {
    return work->unk38;
}

u32 *ScriptWork_GetSEBitMask(ScriptWork *work) {
    return &work->seBitMask;
}

u16 ScriptWork_GetSCRID(ScriptWork *work) {
    return work->scriptId;
}

FieldActor *ScriptWork_GetParentActor(ScriptWork *work) {
    return work->parentActor;
}

void ScriptWork_SetParentActor(ScriptWork *work, FieldActor *actor) {
    work->parentActor = actor;
    if (actor != NULL) {
        *ScriptWork_GetLocalWork(work, 0x8011) = GetActorUID(actor);
    }
}

void **ScriptWork_GetUserHeapPtr(ScriptWork *work) {
    return &work->userHeap;
}

void *ScriptWork_GetUserHeap(ScriptWork *work) {
    return work->userHeap;
}

void ScriptWork_FreeUserHeap(ScriptWork *work) {
    if (work->userHeap != NULL) {
        GFL_HeapFree(work->userHeap);
        work->userHeap = NULL;
    }
}

u16 *ScriptWork_GetLocalWork(ScriptWork *work, u16 id) {
    return &work->localWork[id - 0x8000];
}

u16 *ScriptWork_GetWkAddr(ScriptWork *work, GameData *gameData, u16 id) {
    EventWork *eventWork = GameData_GetEventWork(gameData);
    if (id < 0x4000) {
        return NULL;
    }
    if (id < 0x8000) {
        return EventWork_GetWkPtr(eventWork, id);
    }
    if (id < 0xc000) {
        return ScriptWork_GetLocalWork(work, id);
    }
    return NULL;
}

u16 ScriptWork_ResolveHybridValue(ScriptWork *work, GameData *gameData, u16 value) {
    u16 *ptr = ScriptWork_GetWkAddr(work, gameData, value);
    if (ptr != NULL) {
        value = *ptr;
    }
    return value;
}

BOOL ScriptWork_SetWkValue(ScriptWork *work, u16 id, u32 value) {
    GameData *gameData = GSYS_GetGameData(work->gsys);
    u16 *ptr = ScriptWork_GetWkAddr(work, gameData, id);
    if (ptr == NULL) {
        return FALSE;
    }
    *ptr = value;
    return TRUE;
}

void ScriptWork_SetParams(ScriptWork *work, u16 param0, u32 param1, u16 param2, u16 param3) {
    ScriptWork_SetWkValue(work, 0x8000, param0);
    ScriptWork_SetWkValue(work, 0x8001, param1);
    ScriptWork_SetWkValue(work, 0x8002, param2);
    ScriptWork_SetWkValue(work, 0x8003, param3);
}

void *ScriptWork_CreateVarCopy(ScriptWork *work) {
    void *copy;
    u16 *vars;

    copy = GFL_HeapAllocate(work->heapId, 0x7e, TRUE, data_ov012_0216e1b4, 0x21b);
    vars = ScriptWork_GetLocalWork(work, 0x8020);
    sys_memcpy16(vars, copy, 0x7e);
    return copy;
}

void ScriptWork_RestoreVarCopy(ScriptWork *work, void *copy) {
    u16 *vars;

    vars = ScriptWork_GetLocalWork(work, 0x8020);
    sys_memcpy16(copy, vars, 0x7e);
    GFL_HeapFree(copy);
}

void ScriptWork_SetActorAnmProc(ScriptWork *work, FieldActorAnmProc *proc) {
    work->actorAnmProc = proc;
}

FieldActorAnmProc *ScriptWork_GetActorAnmProc(ScriptWork *work) {
    return work->actorAnmProc;
}

void ScriptWork_SetStadiumTrainers(ScriptWork *work, void *trainers) {
    work->stadiumTrainers = trainers;
}

void *ScriptWork_GetStadiumTrainers(ScriptWork *work) {
    return work->stadiumTrainers;
}

void *ScriptWork_GetTrainerState(ScriptWork *work, int index) {
    return work->trainerState[index];
}
