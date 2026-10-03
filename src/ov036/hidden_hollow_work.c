#include "field/hidden_hollow.h"

HiddenHollowWork *func_ov036_021c8954(HeapID heapId) {
    HiddenHollowWork *work;

    work = GFL_HeapAllocate(heapId, sizeof(HiddenHollowWork), TRUE, data_ov036_021d5744, 73);
    work->heapId = heapId;
    work->unk04 = 0xffff;
    return work;
}

void func_ov036_021c897c(HiddenHollowWork *work) {
    GFL_HeapFree(work);
}

void func_ov036_021c8984(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3) {
    work->unk04 = a1;
    work->unk08 = a2;
    work->unk0c = a3;
}
