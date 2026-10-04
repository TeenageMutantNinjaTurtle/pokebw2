#ifndef POKEBW2_FIELD_FIELD_MENU_H
#define POKEBW2_FIELD_FIELD_MENU_H

#include "types.h"
#include "struct_decls.h"
#include "field/app_call.h"
#include "system/game_event.h"

struct FieldMenuWork {
    u16 code;
    u16 pad02;
    GameEvent *event;
    GameSystem *gameSystem;
    Field *field;
    u32 unk10;
    u32 state;
    u32 screenId;
    // The app the menu opens, whose callbacks get the menu as their arg
    FieldAppCallInput appCall;
};

extern const u32 data_ov012_0216cb74[9];

GameEventReturnCode EventFieldMenu_Callback(GameEvent *event, u32 *state, void *data);
GameEvent *EventFieldMenu_Create(GameSystem *gsys, Field *field, u16 param);
GameEvent *EventFieldMenu_CreateUnionRoom(GameSystem *gsys, Field *field, u16 param);
BOOL func_ov012_0215aa74(FieldAppCallInput *input, void *arg);
BOOL func_ov012_0215aa90(FieldAppCallInput *input, void *arg);
BOOL func_ov012_0215aa94(FieldAppCallInput *input, void *arg);
u32 func_ov012_0215aa68(u32 index);
// Runs one of the field's common events, such as the bike or the Escape Rope
GameEvent *CallFieldCommonEventFunc(u32 id, GameSystem *gsys, Field *field);

// Overlay 36: the event that returns from the menu to the subscreen
GameEvent *EventFieldMenuReturn_Create(GameSystem *gsys, Field *field, u32 screenId);

#endif // POKEBW2_FIELD_FIELD_MENU_H
