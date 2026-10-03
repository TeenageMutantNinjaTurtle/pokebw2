#ifndef POKEBW2_FIELD_EVENT_SAVE_H
#define POKEBW2_FIELD_EVENT_SAVE_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct EventSaveArgs {
    GameSystem *gameSystem;
    Field *field;
    u32 unk8;
    void *unkC;
};

struct EventSaveWork {
    SaveControl *save;
    GameSystem *gameSystem;
    Field *field;
    u32 arg3;
    u16 code;
    u16 pad12;
    u32 *result;
    EventSaveArgs *args;
    u32 unk1C;
};

GameEvent *EventSave_Create(GameSystem *gsys, Field *field, u16 code, u32 arg3, EventSaveArgs *args, u32 *result);
GameEventReturnCode EventSave_Callback(GameEvent *event, u32 *state, void *data);
// Callbacks of the save in FIELD_PROC_LINK_LIST
void func_ov012_0215c574(FieldAppCallWork *work);
void func_ov012_0215c594(void *param);
u32 EventSave_Update(EventSaveWork *work);

#endif // POKEBW2_FIELD_EVENT_SAVE_H
