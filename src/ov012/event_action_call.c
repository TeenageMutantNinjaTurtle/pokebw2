#include "types.h"
#include "field/event_action_call.h"
#include "field/event_actor_move.h"
#include "field/field.h"
#include "field/field_acmd.h"
#include "field/field_actor.h"
#include "field/field_visuals.h"
#include "gfl/sound.h"
#include "nitro/fx.h"
#include "system/game_event.h"
#include "system/game_system.h"

struct PrepareResidentActorsWork {
    GameSystem *gameSystem;
    Field *field;
    GameData *gameData;
    u32 unkC;
};

GameEvent *CallEventPrepareResidentActorsForZoneChange(GameSystem *gsys, Field *field) {
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_0215c59c, sizeof(PrepareResidentActorsWork));
    PrepareResidentActorsWork *work = GameEvent_GetData(event);
    work->gameSystem = gsys;
    work->field = field;
    work->gameData = GSYS_GetGameData(gsys);
    return event;
}

GameEventReturnCode EventActionCall_Callback(GameEvent *event, u32 *state, void *data) {
    EventActionCallWork *work = data;
    MMSys *mmSys = Field_GetActorSystem(work->field);
    switch (*state) {
    case 0: {
        FieldActor *actor = EventActionCall_FindActor(mmSys, work->actorId);
        if (actor == NULL) {
            return GAMEEVENT_DONE;
        }
        FieldAcmdTCB *task = FieldAcmdTCB_Create(actor, work->action);
        EventActionCall_AddTCB(work, task);
        (*state)++;
        break;
    }
    case 1:
        if (!EventActionCall_UpdateTCBs(work)) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventActionCall_Create(GameSystem *gsys, Field *field, u16 actorId, const u32 *action) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActionCall_Callback, sizeof(EventActionCallWork));
    EventActionCallWork *work = GameEvent_GetData(event);
    EventActionCall_ClearTCBs(work);
    work->gameSystem = gsys;
    work->field = field;
    work->gameData = GSYS_GetGameData(gsys);
    work->actorId = actorId;
    work->action = action;
    return event;
}

GameEvent *CallMoveOneTileFrontEvent(GameSystem *gsys, Field *field) {
    u32 direction = GetActorFaceDir(FieldPlayer_GetActor(Field_GetPlayer(field)));
    const u32 *queue;
    switch (direction) {
    case 0: queue = ACMD_QUEUE_WALK_N_8F; break;
    case 1: queue = ACMD_QUEUE_WALK_S_8F; break;
    case 2: queue = ACMD_QUEUE_WALK_W_8F; break;
    case 3: queue = ACMD_QUEUE_WALK_E_8F; break;
    }
    return EventActionCall_Create(gsys, field, 0xff, queue);
}

FieldActor *EventActionCall_FindActor(MMSys *mmSys, u16 actorId) {
    if (actorId == 0xf2) {
        return FindActorByMoveCode(mmSys, 0x30);
    }
    if (actorId != 0xf1) {
        return FindFieldActor(mmSys, actorId);
    }
    return (FieldActor *)mmSys;
}

void EventActionCall_ClearTCBs(EventActionCallWork *work) {
    int i;
    for (i = 0; i < 8; i++) {
        work->tasks[i] = NULL;
    }
}

void EventActionCall_AddTCB(EventActionCallWork *work, FieldAcmdTCB *task) {
    int i;
    for (i = 0; i < 8; i++) {
        if (work->tasks[i] == NULL) {
            work->tasks[i] = task;
            return;
        }
    }
}

BOOL EventActionCall_UpdateTCBs(EventActionCallWork *work) {
    int i;
    BOOL active = 0;
    for (i = 0; i < 8; i++) {
        if (work->tasks[i] != NULL) {
            if (FieldAcmdTCB_CheckEnded(work->tasks[i]) == TRUE) {
                FieldAcmdTCB_Remove(work->tasks[i]);
                work->tasks[i] = NULL;
            } else {
                active = 1;
            }
        }
    }
    return active;
}

GameEvent *EventActorJump_Create(GameSystem *gsys, Field *field, const VecFx32 *start, const VecFx32 *end) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActorJump_Callback, sizeof(EventActorJumpWork));
    EventActorJumpWork *work = GameEvent_GetData(event);
    work->field = field;
    work->effects = Field_GetFieldEffects(GSYS_GetField(gsys));
    work->start = *start;
    VEC_Subtract(end, start, &work->displacement);
    GFL_SndSEPlay(0x55e);
    return event;
}

FieldAcmdTCB *FieldAcmdTCB_CreateWalkOneTile(FieldActor *actor, u32 direction) {
    const u32 *queue;
    switch (direction) {
    case 0: queue = ACMD_QUEUE_WALK_N_8F; break;
    case 1: queue = ACMD_QUEUE_WALK_S_8F; break;
    case 2: queue = ACMD_QUEUE_WALK_W_8F; break;
    case 3: queue = ACMD_QUEUE_WALK_E_8F; break;
    }
    func_ov012_02166f2c(actor);
    return FieldAcmdTCB_Create(actor, queue);
}
