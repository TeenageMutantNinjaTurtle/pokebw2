// Two script commands that move an actor outside its movement codes: one raises or lowers it to a height over frames,
// and one holds it in place for a few frames. The name is descriptive
#include "types.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_script.h"
#include "nitro/fx.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/vm.h"

// The actor's movement flag that keeps its movement codes from moving it
#define ACTOR_MOVEMENT_FLAG_HELD 0x8000

typedef struct {
    fx32 distance;
    u16 frames;
    u16 frame;
    FieldActor *actor;
    VecFx32 pos;
} ActorMoveHeightData;

typedef struct {
    u32 frame;
    FieldActor *actor;
    VecFx32 pos;
} ActorHoldData;

static GameEventReturnCode func_ov012_021648d0(GameEvent *event, u32 *state, void *work);
static GameEventReturnCode func_ov012_02164988(GameEvent *event, u32 *state, void *work);

BOOL func_ov012_02164838(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 actorId;
    u16 height;
    u16 frames;
    GameEvent *event;
    ActorMoveHeightData *data;
    FieldActor *actor;

    FieldScriptEnv_GetGameData(env);
    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    actorId = ScriptReadAny(vm, env);
    height = ScriptReadAny(vm, env);
    frames = ScriptReadAny(vm, env);
    event = GameEvent_Create(gsys, NULL, func_ov012_021648d0, sizeof(ActorMoveHeightData));
    data = GameEvent_GetData(event);
    data->frames = frames;
    data->frame = 0;
    actor = FindFieldActor(Field_GetActorSystem(GSYS_GetField(gsys)), actorId);
    CopyActorWPos(actor, &data->pos);
    data->actor = actor;
    SetActorMovementFlag(actor, ACTOR_MOVEMENT_FLAG_HELD);
    // The height is in half tiles
    data->distance = height * (8 * FX32_ONE) - data->pos.y;
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

static GameEventReturnCode func_ov012_021648d0(GameEvent *event, u32 *state, void *work) {
    ActorMoveHeightData *data = work;
    VecFx32 pos;

    data->frame++;
    pos = data->pos;
    pos.y += data->distance * data->frame / data->frames;
    SetActorWPosValue(data->actor, &pos);
    if (data->frame >= data->frames) {
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

BOOL func_ov012_0216491c(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 actorId;
    GameEvent *event;
    ActorHoldData *data;
    FieldActor *actor;

    FieldScriptEnv_GetGameData(env);
    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    actorId = ScriptReadAny(vm, env);
    event = GameEvent_Create(gsys, NULL, func_ov012_02164988, sizeof(ActorHoldData));
    data = GameEvent_GetData(event);
    data->frame = 0;
    actor = FindFieldActor(Field_GetActorSystem(GSYS_GetField(gsys)), actorId);
    CopyActorWPos(actor, &data->pos);
    data->actor = actor;
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

static GameEventReturnCode func_ov012_02164988(GameEvent *event, u32 *state, void *work) {
    ActorHoldData *data = work;
    VecFx32 pos = data->pos;

    data->frame++;
    switch (*state) {
    case 0:
        SetActorWPosValue(data->actor, &pos);
        data->frame = 0;
        *state = 1;
        break;
    case 1:
        SetActorWPosValue(data->actor, &pos);
        data->frame = 0;
        *state = 2;
        break;
    case 2:
        SetActorWPosValue(data->actor, &pos);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
