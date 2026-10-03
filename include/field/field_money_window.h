#ifndef POKEBW2_FIELD_FIELD_MONEY_WINDOW_H
#define POKEBW2_FIELD_FIELD_MONEY_WINDOW_H

#include "types.h"
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

void func_ov033_02177a28(FieldMoneyWindow *work);

#endif // POKEBW2_FIELD_FIELD_MONEY_WINDOW_H
