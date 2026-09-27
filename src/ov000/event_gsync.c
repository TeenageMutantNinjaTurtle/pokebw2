#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;
typedef struct SaveControl SaveControl;
typedef struct DreamWorldSave DreamWorldSave;
typedef struct BoxSaveAccessor BoxSaveAccessor;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

#define reg_OS_IME (*(volatile u16 *)0x04000208)
#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
// Swaps the screens, so that the main engine drives the top screen
#define REG_GX_POWCNT_DSEL_MASK 0x8000

// From the NitroSDK
static inline BOOL OS_EnableIrq(void) {
    u16 prev = reg_OS_IME;
    reg_OS_IME = 1;
    return prev;
}

// Results of the Game Sync procs
#define GSYNC_RESULT_ACCOUNT 1
#define GSYNC_RESULT_CONNECT 2
#define GSYNC_RESULT_WIFI_SETTINGS 3
#define GSYNC_RESULT_NO_POKEMON 4
#define GSYNC_RESULT_SELECT_POKEMON 5
#define GSYNC_RESULT_RETRY_LOGIN 7

#define BOX2_MODE_DREAM_WORLD 5

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    void *buffer;
    u32 unk14;
    u32 unk18;
    u32 result;
    u32 unk20;
    u32 unk24;
} WifiLoginParam;

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} WifiLogoutParam;

typedef struct {
    GameData *gameData;
    BoxSaveAccessor *boxes;
    void *party;
    void *bag;
    void *playerInfo;
    u32 unk14;
    void *trainerData;
    u32 unk1C;
    void *unk20;
    u32 mode;
    u16 unk28;
    // Where the chosen Pokemon is, 0xff for both if none was chosen
    u8 tray;
    u8 position;
} Box2Param;

// The Game Sync procs also take this as their parameter
typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    SaveControl *save;
    u8 unkC[0x44];
    u32 unk50;
    u8 loginBuffer[0x174];
    u32 gsyncResult;
    BOOL bgmPushed;
    u16 boxTray;
    u16 boxPosition;
    u32 bgm;
    u8 unk1D8[0x80];
    WifiLoginParam login;
    WifiLogoutParam logout;
    Box2Param box;
    BOOL unk2C8;
} EventGameSync;

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern Field *GSYS_GetField(GameSystem *gsys);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern BoxSaveAccessor *GameData_GetBoxSaveAccessor(GameData *gameData);
extern void *GameData_GetParty(GameData *gameData);
extern void *GameData_GetBag(GameData *gameData);
extern void *GetGameDataPlayerInfo(GameData *gameData);
extern void *getTrainerDataBlkAddress(SaveControl *save);
extern DreamWorldSave *getDreamWorldStuffAddress(SaveControl *save);
extern BOOL DreamWorldSave_IsPokemonAsleep(DreamWorldSave *dreamWorld);
extern u32 howManyNormalPokesAreInAllBoxes(BoxSaveAccessor *boxes);
extern void sys_memset(void *dest, u32 value, u32 size);
extern u32 GFL_SndBGMGetID(void);
extern void GFL_SndBGMPlay(u32 bgm, u32 a1);
extern void GFL_SndBGMFadeIn(u32 frames);
extern void GFL_SndBGMPush(void);
extern void GFL_SndBGMPop(void);
extern void GFL_SndBGMSetPaused(BOOL paused);
extern void GFL_SndInit(void);
extern void GFL_SndDestroyHeap(void);
extern BOOL GFL_NetErrCheck(void);
extern void GFL_NetErrMarkShown(void);
extern void GFL_NetErrShow(u32 a0);
extern GameEvent *CallFieldMapEntranceOutTransitionDefault(GameSystem *gsys, Field *field, u32 type, u32 a3);
extern GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4, u32 a5,
                                                  u32 a6);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern void GSYS_QueueProc(GameSystem *gsys, u32 overlayId, const void *procFunctions, void *param);
extern void GSYS_QueueProcAsEvent(GameEvent *event, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GSYS_GetProcMgrState(GameSystem *gsys);
extern BOOL GSYS_TryBootGameComm(GameSystem *gsys);
extern const u8 GSYNC_PROC_FUNCTIONS[];
extern const u8 PDWACC_PROC_FUNCTIONS[];
extern const u8 DWC_UTILITY_PROC_FUNCTIONS[];
extern const u8 WIFILOGIN_PROC_FUNCTIONS[];
extern const u8 WIFILOGOUT_PROC_FUNCTIONS[];
extern const u8 BOX2_PROC_FUNCTIONS[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_182_ID[];
extern u32 OVERLAY_190_ID[];
extern u32 OVERLAY_199_ID[];
extern u32 OVERLAY_255_ID[];
#define OVERLAY_DWC_UTILITY ((u32)OVERLAY_182_ID)
#define OVERLAY_WIFILOGIN ((u32)OVERLAY_190_ID)
#define OVERLAY_GSYNC ((u32)OVERLAY_199_ID)
#define OVERLAY_BOX2 ((u32)OVERLAY_255_ID)

GameEvent *EventGameSync_Create(GameSystem *gsys);

GameEventReturnCode EventGameSync_Callback(GameEvent *event, u32 *state, EventGameSync *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = GSYS_GetField(gsys);

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, field, 0, 0));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, field));
        wk->unk2C8 = FALSE;
        *state = 2;
        break;
    case 2:
        sys_memset(wk->unkC, 0, sizeof(wk->unkC));
        wk->unk50 = 0;
        GSYS_QueueProc(gsys, OVERLAY_GSYNC, GSYNC_PROC_FUNCTIONS, wk);
        (*state)++;
        break;
    case 3:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (wk->gsyncResult == GSYNC_RESULT_CONNECT) {
                *state = 16;
            } else if (wk->gsyncResult == GSYNC_RESULT_WIFI_SETTINGS) {
                *state = 5;
            } else {
                *state = 10;
            }
        }
        break;
    case 5:
        (*state)++;
        break;
    case 6:
        // Nintendo Wi-Fi Connection settings, which need the sound heap's memory
        wk->bgm = GFL_SndBGMGetID();
        GFL_SndDestroyHeap();
        GSYS_QueueProc(gsys, OVERLAY_DWC_UTILITY, DWC_UTILITY_PROC_FUNCTIONS, wk);
        (*state)++;
        break;
    case 7:
        if (!GSYS_GetProcMgrState(gsys)) {
            *state = 14;
        }
        break;
    case 14:
        // Back from the Wi-Fi settings
        OS_EnableIrq();
        GFL_SndInit();
        GFL_SndBGMPlay(wk->bgm, 0xffff);
        GFL_SndBGMFadeIn(60);
        *state = 15;
        break;
    case 15:
        wk->unk2C8 = TRUE;
        *state = 2;
        break;
    case 10:
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        (*state)++;
        break;
    case 11:
        GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 12:
        if (wk->bgmPushed) {
            GFL_SndBGMPop();
            GFL_SndBGMSetPaused(FALSE);
            GFL_SndBGMFadeIn(60);
            wk->bgmPushed = FALSE;
        }
        (*state)++;
        break;
    case 13:
        return GAMEEVENT_DONE;
    case 16: {
        BOOL asleep = DreamWorldSave_IsPokemonAsleep(
            getDreamWorldStuffAddress(GameData_GetSaveControl(GSYS_GetGameData(gsys))));

        if (howManyNormalPokesAreInAllBoxes(GameData_GetBoxSaveAccessor(GSYS_GetGameData(gsys))) == 0 && !asleep) {
            wk->gsyncResult = GSYNC_RESULT_NO_POKEMON;
            *state = 19;
        } else {
            wk->login.unk14 = 0;
            GFL_SndBGMSetPaused(TRUE);
            GFL_SndBGMPush();
            wk->bgmPushed = TRUE;
            (*state)++;
        }
        break;
    }
    case 17:
        wk->login.buffer = wk->loginBuffer;
        GSYS_QueueProc(gsys, OVERLAY_WIFILOGIN, WIFILOGIN_PROC_FUNCTIONS, &wk->login);
        (*state)++;
        break;
    case 18:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (wk->login.result == 1) {
                *state = 10;
            } else if (!DreamWorldSave_IsPokemonAsleep(getDreamWorldStuffAddress(wk->save))) {
                wk->gsyncResult = GSYNC_RESULT_WIFI_SETTINGS;
                *state = 19;
            } else {
                wk->gsyncResult = 0;
                *state = 19;
            }
        }
        break;
    case 19:
        GSYS_QueueProc(gsys, OVERLAY_GSYNC, PDWACC_PROC_FUNCTIONS, wk);
        (*state)++;
        break;
    case 20:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (wk->gsyncResult == GSYNC_RESULT_ACCOUNT) {
                wk->unk2C8 = FALSE;
                *state = 2;
            } else if (wk->gsyncResult == GSYNC_RESULT_SELECT_POKEMON) {
                *state = 21;
            } else if (wk->gsyncResult == GSYNC_RESULT_NO_POKEMON) {
                *state = 21;
            } else if (wk->gsyncResult == GSYNC_RESULT_RETRY_LOGIN) {
                wk->login.unk14 = 1;
                *state = 17;
            } else {
                *state = 23;
            }
        }
        break;
    case 21:
        // Choose the Pokemon to send to the Dream World
        wk->box.gameData = GSYS_GetGameData(gsys);
        wk->box.boxes = GameData_GetBoxSaveAccessor(wk->box.gameData);
        wk->box.party = GameData_GetParty(wk->box.gameData);
        wk->box.bag = GameData_GetBag(wk->box.gameData);
        wk->box.playerInfo = GetGameDataPlayerInfo(wk->box.gameData);
        wk->box.trainerData = getTrainerDataBlkAddress(GameData_GetSaveControl(wk->box.gameData));
        wk->box.unk20 = wk->unk1D8;
        wk->box.unk1C = 0;
        wk->box.mode = BOX2_MODE_DREAM_WORLD;
        GSYS_QueueProcAsEvent(event, OVERLAY_BOX2, BOX2_PROC_FUNCTIONS, &wk->box);
        (*state)++;
        break;
    case 22:
        if (GFL_NetErrCheck()) {
            GFL_NetErrMarkShown();
            GFL_NetErrShow(0);
            wk->login.unk14 = 1;
            *state = 17;
        } else {
            wk->boxTray = wk->box.tray;
            wk->boxPosition = wk->box.position;
            if (wk->box.tray == 0xff && wk->box.position == 0xff) {
                *state = 23;
            } else {
                if (wk->gsyncResult == GSYNC_RESULT_NO_POKEMON) {
                    wk->gsyncResult = GSYNC_RESULT_CONNECT;
                } else {
                    wk->gsyncResult = GSYNC_RESULT_ACCOUNT;
                }
                *state = 19;
            }
        }
        break;
    case 23:
        wk->logout.gameData = GSYS_GetGameData(gsys);
        wk->logout.unk4 = 1;
        wk->logout.unk8 = 0;
        GSYS_QueueProc(gsys, OVERLAY_WIFILOGIN, WIFILOGOUT_PROC_FUNCTIONS, &wk->logout);
        (*state)++;
        break;
    case 24:
        if (!GSYS_GetProcMgrState(gsys)) {
            GSYS_TryBootGameComm(gsys);
            reg_GX_POWCNT |= REG_GX_POWCNT_DSEL_MASK;
            wk->unk2C8 = FALSE;
            *state = 2;
            if (wk->bgmPushed) {
                GFL_SndBGMPop();
                GFL_SndBGMSetPaused(FALSE);
                GFL_SndBGMFadeIn(60);
                wk->bgmPushed = FALSE;
            }
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

// Called through GameEvent_CreateOverlayDelegate, by the C-Gear's Game Sync button in overlay 79
GameEvent *EventGameSync_CreateFromArgs(GameSystem *gsys, void *args) {
    return EventGameSync_Create(gsys);
}

GameEvent *EventGameSync_Create(GameSystem *gsys) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventGameSync_Callback, sizeof(EventGameSync));
    EventGameSync *wk = GameEvent_GetData(event);

    wk->gameData = GSYS_GetGameData(gsys);
    wk->save = GameData_GetSaveControl(wk->gameData);
    wk->gsys = gsys;
    wk->login.gameData = GSYS_GetGameData(gsys);
    wk->login.unk4 = 1;
    wk->login.unk8 = 0;
    wk->login.unkC = 0x31;
    return event;
}
