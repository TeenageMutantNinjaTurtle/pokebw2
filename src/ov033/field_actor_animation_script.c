#include "field/field.h"
#include "field/field_actor_animation.h"
#include "field/field_script.h"

typedef struct {
    u32 unk0;
    Field *field;
} ActorAnimationFieldWork;

typedef struct {
    FieldActorAnmProc *proc;
} EventActorAnmProcWaitWork;

BOOL s0157_ActorAnimationInit(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ActorAnimationFieldWork *fieldWork = ScriptWork_GetFieldWork(work);
    HeapID heapId = Field_GetHeapID(fieldWork->field);
    u16 actorId = ScriptReadAny(vm, env);
    VecFx32 pos;

    FieldPlayer_GetWPos(Field_GetPlayer(fieldWork->field), &pos);
    ScriptWork_SetActorAnmProc(work, FieldActorAnmProc_Create(fieldWork->field, actorId, &pos, heapId));
    return FALSE;
}

BOOL s0158_ActorAnimationFree(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);

    FieldActorAnmProc_Free(ScriptWork_GetActorAnmProc(work));
    ScriptWork_SetActorAnmProc(work, NULL);
    return FALSE;
}

BOOL s0159_ActorAnimationPlay(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 animation = ScriptReadAny(vm, env);

    FieldActorAnmProc_Play(ScriptWork_GetActorAnmProc(work), animation);
    return FALSE;
}

GameEventReturnCode EventActorAnmProcWait_Callback(GameEvent *event, u32 *state, void *data) {
    EventActorAnmProcWaitWork *work = data;

    return FieldActorAnmProc_IsPlaying(work->proc) == TRUE ? GAMEEVENT_DONE : GAMEEVENT_CONTINUE;
}

BOOL s015A_ActorAnimationWait(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActorAnmProcWait_Callback, sizeof(EventActorAnmProcWaitWork));
    EventActorAnmProcWaitWork *eventWork = GameEvent_GetData(event);

    eventWork->proc = ScriptWork_GetActorAnmProc(work);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}
