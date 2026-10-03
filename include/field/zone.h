#ifndef POKEBW2_FIELD_ZONE_H
#define POKEBW2_FIELD_ZONE_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

struct RailPosition {
    u16 componentId;
    u8 componentIsLine;
    u8 railDirection;
    s16 posSide;
    u16 posFront;
};

typedef union {
    VecFx32 vec;
    RailPosition rail;
} FieldPosition;

struct ZoneSpawnInfo {
    u32 changeType;
    s16 zoneId;
    u16 warpId;
    s16 warpDir;
    u16 posWeightBits;
    BOOL isRail;
    FieldPosition pos;
};

struct RespawnZoneInfo {
    u16 discoveryFlagId;
    u16 canReturnHere : 1;
    u16 discoverOnVisit : 1;
    u16 unkFlags : 14;
    u16 zoneId;
    u16 x : 8;
    u16 z : 8;
    u16 mainZoneId;
    u8 unk0A[10];
};

struct ZoneWarp {
    u16 unk0;
    u16 destId;
    u8 unk4;
    u8 transitionType;
    u8 unk6[0xe];
};

extern const RespawnZoneInfo RESPAWN_ZONE_INFO[];

// Spawns at a position instead of a warp, warpId is -1
#define ZONE_SPAWN_CHANGE_TYPE_POSITION 1
#define ZONE_SPAWN_CHANGE_TYPE_3 3

#define WARP_DIR_UP 1
#define WARP_DIR_DOWN 2
#define WARP_DIR_LEFT 3
#define WARP_DIR_RIGHT 4

// With a map replace event set, each version allows its own area
#define VERSION_AREA_BLACK2 0
#define VERSION_AREA_WHITE2 1
#define VERSION_AREA_2 2
#ifdef BLACK2
#define VERSION_AREA_OWN VERSION_AREA_BLACK2
#else
#define VERSION_AREA_OWN VERSION_AREA_WHITE2
#endif

u16 ConvDirToWarpDir(u16 dir);
u32 ConvDirToTriggerDir(u32 dir);
BOOL CheckWarpPositionMatch(const ZoneWarp *warp, const VecFx32 *position);
BOOL CheckWarpPositionMatchRail(const ZoneWarp *warp, const RailPosition *position);
BOOL CheckWarpDirectionMatch(const ZoneWarp *warp, u16 direction);
BOOL IsWarpZoneOrWarpID0xFFFF(const ZoneWarp *warp);
void CreateZoneChangeData(ZoneSpawnInfo *spawn, u32 zoneId, s16 warpDir, s32 x, s32 y, s32 z);
void CreateZoneChangeDataRail(ZoneSpawnInfo *spawn, u16 zoneId, s16 warpDir, u16 componentId, u16 posFront,
                              s16 posSide);
void SetupZoneSpawnInfoWarp(ZoneSpawnInfo *spawn, u16 zoneId, u16 warpId, u32 direction);
void SetupWarpParamByWarp(ZoneWarp *warp, ZoneSpawnInfo *spawn, u32 direction);
u32 GetInTransitionTypeBetweenZones(u16 fromZone, u16 toZone);
BOOL GetIsZoneMatrix0(u16 zoneId);
u32 GetMapBGMIDByPlayerState2(GameData *gameData, s32 zoneId, u8 season);
u32 GetOutTransitionTypeBetweenZones(u16 fromZone, u16 toZone);
u32 GetRespawnLocationIndexForRespawnZone(s32 zoneId);
u16 GetRespawnZoneMainZone(u16 index);
u32 GetLeaguePokeCenReturnLocationIdx(void);
BOOL IsReturnLocationNonLeaguePokeCen(GameData *gameData);
BOOL RangeCheckTeleportZone(s32 index);
u32 GetActualRespawnZoneIdx(u32 index);
void CreateRespawnZoneChangeData(ZoneSpawnInfo *spawn, u16 zoneId, u32 unused, u16 x, u16 z);
u32 GetWarpTransitionType(ZoneWarp *warp);
BOOL GetZoneFlagsEnableEscapeRope(u16 zoneId);
BOOL GetZoneFlagsEnableEntralinkWarp(u16 zoneId);
BOOL GetZoneFlagsEnableFlyFrom(u16 zoneId);
BOOL GetZoneIsEntralinkAny(u16 zoneId);
void *FindCollidingZoneTriggerAtLocation(EventData *eventData, EventWork *eventWork, const VecFx32 *position);
u16 *FindTriggerAtPosGrid(EventData *eventData, EventWork *eventWork, const VecFx32 *position, u32 direction);
u16 *FindTriggerAtPosRail(EventData *eventData, EventWork *eventWork, const RailPosition *position);
u32 GetTriggerSCRIDAtPosGrid(EventData *eventData, EventWork *eventWork, const VecFx32 *position, u32 direction);
u32 GetSCRIDOfCollidingTriggerAtLocation(EventData *eventData, EventWork *eventWork, const VecFx32 *position);
u32 GetTriggerSCRIDAtPosRail(EventData *eventData, EventWork *eventWork, const RailPosition *position);
u32 GetZoneFlashFlags(u16 zoneId);
BOOL GetZoneIsMusicalTheater(u16 zoneId);
BOOL GetZoneIsPWTBattleStage(u16 zoneId);
BOOL GetZoneIsUnionRoom(u16 zoneId);
u16 GetZoneMatrixId(u16 zoneId);
u32 getGameOrigin(GameCommSys *commSys);
BOOL GetZoneSpawnInfoIsRail(ZoneSpawnInfo *spawn);
ZoneWarp *GetZoneWarpByID(EventData *eventData, u16 warpId);
BOOL IsWarpDestId256(ZoneWarp *warp);
BOOL IsZone150Or151(u16 zoneId);
BOOL IsZoneAbyssalRuinsOutside(u16 zoneId);
BOOL IsZoneAbyssalRuinsInside(u16 zoneId);
BOOL IsZoneEntralinkHub(u16 zoneId);
BOOL IsZoneGameCommDisabled(u16 zoneId);
BOOL IsZoneInVictoryRoad(u16 zoneId);
BOOL IsZoneJoinAvenue(u16 zoneId);
BOOL IsZoneJoinAvenueSubZone(u16 zoneId);
BOOL IsZoneRoyalUnova(u16 zoneId);
void LoadAspertiaCitySpawnInfo(ZoneSpawnInfo *spawn);
void LoadZoneSpawnInfoCheckRail(ZoneSpawnInfo *spawn, u16 zoneId);
void SetAllowVersionSpecificArea(u32 area, BOOL allow);
void SetTeleportZoneDiscover(GameData *gameData, s32 zoneId);
void SetupTeleportZoneChange(u16 returnLocation, ZoneSpawnInfo *spawn);
void SetupWarpParamByWarp(ZoneWarp *warp, ZoneSpawnInfo *spawn, u32 a2);
BOOL SetupZoneWarpArrival(EventData *eventData, ZoneSpawnInfo *spawn, u16 warpId, u16 posWeightBits);
u16 ZoneData_GetAreaID(u16 zoneId);
// The zone data, which the functions that read it need loaded
void InitZoneDataSystem(HeapID heapId);
void FreeZoneDataSystem(void);
u16 ZoneData_GetPlaceNameID(u16 zoneId);

#endif // POKEBW2_FIELD_ZONE_H
