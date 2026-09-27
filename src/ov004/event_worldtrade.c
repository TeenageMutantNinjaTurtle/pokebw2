#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;
typedef struct SaveControl SaveControl;
typedef struct WorldTradeData WorldTradeData;
typedef struct WifiList WifiList;
typedef struct PlayerInfo PlayerInfo;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

// Passed to the Global Trade Station, which runs in overlay 214
typedef struct {
    WorldTradeData *worldTrade;
    void *adventure;
    void *party;
    void *boxes;
    void *pokedex;
    WifiList *wifiList;
    void *unityTowerSurvey;
    PlayerInfo *playerInfo;
    void *trainerData;
    void *trainerCardInfo;
    void *bag;
    BOOL isNationalDex;
    s32 profileId;
    u32 unk34;
    u32 unk38;
    SaveControl *save;
    GameSystem *gsys;
} WorldTradeParam;

typedef struct {
    u32 bgm;
    GameSystem *gsys;
    Field *field;
    WorldTradeParam param;
    // Never set here, so the field transitions are skipped
    BOOL useTransitions;
} EventWorldTrade;

typedef struct {
    Field *field;
    u32 unused;
} EventWorldTradeArgs;

extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern BOOL GameCommSys_BootCheck(void *comm);
extern void GameCommSys_ExitReq(void *comm);
extern void *GameEvent_GetData(GameEvent *event);
extern void sys_memset(void *dest, u32 value, u32 size);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern WorldTradeData *SaveControl_GetWorldTradeData(SaveControl *save);
extern void *getSaveAdventureDataBlk(SaveControl *save);
extern void *SaveControl_GetPokePartySave(SaveControl *save);
extern void *GameData_GetBoxSaveAccessor(GameData *gameData);
extern void *GameData_GetPokedex(GameData *gameData);
extern WifiList *GameData_GetWifiList(GameData *gameData);
extern void *getUnityTower_SurveySaveBlkAddrress(SaveControl *save);
extern PlayerInfo *SaveControl_GetPlayerInfo(SaveControl *save);
extern void *getTrainerDataBlkAddress(SaveControl *save);
extern void *getTrainerCardInfoBlkAddress(SaveControl *save);
extern void *GameData_GetBag(GameData *gameData);
extern BOOL PokeDex_IsNationalObtained(void *pokedex);
extern s32 WifiList_GetMyGSID(WifiList *wifiList);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameEvent *CallFieldMapEntranceOutTransitionDefault(GameSystem *gsys, Field *field, u32 type, u32 a3);
extern u32 GFL_SndBGMGetID(void);
extern void GFL_SndBGMFadeOut(u32 frames);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern void GSYS_QueueProc(GameSystem *gsys, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GSYS_GetProcMgrState(GameSystem *gsys);
extern void GFL_SndBGMPlay(u32 bgm, u32 a1);
extern void GFL_SndBGMFadeIn(u32 frames);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4, u32 a5,
                                                  u32 a6);
extern const u8 WORLDTRADE_PROC_FUNCTIONS[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_214_ID[];
#define OVERLAY_WORLDTRADE ((u32)OVERLAY_214_ID)

GameEvent *EventWorldTrade_Create(GameSystem *gsys, Field *field, u32 unused);
GameEventReturnCode EventWorldTrade_Callback(GameEvent *event, int *state, EventWorldTrade *wk);

// Called through GameEvent_CreateOverlayDelegate, by the NetConnectGTS script command
GameEvent *EventWorldTrade_CreateFromArgs(GameSystem *gsys, EventWorldTradeArgs *args) {
    return EventWorldTrade_Create(gsys, args->field, args->unused);
}

GameEvent *EventWorldTrade_Create(GameSystem *gsys, Field *field, u32 unused) {
    GameData *gameData = GSYS_GetGameData(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventWorldTrade_Callback, sizeof(EventWorldTrade));
    EventWorldTrade *wk;

    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }

    wk = GameEvent_GetData(event);
    sys_memset(wk, 0, sizeof(EventWorldTrade));
    wk->gsys = gsys;
    wk->field = field;
    wk->param.save = GameData_GetSaveControl(gameData);
    wk->param.worldTrade = SaveControl_GetWorldTradeData(wk->param.save);
    wk->param.adventure = getSaveAdventureDataBlk(wk->param.save);
    wk->param.party = SaveControl_GetPokePartySave(wk->param.save);
    wk->param.boxes = GameData_GetBoxSaveAccessor(gameData);
    wk->param.pokedex = GameData_GetPokedex(gameData);
    wk->param.wifiList = GameData_GetWifiList(gameData);
    wk->param.unityTowerSurvey = getUnityTower_SurveySaveBlkAddrress(wk->param.save);
    wk->param.playerInfo = SaveControl_GetPlayerInfo(wk->param.save);
    wk->param.trainerData = getTrainerDataBlkAddress(wk->param.save);
    wk->param.trainerCardInfo = getTrainerCardInfoBlkAddress(wk->param.save);
    wk->param.bag = GameData_GetBag(gameData);
    wk->param.gsys = gsys;
    wk->param.isNationalDex = PokeDex_IsNationalObtained(wk->param.pokedex);
    wk->param.profileId = WifiList_GetMyGSID(wk->param.wifiList);
    wk->param.unk34 = 0;
    wk->param.unk38 = 0;
    return event;
}

GameEventReturnCode EventWorldTrade_Callback(GameEvent *event, int *state, EventWorldTrade *wk) {
    switch (*state) {
    case 0:
        // Wait for the comm system to shut down
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(wk->gsys))) {
            *state = 1;
        }
        break;
    case 1:
        if (wk->useTransitions) {
            GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(wk->gsys, wk->field, 0, 0));
        }
        wk->bgm = GFL_SndBGMGetID();
        GFL_SndBGMFadeOut(6);
        *state = 2;
        break;
    case 2:
        GameEvent_ChainNext(event, CreateFieldCloseEvent(wk->gsys, wk->field));
        *state = 3;
        break;
    case 3:
        GSYS_QueueProc(wk->gsys, OVERLAY_WORLDTRADE, WORLDTRADE_PROC_FUNCTIONS, &wk->param);
        *state = 4;
        break;
    case 4:
        if (!GSYS_GetProcMgrState(wk->gsys)) {
            GFL_SndBGMPlay(wk->bgm, 0xffff);
            GFL_SndBGMFadeIn(60);
            GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(wk->gsys));
            *state = 5;
        }
        break;
    case 5:
        if (wk->useTransitions) {
            GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(wk->gsys, wk->field, 0, 0, 1, 0, 0));
        }
        *state = 6;
        break;
    case 6:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
