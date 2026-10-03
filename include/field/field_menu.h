#ifndef POKEBW2_FIELD_FIELD_MENU_H
#define POKEBW2_FIELD_FIELD_MENU_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct FieldMenuWork {
    u16 code;
    u16 pad02;
    GameEvent *event;
    GameSystem *gameSystem;
    Field *field;
    u32 unk10;
    u32 unk14;
    u32 screenId;
    GameSystem *gameSystem2;
    Field *field2;
    GameEvent *event2;
    u32 prevScreenId;
    u32 unk2C;
    s32 unk30;
    BOOL (*callback34)(FieldMenuWork *work, FieldMenuWork *context);
    BOOL (*callback38)(void);
    BOOL (*callback3C)(FieldMenuWork *work, FieldMenuWork *context);
    FieldMenuWork *self;
    u8 unk44[0x1C];
};

extern const u32 data_ov012_0216cb74[9];

GameEventReturnCode EventFieldMenu_Callback(GameEvent *event, u32 *state, void *data);
GameEvent *EventFieldMenu_Create(GameSystem *gsys, Field *field, u16 param);
GameEvent *EventFieldMenu_CreateUnionRoom(GameSystem *gsys, Field *field, u16 param);
BOOL func_ov012_0215aa74(FieldMenuWork *work, FieldMenuWork *context);
BOOL func_ov012_0215aa90(void);
BOOL func_ov012_0215aa94(FieldMenuWork *work, FieldMenuWork *context);
u32 func_ov012_0215aa68(u32 index);

#endif // POKEBW2_FIELD_FIELD_MENU_H
