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
    u32 changeType;
    s16 zoneId;
    u16 warpId;
    u16 warpDir;
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
    u32 unk0;
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
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    BOOL unk40;
    BOOL seasonChanged;
    u16 prevSeason;
    u16 season;
    WarpSequence warp;
} EventMapChange;

#define ZONE_SPAWN_CHANGE_TYPE_WARP 1

#define EVENT_FLAG_CONTINUE_SCRIPT 0x965
#define EVENT_WORK_CONTINUE_SCRIPT 0x4041

// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_279_ID[];
#define OVERLAY_NEW_GAME ((u32)OVERLAY_279_ID)

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
extern void *func_02017214(GameData *gameData);
extern PlayerInfo *GetGameDataPlayerInfo(GameData *gameData);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern void func_ov012_0215cd58(void *a0);
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
extern void EventScriptCall_Start(GameEvent *event, u32 scriptId, void *a2, void *a3, u32 a4);
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
extern void func_ov035_0217ec9c(GameData *gameData);
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

GameEvent *EventGameOpening_Create(GameSystem *gsys, GameSystemProcData *procData);
GameEvent *EventFieldFirst_Create(GameSystem *gsys, GameSystemProcData *procData);
GameEvent *EventFieldContinue_Create(GameSystem *gsys, GameSystemProcData *procData);
void func_ov035_0217ca2c(GameSystem *gsys);
void func_ov035_0217cbec(GameSystem *gsys);
void func_ov035_0217ed20(u16 *out, PlayerInfo *player, SaveControl *save, u32 unused);

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

void func_ov035_0217ca2c(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    void *keys = func_02017214(gameData);
    PlayerInfo *player = GetGameDataPlayerInfo(gameData);

    func_ov035_0217ed20(keys, player, GameData_GetSaveControl(gameData), 1);
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

    func_ov035_0217ca2c(gsys);
    setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(getSaveAdventureDataBlk(GameData_GetSaveControl(wk->gameData)));
    GameSystemTimer_Start();
    ClearLCDCVram();
    return event;
}

void func_ov035_0217cbec(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    void *keys = func_02017214(gameData);
    PlayerInfo *player = GetGameDataPlayerInfo(gameData);

    func_ov035_0217ed20(keys, player, GameData_GetSaveControl(gameData), 1);
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
            func_ov035_0217ec9c(gameData);
            FieldMapControl_InitSpawn(gsys, next);
            func_0202d3f0(next->zoneId, gameData);
        } else {
            s32 cacheIdx;
            MMSys *mmSys;

            FieldMapControl_LoadZone(gsys, wk->zoneId);
            func_ov035_0217ec9c(gameData);
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

    func_ov035_0217cbec(gsys);
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

void EventMapChange_SetupWarpSequenceOut(EventMapChange *wk, u32 unk0) {
    WarpSequence *warp = &wk->warp;

    warp->gsys = wk->gsys;
    warp->gameData = wk->gameData;
    warp->field = wk->field;
    warp->unk10 = wk->unk2C;
    warp->unk0 = unk0;
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

void EventMapChange_SetupWarpSequenceIn(EventMapChange *wk, u32 unk0) {
    WarpSequence *warp = &wk->warp;

    warp->gsys = wk->gsys;
    warp->gameData = wk->gameData;
    warp->field = wk->field;
    warp->unk10 = wk->unk2C;
    warp->unk0 = unk0;
    warp->zoneId = wk->zoneId;
    warp->spawn = wk->spawn;
    warp->outTransition = GetOutTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId);
    warp->inTransition = GetInTransitionTypeBetweenZones(wk->zoneId, wk->spawn.zoneId);
    warp->seasonChanged = (wk->unk40 && wk->seasonChanged) ? TRUE : FALSE;
    warp->startSeason = Season_GetNext(wk->prevSeason);
    warp->endSeason = wk->season;
    if (wk->spawn.changeType == ZONE_SPAWN_CHANGE_TYPE_WARP) {
        warp->transitionType = 0;
    } else {
        warp->transitionType = GetWarpTransitionType(GetZoneWarpByID(GameData_GetEventData(wk->gameData), wk->spawn.warpId));
    }
}
