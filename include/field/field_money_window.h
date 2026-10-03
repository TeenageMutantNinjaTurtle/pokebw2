#ifndef POKEBW2_FIELD_FIELD_MONEY_WINDOW_H
#define POKEBW2_FIELD_FIELD_MONEY_WINDOW_H

#include "types.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "system/game_event.h"
#include "struct_decls.h"

struct FieldMoneyWindow {
    u16 heapId;
    u16 padding;
    Field *field;
    MsgData *messages;
    void *window;
    u32 unk10;
    WordSet *wordSet;
    StrBuf *first;
    StrBuf *second;
    u32 unk20;
    u32 unk24;
};

struct FieldMoneyWindowEvent {
    Field *field;
    FieldMoneyWindow *window;
    u32 *entries;
    u32 count;
    u16 index;
};

struct GFLBitmap;
extern const char data_ov033_0217c600[];
u16 func_02009a18(void *items, u32 index);
u16 func_02009a38(void *items, u32 index);
void func_02009a6c(void *items, u32 index);
u32 func_ov036_02189cb0(void *bgSys);
void func_ov036_02189cd8(u32 value);
void func_ov036_02189de8(u32 value, struct GFLBitmap *bitmap, u32 number);

FieldMoneyWindow *func_ov033_02177998(Field *field, u32 value, u32 lines);
void func_ov033_02177a28(FieldMoneyWindow *work);
void func_ov033_02177a60(FieldMoneyWindow *work);
GameEventReturnCode func_ov033_02177b08(GameEvent *unused, u32 *state, void *data);
u32 *func_ov033_02177bd4(GameData *gameData, HeapID heapId, void *items, u32 *count);
void func_ov033_02177c48(GameData *gameData, HeapID heapId, void *items);
u32 func_ov033_02177c8c(GameData *gameData, HeapID heapId, void *items);
u16 func_ov033_02177cd4(GameData *gameData, HeapID heapId, void *items, u32 position);
GameEvent *func_ov033_02177d28(GameSystem *gameSystem);

#endif // POKEBW2_FIELD_FIELD_MONEY_WINDOW_H
