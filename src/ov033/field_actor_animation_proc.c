#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_actor_animation.h"
#include "gfl/overlay.h"

FieldActorAnmProc *FieldActorAnmProc_Create(Field *field, u16 actorId, const VecFx32 *pos, HeapID heapId) {
    MMSys *actors = Field_GetActorSystem(field);
    FieldAsyncProc *asyncProc =
        FieldAsyncProcManager_AddProc(OVERLAY_NONE, Field_GetAsyncProcMgr(field), &FIELD_ACTOR_ANM_ASYNC_PROC_TEMPLATE);
    FieldActorAnmProc *work = FieldAsyncProc_GetData(asyncProc);

    work->asyncProc = asyncProc;
    work->heapId = heapId;
    work->pos = *pos;
    work->actor = FindFieldActor(actors, actorId);
    return work;
}

void FieldActorAnmProc_Free(FieldActorAnmProc *proc) {
    FieldAsyncProc_End(proc->asyncProc);
}

void FieldActorAnmProc_Play(FieldActorAnmProc *proc, u16 animation) {
    proc->curve = GFL_G3DCurveCreateToLoadBuffer(proc->heapId, 0xc8, animation, 0xa, proc->unk4, sizeof(proc->unk4));
    proc->finished = TRUE;
    proc->animation = animation;
    FieldActorAnmProc_CommitTransform(proc->curve, proc->actor, &proc->pos);
    SetActorMovementFlag(proc->actor, 0x8000);
}

BOOL FieldActorAnmProc_IsPlaying(FieldActorAnmProc *proc) {
    return proc->finished == 0;
}
