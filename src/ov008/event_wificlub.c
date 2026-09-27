#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;
typedef struct SaveControl SaveControl;
typedef struct PlayerInfo PlayerInfo;
typedef struct PokeParty PokeParty;
typedef struct WifiList WifiList;
typedef struct GameProcManager GameProcManager;
typedef struct NetHandle NetHandle;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

#define HEAPID_USER 0x1
#define HEAPID_GAMEEVENT 0x4
// Allocates from the end of the heap
#define HEAP_LOW(heapId) ((heapId) | 0x8000)

#define SEQ_BGM_WIFI_CLUB 0x481
#define SEQ_BGM_WIFI_BATTLE 0x48c

typedef struct {
    u8 unk0[0x84];
    void *records;
} BtlSetup;

// Shared with the Wi-Fi Club proc
typedef struct {
    void *buffer;
    GameData *gameData;
    SaveControl *save;
    // What the player chose in the Wi-Fi Club, an index into sWifiClubModes
    u32 mode;
    u32 unk10;
    PokeParty *parties[2];
    void *unk1C;
    u8 unk20;
    u8 unk21[0x25];
    u8 unk46;
    // The friend's index in the friend list, plus 1
    u8 friendIndex;
    u8 unk48;
    u8 unk49;
    u8 unk4A[2];
} WifiClubData;

typedef struct {
    u8 battleMode;
    u16 nextState;
} WifiClubMode;

typedef struct {
    void *unk0;
    PokeParty *party;
    void *otherName;
    u8 otherGender;
    PokeParty *otherParty;
    GameData *gameData;
    u8 unk18;
    PokeParty *unk1C;
    PokeParty *party0;
    PokeParty *party1;
    u32 result;
} BattleSelectParam;

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} CommTvtParam;

typedef struct {
    GameData *gameData;
    PokeParty *party;
    u16 partyIndex;
    u8 unkA;
    u8 unkB;
    u32 unkC;
    u32 unk10;
} ShinkaDemoParam;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 next;
    u32 unkC;
    u32 unk10;
    GameData *gameData;
    void *unk18;
    PokeParty *party;
    ShinkaDemoParam *evolution;
    void *unk24;
    u32 unk28;
    u16 friendIndex;
} PokemonTradeParam;

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
    PokeParty *party;
    PlayerInfo *info;
    u32 unk8;
    u32 unkC;
} BattlePlayer;

typedef struct {
    GameData *gameData;
    BtlSetup *setup;
    BattlePlayer *players;
    u32 rule;
    u32 unk10;
    u32 unk14;
} BattleParam;

typedef struct {
    GameEvent *event;
    GameSystem *gsys;
    Field *field;
    void *self;
    u32 unk10;
    BOOL useTransitions;
    u32 unk18;
    GameProcManager *procManager;
    BattleSelectParam select;
    CommTvtParam tvt;
    WifiClubData *club;
    PokemonTradeParam trade;
    GameData *gameData;
    WifiList *wifiList;
    WifiLoginParam login;
    WifiLogoutParam logout;
    BtlSetup *btlSetup;
    BattlePlayer players[2];
    u8 unk100[0x20];
    u32 battleResult;
    u32 unk124;
    u8 unk128[0xc];
    void *records;
    BattleParam battle;
    u8 unk150[0x18];
    PokeParty *party;
    u32 unk16C;
    u16 bgm;
    u8 battleMode;
} EventWifiClub;

typedef struct {
    Field *field;
    BOOL useTransitions;
} EventWifiClubArgs;

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern BOOL GameCommSys_BootCheck(void *comm);
extern void GameCommSys_ExitReq(void *comm);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern WifiList *GameData_GetWifiList(GameData *gameData);
extern void *GameData_GetRecords(GameData *gameData);
extern PlayerInfo *func_02017378(GameData *gameData, u32 netId);
extern void *GetPlayerName(PlayerInfo *info);
extern u32 getTrainerGender(PlayerInfo *info);
extern PokeParty *PokeParty_Create(u16 heapId);
extern void PokeParty_Init(PokeParty *party);
extern void *GFL_HeapAllocate(u16 heapId, u32 size, BOOL clear, const char *file, u32 line);
extern void GFL_HeapFree(void *ptr);
extern void sys_memset(void *dest, u32 value, u32 size);
extern void GFL_OvlLoad(u32 overlayId);
extern void GFL_OvlUnload(u32 overlayId);
extern u32 GFL_SndBGMGetID(void);
extern void GFL_SndBGMFadeOut(u32 frames);
extern void GFL_SndBGMPlay(u32 bgm, u32 a1);
extern void GFL_SndBGMFadeIn(u32 frames);
extern void GFL_SndSetVolumeControlCallbacks(void);
extern void GFL_SndPlayerSetVolumeEx(u32 volume, u32 a1);
extern void PokeVoice_SetMasterVolume(u32 volume);
extern void PokeVoice_ResetMasterVolume(void);
extern void GFL_NetErrShow(u32 a0);
extern BOOL GFL_NetErrCheck(void);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4, u32 a5,
                                                  u32 a6);
extern void GSYS_QueueProcAsEvent(GameEvent *event, u32 overlayId, const void *procFunctions, void *param);
extern GameProcManager *CreateGameProcManager(u16 heapId);
extern void FreeGameProcManager(GameProcManager *manager);
extern void QueueGameProc(GameProcManager *manager, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GFL_ProcMgrUpdate(GameProcManager *manager);
extern BtlSetup *BtlSetup_Create(u16 heapId);
extern void BtlSetup_Free(BtlSetup *setup);
extern void BtlSetup_SetNet1v1Single(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, u16 heapId);
extern void BtlSetup_SetNet1v1Double(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, u16 heapId);
extern void BtlSetup_SetNetTriple(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, u16 heapId);
extern void BtlSetup_SetNetRotation(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, u16 heapId);
extern void func_0200b608(void *a0, u32 a1, BOOL a2);
extern void *func_0200b50c(u16 heapId);
extern void func_020186b0(BtlSetup *setup, u32 a1);
extern void func_02017d30(BtlSetup *setup, void *a1, u16 heapId);
extern void func_0201f63c(void *a0, PokeParty *party);
extern void func_02017cfc(BtlSetup *setup, PokeParty *party, u32 a2);
extern BOOL func_0200a150(WifiList *wifiList);
extern void func_0200a2d4(WifiList *wifiList, u32 friendIndex, u32 wins, u32 losses, u32 draws);
extern void func_0203021c(void);
// Network functions
extern BOOL func_02042788(void);
extern NetHandle *func_02040440(void);
extern u32 func_02042a6c(NetHandle *handle);
extern void func_02040624(NetHandle *handle, u32 a1, u32 a2);
extern BOOL func_02040664(NetHandle *handle, u32 a1, u32 a2);
extern void func_02040c20(u32 a0, const void *commands, u32 count, u32 a3);
extern void func_02040c64(u32 a0);
extern BOOL func_020427a4(void);
extern void func_02042860(u32 a0);
extern BOOL func_02042ab8(void);
extern void func_02012154(void);
extern void func_02011de0(void);
extern void func_ov173_021a6240(void *buffer);
extern const u8 WIFILOGIN_PROC_FUNCTIONS[];
extern const u8 WIFILOGOUT_PROC_FUNCTIONS[];
extern const u8 WIFICLUB_PROC_FUNCTIONS[];
extern const u8 POKEMONTRADE_WIFICLUB_PROC_FUNCTIONS[];
extern const u8 SHINKA_DEMO_PROC_FUNCTIONS[];
extern const u8 COMM_TVT_PROC_FUNCTIONS[];
// The battle party selection, the battle's comm commands and the battle
extern const u8 data_ov213_021bbb38[];
extern const u8 data_ov167_021d7448[];
extern const u8 data_ov010_0215039c[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_10_ID[];
extern u32 OVERLAY_139_ID[];
extern u32 OVERLAY_167_ID[];
extern u32 OVERLAY_173_ID[];
extern u32 OVERLAY_190_ID[];
extern u32 OVERLAY_194_ID[];
extern u32 OVERLAY_203_ID[];
extern u32 OVERLAY_213_ID[];
extern u32 OVERLAY_257_ID[];
extern u32 OVERLAY_284_ID[];
#define OVERLAY_BATTLE ((u32)OVERLAY_10_ID)
#define OVERLAY_139 ((u32)OVERLAY_139_ID)
#define OVERLAY_BATTLE_MAIN ((u32)OVERLAY_167_ID)
#define OVERLAY_WIFICLUB_MAIN ((u32)OVERLAY_173_ID)
#define OVERLAY_WIFILOGIN ((u32)OVERLAY_190_ID)
#define OVERLAY_POKEMONTRADE ((u32)OVERLAY_194_ID)
#define OVERLAY_WIFICLUB ((u32)OVERLAY_203_ID)
#define OVERLAY_BATTLE_SELECT ((u32)OVERLAY_213_ID)
#define OVERLAY_COMM_TVT ((u32)OVERLAY_257_ID)
#define OVERLAY_SHINKA_DEMO ((u32)OVERLAY_284_ID)

void EventWifiClub_Free(EventWifiClub *wk);
GameEventReturnCode EventWifiClub_Callback(GameEvent *event, u32 *state, EventWifiClub *wk);
void EventWifiClub_Init(GameEvent *event, GameSystem *gsys, Field *field, BOOL useTransitions);

static WifiClubMode sWifiClubModes[16] = {
    { 0, 25 }, { 0, 9 },  { 0, 25 },  { 0, 25 },  { 0, 25 },  { 0, 23 },  { 0, 18 },  { 7, 13 },
    { 8, 13 }, { 9, 13 }, { 10, 13 }, { 11, 13 }, { 12, 13 }, { 13, 13 }, { 14, 13 }, { 0, 25 },
};

void EventWifiClub_SetupBattle(EventWifiClub *wk, u32 mode) {
    GameData *gameData = GSYS_GetGameData(wk->gsys);
    u8 unk48 = wk->club->unk48;
    u32 rule;

    if (unk48) {
        func_0200b608(wk->club->unk1C, 13, TRUE);
    } else {
        func_0200b608(wk->club->unk1C, 13, FALSE);
    }

    switch (mode) {
    case 8:
        rule = 1;
        if (unk48) {
            rule = 3;
        }
        break;
    case 7:
        rule = 0;
        if (unk48) {
            rule = 2;
        }
        break;
    case 10:
        rule = 5;
        if (unk48) {
            rule = 7;
        }
        break;
    case 9:
        rule = 4;
        if (unk48) {
            rule = 6;
        }
        break;
    case 12:
        rule = 9;
        if (unk48) {
            rule = 11;
        }
        break;
    case 11:
        rule = 8;
        if (unk48) {
            rule = 10;
        }
        break;
    case 14:
        rule = 13;
        if (unk48) {
            rule = 15;
        }
        break;
    case 13:
        rule = 12;
        if (unk48) {
            rule = 14;
        }
        break;
    }
    wk->battle.rule = rule;
    wk->battle.unk10 = 0;

    switch (mode) {
    case 7:
    case 8:
        BtlSetup_SetNet1v1Single(wk->btlSetup, gameData, func_02040440(), 1, HEAPID_GAMEEVENT);
        break;
    case 9:
    case 10:
        BtlSetup_SetNet1v1Double(wk->btlSetup, gameData, func_02040440(), 1, HEAPID_GAMEEVENT);
        break;
    case 11:
    case 12:
        BtlSetup_SetNetTriple(wk->btlSetup, gameData, func_02040440(), 1, HEAPID_GAMEEVENT);
        break;
    case 13:
    case 14:
        BtlSetup_SetNetRotation(wk->btlSetup, gameData, func_02040440(), 1, HEAPID_GAMEEVENT);
        break;
    }

    func_020186b0(wk->btlSetup, 1);
    func_02017d30(wk->btlSetup, wk->club->unk1C, HEAPID_GAMEEVENT);
    func_0201f63c(wk->club->unk1C, wk->club->parties[0]);
    func_0201f63c(wk->club->unk1C, wk->club->parties[1]);
    wk->btlSetup->records = GameData_GetRecords(GSYS_GetGameData(wk->gsys));
}

void EventWifiClub_SetupBattleSelect(EventWifiClub *wk, GameData *gameData, u32 unused) {
    u32 netId = func_02042a6c(func_02040440());
    u32 otherNetId = 1 - netId;
    PlayerInfo *other = func_02017378(gameData, otherNetId);
    BattleSelectParam *select = &wk->select;

    select->unk0 = wk->club->unk1C;
    select->party = wk->club->parties[netId];
    select->otherName = GetPlayerName(other);
    select->otherGender = getTrainerGender(other);
    select->otherParty = wk->club->parties[otherNetId];
    select->gameData = gameData;
    select->unk18 = 0;
    PokeParty_Init(wk->party);
    select->unk1C = wk->party;
    select->party0 = wk->club->parties[0];
    select->party1 = wk->club->parties[1];
}

void EventWifiClub_SetBattleParty(EventWifiClub *wk, GameData *gameData, u32 unused) {
    func_02017cfc(wk->btlSetup, wk->party, 0);
}

// Resets the volume before logging in again
void EventWifiClub_ResetForLogin(EventWifiClub *wk) {
    GFL_SndPlayerSetVolumeEx(127, 63);
    PokeVoice_SetMasterVolume(127);
    wk->login.unk14 = 1;
}

GameEventReturnCode EventWifiClub_Callback(GameEvent *event, u32 *state, EventWifiClub *wk) {
    GameSystem *gsys = wk->gsys;
    u32 seq = *state;

    switch (seq) {
    case 0:
        wk->bgm = GFL_SndBGMGetID();
        GFL_SndBGMFadeOut(6);
        (*state)++;
        break;
    case 1:
        // Wait for the comm system to shut down
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
            wk->unk10 = 0;
            GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, wk->field));
            (*state)++;
        }
        break;
    case 2:
        GFL_SndSetVolumeControlCallbacks();
        *state = 8;
        break;
    case 4:
        if (func_020427a4()) {
            (*state)++;
            EventWifiClub_Free(wk);
            PokeVoice_ResetMasterVolume();
            GFL_SndBGMPlay(wk->bgm, 0xffff);
            GFL_SndBGMFadeIn(60);
        }
        break;
    case 5:
        func_0203021c();
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        (*state)++;
        break;
    case 6:
        if (wk->useTransitions) {
            GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, wk->field, 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 7:
        return GAMEEVENT_DONE;
    case 8:
        sys_memset(&wk->login, 0, sizeof(WifiLoginParam));
        *state = 9;
        wk->login.unk14 = 0;
        break;
    case 9:
        wk->login.gameData = GSYS_GetGameData(gsys);
        wk->login.unk8 = 1;
        wk->login.unk4 = 0;
        wk->login.unkC = 10;
        wk->login.unk18 = 1;
        GFL_SndBGMPlay(SEQ_BGM_WIFI_CLUB, 0xffff);
        wk->procManager = CreateGameProcManager(HEAPID_GAMEEVENT);
        QueueGameProc(wk->procManager, OVERLAY_WIFILOGIN, WIFILOGIN_PROC_FUNCTIONS, &wk->login);
        wk->club->mode = 0;
        *state = 10;
        break;
    case 10:
        if (GFL_ProcMgrUpdate(wk->procManager)) {
            GFL_NetErrShow(0);
            return GAMEEVENT_CONTINUE;
        }
        FreeGameProcManager(wk->procManager);
        if (wk->login.result == 1) {
            GFL_SndBGMFadeOut(6);
            *state = 25;
        } else if (!func_0200a150(GameData_GetWifiList(wk->gameData))) {
            *state = 30;
        } else if (wk->login.result == 0) {
            *state = 11;
            GFL_SndBGMFadeOut(6);
        } else {
            GFL_SndBGMFadeOut(6);
            *state = 25;
        }
        break;
    case 30:
        wk->logout.gameData = GSYS_GetGameData(gsys);
        wk->logout.unk8 = 1;
        wk->logout.unk4 = 0;
        wk->logout.unkC = 1;
        wk->logout.unk10 = 0;
        wk->logout.unk14 = 0;
        wk->logout.unk18 = 0;
        wk->procManager = CreateGameProcManager(HEAPID_GAMEEVENT);
        QueueGameProc(wk->procManager, OVERLAY_WIFILOGIN, WIFILOGOUT_PROC_FUNCTIONS, &wk->logout);
        (*state)++;
        break;
    case 31:
        if (GFL_ProcMgrUpdate(wk->procManager)) {
            GFL_NetErrShow(0);
            return GAMEEVENT_CONTINUE;
        }
        FreeGameProcManager(wk->procManager);
        GFL_SndBGMFadeOut(6);
        *state = 4;
        break;
    case 11:
        GFL_OvlLoad(OVERLAY_WIFICLUB_MAIN);
        GFL_OvlLoad(OVERLAY_139);
        func_ov173_021a6240(wk->club->buffer);
        if (wk->btlSetup != NULL) {
            BtlSetup_Free(wk->btlSetup);
            wk->btlSetup = NULL;
        }
        GSYS_QueueProcAsEvent(wk->event, OVERLAY_WIFICLUB, WIFICLUB_PROC_FUNCTIONS, wk->club);
        (*state)++;
        break;
    case 12:
        *state = sWifiClubModes[wk->club->mode].nextState;
        if (wk->club->mode == 1) {
            wk->login.unk14 = 1;
            EventWifiClub_ResetForLogin(wk);
        }
        wk->battleMode = sWifiClubModes[wk->club->mode].battleMode;
        GFL_OvlUnload(OVERLAY_139);
        GFL_OvlUnload(OVERLAY_WIFICLUB_MAIN);
        break;
    case 13:
        EventWifiClub_SetupBattleSelect(wk, GSYS_GetGameData(gsys), seq);
        wk->btlSetup = BtlSetup_Create(HEAPID_GAMEEVENT);
        EventWifiClub_SetupBattle(wk, wk->club->mode);
        GSYS_QueueProcAsEvent(wk->event, OVERLAY_BATTLE_SELECT, data_ov213_021bbb38, &wk->select);
        (*state)++;
        break;
    case 14:
        if (wk->select.result == 1) {
            if (func_02042788()) {
                wk->club->unk49 = 0;
                *state = 11;
            } else {
                EventWifiClub_ResetForLogin(wk);
                *state = 9;
            }
        } else {
            EventWifiClub_SetBattleParty(wk, GSYS_GetGameData(gsys), seq);
            GFL_OvlLoad(OVERLAY_BATTLE_MAIN);
            func_02040c20(0x100, data_ov167_021d7448, 9, 0);
            func_02040624(func_02040440(), 100, 10);
            (*state)++;
        }
        break;
    case 15:
        if (!func_02042788() || GFL_NetErrCheck()) {
            func_02012154();
            func_02011de0();
            EventWifiClub_ResetForLogin(wk);
            *state = 9;
        } else if (func_02040664(func_02040440(), 100, 10)) {
            (*state)++;
        }
        break;
    case 16: {
        int i;

        GFL_SndBGMPlay(SEQ_BGM_WIFI_BATTLE, 0xffff);
        wk->unk124 = 1;
        if (func_02042a6c(func_02040440()) == 0) {
            for (i = 0; i < 2; i++) {
                wk->players[i].info = func_02017378(GSYS_GetGameData(gsys), i);
                wk->players[i].party = wk->club->parties[i];
            }
        } else {
            u8 order[2] = { 1, 0 };

            for (i = 0; i < 2; i++) {
                wk->players[order[i]].info = func_02017378(GSYS_GetGameData(gsys), i);
                wk->players[order[i]].party = wk->club->parties[i];
            }
        }
        wk->battle.gameData = GSYS_GetGameData(wk->gsys);
        wk->battle.setup = wk->btlSetup;
        wk->battle.players = wk->players;
        wk->battle.unk14 = 1;
        wk->records = GameData_GetRecords(GSYS_GetGameData(wk->gsys));
        GFL_OvlUnload(OVERLAY_BATTLE_MAIN);
        GSYS_QueueProcAsEvent(wk->event, OVERLAY_BATTLE, data_ov010_0215039c, &wk->battle);
        (*state)++;
        break;
    }
    case 17:
        if (!func_02042788()) {
            EventWifiClub_ResetForLogin(wk);
            *state = 9;
        } else {
            if (wk->battleResult == 0) {
                func_0200a2d4(GameData_GetWifiList(GSYS_GetGameData(wk->gsys)), wk->club->friendIndex - 1, 1, 0, 0);
            } else if (wk->battleResult == 1) {
                func_0200a2d4(GameData_GetWifiList(GSYS_GetGameData(wk->gsys)), wk->club->friendIndex - 1, 0, 1, 0);
            }
            func_02040c64(0x100);
            *state = 11;
        }
        break;
    case 18:
        wk->trade.next = 0;
        wk->trade.friendIndex = wk->club->friendIndex;
        (*state)++;
        break;
    case 19:
        wk->trade.gameData = GSYS_GetGameData(gsys);
        GSYS_QueueProcAsEvent(wk->event, OVERLAY_POKEMONTRADE, POKEMONTRADE_WIFICLUB_PROC_FUNCTIONS, &wk->trade);
        (*state)++;
        break;
    case 20:
        switch (wk->trade.next) {
        case 1:
            *state = 21;
            break;
        case 2:
            wk->club->mode = 1;
            *state = 11;
            break;
        default:
            *state = 11;
            break;
        }
        if (!func_02042788()) {
            EventWifiClub_ResetForLogin(wk);
            *state = 9;
        }
        break;
    case 21: {
        ShinkaDemoParam *evolution =
            GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(ShinkaDemoParam), FALSE, "event_wificlub.c", 582);

        evolution->gameData = GSYS_GetGameData(wk->gsys);
        evolution->party = wk->trade.party;
        evolution->partyIndex = wk->trade.unkC;
        evolution->unkA = 0;
        evolution->unkB = wk->trade.unk10;
        evolution->unkC = 1;
        evolution->unk10 = 0;
        wk->trade.evolution = evolution;
        GSYS_QueueProcAsEvent(wk->event, OVERLAY_SHINKA_DEMO, SHINKA_DEMO_PROC_FUNCTIONS, evolution);
        *state = 22;
        break;
    }
    case 22:
        GFL_HeapFree(wk->trade.evolution);
        wk->trade.next = 1;
        *state = 19;
        if (!func_02042788()) {
            EventWifiClub_ResetForLogin(wk);
            *state = 9;
        }
        break;
    case 23:
        wk->tvt.gameData = GSYS_GetGameData(gsys);
        wk->tvt.unk4 = 3;
        GSYS_QueueProcAsEvent(wk->event, OVERLAY_COMM_TVT, COMM_TVT_PROC_FUNCTIONS, &wk->tvt);
        (*state)++;
        break;
    case 24:
        if (!func_02042788()) {
            EventWifiClub_ResetForLogin(wk);
            *state = 9;
        } else {
            *state = 11;
        }
        break;
    case 28:
        func_02042860(0);
        *state = 29;
        break;
    case 29:
        if (func_02042ab8()) {
            *state = 4;
        }
        break;
    case 25:
    case 26:
    case 27:
        *state = 4;
        break;
    }
    return GAMEEVENT_CONTINUE;
}

void EventWifiClub_Free(EventWifiClub *wk) {
    if (wk->btlSetup != NULL) {
        BtlSetup_Free(wk->btlSetup);
        wk->btlSetup = NULL;
    }
    GFL_HeapFree(wk->club->parties[0]);
    GFL_HeapFree(wk->club->parties[1]);
    GFL_HeapFree(wk->club->unk1C);
    GFL_HeapFree(wk->party);
    GFL_HeapFree(wk->club->buffer);
    GFL_HeapFree(wk->club);
}

void EventWifiClub_Init(GameEvent *event, GameSystem *gsys, Field *field, BOOL useTransitions) {
    EventWifiClub *wk;

    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }

    wk = GameEvent_GetData(event);
    wk->gsys = gsys;
    wk->field = field;
    wk->event = event;
    wk->useTransitions = useTransitions;
    wk->club = GFL_HeapAllocate(HEAP_LOW(HEAPID_GAMEEVENT), sizeof(WifiClubData), TRUE, "event_wificlub.c", 683);
    wk->club->buffer = GFL_HeapAllocate(HEAP_LOW(HEAPID_GAMEEVENT), 0x20, TRUE, "event_wificlub.c", 684);
    wk->club->gameData = GSYS_GetGameData(wk->gsys);
    wk->club->save = GameData_GetSaveControl(wk->club->gameData);
    wk->club->unk46 = 1;
    wk->club->unk49 = 0;
    wk->gameData = wk->club->gameData;
    wk->wifiList = GameData_GetWifiList(wk->gameData);
    wk->club->mode = 0;
    wk->party = PokeParty_Create(HEAP_LOW(HEAPID_GAMEEVENT));
    wk->trade.party = wk->party;
    wk->self = wk;
    wk->bgm = GFL_SndBGMGetID();
    wk->club->parties[0] = PokeParty_Create(HEAP_LOW(HEAPID_USER));
    wk->club->parties[1] = PokeParty_Create(HEAP_LOW(HEAPID_USER));
    wk->club->unk1C = func_0200b50c(HEAP_LOW(HEAPID_USER));
    wk->club->unk20 = 1;
}

GameEvent *EventWifiClub_Create(GameSystem *gsys, Field *field, BOOL useTransitions) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventWifiClub_Callback, sizeof(EventWifiClub));

    EventWifiClub_Init(event, gsys, field, useTransitions);
    return event;
}

// Called through GameEvent_CreateOverlayDelegate, by the NetConnectWiFiClub script command
GameEvent *EventWifiClub_CreateFromArgs(GameSystem *gsys, EventWifiClubArgs *args) {
    return EventWifiClub_Create(gsys, args->field, args->useTransitions);
}
