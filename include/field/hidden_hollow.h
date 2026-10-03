#ifndef POKEBW2_FIELD_HIDDEN_HOLLOW_H
#define POKEBW2_FIELD_HIDDEN_HOLLOW_H

#include "gfl/heap.h"
#include "struct_decls.h"

struct HiddenHollowWork {
    u16 heapId;
    u16 padding;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

extern const char data_ov036_021d5744[];

HiddenHollowWork *func_ov036_021c8954(HeapID heapId);
void func_ov036_021c897c(HiddenHollowWork *work);
void func_ov036_021c8984(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3);
u32 func_ov036_021c898c(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
u32 func_ov036_021c89cc(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

#endif // POKEBW2_FIELD_HIDDEN_HOLLOW_H
