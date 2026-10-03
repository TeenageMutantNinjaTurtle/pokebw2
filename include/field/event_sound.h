#ifndef POKEBW2_FIELD_EVENT_SOUND_H
#define POKEBW2_FIELD_EVENT_SOUND_H

#include "types.h"
#include "struct_decls.h"

GameEvent *EventMEPlay_Create(GameSystem *gsys, u32 meId);
GameEvent *EventPushBGMFinish_Create(GameSystem *gsys, u32 a1, u32 a2);
GameEvent *EventBGMPopAll_Create(GameSystem *gsys, u32 a1);

#endif // POKEBW2_FIELD_EVENT_SOUND_H
