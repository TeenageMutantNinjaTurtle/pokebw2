#ifndef POKEBW2_FIELD_FIELD_MENU_H
#define POKEBW2_FIELD_FIELD_MENU_H

#include "types.h"
#include "struct_decls.h"

struct FieldMenuWork {
    u8 unk00[0x0C];
    Field *field;
    u32 unk10;
    u8 unk14[4];
    u32 screenId;
    u8 unk1C[0x0C];
    u32 prevScreenId;
    u8 unk2C[0x34];
};

GameEvent *EventFieldMenu_Create(GameSystem *gsys, Field *field, u32 param);
GameEvent *EventFieldMenu_CreateUnionRoom(GameSystem *gsys, Field *field, u32 param);
BOOL func_ov012_0215aa74(FieldMenuWork *work, FieldMenuWork *context);
BOOL func_ov012_0215aa90(void);

#endif // POKEBW2_FIELD_FIELD_MENU_H
