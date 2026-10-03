#ifndef POKEBW2_FIELD_FIELD_MAP_H
#define POKEBW2_FIELD_FIELD_MAP_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

struct MapMatrix {
    u16 heapId;
    u16 zoneId;
    u32 matrixId;
    u16 width;
    u16 height;
    u16 format;
    u16 unk0E;
    u32 chunkIdCount;
    u16 zoneIds[900];
    u32 chunkIds[900];
};

struct FieldTerrain {
    u32 unk00;
    u32 unk04;
    u32 tileType;
    fx32 height;
};

struct MapMatrixFileHeader {
    u16 format;
    u16 unk02;
    u16 width;
    u16 height;
    u8 data[];
};

struct MapReplace {
    u16 heapId;
    u16 unk02;
    ArcTool *arc;
    u32 entryCount;
    u8 variables[14];
    u8 entry[16];
    u8 unk2A[2];
};

struct MapReplaceEvent {
    u8 condition;
    u8 uid;
    u16 workId;
    u16 expectedValue;
};

extern const MapReplaceEvent EVENT_MAP_REPLACE_TABLE[];

extern const char data_ov012_0216e1c4[];
extern const char data_ov012_0216e1d4[];

AreaData *AreaData_Create(HeapID heapId, u16 areaId, u32 a2);
void AreaData_Free(AreaData *areaData);
BOOL AreaData_IsExterior(AreaData *areaData);
void EventData_LoadZone(EventData *eventData, u16 zoneId, u8 season);
void GimmickState_Reset(GimmickState *gimmick);
void GimmickState_SetID(GimmickState *gimmick, u16 gimmickId);
// The state of the zone's gimmick that the save keeps. The ID is not checked
void *GimmickState_GetUserData(GimmickState *gimmick, u32 gimmickId);
MapMatrix *InitMapMatrix(HeapID heapId);
void MapMatrix_Load(MapMatrix *matrix, u16 matrixId, u16 zoneId, HeapID heapId);
void ProcessMapMatrix(MapMatrix *matrix, MapMatrixFileHeader *data, u32 matrixId, u32 zoneId);
void FreeMapMatrix(MapMatrix *matrix);
u16 GetZoneIDAtMatrixXZ(MapMatrix *matrix, s32 x, s32 z);
u16 GetZoneIDAtMatrixXZWorld(MapMatrix *matrix, s32 x, s32 z);
u16 GetMapMatrixWidth(MapMatrix *matrix);
u16 GetMapMatrixHeight(MapMatrix *matrix);
u32 GetMapMatrixChunkIDCount(MapMatrix *matrix);
u32 *GetMapMatrixChunkIDs(MapMatrix *matrix);
BOOL RangeCheckChunkCoordinate(MapMatrix *matrix, s32 x, s32 z);
BOOL RangeCheckChunkCoordinateWorld(MapMatrix *matrix, s32 x, s32 z);
u32 GetChunkCoordOfWorld(s32 coordinate);
MapReplace *MapReplace_Create(HeapID heapId, GameSystem *gsys);
s32 MapReplace_GetEntryCount(MapReplace *replace);
s32 MapReplace_LoadEntry(MapReplace *replace, u32 index);
void MapReplace_Free(MapReplace *replace);
void MapReplace_Patch(MapMatrix *matrix, MapReplace *replace, HeapID heapId);
u32 MapReplace_ResolvePatch(MapReplace *replace, u32 *oldValue, u32 *newValue);
int MapReplace_GetEventByCond(u8 condition);
const MapReplaceEvent *MapReplace_GetEventByUID(GameData *gameData, u16 uid);
void GameData_SetEventMapReplace(GameData *gameData, u16 uid, BOOL set);
BOOL GameData_IsMapReplaceEventSet(GameData *gameData, u16 uid);
void MapReplace_LoadVariables(u8 *variables, GameSystem *gsys);
void MapMatrix_Patch(MapMatrix *matrix, GameSystem *gsys, HeapID heapId);
u32 GetTileTypeAtPos(G3DMapper *mapper, const VecFx32 *position);
u16 GetAbyssalRuinsDiveZoneID(Field *field, u16 *zoneId);
BOOL FieldG3DMapper_GetTerrain(G3DMapper *mapper, const VecFx32 *position, FieldTerrain *terrain);
u32 GetTileClass(u32 tileType);
BOOL MapTile_IsSurfEdge(u32 tileClass);
BOOL IsTileSurfWater(u32 tileClass);
u32 GetWeatherAll(GameSystem *gsys, u16 zoneId);
void ResetWeather(GameSystem *gsys, s32 zoneId);
void UpdateWeatherToDefault(GameData *gameData, u16 zoneId);

#endif // POKEBW2_FIELD_FIELD_MAP_H
