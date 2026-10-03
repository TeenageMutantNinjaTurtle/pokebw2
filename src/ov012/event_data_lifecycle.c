#include "field/event_data.h"
#include "gfl/arc.h"
#include "gfl/heap.h"

EventData *EventData_Create(HeapID heapId) {
    EventData *data;

    data = GFL_HeapAllocate(heapId, sizeof(EventData), TRUE, data_ov012_0216e298, 0xae);
    data->entityArc = GFL_ArcSysCreateFileHandle(0x7e, heapId);
    data->encArc = GFL_ArcSysCreateFileHandle(0x7f, heapId);
    data->otherArc = GFL_ArcSysCreateFileHandle(0x38, heapId);
    return data;
}

void EventData_Free(EventData *data) {
    GFL_ArcToolFree(data->entityArc);
    GFL_ArcToolFree(data->encArc);
    GFL_ArcToolFree(data->otherArc);
    GFL_HeapFree(data);
}

void EventData_Reset(EventData *data) {
    EventData_Clear(data);
    data->initScript = (u8 *)data + 0x2328;
    data->encLoaded = 0;
    data->encDataFlags.high = 0;
}
