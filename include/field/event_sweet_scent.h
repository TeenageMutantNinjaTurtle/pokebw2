#ifndef POKEBW2_FIELD_EVENT_SWEET_SCENT_H
#define POKEBW2_FIELD_EVENT_SWEET_SCENT_H

#include "system/game_event.h"

GameEvent *EventSweetScent_Create(Field *field, GameSystem *gsys);
GameEvent *func_ov033_021785d4(GameSystem *gsys, Field *field, u8 partySlot);
GameEventReturnCode EventSweetScent_Callback(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_EVENT_SWEET_SCENT_H
