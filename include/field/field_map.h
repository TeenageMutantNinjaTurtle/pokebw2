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

// The terrain of a layer at a position. Layout from swan, which names the normal's components SlopeX, HeightDiv and
// SlopeZ
struct MapTerrainBuf {
    VecFx16 normal;
    u16 pad06;
    u32 tileType;
    fx32 height;
};

// The terrain at a position in a chunk, a layer for each height. Layout from swan
struct MapTerrainSamplerOutput {
    MapTerrainBuf layers[16];
    u32 layerCount;
};

struct MapMatrixFileHeader {
    u16 format;
    u16 unk02;
    u16 width;
    u16 height;
    // The chunks, then the zones if the format is 1
    u32 chunkIds[];
};

// An entry of the map replacements, file 0 of archive 10
typedef struct {
    u16 id;
    u8 kind;
    // What picks the value: the season, the version, both, or an event of EVENT_MAP_REPLACE_TABLE
    u8 condition;
    // The original value, then the replacements
    u16 values[6];
} MapReplaceEntry;

// The values that MapReplaceEntry.condition picks from
typedef struct {
    u8 season;
    // 0 in Black and Black 2, 1 in White and White 2
    u8 version;
    // 0 in Black and Black 2, the season plus 1 in White and White 2
    u8 versionSeason;
    // Whether each event of EVENT_MAP_REPLACE_TABLE happened
    u8 events[10];
} MapReplaceVariables;

struct MapReplace {
    u16 heapId;
    ArcTool *arc;
    u32 entryCount;
    MapReplaceVariables variables;
    MapReplaceEntry entry;
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
// The area's props, a file of ARCID_AREA_BMDATA_EXT or ARCID_AREA_BMDATA_INT
u16 AreaData_GetPropBundleID(AreaData *areaData);
u32 AreaData_GetTexSetID(AreaData *areaData);
u32 AreaData_GetSRTAnmID(AreaData *areaData);
u32 AreaData_GetPatAnmID(AreaData *areaData);
void GimmickState_Reset(GimmickState *gimmick);
void GimmickState_SetID(GimmickState *gimmick, u16 gimmickId);
u32 GimmickState_GetID(GimmickState *gimmick);
// The state of the zone's gimmick that the save keeps. The ID is not checked
void *GimmickState_GetUserData(GimmickState *gimmick, u32 gimmickId);
MapMatrix *InitMapMatrix(HeapID heapId);
void MapMatrix_Load(MapMatrix *matrix, u16 matrixId, u16 zoneId, HeapID heapId);
void ProcessMapMatrix(MapMatrix *matrix, MapMatrixFileHeader *data, u32 matrixId, u16 zoneId);
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
void MapReplace_LoadVariables(MapReplaceVariables *variables, GameSystem *gsys);
void MapMatrix_Patch(MapMatrix *matrix, GameSystem *gsys, HeapID heapId);
u32 GetTileTypeAtPos(FieldG3DMapper *mapper, const VecFx32 *position);
u32 GetTileFlags(u32 tileType);
u16 GetAbyssalRuinsDiveZoneID(Field *field, u16 *zoneId);
u32 GetTileClass(u32 tileType);
BOOL MapTile_IsValid(u32 tileType);
BOOL MapTile_BlocksCollision(u32 tileType);
BOOL MapTile_IsBlocksCycling(u32 tileClass);
BOOL MapTile_IsNormalTallGrassDoubleBtl(u32 tileClass);
BOOL MapTile_IsReallyTallGrassSingleBtl(u32 tileClass);
BOOL MapTile_IsReallyTallGrassDoubleBtl(u32 tileClass);
BOOL func_ov036_021a2bf4(u32 tileClass);
BOOL func_ov036_021a2c04(u32 tileClass);
BOOL MapTile_IsSnowNoCycling(u32 tileClass);
BOOL MapTile_IsSnow(u32 tileClass);
BOOL func_ov036_021a2c58(u32 tileClass);
BOOL MapTile_IsSwamp(u32 tileClass);
BOOL func_ov036_021a2cd4(u32 tileClass);
BOOL func_ov036_021a2ce0(u32 tileClass);
BOOL func_ov036_021a2cec(u32 tileClass);
BOOL MapTile_IsElectricField(u32 tileClass);
BOOL MapTile_IsDeepSand(u32 tileClass);
BOOL func_ov036_021a2d34(u32 tileClass);
BOOL func_ov036_021a2d40(u32 tileClass);
BOOL func_ov036_021a2d4c(u32 tileClass);
// Whether a tile class keeps an actor from leaving it in a direction
BOOL TileExitBlockCheck_Up(u32 tileClass);
BOOL TileExitBlockCheck_Down(u32 tileClass);
BOOL TileExitBlockCheck_Left(u32 tileClass);
BOOL TileExitBlockCheck_Right(u32 tileClass);
BOOL func_ov036_021a2df4(u32 tileClass);
BOOL func_ov036_021a2e00(u32 tileClass);
BOOL func_ov036_021b3b54(u32 tileClass);
BOOL MapTile_IsSurfEdge(u32 tileClass);
BOOL IsTileSurfWater(u32 tileClass);
u32 GetWeatherAll(GameSystem *gsys, u16 zoneId);
void ResetWeather(GameSystem *gsys, s32 zoneId);
void UpdateWeatherToDefault(GameData *gameData, u16 zoneId);

// Overlay 36: patches of map land data from archive 0x9a, of which Join Avenue's shops are built
typedef struct LandDataPatch LandDataPatch;

LandDataPatch *ReadLandDataPatchA154Data(u16 fileId, HeapID heapId);
void FreeLandDataPatch(LandDataPatch *patch);
// Copies height rows of width cells, from srcX and srcY in the patch to destX and destY in the map
void func_ov036_021c2d04(LandDataPatch *patch, void *map, u32 srcX, u32 srcY, u32 destX, u32 destY, u32 width,
                         u32 height);
// Adds the patch's buildings at x and y, after the count already added, and returns the new count
u32 LoadLandDataPatchBuildings(LandDataPatch *patch, void *a1, void *a2, u32 count, u32 x, u32 y);
u8 AreaData_GetLightsID(AreaData *areaData);
u8 AreaData_GetEdgeColorTableID(AreaData *areaData);
u8 AreaData_GetActorMatColorID(AreaData *areaData);
BOOL AreaData_HasSeasons(u16 areaId);
BOOL func_02018f60(u16 areaId);
BOOL func_02018f78(u16 areaId);
BOOL func_02018f90(u16 areaId);

#endif // POKEBW2_FIELD_FIELD_MAP_H
