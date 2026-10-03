#include "field/field_actor.h"
#include "field/field_script.h"

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