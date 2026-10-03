#include "field/field_map.h"

void MapReplace_Patch(MapMatrix *matrix, MapReplace *replace, HeapID heapId) {
    u32 oldValue;
    u32 newValue;
    u32 result = MapReplace_ResolvePatch(replace, &oldValue, &newValue);
    u32 i;

    switch (result) {
    case 2:
        MapMatrix_Load(matrix, (u16)newValue, matrix->zoneId, heapId);
        return;
    case 1:
        for (i = 0; i < matrix->chunkIdCount; i++) {
            if (matrix->chunkIds[i] == oldValue) {
                matrix->chunkIds[i] = newValue;
            }
        }
        break;
    case 0:
        break;
    }
}

void MapMatrix_Patch(MapMatrix *matrix, GameSystem *gsys, HeapID heapId) {
    MapReplace *replace = MapReplace_Create(heapId, gsys);
    s32 count = MapReplace_GetEntryCount(replace);
    s32 i;

    for (i = 0; i < count; i++) {
        s32 entryId = MapReplace_LoadEntry(replace, i);

        if (entryId == matrix->matrixId) {
            MapReplace_Patch(matrix, replace, heapId);
        }
    }
    MapReplace_Free(replace);
}
