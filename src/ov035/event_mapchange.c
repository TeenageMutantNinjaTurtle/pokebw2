#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct SaveControl SaveControl;
typedef struct PlayerInfo PlayerInfo;
typedef struct EventWork EventWork;
typedef struct Field Field;
typedef struct FieldPlayer FieldPlayer;
typedef struct FieldStatus FieldStatus;
typedef struct FieldActor FieldActor;
typedef struct MMSys MMSys;
typedef struct PlaceName PlaceName;
typedef struct AreaData AreaData;
typedef struct EventData EventData;
typedef struct ZoneWarp ZoneWarp;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1
// Runs the current event again in the same frame, such as an event that was just chained
#define GAMEEVENT_CONTINUE_DIRECT 0x21

typedef enum {
    GAME_ENTRYPOINT_OPENING,
    GAME_ENTRYPOINT_FIELD_CONTINUE,
    GAME_ENTRYPOINT_DEBUG,
} GameEntryPoint;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct {
    GameEntryPoint entryPoint;
    VecFx32 spawnPos;
    u16 zoneId;
    u16 unk12;
} GameSystemProcData;

typedef struct {
    u16 componentId;
    u8 componentIsLine;
    u8 railDirection;
    s16 posSide;
    u16 posFront;
} RailPosition;

typedef struct {
    u32 changeType;
    s16 zoneId;
    u16 warpId;
    s16 warpDir;
    u16 posWeightBits;
    BOOL isRail;
    VecFx32 pos;
} ZoneSpawnInfo;

typedef struct {
    GameSystem *gsys;
    GameSystemProcData *procData;
} EventGameOpening;

typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    ZoneSpawnInfo spawn;
} EventFieldFirst;

typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    u16 zoneId;
    BOOL continueFromSave;
} EventFieldContinue;

typedef struct {
    GameEvent *parent;
    GameSystem *gsys;
    GameData *gameData;
    Field *field;
    u32 unk10;
    u32 transitionType;
    u16 zoneId;
    ZoneSpawnInfo spawn;
    u32 outTransition;
    u32 inTransition;
    BOOL seasonChanged;
    u8 startSeason;
    u8 endSeason;
    u32 unk48;
    u32 unk4C;
} WarpSequence;

typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    Field *field;
    u16 zoneId;
    ZoneSpawnInfo spawn;
    u32 unk2C;
    u8 mode;
    VecFx32 unk34;
    BOOL unk40;
    BOOL seasonChanged;
    u16 prevSeason;
    u16 season;
    WarpSequence warp;
    u32 unk9C;
    BOOL lensFlareStarted;
} EventMapChange;

typedef struct {
    EventMapChange *mapChange;
} EventMapChangeCore;

typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    ZoneSpawnInfo spawn;
} EventMapChangeBlackout;

typedef struct {
    u32 zoneId;
    u16 gimmickId;
} ZoneGimmick;

typedef void *(*DSProtCallback)(void *arg0, void *arg1);

typedef struct {
    ZoneSpawnInfo spawn;
    GameSystem *gsys;
    GameData *gameData;
    Field *field;
    u32 unk28;
    u8 unk2C;
    u32 festMissionStatus;
} EventEntralinkWarp;

// The city of the player's version, which a key from Unova Link can switch
#define CITY_BLACK_CITY 0
#define CITY_WHITE_FOREST 1

typedef struct {
    u16 initialized;
    u16 city;
} CityState;

// Spawns at a position instead of a warp, warpId is -1
#define ZONE_SPAWN_CHANGE_TYPE_POSITION 1
#define ZONE_SPAWN_CHANGE_TYPE_3 3

#define WARP_DIR_UP 1
#define WARP_DIR_DOWN 2
#define WARP_DIR_LEFT 3
#define WARP_DIR_RIGHT 4

#define FX32_CONST(x) ((s32)((x) * 4096))

// Allocates from the end of the heap
#define HEAP_LOW(heapId) ((heapId) | 0x8000)
#define HEAPID_FIELD 1

#define ARC_ZONE_GIMMICKS 0x66

#define SEQ_SE_ENTRALINK_WARP 0x772

// With a map replace event set, each version allows its own area
#define VERSION_AREA_BLACK2 0
#define VERSION_AREA_WHITE2 1
#define VERSION_AREA_2 2
#ifdef BLACK2
#define VERSION_AREA_OWN VERSION_AREA_BLACK2
#else
#define VERSION_AREA_OWN VERSION_AREA_WHITE2
#endif

#define EVENT_FLAG_CONTINUE_SCRIPT 0x965
#define EVENT_WORK_CONTINUE_SCRIPT 0x4041

// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_27_ID[];
extern u32 OVERLAY_28_ID[];
extern u32 OVERLAY_279_ID[];
extern u32 OVERLAY_337_ID[];
#define OVERLAY_27 ((u32)OVERLAY_27_ID)
#define OVERLAY_28 ((u32)OVERLAY_28_ID)
#define OVERLAY_NEW_GAME ((u32)OVERLAY_279_ID)
#define OVERLAY_DSPROT ((u32)OVERLAY_337_ID)

#define HW_VBLANK_COUNT_BUF 0x02fffc3c
#define DSPROT_CHECKSUM 0x9f75a8d6

// DS Protect state in overlay 337
extern u32 data_ov337_02182440;
extern DSProtCallback data_ov337_02182444[2];

// Calls a DS Protect function after verifying its code. If the checksum does not match, `tamper` is called instead.
// The dummy and tamper functions are put in a table in a random order, picked with the VBlank counter.
#define DSPROT_CHECKED_CALL(func, tamper, arg0, arg1)                                                                  \
    {                                                                                                                  \
        u32 index = *(u32 *)HW_VBLANK_COUNT_BUF & 1;                                                                   \
        u32 tamperIndex;                                                                                               \
        u32 i;                                                                                                         \
        u32 checksum;                                                                                                  \
        u32 *code;                                                                                                     \
        data_ov337_02182440 = index;                                                                                   \
        tamperIndex = index ^ 1;                                                                                       \
        data_ov337_02182444[index] = EventMapChange_DSProtNop;                                                         \
        data_ov337_02182444[tamperIndex] = tamper;                                                                     \
        code = (u32 *)func;                                                                                            \
        for (i = 0x25, checksum = 0; i != 0; i--) {                                                                    \
            checksum ^= (*code >> i) | (*code << (32 - i));                                                            \
            code++;                                                                                                    \
        }                                                                                                              \
        if (checksum == DSPROT_CHECKSUM) {                                                                             \
            func(arg0, arg1);                                                                                          \
        } else {                                                                                                       \
            data_ov337_02182444[tamperIndex](arg0, arg1);                                                              \
        }                                                                                                              \
    }

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern void GameEvent_Replace(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern Field *GSYS_GetField(GameSystem *gsys);
extern GameEvent *EventSeasonBanner_CreateStandalone(GameSystem *gsys, u8 startSeason, u8 endSeason);
extern GameEvent *Event3DDemo_Create(GameSystem *gsys, GameEvent *parent, u32 demoId, u32 unk3, u32 unk4);
extern void gfxSetLCDCBanks(u32 banks);
extern void gfxDisableLCDCBanks(void);
extern void sys_memset32_fast(u32 value, void *dest, u32 size);
extern u32 Season_GetRealTime(void);
extern void Season_Set(GameData *gameData, u16 season);
extern u8 GameData_GetSeason(GameData *gameData);
extern void GameData_GetSeasons(GameData *gameData, u16 *prevSeason, u16 *season);
extern u32 Season_GetNext(u8 season);
extern CityState *func_02017214(GameData *gameData);
extern PlayerInfo *GetGameDataPlayerInfo(GameData *gameData);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern void func_ov012_0215cd58(CityState *state);
extern EventWork *GameData_GetEventWork(GameData *gameData);
extern void FieldScript_CallPlayerInitSetup(GameSystem *gsys, u32 a1);
extern void FieldMapControl_LoadZone(GameSystem *gsys, u16 zoneId);
extern void FieldMapControl_InitSpawn(GameSystem *gsys, ZoneSpawnInfo *spawn);
extern void FieldMapControl_DeleteAllActors(GameSystem *gsys);
extern void func_0202d3f0(u16 zoneId, GameData *gameData);
extern u32 GetMapBGMIDByPlayerState2(GameData *gameData, int zoneId, u8 season);
extern GameEvent *EventBGMChange_Create(GameSystem *gsys, u32 bgm, u32 a2, u32 a3);
extern GameEvent *EventFieldOpen_Create(GameSystem *gsys);
extern FieldPlayer *Field_GetPlayer(Field *field);
extern FieldActor *FieldPlayer_GetActor(FieldPlayer *player);
extern void SetActorFlag(FieldActor *actor, u32 flag);
extern void EventScriptCall_Start(GameEvent *event, u16 scriptId, void *a2, void *a3, u32 heapId);
extern GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4, u8 a5,
                                                  u8 a6);
extern void LoadAspertiaCitySpawnInfo(ZoneSpawnInfo *spawn);
extern void GFL_OvlLoad(u32 overlayId);
extern void GFL_OvlUnload(u32 overlayId);
extern void InitDreamRadarFlagSave(GameData *gameData, u32 heapId);
extern void InitItemBag(GameData *gameData, u32 heapId);
extern void *getSaveAdventureDataBlk(SaveControl *save);
extern void setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(void *adventure);
extern void GameSystemTimer_Start(void);
extern FieldStatus *GameData_GetFieldStatus(GameData *gameData);
extern void FieldStatus_SetContinueFlag(FieldStatus *status, BOOL flag);
extern ZoneSpawnInfo *GameData_GetNextZone(GameData *gameData);
void GameData_UpdatePartyForTimeOfDay(GameData *gameData);
extern void func_ov012_02162f44(GameData *gameData);
extern void func_ov012_0215ef24(GameData *gameData, u16 zoneId);
extern void UpdateWeatherToDefault(GameData *gameData, u16 zoneId);
extern s32 GetZoneNPCInfoCacheIdx(u16 zoneId);
extern MMSys *GameData_GetMMSys(GameData *gameData);
extern void LoadMModelSystemInfoCache(MMSys *mmSys, s32 index);
extern void FldActSys_ClearCache(MMSys *mmSys);
extern u16 *EventWork_GetWkPtr(EventWork *eventWork, u32 work);
extern PlaceName *Field_GetPlaceName(Field *field);
extern void BeginContinuePlaceNameDisp(PlaceName *placeName, u16 zoneId);
extern BOOL EventWork_FlagGet(EventWork *eventWork, u32 flag);
extern void EventWork_FlagReset(EventWork *eventWork, u32 flag);
extern void *SaveControl_GetPokePartySave(SaveControl *save);
extern void *getTrainerCardDataBlkAddress(GameData *gameData);
extern BOOL hasClockNotBeenTampered(void *adventure);
extern void *getSaveAdventureTimeBlock(SaveControl *save);
extern void setNewDayForCountdown(void *adventureTime);
extern u32 func_ov012_02164428(GameData *gameData, void *party);
extern s64 RTC_ConvertSecondsCached(u32 time);
extern void setSecondsCurrentTimeInTrainerCard(void *trainerCard, s64 seconds);
extern void TransformVsPokePartyBySeason(GameData *gameData, void *party, u8 season);
extern u16 Field_GetHeapID(Field *field);
extern u16 ZoneData_GetAreaID(u16 zoneId);
extern AreaData *AreaData_Create(u16 heapId, u16 areaId, u32 a2);
extern BOOL AreaData_IsExterior(AreaData *areaData);
extern void AreaData_Free(AreaData *areaData);
extern u32 GetOutTransitionTypeBetweenZones(u16 fromZone, u16 toZone);
extern u32 GetInTransitionTypeBetweenZones(u16 fromZone, u16 toZone);
extern EventData *GameData_GetEventData(GameData *gameData);
extern ZoneWarp *GetZoneWarpByID(EventData *eventData, u16 warpId);
extern u32 GetWarpTransitionType(ZoneWarp *warp);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern void FieldStatus_SetBusyFlag(FieldStatus *status, u32 flag);
typedef struct FieldLensFlare FieldLensFlare;
extern FieldLensFlare *Field_GetLensFlare(Field *field);
extern u32 GetZoneFogIndexAll(Field *field, u16 zoneId);
extern u16 Field_GetPlayerStateZoneID(Field *field);
extern void FieldLensFlare_DecideForZoneTransit(FieldLensFlare *lensFlare, u16 zoneId, u16 prevZoneId, u32 fog);
extern GameEvent *EventFieldCloseKeepSound_Create(GameSystem *gsys, Field *field);
extern void func_ov337_02180bdc(void);
extern BOOL func_02018b10(u16 zoneId);
extern u8 GameCommSys_BootCheck(void *comm);
extern void func_0202bd80(void *comm);
extern void *func_ov337_02180a84(void *arg0, void *arg1);
extern void *func_ov337_02180b30(void *arg0, void *arg1);
extern void *GameData_GetParty(GameData *gameData);
extern void func_ov012_021643f0(GameData *gameData, void *party, void *hour, u8 season);
void GameData_UpdateZoneChangeFlag(GameData *gameData, u16 zoneId, u16 prevZoneId);
extern void func_ov012_0215ee94(GameData *gameData, u16 zoneId);
extern void func_ov012_0215eedc(GameData *gameData, u16 zoneId);
extern void func_ov012_0215eeb8(GameData *gameData, u16 zoneId);
extern void ShutdownFollowWork(GameData *gameData);
extern void func_ov012_02153668(void *comm);
extern BOOL GameData_IsLensFlareRequested(GameData *gameData);
extern void GameData_SetLensFlareRequested(GameData *gameData, BOOL requested);
extern void FieldLensFlare_RequestStart(FieldLensFlare *lensFlare);
extern void GameData_InitEncountTerrain(GameData *gameData, Field *field);
extern GameEvent *func_0202fee8(GameSystem *gsys);
typedef struct FieldSound FieldSound;
typedef struct FieldActorSystem FieldActorSystem;
typedef struct FieldTaskManager FieldTaskManager;
typedef struct FieldSubscreen FieldSubscreen;
typedef struct PlayerState PlayerState;
typedef struct EncountSystem EncountSystem;
extern FieldSound *GameData_GetFieldSoundSystem(GameData *gameData);
extern void FieldSnd_SetZoneBGM(FieldSound *fieldSound, GameData *gameData, u16 zoneId, u8 season);
extern void FieldSnd_FadeInImmediate(FieldSound *fieldSound, GameData *gameData);
extern GameEvent *CallEventPrepareResidentActorsForZoneChange(GameSystem *gsys, Field *field);
extern FieldActorSystem *Field_GetActorSystem(Field *field);
extern void DisableAllActorsMovement(FieldActorSystem *actorSystem);
extern GameEvent *EventWarpSequence_CreateOut(WarpSequence *warp);
extern GameEvent *EventWarpSequence_CreateIn(WarpSequence *warp);
extern GameEvent *CallFieldMapEntranceOutTransitionDefault(GameSystem *gsys, Field *field, u32 type, u32 a3);
extern GameEvent *EventQuicksandDrawIn_Create(GameEvent *event, GameSystem *gsys, Field *field, VecFx32 *pos);
extern GameEvent *EventQuicksandArrive_Create(GameEvent *event, GameSystem *gsys, Field *field);
extern GameEvent *EventEscapeRope_Create(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged);
extern GameEvent *EventDig_Create(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged);
extern GameEvent *EventTeleportEffect_Create(GameEvent *event, GameSystem *gsys, Field *field, BOOL a3);
extern GameEvent *func_ov036_021b95ac(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged,
                                      u16 prevSeason, u16 season);
extern GameEvent *func_ov036_021b95e0(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged,
                                      u16 prevSeason, u16 season);
extern GameEvent *func_ov036_021b9614(GameEvent *event, GameSystem *gsys, Field *field);
extern GameEvent *func_ov036_021b9664(GameEvent *event, GameSystem *gsys, Field *field);
extern GameEvent *func_ov036_021b9df8(GameEvent *event, GameSystem *gsys, Field *field);
extern GameEvent *EventPlayerSpinDown_Create(GameEvent *event, GameSystem *gsys, Field *field);
extern void func_ov036_021b50c8(PlaceName *placeName, int zoneId);
extern PlayerState *GameData_GetPlayerState(GameData *gameData);
extern void SetPlayerSpecialState(PlayerState *playerState, u32 state);
extern FieldTaskManager *Field_GetTaskManager(Field *field);
extern BOOL FieldTaskManager_IsIdle(FieldTaskManager *taskManager);
extern void func_02017414(GameData *gameData);
extern void func_02017424(GameData *gameData);
extern FieldSubscreen *Field_GetSubscreen(Field *field);
extern void FieldSubscreen_ChangeImm(FieldSubscreen *subscreen, u32 mode);
extern void func_ov028_02170ec8(GameSystem *gsys);
extern EncountSystem *Field_GetEncountSystem(Field *field);
extern void func_ov036_021a2398(EncountSystem *encount, u32 a1);
extern u16 ConvDirToWarpDir(u16 dir);
extern void CreateZoneChangeData(ZoneSpawnInfo *spawn, u16 zoneId, s16 warpDir, s32 x, s32 y, s32 z);
extern void func_0201906c(ZoneSpawnInfo *spawn, u16 zoneId, s16 warpDir, u16 componentId, u16 posFront,
                          s16 posSide);
extern ZoneSpawnInfo *GameData_GetEscapeRopeZone(GameData *gameData);
extern u16 GetReturnLocationIdx(GameData *gameData);
extern u16 GetRespawnZoneMainZone(u16 index);
extern void LoadZoneSpawnInfoCheckRail(ZoneSpawnInfo *spawn, u16 zoneId);
typedef struct HighLinkSave HighLinkSave;
extern VecFx32 *PlayerState_GetWPos(PlayerState *playerState);
extern u16 PlayerState_GetZoneID(PlayerState *playerState);
extern u16 PlayerState_CalcDirection(PlayerState *playerState);
extern void GameData_SetNextZone(GameData *gameData, ZoneSpawnInfo *spawn);
extern void GameData_SetEntralinkParentSpawnInfo(GameData *gameData, ZoneSpawnInfo *spawn);
extern ZoneSpawnInfo *GameData_GetEntralinkParentSpawnInfo(GameData *gameData);
extern HighLinkSave *getHighLinkBlockAddress(SaveControl *save);
extern u32 func_02017a40(GameData *gameData);
extern void func_0200c6f0(HighLinkSave *highLink, u32 a1, u32 a2);
extern void func_0202be00(void *comm);
extern void GameData_SetForceSeasonSync(GameData *gameData, BOOL force);
extern void func_020175d8(GameData *gameData, u32 a1);
extern void func_02017608(GameData *gameData, u32 a1);
extern void func_020175c4(GameData *gameData, u32 a1);
extern u32 Field_GetResolvedControllerTypeID(Field *field);
extern VecFx32 *GetMModelWPosPtr(FieldActor *actor);
extern void func_ov036_0219ad24(FieldPlayer *player, RailPosition *pos);
GameEvent *EventEntralinkWarpIn_CreateCore(GameSystem *gsys, Field *field, ZoneSpawnInfo *spawn, u32 a3, u32 a4);
GameEvent *EventEntralinkWarp_Create(GameSystem *gsys, Field *field, ZoneSpawnInfo *spawn);
void EventEntralinkWarp_CreateReturnLocation(ZoneSpawnInfo *spawn, Field *field);
extern BOOL IsWarpDestId256(ZoneWarp *warp);
extern void SetupWarpParamByWarp(ZoneWarp *warp, ZoneSpawnInfo *spawn, u32 a2);
extern ZoneSpawnInfo *GetOutboundWarpRememberSpawnInfo(GameData *gameData);
extern BOOL GetIsZoneMatrix0(u16 zoneId);
extern void GameData_SetEscapeRopeZone(GameData *gameData, ZoneSpawnInfo *spawn);
typedef struct ISS ISS;
typedef struct ISSSwitchSys ISSSwitchSys;
extern void SetupTeleportZoneChange(u16 returnLocation, ZoneSpawnInfo *spawn);
extern void func_ov012_0215ef00(GameData *gameData, u16 zoneId);
extern ISS *GameSystem_GetISS(GameSystem *gsys);
extern ISSSwitchSys *ISS_GetSwitchSys(ISS *iss);
extern void func_02032538(ISSSwitchSys *switchSys);
extern BOOL SetupZoneWarpArrival(EventData *eventData, ZoneSpawnInfo *spawn, u16 warpId, u16 posWeightBits);
extern void FieldStatus_SetNewLoadFlag(FieldStatus *status, BOOL flag);
extern void PlayerState_SetZoneID(PlayerState *playerState, u16 zoneId);
extern void PlayerState_SetRotation(PlayerState *playerState, u16 angle);
extern BOOL GetZoneSpawnInfoIsRail(ZoneSpawnInfo *spawn);
extern void PlayerState_SetWPos(PlayerState *playerState, VecFx32 *pos);
extern void PlayerState_SetRailPos(PlayerState *playerState, VecFx32 *pos);
extern void PlayerState_SetIsRail(PlayerState *playerState, BOOL isRail);
extern void ISS_ChangeZone(ISS *iss, u16 zoneId);
extern void SetGameDataNowSpawnZone(GameData *gameData, ZoneSpawnInfo *spawn);
extern u32 GetRespawnLocationIndexForRespawnZone(int zoneId);
extern void SetCurrentTeleportOrDeathZone(GameData *gameData, u16 respawnLocation);
extern void func_ov012_0215ee40(GameData *gameData, u16 zoneId);
extern void SetTeleportZoneDiscover(GameData *gameData, int zoneId);
extern void FieldScript_CallOnZoneInit(GameSystem *gsys, u32 a1);
extern void resetRebattleTrainers(EventWork *eventWork);
extern void func_ov012_021683f4(GameSystem *gsys, u16 zoneId);
extern void ResetWeather(GameSystem *gsys, int zoneId);
extern u32 GetZoneNPCsCount(EventData *eventData);
extern void *GetZoneNPCs(EventData *eventData);
extern void SpawnAllZoneNPCs(MMSys *mmSys, void *npcs, int zoneId, u32 count, EventWork *eventWork);
extern void FldActSys_DeleteAllActors(MMSys *mmSys);
typedef struct MapMatrix MapMatrix;
typedef struct GimmickState GimmickState;
typedef struct ArcTool ArcTool;
typedef struct JoinAvenueSave JoinAvenueSave;
typedef struct JoinAvenueInfo JoinAvenueInfo;
extern void *func_02017b84(GameData *gameData);
extern void **func_02017b7c(GameData *gameData);
extern BOOL IsZoneJoinAvenue(u16 zoneId);
extern BOOL func_02018c10(u16 zoneId);
extern void *func_02037fc4(u32 a0, u32 a1);
extern void func_02037ff4(void *a0);
extern JoinAvenueSave *SaveControl_GetJoinAvenue(SaveControl *save);
extern JoinAvenueInfo *JoinAvenue_GetInfo(JoinAvenueSave *joinAvenue);
extern u32 JoinAvenue_GetParam(JoinAvenueInfo *info, u32 param, u32 a2);
extern void func_02017b64(GameData *gameData, u8 a1);
extern void func_02038bc8(u32 a0);
extern void func_02039980(void *a0, u32 a1, u32 a2);
extern void *func_02010050(JoinAvenueSave *joinAvenue);
extern u32 func_0203802c(void *list);
extern void *func_02038060(void *list, u32 index);
extern BOOL func_02036e44(void *a0);
extern void func_020373ec(void *a0, u32 a1, u32 a2);
extern u32 GetZoneFlashFlags(u16 zoneId);
extern BOOL FieldStatus_CheckFlashUsed(FieldStatus *status);
extern void FieldStatus_SetFlashPerms(FieldStatus *status, u32 flags);
extern BOOL GameData_IsForceSeasonSync(GameData *gameData);
extern BOOL IsZoneEntralinkHub(u16 zoneId);
extern void func_02019318(FieldStatus *status, BOOL a1);
extern BOOL GetZoneIsUnionRoom(u16 zoneId);
extern BOOL IsZone150Or151(u16 zoneId);
extern BOOL GetZoneIsMusicalTheater(u16 zoneId);
extern BOOL IsZoneRoyalUnova(u16 zoneId);
extern BOOL GetZoneIsPWTBattleStage(u16 zoneId);
extern u32 GameData_GetLastSubscreen(GameData *gameData);
extern void GameData_SetLastSubscreen(GameData *gameData, u32 subscreen);
extern void EventData_LoadZone(EventData *eventData, u16 zoneId, u8 season);
extern MapMatrix *GetMapMatrixSystem(GameData *gameData);
extern u16 GetZoneMatrixId(u16 zoneId);
extern void MapMatrix_Load(MapMatrix *matrix, u16 matrixId, u16 zoneId, u16 heapId);
extern void MapMatrix_Patch(MapMatrix *matrix, GameSystem *gsys, u16 heapId);
extern void SetAllowVersionSpecificArea(u32 area, BOOL allow);
extern BOOL func_ov011_02154e70(GameData *gameData, u32 a1);
extern void SetActorHidden(FieldActor *actor, BOOL hidden);
extern GimmickState *GameData_GetGimmickState(GameData *gameData);
extern void GimmickState_Reset(GimmickState *gimmick);
extern void GimmickState_SetID(GimmickState *gimmick, u16 gimmickId);
extern ArcTool *GFL_ArcSysCreateFileHandle(u32 arcId, u16 heapId);
extern void *GFL_ArcToolReadHeapNew(ArcTool *handle, u32 fileId, u16 heapId);
extern u32 GFL_ArcToolGetDataLength(ArcTool *handle, u32 fileId);
extern void GFL_ArcToolFree(ArcTool *handle);
extern void GFL_HeapFree(void *ptr);
typedef struct LinkFestival LinkFestival;
typedef struct EncEff EncEff;
typedef struct KeyInfoSave KeyInfoSave;
extern void *GFL_HeapAllocate(u16 heapId, u32 size, BOOL clear, const char *file, u32 line);
extern LinkFestival *GSYS_GetLinkFestival(GameSystem *gsys);
extern u32 getStatusOfFesMission(LinkFestival *festival);
extern void func_ov036_021b5168(PlaceName *placeName);
extern void GFL_SndSEPlay(u16 se);
extern GameEvent *CallFieldMapEntranceOutTransition(GameSystem *gsys, Field *field, u32 type, u32 a3, u32 a4);
extern EncEff *Field_GetEncEff(Field *field);
extern void EncEff_StartEvent(EncEff *encEff, GameEvent *event, u32 effect);
extern GameEvent *func_ov036_021b8850(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4);
extern void BeginForcePlaceNameDisp(PlaceName *placeName, int zoneId);
extern BOOL EventEntralinkWarpIn_CheckAllowed(GameSystem *gsys);
extern BOOL GameData_CheckPairFlag(GameData *gameData);
extern u32 func_0203ffc4(void);
extern ZoneSpawnInfo *GetGameDataNowSpawnZone(GameData *gameData);
extern BOOL func_02018ecc(u16 zoneId);
extern BOOL GetZoneFlagsEnableEscapeRope(u16 zoneId);
extern BOOL IsZoneAbyssalRuinsOutside(u16 zoneId);
extern u32 FieldPlayerState_GetExState(PlayerState *playerState);
extern KeyInfoSave *getKeyInfoSaveBlk(SaveControl *save);
// Returns 1 if the key that switches the city is set
extern u32 func_02010564(KeyInfoSave *keyInfo);
GameEventReturnCode EventEntralinkWarpIn_Callback(GameEvent *event, u32 *state, EventEntralinkWarp *wk);
GameEventReturnCode EventEntralinkWarp_Callback(GameEvent *event, u32 *state, EventEntralinkWarp *wk);
void GameData_UpdateJoinAvenueForZone(GameData *gameData, u16 zoneId);
void GameData_SetGimmickByZone(GameData *gameData, int zoneId);
void GameData_UpdateFlashStatus(GameData *gameData, u16 zoneId);
void CallSpawnAllZoneNPCs(GameData *gameData, const ZoneSpawnInfo *spawn);
void GameData_UpdateEscapeRopeZone(GameData *gameData, const ZoneSpawnInfo *spawn);
void AdjustEscapeRopeSpawn(GameData *gameData, ZoneSpawnInfo *spawn);
void GameData_AdjustPlayerStateOnDiveOut(GameData *gameData);
void *EventMapChange_DSProtNop(void *arg0, void *arg1);
void *EventMapChange_DSProtTamper1(void *arg0, void *arg1);
void *EventMapChange_DSProtTamper2(void *arg0, void *arg1);

GameEvent *EventGameOpening_Create(GameSystem *gsys, GameSystemProcData *procData);
GameEvent *EventFieldFirst_Create(GameSystem *gsys, GameSystemProcData *procData);
GameEvent *EventFieldContinue_Create(GameSystem *gsys, GameSystemProcData *procData);
void EventFieldFirst_SetupCity(GameSystem *gsys);
void EventFieldContinue_SetupCity(GameSystem *gsys);
void CityState_InitFromSave(CityState *state, PlayerInfo *player, SaveControl *save, u32 unused);

// From the NitroSDK
static inline void VEC_Set(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void ClearLCDCVram(void) {
    gfxSetLCDCBanks(0x1ff);
    sys_memset32_fast(0, (void *)0x06800000, 0xa4000);
    gfxDisableLCDCBanks();
}

GameEvent *CreateGameEntryPointEvent(GameSystem *gsys, GameSystemProcData *procData) {
    switch (procData->entryPoint) {
    case GAME_ENTRYPOINT_OPENING:
        return EventGameOpening_Create(gsys, procData);
    case GAME_ENTRYPOINT_FIELD_CONTINUE:
        return EventFieldContinue_Create(gsys, procData);
    case GAME_ENTRYPOINT_DEBUG:
        return EventFieldFirst_Create(gsys, procData);
    }
}

GameEventReturnCode EventGameOpening_Callback(GameEvent *event, u32 *state, EventGameOpening *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = GSYS_GetGameData(gsys);
    u8 season;

    switch (*state) {
    case 0:
        ClearLCDCVram();
        (*state)++;
        break;
    case 1:
        Season_Set(gameData, Season_GetRealTime());
        season = GameData_GetSeason(gameData);
        GameEvent_ChainNext(event, EventSeasonBanner_CreateStandalone(gsys, season, season));
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, Event3DDemo_Create(gsys, event, 5, 0, 1));
        (*state)++;
        break;
    case 3:
        GameEvent_Replace(event, EventFieldFirst_Create(gsys, wk->procData));
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventGameOpening_Create(GameSystem *gsys, GameSystemProcData *procData) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventGameOpening_Callback, sizeof(EventGameOpening));
    EventGameOpening *wk = GameEvent_GetData(event);

    wk->gsys = gsys;
    wk->procData = procData;
    return event;
}

void EventFieldFirst_SetupCity(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    CityState *city = func_02017214(gameData);
    PlayerInfo *player = GetGameDataPlayerInfo(gameData);

    CityState_InitFromSave(city, player, GameData_GetSaveControl(gameData), 1);
    func_ov012_0215cd58(func_02017214(gameData));
}

GameEventReturnCode EventFieldFirst_Callback(GameEvent *event, u32 *state, EventFieldFirst *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = GSYS_GetGameData(gsys);
    EventWork *eventWork = GameData_GetEventWork(gameData);

    switch (*state) {
    case 0:
        FieldScript_CallPlayerInitSetup(gsys, 1);
        FieldMapControl_LoadZone(gsys, wk->spawn.zoneId);
        FieldMapControl_InitSpawn(gsys, &wk->spawn);
        func_0202d3f0(wk->spawn.zoneId, gameData);
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventBGMChange_Create(gsys,
            GetMapBGMIDByPlayerState2(gameData, wk->spawn.zoneId, GameData_GetSeason(gameData)), 0, 60));
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, EventFieldOpen_Create(gsys));
        (*state)++;
        break;
    case 3:
        SetActorFlag(FieldPlayer_GetActor(Field_GetPlayer(GSYS_GetField(gsys))), 4);
        EventScriptCall_Start(event, 0x1d, NULL, NULL, 1);
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, GSYS_GetField(gsys), 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 5:
        EventScriptCall_Start(event, 0x1e, NULL, NULL, 1);
        (*state)++;
        break;
    case 6:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventFieldFirst_Create(GameSystem *gsys, GameSystemProcData *procData) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventFieldFirst_Callback, sizeof(EventFieldFirst));
    EventFieldFirst *wk = GameEvent_GetData(event);

    wk->gsys = gsys;
    wk->gameData = GSYS_GetGameData(gsys);
    LoadAspertiaCitySpawnInfo(&wk->spawn);

    GFL_OvlLoad(OVERLAY_NEW_GAME);
    InitDreamRadarFlagSave(GSYS_GetGameData(gsys), 1);
    GFL_OvlUnload(OVERLAY_NEW_GAME);

    if (procData->entryPoint == GAME_ENTRYPOINT_OPENING) {
        GFL_OvlLoad(OVERLAY_NEW_GAME);
        InitItemBag(GSYS_GetGameData(gsys), 1);
        GFL_OvlUnload(OVERLAY_NEW_GAME);
    }

    EventFieldFirst_SetupCity(gsys);
    setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(getSaveAdventureDataBlk(GameData_GetSaveControl(wk->gameData)));
    GameSystemTimer_Start();
    ClearLCDCVram();
    return event;
}

void EventFieldContinue_SetupCity(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    CityState *city = func_02017214(gameData);
    PlayerInfo *player = GetGameDataPlayerInfo(gameData);

    CityState_InitFromSave(city, player, GameData_GetSaveControl(gameData), 1);
    func_ov012_0215cd58(func_02017214(gameData));
}

GameEventReturnCode EventFieldContinue_Callback(GameEvent *event, u32 *state, EventFieldContinue *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = GSYS_GetGameData(gsys);
    EventWork *eventWork = GameData_GetEventWork(gameData);

    switch (*state) {
    case 0:
        FieldStatus_SetContinueFlag(GameData_GetFieldStatus(gameData), TRUE);
        if (wk->continueFromSave) {
            ZoneSpawnInfo *next = GameData_GetNextZone(gameData);

            wk->zoneId = next->zoneId;
            FieldMapControl_DeleteAllActors(gsys);
            FieldMapControl_LoadZone(gsys, wk->zoneId);
            GameData_UpdatePartyForTimeOfDay(gameData);
            FieldMapControl_InitSpawn(gsys, next);
            func_0202d3f0(next->zoneId, gameData);
        } else {
            s32 cacheIdx;
            MMSys *mmSys;

            FieldMapControl_LoadZone(gsys, wk->zoneId);
            GameData_UpdatePartyForTimeOfDay(gameData);
            func_ov012_02162f44(gameData);
            func_ov012_0215ef24(gameData, wk->zoneId);
            UpdateWeatherToDefault(gameData, wk->zoneId);
            cacheIdx = GetZoneNPCInfoCacheIdx(wk->zoneId);
            mmSys = GameData_GetMMSys(gameData);
            if (cacheIdx < 24) {
                LoadMModelSystemInfoCache(mmSys, cacheIdx);
            } else {
                FldActSys_ClearCache(mmSys);
            }
        }
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventBGMChange_Create(gsys,
            GetMapBGMIDByPlayerState2(gameData, wk->zoneId, GameData_GetSeason(gameData)), 0, 60));
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, EventFieldOpen_Create(gsys));
        (*state)++;
        break;
    case 3:
        if (wk->continueFromSave && *EventWork_GetWkPtr(eventWork, EVENT_WORK_CONTINUE_SCRIPT) != 0) {
            EventScriptCall_Start(event, 0x83b, NULL, NULL, 0x15);
        } else {
            u8 season = GameData_GetSeason(gameData);
            GameEvent_ChainNext(event,
                CallFieldMapEntranceInTransition(gsys, GSYS_GetField(gsys), 3, 0, 0, season, season));
        }
        (*state)++;
        break;
    case 4: {
        Field *field = GSYS_GetField(gsys);

        if (Field_GetPlaceName(field) != NULL) {
            BeginContinuePlaceNameDisp(Field_GetPlaceName(field), wk->zoneId);
        }
        return GAMEEVENT_DONE;
    }
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventFieldContinue_Create(GameSystem *gsys, GameSystemProcData *procData) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventFieldContinue_Callback, sizeof(EventFieldContinue));
    EventFieldContinue *wk = GameEvent_GetData(event);
    EventWork *eventWork;
    SaveControl *save;
    void *adventure;
    void *party;
    void *trainerCard;

    wk->gsys = gsys;
    wk->gameData = GSYS_GetGameData(gsys);
    wk->zoneId = procData->zoneId;
    eventWork = GameData_GetEventWork(wk->gameData);
    wk->continueFromSave = EventWork_FlagGet(eventWork, EVENT_FLAG_CONTINUE_SCRIPT);
    EventWork_FlagReset(eventWork, EVENT_FLAG_CONTINUE_SCRIPT);

    save = GameData_GetSaveControl(wk->gameData);
    adventure = getSaveAdventureDataBlk(save);
    party = SaveControl_GetPokePartySave(save);
    trainerCard = getTrainerCardDataBlkAddress(wk->gameData);
    if (!hasClockNotBeenTampered(adventure)) {
        setNewDayForCountdown(getSaveAdventureTimeBlock(save));
        setSecondsCurrentTimeInTrainerCard(trainerCard,
                                           RTC_ConvertSecondsCached(func_ov012_02164428(wk->gameData, party)));
    }
    setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(adventure);
    TransformVsPokePartyBySeason(wk->gameData, party, GameData_GetSeason(wk->gameData));

    EventFieldContinue_SetupCity(gsys);
    GameSystemTimer_Start();
    ClearLCDCVram();
    return event;
}

void EventMapChange_LoadSeasons(EventMapChange *wk) {
    u16 prevSeason;
    u16 season;
    u16 heapId;
    AreaData *areaData;
    BOOL isExterior;

    GameData_GetSeasons(wk->gameData, &prevSeason, &season);
    heapId = Field_GetHeapID(wk->field);
    areaData = AreaData_Create(heapId, ZoneData_GetAreaID(wk->spawn.zoneId), 0);
    isExterior = FALSE;
    if (AreaData_IsExterior(areaData)) {
        isExterior = TRUE;
    }
    AreaData_Free(areaData);

    if (season != prevSeason && isExterior) {
        wk->seasonChanged = TRUE;
        wk->prevSeason = prevSeason;
        wk->season = season;
    }
}

void EventMapChange_SetupWarpSequenceOut(EventMapChange *wk, GameEvent *parent) {
    WarpSequence *warp = &wk->warp;

    warp->gsys = wk->gsys;
    warp->gameData = wk->gameData;
    warp->field = wk->field;
    warp->unk10 = wk->unk2C;
    warp->parent = parent;
    warp->zoneId = wk->zoneId;
    warp->spawn = wk->spawn;
    warp->outTransition = GetOutTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId);
    warp->inTransition = GetInTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId);
    warp->seasonChanged = (wk->unk40 && wk->seasonChanged) ? TRUE : FALSE;
    warp->startSeason = Season_GetNext(wk->prevSeason);
    warp->endSeason = wk->season;
    warp->unk48 = 0;
    warp->unk4C = 0;
}

void EventMapChange_SetupWarpSequenceIn(EventMapChange *wk, GameEvent *parent) {
    WarpSequence *warp = &wk->warp;

    warp->gsys = wk->gsys;
    warp->gameData = wk->gameData;
    warp->field = wk->field;
    warp->unk10 = wk->unk2C;
    warp->parent = parent;
    warp->zoneId = wk->zoneId;
    warp->spawn = wk->spawn;
    warp->outTransition = GetOutTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId);
    warp->inTransition = GetInTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId);
    warp->seasonChanged = (wk->unk40 && wk->seasonChanged) ? TRUE : FALSE;
    warp->startSeason = Season_GetNext(wk->prevSeason);
    warp->endSeason = wk->season;
    if (wk->spawn.changeType == ZONE_SPAWN_CHANGE_TYPE_POSITION) {
        warp->transitionType = 0;
    } else {
        warp->transitionType = GetWarpTransitionType(GetZoneWarpByID(GameData_GetEventData(wk->gameData), wk->spawn.warpId));
    }
}

GameEventReturnCode EventMapChangeCore_Callback(GameEvent *event, u32 *state, EventMapChangeCore *core) {
    EventMapChange *wk = core->mapChange;
    GameSystem *gsys = wk->gsys;
    GameData *gameData = wk->gameData;
    Field *field = wk->field;
    void *comm = GSYS_GetGameCommSystem(gsys);

    switch (*state) {
    case 0: {
        FieldLensFlare *lensFlare;
        u32 fog;

        FieldStatus_SetBusyFlag(GameData_GetFieldStatus(gameData), 2);
        lensFlare = Field_GetLensFlare(field);
        fog = GetZoneFogIndexAll(field, wk->spawn.zoneId);
        FieldLensFlare_DecideForZoneTransit(lensFlare, wk->spawn.zoneId, Field_GetPlayerStateZoneID(field), fog);
        GameEvent_ChainNext(event, EventFieldCloseKeepSound_Create(gsys, field));
        (*state)++;
        break;
    }
    case 1:
        GFL_OvlLoad(OVERLAY_DSPROT);
        func_ov337_02180bdc();
        if (func_02018b10(wk->spawn.zoneId) == TRUE) {
            u8 status = GameCommSys_BootCheck(comm);
            if (status == 1 || status == 2) {
                func_0202bd80(comm);
                *state = 2;
                break;
            }
        }
        *state = 3;
        break;
    case 2:
        if (!GameCommSys_BootCheck(comm)) {
            *state = 3;
        }
        break;
    case 3:
        DSPROT_CHECKED_CALL(func_ov337_02180a84, EventMapChange_DSProtTamper1, wk, gsys);
        FieldMapControl_DeleteAllActors(gsys);
        if (wk->unk40 && wk->seasonChanged) {
            void *adventureTime;
            u8 season;
            void *party;

            Season_Set(gameData, wk->season);
            adventureTime = getSaveAdventureTimeBlock(GameData_GetSaveControl(gameData));
            season = GameData_GetSeason(gameData);
            party = GameData_GetParty(gameData);
            TransformVsPokePartyBySeason(gameData, party, season);
            func_ov012_021643f0(gameData, party, (u8 *)adventureTime + 0x14, season);
        }
        DSPROT_CHECKED_CALL(func_ov337_02180b30, EventMapChange_DSProtTamper2, wk, gsys);
        FieldMapControl_LoadZone(gsys, wk->spawn.zoneId);
        GameData_UpdateZoneChangeFlag(gameData, wk->spawn.zoneId, wk->zoneId);
        FieldMapControl_InitSpawn(gsys, &wk->spawn);
        if (wk->mode != 4) {
            func_0202d3f0(wk->spawn.zoneId, gameData);
        }
        switch (wk->mode) {
        case 1:
            func_ov012_0215ee94(gameData, wk->spawn.zoneId);
            break;
        case 2:
            func_ov012_0215eedc(gameData, wk->spawn.zoneId);
            break;
        case 3:
            func_ov012_0215eeb8(gameData, wk->spawn.zoneId);
            break;
        }
        if (wk->mode != 0) {
            ShutdownFollowWork(wk->gameData);
        }
        GFL_OvlUnload(OVERLAY_DSPROT);
        func_ov012_02153668(comm);
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event, EventFieldOpen_Create(gsys));
        (*state)++;
        break;
    case 5: {
        Field *currentField = GSYS_GetField(gsys);

        if (GameData_IsLensFlareRequested(gameData)) {
            wk->lensFlareStarted = FALSE;
            GameData_SetLensFlareRequested(gameData, FALSE);
        }
        if (!wk->lensFlareStarted) {
            FieldLensFlare_RequestStart(Field_GetLensFlare(currentField));
        }
        GameData_InitEncountTerrain(gameData, currentField);
        GameEvent_ChainNext(event, func_0202fee8(gsys));
        (*state)++;
        break;
    }
    case 6:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventMapChangeCore_Create(EventMapChange *wk, u8 mode) {
    GameEvent *event = GameEvent_Create(wk->gsys, NULL, EventMapChangeCore_Callback, sizeof(EventMapChangeCore));
    EventMapChangeCore *core = GameEvent_GetData(event);

    core->mapChange = wk;
    wk->mode = mode;
    return event;
}

GameEventReturnCode EventMapChangeWarp_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    Field *field = wk->field;

    switch (*state) {
    case 0:
        EventMapChange_LoadSeasons(wk);
        DisableAllActorsMovement(Field_GetActorSystem(field));
        EventMapChange_SetupWarpSequenceOut(wk, event);
        GameEvent_ChainNext(event, EventWarpSequence_CreateOut(&wk->warp));
        (*state)++;
        return GAMEEVENT_CONTINUE_DIRECT;
    case 1:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 0));
        (*state)++;
        break;
    case 2:
        EventMapChange_SetupWarpSequenceIn(wk, event);
        GameEvent_ChainNext(event, EventWarpSequence_CreateIn(&wk->warp));
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChange_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;
    GameData *gameData = wk->gameData;
    FieldSound *fieldSound = GameData_GetFieldSoundSystem(gameData);

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        FieldSnd_SetZoneBGM(fieldSound, gameData, wk->spawn.zoneId, wk->season);
        FieldSnd_FadeInImmediate(fieldSound, gameData);
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, wk->mode));
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeEnding_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, wk->mode));
        (*state)++;
        break;
    case 2:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeFakeWarp_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;

    switch (*state) {
    case 0:
        EventMapChange_LoadSeasons(wk);
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        if (wk->unk40 && wk->seasonChanged) {
            GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, field, 0, 0));
        } else {
            GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, field,
                GetOutTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId), 0));
        }
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, wk->mode));
        (*state)++;
        break;
    case 3:
        if (wk->unk40 && wk->seasonChanged) {
            GameEvent_ChainNext(event,
                CallFieldMapEntranceInTransition(gsys, field, 3, 0, 0, wk->prevSeason, wk->season));
        } else {
            GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, field,
                GetInTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId), 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 4:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeQuicksand_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = wk->gameData;
    Field *field = wk->field;
    FieldSound *fieldSound = GameData_GetFieldSoundSystem(gameData);

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventQuicksandDrawIn_Create(event, gsys, field, &wk->unk34));
        (*state)++;
        break;
    case 2:
        FieldSnd_SetZoneBGM(fieldSound, gameData, wk->spawn.zoneId, wk->season);
        FieldSnd_FadeInImmediate(fieldSound, gameData);
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 0));
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event, EventQuicksandArrive_Create(event, gsys, field));
        (*state)++;
        break;
    case 5:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeEscapeRope_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = wk->gameData;
    Field *field = wk->field;
    FieldSound *fieldSound = GameData_GetFieldSoundSystem(gameData);

    switch (*state) {
    case 0:
        EventMapChange_LoadSeasons(wk);
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventEscapeRope_Create(event, gsys, field, wk->seasonChanged));
        (*state)++;
        break;
    case 2:
        GameData_AdjustPlayerStateOnDiveOut(gameData);
        FieldSnd_SetZoneBGM(fieldSound, gameData, wk->spawn.zoneId, wk->season);
        FieldSnd_FadeInImmediate(fieldSound, gameData);
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 2));
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event,
            func_ov036_021b95ac(event, gsys, field, wk->seasonChanged, wk->prevSeason, wk->season));
        (*state)++;
        break;
    case 5:
        func_ov036_021b50c8(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeDig_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = wk->gameData;
    Field *field = wk->field;
    FieldSound *fieldSound = GameData_GetFieldSoundSystem(gameData);

    switch (*state) {
    case 0:
        EventMapChange_LoadSeasons(wk);
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventDig_Create(event, gsys, field, wk->seasonChanged));
        (*state)++;
        break;
    case 2:
        GameData_AdjustPlayerStateOnDiveOut(gameData);
        FieldSnd_SetZoneBGM(fieldSound, gameData, wk->spawn.zoneId, wk->season);
        FieldSnd_FadeInImmediate(fieldSound, gameData);
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 2));
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event,
            func_ov036_021b95e0(event, gsys, field, wk->seasonChanged, wk->prevSeason, wk->season));
        (*state)++;
        break;
    case 5:
        func_ov036_021b50c8(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeTeleport_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = wk->gameData;
    Field *field = wk->field;
    FieldSound *fieldSound = GameData_GetFieldSoundSystem(gameData);

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventTeleportEffect_Create(event, gsys, field, TRUE));
        (*state)++;
        break;
    case 2:
        SetPlayerSpecialState(GameData_GetPlayerState(gameData), 0);
        FieldSnd_SetZoneBGM(fieldSound, gameData, wk->spawn.zoneId, wk->season);
        FieldSnd_FadeInImmediate(fieldSound, gameData);
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 3));
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event, func_ov036_021b9614(event, gsys, field));
        (*state)++;
        break;
    case 5:
        func_ov036_021b50c8(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeDiveOut_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;
    FieldTaskManager *taskManager = Field_GetTaskManager(field);

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, field, 1, 0));
        (*state)++;
        break;
    case 1:
        if (FieldTaskManager_IsIdle(taskManager)) {
            GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
            (*state)++;
        }
        break;
    case 2:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 0));
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, field, 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_ov036_021b50c8(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeDiveIn_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, field, 0, 0));
        (*state)++;
        break;
    case 2: {
        GameEvent *mapChange = GameEvent_Create(gsys, NULL, EventMapChange_Callback, sizeof(EventMapChange));
        EventMapChange *mapChangeWk = GameEvent_GetData(mapChange);

        *mapChangeWk = *wk;
        GameEvent_ChainNext(event, mapChange);
        (*state)++;
        break;
    }
    case 3:
        GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_ov036_021b50c8(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeWarpPad_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = wk->gameData;
    Field *field = wk->field;
    FieldSound *fieldSound = GameData_GetFieldSoundSystem(gameData);

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, func_ov036_021b9df8(event, gsys, field));
        (*state)++;
        break;
    case 2:
        FieldSnd_SetZoneBGM(fieldSound, gameData, wk->spawn.zoneId, wk->season);
        FieldSnd_FadeInImmediate(fieldSound, gameData);
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 0));
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, EventPlayerSpinDown_Create(event, gsys, field));
        (*state)++;
        break;
    case 4:
        func_ov036_021b50c8(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventMapChangeUnionRoomExit_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;
    GameData *gameData = wk->gameData;

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, EventTeleportEffect_Create(event, gsys, field, FALSE));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 0));
        (*state)++;
        break;
    case 2:
        GFL_OvlUnload(OVERLAY_28);
        GFL_OvlLoad(OVERLAY_27);
        func_02017424(gameData);
        FieldSubscreen_ChangeImm(Field_GetSubscreen(field), 0);
        EventScriptCall_Start(event, 0x83a, NULL, NULL, 0x15);
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventUnionRoomWarp_Callback(GameEvent *event, u32 *state, EventMapChange *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;
    GameData *gameData = wk->gameData;

    switch (*state) {
    case 0:
        func_02017414(gameData);
        FieldSubscreen_ChangeImm(Field_GetSubscreen(field), 0);
        GameEvent_ChainNext(event, CallEventPrepareResidentActorsForZoneChange(gsys, field));
        (*state)++;
        break;
    case 1:
        GFL_OvlUnload(OVERLAY_27);
        GFL_OvlLoad(OVERLAY_28);
        GameEvent_ChainNext(event, EventMapChangeCore_Create(wk, 4));
        (*state)++;
        break;
    case 2:
        func_ov028_02170ec8(gsys);
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, func_ov036_021b9664(event, gsys, field));
        (*state)++;
        break;
    case 4:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

void InitMapChangeEvent(EventMapChange *wk, GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);
    u8 season = GameData_GetSeason(gameData);

    wk->gsys = gsys;
    wk->gameData = gameData;
    wk->field = field;
    wk->zoneId = Field_GetPlayerStateZoneID(field);
    wk->unk40 = FALSE;
    wk->seasonChanged = FALSE;
    wk->prevSeason = season;
    wk->season = season;
    func_ov036_021a2398(Field_GetEncountSystem(wk->field), 1);
}

GameEvent *EventMapChangeWarp_CreateGrid(GameSystem *gsys, Field *field, u16 zoneId, const VecFx32 *pos, u16 dir,
                                         BOOL unk40) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeWarp_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    CreateZoneChangeData(&wk->spawn, zoneId, dir, pos->x, pos->y, pos->z);
    wk->unk2C = 0;
    wk->unk40 = unk40;
    wk->lensFlareStarted = TRUE;
    return event;
}

GameEvent *EventMapChangeWarp_CreateRail(GameSystem *gsys, Field *field, u16 zoneId, const RailPosition *pos, u16 dir,
                                         BOOL unk40) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeWarp_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    func_0201906c(&wk->spawn, zoneId, dir, pos->componentId, pos->posFront, pos->posSide);
    wk->unk2C = 0;
    wk->unk40 = unk40;
    wk->lensFlareStarted = TRUE;
    return event;
}

GameEvent *EventMapChange_CreateRail(GameSystem *gsys, Field *field, u16 zoneId, const RailPosition *pos, u16 dir,
                                     BOOL unk40) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChange_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    func_0201906c(&wk->spawn, zoneId, dir, pos->componentId, pos->posFront, pos->posSide);
    wk->unk2C = 0;
    wk->unk40 = unk40;
    return event;
}

GameEvent *EventMapChangeQuicksand_Create(GameSystem *gsys, Field *field, const VecFx32 *effectPos, u16 zoneId,
                                          VecFx32 *pos) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeQuicksand_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    CreateZoneChangeData(&wk->spawn, zoneId, 1, pos->x, pos->y, pos->z);
    VEC_Set(&wk->unk34, effectPos->x, effectPos->y, effectPos->z);
    wk->unk2C = 0;
    return event;
}

GameEvent *EventMapChangeEscapeRope_Create(Field *field, GameSystem *gsys) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeEscapeRope_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    wk->spawn = *GameData_GetEscapeRopeZone(wk->gameData);
    AdjustEscapeRopeSpawn(wk->gameData, &wk->spawn);
    wk->spawn.changeType = ZONE_SPAWN_CHANGE_TYPE_POSITION;
    wk->unk2C = 0;
    wk->unk40 = TRUE;
    return event;
}

GameEvent *EventMapChangeDig_Create(GameSystem *gsys) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeDig_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    wk->spawn = *GameData_GetEscapeRopeZone(wk->gameData);
    AdjustEscapeRopeSpawn(wk->gameData, &wk->spawn);
    wk->spawn.changeType = ZONE_SPAWN_CHANGE_TYPE_POSITION;
    wk->unk2C = 0;
    wk->unk40 = TRUE;
    return event;
}

GameEvent *EventMapChangeTeleport_Create(GameSystem *gsys) {
    u16 returnLocation = GetReturnLocationIdx(GSYS_GetGameData(gsys));
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeTeleport_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    LoadZoneSpawnInfoCheckRail(&wk->spawn, GetRespawnZoneMainZone(returnLocation));
    wk->spawn.changeType = ZONE_SPAWN_CHANGE_TYPE_POSITION;
    wk->unk2C = 0;
    return event;
}

GameEvent *EventMapChangeDiveOut_Create(GameSystem *gsys) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeDiveOut_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    wk->spawn = *GameData_GetNextZone(wk->gameData);
    wk->spawn.changeType = ZONE_SPAWN_CHANGE_TYPE_POSITION;
    wk->spawn.warpDir = WARP_DIR_DOWN;
    wk->unk2C = 0;
    return event;
}

GameEvent *EventMapChangeDiveIn_Create(GameSystem *gsys, u16 zoneId) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeDiveIn_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);
    ZoneSpawnInfo returnSpawn;
    PlayerState *playerState;
    VecFx32 *pos;
    u16 currentZoneId;

    InitMapChangeEvent(wk, gsys);
    LoadZoneSpawnInfoCheckRail(&wk->spawn, zoneId);
    wk->unk2C = 0;
    wk->spawn.warpDir = WARP_DIR_UP;

    // Resurface where the dive started
    playerState = GameData_GetPlayerState(wk->gameData);
    pos = PlayerState_GetWPos(playerState);
    currentZoneId = PlayerState_GetZoneID(playerState);
    CreateZoneChangeData(&returnSpawn, currentZoneId, PlayerState_CalcDirection(playerState), pos->x, pos->y, pos->z);
    GameData_SetNextZone(wk->gameData, &returnSpawn);
    return event;
}

GameEvent *EventMapChangeWarpPad_Create(GameSystem *gsys, Field *field, u16 zoneId, const VecFx32 *pos, u16 dir) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeWarpPad_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    CreateZoneChangeData(&wk->spawn, zoneId, dir, pos->x, pos->y, pos->z);
    wk->unk2C = 5;
    wk->unk40 = FALSE;
    wk->lensFlareStarted = TRUE;
    return event;
}

GameEvent *EventUnionRoomWarp_Create(GameSystem *gsys) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventUnionRoomWarp_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    CreateZoneChangeData(&wk->spawn, 0x1a6, ConvDirToWarpDir(0), FX32_CONST(184), 0, FX32_CONST(248));
    wk->unk2C = 0;
    return event;
}

GameEvent *EventMapChangeUnionRoomExit_Create(GameSystem *gsys) {
    ZoneSpawnInfo *next = GameData_GetNextZone(GSYS_GetGameData(gsys));
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeUnionRoomExit_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    wk->spawn = *next;
    return event;
}

GameEvent *EventEntralinkWarpIn_Create(GameSystem *gsys, u16 zoneId, VecFx32 *pos, u32 a3) {
    Field *field = GSYS_GetField(gsys);
    GameData *gameData = GSYS_GetGameData(gsys);
    VecFx32 spawnPos = *pos;
    ZoneSpawnInfo returnSpawn;
    ZoneSpawnInfo spawn;

    EventEntralinkWarp_CreateReturnLocation(&returnSpawn, field);
    GameData_SetEntralinkParentSpawnInfo(gameData, &returnSpawn);
    func_0200c6f0(getHighLinkBlockAddress(GameData_GetSaveControl(gameData)), func_02017a40(gameData), 0);
    CreateZoneChangeData(&spawn, zoneId, ConvDirToWarpDir(0), spawnPos.x, spawnPos.y, spawnPos.z);
    return EventEntralinkWarpIn_CreateCore(gsys, field, &spawn, a3, 0);
}

GameEvent *EventEntralinkWarp_CreateOut(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);
    ZoneSpawnInfo spawn = *GameData_GetEntralinkParentSpawnInfo(gameData);
    GameEvent *event = EventEntralinkWarp_Create(gsys, field, &spawn);
    void *comm = GSYS_GetGameCommSystem(gsys);

    if (!GameCommSys_BootCheck(comm)) {
        func_0202be00(comm);
    }
    GameData_SetForceSeasonSync(gameData, FALSE);
    func_020175d8(gameData, 0);
    func_02017608(gameData, 0);
    func_020175c4(gameData, 1);
    return event;
}

void EventEntralinkWarp_CreateReturnLocation(ZoneSpawnInfo *spawn, Field *field) {
    FieldPlayer *player = Field_GetPlayer(field);

    if (Field_GetResolvedControllerTypeID(field) == 0) {
        VecFx32 *pos = GetMModelWPosPtr(FieldPlayer_GetActor(player));

        CreateZoneChangeData(spawn, Field_GetPlayerStateZoneID(field), WARP_DIR_DOWN, pos->x, pos->y, pos->z);
    } else {
        RailPosition railPos;

        func_ov036_0219ad24(player, &railPos);
        func_0201906c(spawn, Field_GetPlayerStateZoneID(field), WARP_DIR_DOWN, railPos.componentId, railPos.posFront,
                      railPos.posSide);
    }
}

GameEvent *EventMapChangeWarp_CreateFromEntity(GameSystem *gsys, Field *field, ZoneWarp *warp, u32 a3) {
    EventMapChange *wk;
    GameEvent *event;
    ZoneSpawnInfo *remember;
    GameData *gameData;

    gameData = GSYS_GetGameData(gsys);
    event = GameEvent_Create(gsys, NULL, EventMapChangeWarp_Callback, sizeof(EventMapChange));
    wk = GameEvent_GetData(event);
    InitMapChangeEvent(wk, gsys);
    wk->unk40 = TRUE;
    if (IsWarpDestId256(warp)) {
        wk->spawn = *GameData_GetNextZone(gameData);
    } else {
        SetupWarpParamByWarp(warp, &wk->spawn, a3);
    }
    wk->unk2C = GetWarpTransitionType(warp);

    // Remember the exit when going from the overworld into a building or cave
    remember = GetOutboundWarpRememberSpawnInfo(gameData);
    if (GetIsZoneMatrix0(remember->zoneId) == TRUE && GetIsZoneMatrix0(wk->spawn.zoneId) == FALSE) {
        GameData_SetEscapeRopeZone(gameData, remember);
    }
    GameData_UpdateEscapeRopeZone(gameData, &wk->spawn);
    FieldStatus_SetBusyFlag(GameData_GetFieldStatus(gameData), 2);
    return event;
}

GameEvent *EventMapChange_CreateGrid(GameSystem *gsys, Field *field, u8 mode, u16 zoneId, VecFx32 *pos, u16 dir) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChange_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    CreateZoneChangeData(&wk->spawn, zoneId, dir, pos->x, pos->y, pos->z);
    wk->unk2C = 0;
    wk->mode = mode;
    wk->lensFlareStarted = TRUE;
    return event;
}

GameEvent *EventMapChange_CreateGridDefault(GameSystem *gsys, Field *field, u16 zoneId, VecFx32 *pos, u16 dir) {
    return EventMapChange_CreateGrid(gsys, field, 0, zoneId, pos, dir);
}

GameEvent *EventMapChange_CreateForFly(GameSystem *gsys, Field *field, u32 unused, ZoneSpawnInfo *spawn, u16 warpDir) {
    GameData *gameData = GSYS_GetGameData(gsys);
    GameEvent *event;
    EventMapChange *wk;

    SetPlayerSpecialState(GameData_GetPlayerState(gameData), 0);
    event = GameEvent_Create(gsys, NULL, EventMapChange_Callback, sizeof(EventMapChange));
    wk = GameEvent_GetData(event);
    InitMapChangeEvent(wk, gsys);
    wk->spawn = *spawn;
    wk->spawn.warpDir = warpDir;
    wk->unk2C = 0;
    wk->mode = 1;
    GameData_UpdateEscapeRopeZone(gameData, &wk->spawn);
    return event;
}

GameEvent *EventMapChangeFakeWarp_Create(GameSystem *gsys, Field *field, u16 zoneId, const VecFx32 *pos, u16 dir) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeFakeWarp_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    CreateZoneChangeData(&wk->spawn, zoneId, dir, pos->x, pos->y, pos->z);
    wk->unk2C = 0;
    wk->lensFlareStarted = TRUE;
    return event;
}

GameEvent *EventMapChangeEnding_Create(GameSystem *gsys, Field *field, u16 zoneId, const VecFx32 *pos, u16 dir) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeEnding_Callback, sizeof(EventMapChange));
    EventMapChange *wk = GameEvent_GetData(event);

    InitMapChangeEvent(wk, gsys);
    dir = ConvDirToWarpDir(dir);
    CreateZoneChangeData(&wk->spawn, zoneId, dir, pos->x, pos->y, pos->z);
    wk->unk2C = 0;
    wk->mode = 0;
    wk->lensFlareStarted = TRUE;
    return event;
}

void FieldMapControl_LoadBlackoutZone(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    ZoneSpawnInfo spawn;
    ZoneSpawnInfo escapeRopeSpawn;

    SetupTeleportZoneChange(GetReturnLocationIdx(gameData), &spawn);
    LoadZoneSpawnInfoCheckRail(&escapeRopeSpawn, GetRespawnZoneMainZone(GetReturnLocationIdx(gameData)));
    GameData_SetEscapeRopeZone(gameData, &escapeRopeSpawn);
    FieldMapControl_DeleteAllActors(gsys);
    FieldMapControl_LoadZone(gsys, spawn.zoneId);
    FieldMapControl_InitSpawn(gsys, &spawn);
    func_0202d3f0(spawn.zoneId, gameData);
    func_ov012_02162f44(gameData);
    func_ov012_0215ef00(gameData, spawn.zoneId);
    ShutdownFollowWork(gameData);
}

GameEventReturnCode EventMapChangeBlackout_Callback(GameEvent *event, u32 *state, EventMapChangeBlackout *wk) {
    switch (*state) {
    case 0:
        FieldMapControl_LoadBlackoutZone(wk->gsys);
        (*state)++;
        break;
    case 1:
        SetPlayerSpecialState(GameData_GetPlayerState(GSYS_GetGameData(wk->gsys)), 0);
        func_02032538(ISS_GetSwitchSys(GameSystem_GetISS(wk->gsys)));
        GameEvent_ChainNext(event, EventBGMChange_Create(wk->gsys,
            GetMapBGMIDByPlayerState2(wk->gameData, wk->spawn.zoneId, GameData_GetSeason(wk->gameData)), 0, 60));
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, EventFieldOpen_Create(wk->gsys));
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventMapChangeBlackout_Create(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventMapChangeBlackout_Callback, sizeof(EventMapChangeBlackout));
    EventMapChangeBlackout *wk = GameEvent_GetData(event);

    wk->gsys = gsys;
    wk->gameData = GSYS_GetGameData(gsys);
    SetupTeleportZoneChange(GetReturnLocationIdx(wk->gameData), &wk->spawn);
    return event;
}

u16 ConvWarpDirToAngle(int warpDir) {
    switch (warpDir) {
    default:
    case WARP_DIR_UP:
        return 0;
    case WARP_DIR_LEFT:
        return 0x4000;
    case WARP_DIR_DOWN:
        return 0x8000;
    case WARP_DIR_RIGHT:
        return 0xc000;
    }
}

void SetupZoneChangeSpawn(EventData *eventData, ZoneSpawnInfo *next, ZoneSpawnInfo *spawn) {
    if (next->changeType == ZONE_SPAWN_CHANGE_TYPE_POSITION) {
        *spawn = *next;
    } else if (!SetupZoneWarpArrival(eventData, spawn, next->warpId, next->posWeightBits)) {
        LoadZoneSpawnInfoCheckRail(spawn, next->zoneId);
    }
}

void FieldMapControl_InitSpawn(GameSystem *gsys, ZoneSpawnInfo *next) {
    GameData *gameData = GSYS_GetGameData(gsys);
    PlayerState *playerState = GameData_GetPlayerState(gameData);
    EventData *eventData = GameData_GetEventData(gameData);
    ZoneSpawnInfo spawn;
    u16 respawnLocation;
    s32 cacheIdx;
    MMSys *mmSys;

    FieldStatus_SetNewLoadFlag(GameData_GetFieldStatus(gameData), TRUE);
    SetupZoneChangeSpawn(eventData, next, &spawn);
    if (spawn.changeType == ZONE_SPAWN_CHANGE_TYPE_3) {
        GameData_SetNextZone(gameData, GetOutboundWarpRememberSpawnInfo(gameData));
    }

    PlayerState_SetZoneID(playerState, spawn.zoneId);
    PlayerState_SetRotation(playerState, ConvWarpDirToAngle(spawn.warpDir));
    if (!GetZoneSpawnInfoIsRail(&spawn)) {
        PlayerState_SetWPos(playerState, &spawn.pos);
        PlayerState_SetIsRail(playerState, FALSE);
    } else {
        PlayerState_SetRailPos(playerState, &spawn.pos);
        PlayerState_SetIsRail(playerState, TRUE);
    }

    ISS_ChangeZone(GameSystem_GetISS(gsys), spawn.zoneId);
    SetGameDataNowSpawnZone(gameData, &spawn);
    respawnLocation = GetRespawnLocationIndexForRespawnZone(spawn.zoneId);
    if (respawnLocation != 0) {
        SetCurrentTeleportOrDeathZone(gameData, respawnLocation);
    }
    GameData_SetGimmickByZone(gameData, spawn.zoneId);
    func_ov012_02162f44(gameData);
    func_ov012_0215ee40(gameData, spawn.zoneId);
    SetTeleportZoneDiscover(gameData, spawn.zoneId);
    FieldScript_CallOnZoneInit(gsys, 4);
    resetRebattleTrainers(GameData_GetEventWork(gameData));
    CallSpawnAllZoneNPCs(gameData, next);
    func_ov012_021683f4(gsys, spawn.zoneId);
    GameData_UpdateFlashStatus(gameData, spawn.zoneId);
    ResetWeather(gsys, spawn.zoneId);

    cacheIdx = GetZoneNPCInfoCacheIdx(spawn.zoneId);
    mmSys = GameData_GetMMSys(gameData);
    if (cacheIdx < 24) {
        LoadMModelSystemInfoCache(mmSys, cacheIdx);
    } else {
        FldActSys_ClearCache(mmSys);
    }
}

void CallSpawnAllZoneNPCs(GameData *gameData, const ZoneSpawnInfo *spawn) {
    EventData *eventData = GameData_GetEventData(gameData);
    u32 count = GetZoneNPCsCount(eventData);

    if (count != 0) {
        EventWork *eventWork = GameData_GetEventWork(gameData);
        MMSys *mmSys = GameData_GetMMSys(gameData);

        SpawnAllZoneNPCs(mmSys, GetZoneNPCs(eventData), spawn->zoneId, count, eventWork);
    }
}

void GameData_DeleteAllActors(GameData *gameData) {
    FldActSys_DeleteAllActors(GameData_GetMMSys(gameData));
}

// Allocates the Join Avenue data while in Join Avenue and frees it elsewhere, then resets its visitors
void GameData_UpdateJoinAvenueForZone(GameData *gameData, u16 zoneId) {
    void *unk = func_02017b84(gameData);
    void **joinAvenueList;

    if (IsZoneJoinAvenue(zoneId) || func_02018c10(zoneId)) {
        joinAvenueList = func_02017b7c(gameData);
        if (*joinAvenueList == NULL) {
            *joinAvenueList = func_02037fc4(4, 8);
        }
    } else {
        joinAvenueList = func_02017b7c(gameData);
        if (*joinAvenueList != NULL) {
            func_02037ff4(*joinAvenueList);
            *joinAvenueList = NULL;
        }
    }

    if (IsZoneJoinAvenue(zoneId)) {
        u16 param = JoinAvenue_GetParam(JoinAvenue_GetInfo(SaveControl_GetJoinAvenue(GameData_GetSaveControl(gameData))),
                                        5, 0);
        func_02017b64(gameData, param);
        func_02038bc8(0x18);
    }

    func_02039980(unk, 8, 0);
    {
        JoinAvenueSave *joinAvenue = SaveControl_GetJoinAvenue(GameData_GetSaveControl(gameData));
        void *lists[2] = {NULL, NULL};
        int i;

        joinAvenueList = func_02017b7c(gameData);
        lists[0] = func_02010050(joinAvenue);
        if (*joinAvenueList != NULL) {
            lists[1] = *joinAvenueList;
        }
        for (i = 0; i < 2; i++) {
            if (lists[i] != NULL) {
                u32 j;

                for (j = 0; j < func_0203802c(lists[i]); j++) {
                    void *entry = func_02038060(lists[i], j);

                    if (!func_02036e44(entry)) {
                        func_020373ec(entry, 0x26, 0);
                    }
                }
            }
        }
    }
}

// Sets flag 8 when the zone changed, which GameData_UpdateJoinAvenueForZone clears
void GameData_UpdateZoneChangeFlag(GameData *gameData, u16 zoneId, u16 prevZoneId) {
    void *unk = func_02017b84(gameData);

    if (zoneId != prevZoneId) {
        func_02039980(unk, 8, 1);
    }
}

void GameData_UpdateFlashStatus(GameData *gameData, u16 zoneId) {
    FieldStatus *status = GameData_GetFieldStatus(gameData);
    u32 flags = GetZoneFlashFlags(zoneId);

    if ((flags & 1) && FieldStatus_CheckFlashUsed(status)) {
        flags &= ~1;
        flags |= 2;
    }
    FieldStatus_SetFlashPerms(status, flags);
}

void FieldMapControl_LoadZone(GameSystem *gsys, u16 zoneId) {
    GameData *gameData = GSYS_GetGameData(gsys);
    EventData *eventData = GameData_GetEventData(gameData);
    Field *field = GSYS_GetField(gsys);
    MapMatrix *matrix;

    if (GameData_IsForceSeasonSync(gameData) == TRUE && !IsZoneEntralinkHub(zoneId)) {
        func_02019318(GameData_GetFieldStatus(gameData), TRUE);
    } else {
        func_02019318(GameData_GetFieldStatus(gameData), FALSE);
    }

    if (GetZoneIsUnionRoom(zoneId)) {
        GameData_SetLastSubscreen(gameData, 2);
    } else if (IsZone150Or151(zoneId) || GetZoneIsMusicalTheater(zoneId) || IsZoneRoyalUnova(zoneId)) {
        GameData_SetLastSubscreen(gameData, 5);
    } else if (GetZoneIsPWTBattleStage(zoneId)) {
        GameData_SetLastSubscreen(gameData, 11);
    } else {
        u32 subscreen;

        if (GameData_IsForceSeasonSync(gameData) == TRUE && GameData_GetLastSubscreen(gameData) != 3) {
            GameData_SetLastSubscreen(gameData, 3);
        } else if (GameData_IsForceSeasonSync(gameData) == FALSE && GameData_GetLastSubscreen(gameData) == 3) {
            GameData_SetLastSubscreen(gameData, 0);
        }
        subscreen = GameData_GetLastSubscreen(gameData);
        if (subscreen != 3 && subscreen != 4 && subscreen != 10 && subscreen != 6) {
            GameData_SetLastSubscreen(gameData, 0);
        }
    }

    EventData_LoadZone(eventData, zoneId, GameData_GetSeason(gameData));
    matrix = GetMapMatrixSystem(gameData);
    MapMatrix_Load(matrix, GetZoneMatrixId(zoneId), zoneId, HEAP_LOW(HEAPID_FIELD));
    MapMatrix_Patch(matrix, gsys, HEAP_LOW(HEAPID_FIELD));
    GameData_UpdateFlashStatus(gameData, zoneId);
    GameData_UpdateJoinAvenueForZone(gameData, zoneId);

    SetAllowVersionSpecificArea(VERSION_AREA_BLACK2, FALSE);
    SetAllowVersionSpecificArea(VERSION_AREA_WHITE2, FALSE);
    SetAllowVersionSpecificArea(VERSION_AREA_2, FALSE);
    if (func_ov011_02154e70(gameData, 0)) {
        SetAllowVersionSpecificArea(VERSION_AREA_2, TRUE);
        SetAllowVersionSpecificArea(VERSION_AREA_OWN, TRUE);
    }
}

void FieldMapControl_DeleteAllActors(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);

    GameData_DeleteAllActors(gameData);
}

void Field_SetPlayerHidden(Field *field, BOOL hidden) {
    SetActorHidden(FieldPlayer_GetActor(Field_GetPlayer(field)), hidden);
}

void GameData_SetGimmickByZone(GameData *gameData, int zoneId) {
    GimmickState *gimmick = GameData_GetGimmickState(gameData);
    ArcTool *handle;
    u32 i;
    ZoneGimmick *gimmicks;
    u32 count;

    GimmickState_Reset(gimmick);
    handle = GFL_ArcSysCreateFileHandle(ARC_ZONE_GIMMICKS, HEAP_LOW(HEAPID_FIELD));
    gimmicks = GFL_ArcToolReadHeapNew(handle, 0, HEAP_LOW(HEAPID_FIELD));
    count = GFL_ArcToolGetDataLength(handle, 0) / sizeof(ZoneGimmick);
    for (i = 0; i < count; i++) {
        if (zoneId == gimmicks[i].zoneId) {
            GimmickState_SetID(gimmick, gimmicks[i].gimmickId);
            break;
        }
    }
    GFL_HeapFree(gimmicks);
    GFL_ArcToolFree(handle);
}

GameEvent *EventEntralinkWarpIn_CreateCore(GameSystem *gsys, Field *field, ZoneSpawnInfo *spawn, u32 a3, u32 a4) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventEntralinkWarpIn_Callback, sizeof(EventEntralinkWarp));
    EventEntralinkWarp *wk = GameEvent_GetData(event);

    wk->spawn = *spawn;
    wk->gsys = gsys;
    wk->gameData = GSYS_GetGameData(gsys);
    wk->field = field;
    wk->unk28 = a3;
    wk->unk2C = a4;
    return event;
}

GameEvent *EventEntralinkWarp_Create(GameSystem *gsys, Field *field, ZoneSpawnInfo *spawn) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventEntralinkWarp_Callback, sizeof(EventEntralinkWarp));
    EventEntralinkWarp *wk = GameEvent_GetData(event);

    wk->spawn = *spawn;
    wk->gsys = gsys;
    wk->gameData = GSYS_GetGameData(gsys);
    wk->field = field;
    wk->festMissionStatus = getStatusOfFesMission(GSYS_GetLinkFestival(gsys));
    return event;
}

GameEventReturnCode EventEntralinkWarp_Callback(GameEvent *event, u32 *state, EventEntralinkWarp *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = wk->field;

    switch (*state) {
    case 0:
        func_ov036_021b5168(Field_GetPlaceName(field));
        if (wk->festMissionStatus != 0) {
            GFL_SndSEPlay(SEQ_SE_ENTRALINK_WARP);
            GameEvent_ChainNext(event, CallFieldMapEntranceOutTransition(gsys, field, 1, 0, 4));
        } else {
            GFL_SndSEPlay(SEQ_SE_ENTRALINK_WARP);
            EncEff_StartEvent(Field_GetEncEff(field), event, 0x25);
        }
        (*state)++;
        break;
    case 1: {
        GameEvent *mapChange = GameEvent_Create(gsys, NULL, EventMapChange_Callback, sizeof(EventMapChange));
        EventMapChange *mapChangeWk = GameEvent_GetData(mapChange);

        InitMapChangeEvent(mapChangeWk, gsys);
        mapChangeWk->spawn = wk->spawn;
        mapChangeWk->unk2C = 0;
        mapChangeWk->unk40 = FALSE;
        GameEvent_ChainNext(event, mapChange);
        (*state)++;
        break;
    }
    case 2:
        if (wk->festMissionStatus != 0) {
            GameEvent_ChainNext(event, func_ov036_021b8850(gsys, field, 1, 0, 2));
        } else {
            GameEvent_ChainNext(event, func_ov036_021b8850(gsys, field, 0, 0, 2));
        }
        (*state)++;
        break;
    case 3:
        BeginForcePlaceNameDisp(Field_GetPlaceName(field), wk->spawn.zoneId);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventEntralinkWarpIn_Callback(GameEvent *event, u32 *state, EventEntralinkWarp *wk) {
    void *comm = GSYS_GetGameCommSystem(wk->gsys);

    switch (*state) {
    case 0: {
        u32 scriptId;

        if (!EventEntralinkWarpIn_CheckAllowed(wk->gsys)) {
            scriptId = 0x279c;
            *state = 2;
        } else if (GameData_CheckPairFlag(wk->gameData)) {
            scriptId = 0x27a1;
            *state = 2;
        } else {
            scriptId = 0x279a;
            func_0202bd80(comm);
            *state = 1;
        }
        EventScriptCall_Start(event, scriptId, NULL, NULL, Field_GetHeapID(wk->field));
        break;
    }
    case 1:
        if (!GameCommSys_BootCheck(comm)) {
            func_0202be00(comm);
            GameData_SetForceSeasonSync(wk->gameData, TRUE);
            func_020175d8(wk->gameData, func_0203ffc4());
            GameEvent_ChainNext(event, EventEntralinkWarp_Create(wk->gsys, wk->field, &wk->spawn));
            *state = 2;
        }
        break;
    case 2:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

// Sets where an Escape Rope leads when warping into the zones that need a special exit
void GameData_UpdateEscapeRopeZone(GameData *gameData, const ZoneSpawnInfo *spawn) {
    ZoneSpawnInfo *remember = GetOutboundWarpRememberSpawnInfo(gameData);
    ZoneSpawnInfo *now = GetGameDataNowSpawnZone(gameData);
    ZoneSpawnInfo escapeRopeSpawn;

    if (func_02018ecc(spawn->zoneId)) {
        if (now->zoneId == 0x88) {
            GameData_SetEscapeRopeZone(gameData, remember);
        } else if (now->zoneId == 0x23d) {
            LoadZoneSpawnInfoCheckRail(&escapeRopeSpawn, 0x23d);
            GameData_SetEscapeRopeZone(gameData, &escapeRopeSpawn);
        }
    }
    if (now->zoneId == 0x9e && GetZoneFlagsEnableEscapeRope(spawn->zoneId)) {
        GameData_SetEscapeRopeZone(gameData, remember);
    }
    if (now->zoneId == 0x28 && spawn->zoneId == 0x1ef) {
        GameData_SetEscapeRopeZone(gameData, remember);
    }
}

// An Escape Rope used outside the Abyssal Ruins leads to the next zone instead
void AdjustEscapeRopeSpawn(GameData *gameData, ZoneSpawnInfo *spawn) {
    if (IsZoneAbyssalRuinsOutside(GetGameDataNowSpawnZone(gameData)->zoneId)) {
        *spawn = *GameData_GetNextZone(gameData);
    }
}

void GameData_AdjustPlayerStateOnDiveOut(GameData *gameData) {
    PlayerState *playerState = GameData_GetPlayerState(gameData);

    if (FieldPlayerState_GetExState(playerState) != 3) {
        SetPlayerSpecialState(playerState, 0);
    } else {
        SetPlayerSpecialState(playerState, 2);
    }
}

// Applies the form changes of party Pokemon that happen at night. In the base game, only Sky Forme Shaymin changes,
// reverting to Land Forme.
void GameData_UpdatePartyForTimeOfDay(GameData *gameData) {
    SaveControl *save = GameData_GetSaveControl(gameData);
    void *party = SaveControl_GetPokePartySave(save);
    u8 season = GameData_GetSeason(gameData);

    func_ov012_021643f0(gameData, party, (u8 *)getSaveAdventureTimeBlock(save) + 0x14, season);
}

// DS Protect tamper responses, which leak memory
void *EventMapChange_DSProtTamper1(void *arg0, void *arg1) {
    GFL_HeapAllocate(HEAP_LOW(4), 0x1000, FALSE, "event_mapchange.c", 3931);
    return arg0;
}

void *EventMapChange_DSProtTamper2(void *arg0, void *arg1) {
    GFL_HeapAllocate(HEAP_LOW(4), 0x1000, FALSE, "event_mapchange.c", 3937);
    return arg1;
}

void *EventMapChange_DSProtNop(void *arg0, void *arg1) {
    return arg0;
}

void CityState_InitFromSave(CityState *state, PlayerInfo *player, SaveControl *save, u32 unused) {
    u32 switched = func_02010564(getKeyInfoSaveBlk(save));

    state->initialized = TRUE;
#ifdef BLACK2
    if (!switched) {
        state->city = CITY_BLACK_CITY;
    } else {
        state->city = CITY_WHITE_FOREST;
    }
#else
    if (!switched) {
        state->city = CITY_WHITE_FOREST;
    } else {
        state->city = CITY_BLACK_CITY;
    }
#endif
}

BOOL CityState_IsCityValid(CityState *state) {
    if (state->initialized == TRUE && state->city >= 2) {
        return FALSE;
    }
    return TRUE;
}

BOOL CityState_IsSet(CityState *state) {
    if (!state->initialized) {
        return FALSE;
    }
    if (CityState_IsCityValid(state)) {
        return TRUE;
    }
    return FALSE;
}
