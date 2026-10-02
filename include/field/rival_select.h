#ifndef POKEBW2_FIELD_RIVAL_SELECT_H
#define POKEBW2_FIELD_RIVAL_SELECT_H

#include "types.h"
#include "struct_decls.h"

struct RivalEntry {
    u8 id;
    u8 unk1;
    u8 selected;
    u8 active;
    u32 unk4;
};

struct RivalSelectContext {
    void *unk0;
    GameData *gameData;
    void *entryOwner;
    u8 padding[0xc];
    Field *field;
    MMSys *actors;
};

RivalEntry *func_02014864(void *owner);
BOOL func_02018fa8(u16 areaId);
u8 getHollowNum(RivalDataSave *save);
BOOL func_ov026_0216fa30(RivalSelectContext *context);

RivalEntry *func_ov073_021e8be0(RivalSelectContext *context, u32 id);
void func_ov073_021e8bfc(RivalSelectContext *context, u32 id);
BOOL func_ov073_021e8c4c(RivalSelectContext *context);
BOOL func_ov073_021e8c64(RivalSelectContext *context);
BOOL func_ov073_021e8cac(RivalSelectContext *context, u32 id);
void func_ov073_021e8cdc(RivalSelectContext *context, u32 id);
u8 func_ov073_021e8d00(RivalSelectContext *context, u32 id);

#endif // POKEBW2_FIELD_RIVAL_SELECT_H
