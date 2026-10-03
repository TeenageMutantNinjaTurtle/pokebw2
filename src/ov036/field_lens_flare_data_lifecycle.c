#include "field/field_lens_flare.h"
#include "gfl/arc.h"
#include "gfl/heap.h"

FieldLensFlareData *FieldLensFlareData_Create(HeapID heapId) {
    FieldLensFlareData *data;

    data = GFL_HeapAllocate(heapId, sizeof(FieldLensFlareData), TRUE, data_ov036_021d5728, 57);
    data->entries = GFL_ArcSysReadHeapNewLZGetLen(0xf1, 0, 0, heapId, &data->byteCount);
    return data;
}

void FieldLensFlareData_Free(FieldLensFlareData *data) {
    GFL_HeapFree(data->entries);
    GFL_HeapFree(data);
}
