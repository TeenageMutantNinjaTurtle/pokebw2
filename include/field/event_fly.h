#ifndef POKEBW2_FIELD_EVENT_FLY_H
#define POKEBW2_FIELD_EVENT_FLY_H

#include "system/game_event.h"

GameEvent *func_ov033_02178908(GameSystem *gsys, void *unused, u32 zoneId);
GameEventReturnCode EventFly_Callback(GameEvent *event, u32 *state, void *data);
GameEventReturnCode func_ov033_02178c6c(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_EVENT_FLY_H
