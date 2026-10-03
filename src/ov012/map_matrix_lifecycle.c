#include "field/field_map.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/std.h"

MapMatrix *InitMapMatrix(HeapID heapId) {
    MapMatrix *matrix = GFL_HeapAllocate(heapId, sizeof(MapMatrix), TRUE, data_ov012_0216e1c4, 0x4c);

    matrix->heapId = heapId;
    sys_memset32((u32)-1, matrix->chunkIds, sizeof(matrix->chunkIds));
    sys_memset32(0xffff, matrix->zoneIds, sizeof(matrix->zoneIds));
    return matrix;
}

void MapMatrix_Load(MapMatrix *matrix, u16 matrixId, u16 zoneId, HeapID heapId) {
    void *data = GFL_ArcSysReadHeapNew(9, matrixId, heapId);

    ProcessMapMatrix(matrix, data, matrixId, zoneId);
    GFL_HeapFree(data);
}

void FreeMapMatrix(MapMatrix *matrix) {
    GFL_HeapFree(matrix);
}
