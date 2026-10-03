#include "field/field_palace.h"
#include "gfl/heap.h"

FieldPalaceSys *FieldPalaceSys_Create(HeapID heapId, u32 a1, u32 a2, u32 a3) {
    FieldPalaceSys *sys;

    sys = GFL_HeapAllocate(heapId, sizeof(FieldPalaceSys), TRUE, data_ov036_021d56fc, 67);
    sys->unk00 = a1;
    sys->unk04 = a2;
    sys->luminanceTable = NULL;
    FieldPalaceSys_InitPostFX(sys, a3, heapId);
    return sys;
}

void FieldPalaceSys_Free(FieldPalaceSys *sys) {
    if (sys->luminanceTable != NULL) {
        GFL_HeapFree(sys->luminanceTable);
    }
    GFL_HeapFree(sys);
}

void *FieldPalaceSys_GetLuminanceTable(FieldPalaceSys *sys) {
    return sys->luminanceTable;
}
