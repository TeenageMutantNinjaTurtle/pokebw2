#include "field/field_actor.h"
#include "field/field_script.h"

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
