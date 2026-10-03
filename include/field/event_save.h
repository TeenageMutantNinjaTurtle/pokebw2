#ifndef POKEBW2_FIELD_EVENT_SAVE_H
#define POKEBW2_FIELD_EVENT_SAVE_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct EventSaveWork {
    SaveControl *save;
    GameSystem *gameSystem;
    Field *field;
    u32 arg3;
    u16 code;
    u16 pad12;
    u32 *result;
    void *args;
    u32 unk1C;
};

GameEvent *EventSave_Create(GameSystem *gsys, Field *field, u16 code, u32 arg3, void *args, u32 *result);
GameEventReturnCode EventSave_Callback(GameEvent *event, u32 *state, void *data);
u32 EventSave_Update(EventSaveWork *work);

#endif // POKEBW2_FIELD_EVENT_SAVE_H
