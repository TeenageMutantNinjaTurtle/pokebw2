#ifndef POKEBW2_FIELD_EVENT_ACTION_CALL_H
#define POKEBW2_FIELD_EVENT_ACTION_CALL_H

// Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct EventActionCallWork {
    GameSystem *gameSystem;
    Field *field;
    GameData *gameData;
    u16 actorId;
    u16 padE;
    const u32 *action;
    FieldAcmdTCB *tasks[8];
};

GameEventReturnCode EventActionCall_Callback(GameEvent *event, u32 *state, void *data);
GameEvent *EventActionCall_Create(GameSystem *gsys, Field *field, u16 actorId, const u32 *action);
GameEvent *CallMoveOneTileFrontEvent(GameSystem *gsys, Field *field);
FieldActor *EventActionCall_FindActor(MMSys *mmSys, u16 actorId);
void EventActionCall_ClearTCBs(EventActionCallWork *work);
void EventActionCall_AddTCB(EventActionCallWork *work, FieldAcmdTCB *task);
BOOL EventActionCall_UpdateTCBs(EventActionCallWork *work);

#endif // POKEBW2_FIELD_EVENT_ACTION_CALL_H
