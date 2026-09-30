#ifndef POKEBW2_SYSTEM_GAME_EVENT_H
#define POKEBW2_SYSTEM_GAME_EVENT_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

typedef enum {
    GAMEEVENT_CONTINUE = 0x0,
    GAMEEVENT_DONE = 0x1,
    // Runs the current event again in the same frame, such as an event that was just chained
    GAMEEVENT_CONTINUE_DIRECT = 0x21,
} GameEventReturnCode;

typedef GameEventReturnCode (*GameEventCallback)(GameEvent *event, u32 *state, void *data);
// Creates an event for GameEvent_CreateOverlayDelegate, after it loads the event's overlay
typedef GameEvent *(*GameEventProvider)(GameSystem *gsys, void *args);

void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
// Loads an overlay and runs the event that provider, in it, creates with args
GameEvent *GameEvent_CreateOverlayDelegate(GameSystem *gsys, u32 overlayId, GameEventProvider provider, void *args);
// Runs a proc of an overlay
GameEvent *func_020196d0(GameSystem *gsys, Field *field, u32 overlayId, const GameProcFunctions *functions, void *param,
                         u32 a5, u32 a6);
GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, GameEventCallback callback, u32 size);
void *GameEvent_GetData(GameEvent *event);
u32 *GameEvent_GetStatePtr(GameEvent *event);
void GameEvent_Replace(GameEvent *event, GameEvent *next);

#endif // POKEBW2_SYSTEM_GAME_EVENT_H
