#include "field/field_map.h"
#include "gfl/arc.h"
#include "gfl/heap.h"

MapReplace *MapReplace_Create(HeapID heapId, GameSystem *gsys) {
    MapReplace *replace = GFL_HeapAllocate(heapId, sizeof(MapReplace), TRUE, data_ov012_0216e1d4, 0x77);

    replace->heapId = heapId;
    replace->arc = GFL_ArcSysCreateFileHandle(10, heapId);
    replace->entryCount = (u32)(u16)GFL_ArcToolGetDataLength(replace->arc, 0) >> 4;
    MapReplace_LoadVariables(replace->variables, gsys);
    return replace;
}

s32 MapReplace_GetEntryCount(MapReplace *replace) {
    return replace->entryCount;
}

s32 MapReplace_LoadEntry(MapReplace *replace, u32 index) {
    GFL_ArcToolReadRange(replace->arc, 0, index * 16, 16, replace->entry);
    return *(u16 *)replace->entry;
}

void MapReplace_Free(MapReplace *replace) {
    GFL_ArcToolFree(replace->arc);
    GFL_HeapFree(replace);
}
