#ifndef POKEBW2_FIELD_EVENT_SAVE_H
#define POKEBW2_FIELD_EVENT_SAVE_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct EventSaveWork {
    SaveControl *save;
    GameSystem *gameSystem;
    Field *field;
    void *msgBgSys;
    u16 code;
    u16 pad12;
    u32 *result;
    // The subscreen to go back to
    u32 screenId;
    u32 unk1C;
};

GameEvent *EventSave_Create(GameSystem *gsys, Field *field, u16 code, void *msgBgSys, u32 screenId, u32 *result);
GameEventReturnCode EventSave_Callback(GameEvent *event, u32 *state, void *data);
// Callbacks of the save in FIELD_PROC_LINK_LIST
void func_ov012_0215c574(FieldAppCallWork *work, s32 appParam);
void func_ov012_0215c594(void *param);
u32 EventSave_Update(EventSaveWork *work);

#endif // POKEBW2_FIELD_EVENT_SAVE_H
