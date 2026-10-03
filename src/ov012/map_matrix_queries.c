#include "field/field_map.h"

u16 GetZoneIDAtMatrixXZ(MapMatrix *matrix, s32 x, s32 z) {
    return matrix->zoneIds[z * matrix->width + x];
}

u16 GetZoneIDAtMatrixXZWorld(MapMatrix *matrix, s32 x, s32 z) {
    return GetZoneIDAtMatrixXZ(matrix, GetChunkCoordOfWorld(x), GetChunkCoordOfWorld(z));
}

u16 GetMapMatrixWidth(MapMatrix *matrix) {
    return matrix->width;
}

u16 GetMapMatrixHeight(MapMatrix *matrix) {
    return matrix->height;
}

u32 GetMapMatrixChunkIDCount(MapMatrix *matrix) {
    return matrix->chunkIdCount;
}

u32 *GetMapMatrixChunkIDs(MapMatrix *matrix) {
    return matrix->chunkIds;
}

BOOL RangeCheckChunkCoordinate(MapMatrix *matrix, s32 x, s32 z) {
    return z >= 0 && z < matrix->height && x >= 0 && x < matrix->width;
}

BOOL RangeCheckChunkCoordinateWorld(MapMatrix *matrix, s32 x, s32 z) {
    return RangeCheckChunkCoordinate(matrix, GetChunkCoordOfWorld(x), GetChunkCoordOfWorld(z));
}
