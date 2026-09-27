#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;
typedef struct PlayerInfo PlayerInfo;
typedef struct PokeParty PokeParty;
typedef struct NetHandle NetHandle;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

#define HEAPID_GAMEEVENT 0x4

// Results of the GTS Negotiation proc
#define GTSNEGO_RESULT_RETRY_LOGIN 0
#define GTSNEGO_RESULT_EXIT 1

// What to do after the trade proc
#define TRADE_NEXT_NEGOTIATE 2
#define TRADE_NEXT_EVOLVE 1

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
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    // Copies of the player's info
    PlayerInfo *playerInfo;
    PlayerInfo *playerInfo2;
    u8 unk1C[0x194];
    u32 result;
} GtsNegoParam;

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
    GtsNegoParam *nego;
    PokeParty *party;
    ShinkaDemoParam *evolution;
    void *buffer;
    u32 unk28;
    u32 unk2C;
} PokemonTradeParam;

typedef struct {
    u32 bgm;
    s32 timeout;
    u8 buffer[0x174];
    GameSystem *gsys;
    u32 unk180;
    GtsNegoParam nego;
    PokemonTradeParam trade;
    WifiLoginParam login;
    WifiLogoutParam logout;
    PokeParty *party;
    u32 unk3B0;
} EventGtsNego;

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern Field *GSYS_GetField(GameSystem *gsys);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern BOOL GameCommSys_BootCheck(void *comm);
extern void GameCommSys_ExitReq(void *comm);
extern PlayerInfo *GetGameDataPlayerInfo(GameData *gameData);
extern u32 PlayerInfo_GetSize(void);
extern PokeParty *PokeParty_Create(u16 heapId);
extern void sys_memset(void *dest, u32 value, u32 size);
extern void sys_memcpy(const void *src, void *dest, u32 size);
extern void *GFL_HeapAllocate(u16 heapId, u32 size, BOOL clear, const char *file, u32 line);
extern void GFL_HeapFree(void *ptr);
extern u32 GFL_SndBGMGetID(void);
extern void GFL_SndBGMFadeOut(u32 frames);
extern void GFL_SndBGMPlay(u32 bgm, u32 a1);
extern void GFL_SndBGMFadeIn(u32 frames);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern void GSYS_QueueProc(GameSystem *gsys, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GSYS_GetProcMgrState(GameSystem *gsys);
// Network functions, apparently checking the connection and synchronizing with the other player
extern BOOL func_02042788(void);
extern NetHandle *func_02040440(void);
extern void func_02040624(NetHandle *handle, u32 a1, u32 a2);
extern BOOL func_02040664(NetHandle *handle, u32 a1, u32 a2);
extern void func_02042e94(BOOL a0);
extern void func_02042e9c(BOOL a0);
extern void func_020421ac(u32 a0);
extern const u8 WIFILOGIN_PROC_FUNCTIONS[];
extern const u8 WIFILOGOUT_PROC_FUNCTIONS[];
extern const u8 GTSNEGO_PROC_FUNCTIONS[];
extern const u8 POKEMONTRADE_PROC_FUNCTIONS[];
extern const u8 SHINKA_DEMO_PROC_FUNCTIONS[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_190_ID[];
extern u32 OVERLAY_194_ID[];
extern u32 OVERLAY_195_ID[];
extern u32 OVERLAY_284_ID[];
#define OVERLAY_WIFILOGIN ((u32)OVERLAY_190_ID)
#define OVERLAY_POKEMONTRADE ((u32)OVERLAY_194_ID)
#define OVERLAY_GTSNEGO ((u32)OVERLAY_195_ID)
#define OVERLAY_SHINKA_DEMO ((u32)OVERLAY_284_ID)

GameEventReturnCode EventGtsNego_Callback(GameEvent *event, u32 *state, EventGtsNego *wk) {
    GameSystem *gsys = wk->gsys;
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);

    switch (*state) {
    case 0:
        wk->bgm = GFL_SndBGMGetID();
        GFL_SndBGMFadeOut(6);
        (*state)++;
        break;
    case 1:
        // Wait for the comm system to shut down
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
            GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, field));
            (*state)++;
        }
        break;
    case 2:
        wk->login.buffer = wk->buffer;
        wk->login.unkC = 0x33;
        GSYS_QueueProc(gsys, OVERLAY_WIFILOGIN, WIFILOGIN_PROC_FUNCTIONS, &wk->login);
        (*state)++;
        break;
    case 3:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (wk->login.result == 0) {
                (*state)++;
            } else {
                *state = 14;
            }
        }
        break;
    case 4:
        wk->nego.result = 0;
        GSYS_QueueProc(gsys, OVERLAY_GTSNEGO, GTSNEGO_PROC_FUNCTIONS, &wk->nego);
        (*state)++;
        break;
    case 5:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (wk->nego.result == GTSNEGO_RESULT_EXIT) {
                *state = 12;
            } else if (wk->nego.result == GTSNEGO_RESULT_RETRY_LOGIN) {
                wk->login.unk14 = 1;
                *state = 2;
            } else {
                wk->trade.next = 0;
                (*state)++;
            }
        }
        break;
    case 6:
        wk->trade.gameData = gameData;
        wk->trade.nego = &wk->nego;
        wk->trade.buffer = wk->buffer;
        GSYS_QueueProc(gsys, OVERLAY_POKEMONTRADE, POKEMONTRADE_PROC_FUNCTIONS, &wk->trade);
        (*state)++;
        break;
    case 7:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (!func_02042788()) {
                wk->login.unk14 = 1;
                *state = 2;
            } else if (wk->trade.next == TRADE_NEXT_NEGOTIATE) {
                *state = 4;
            } else if (wk->trade.next == TRADE_NEXT_EVOLVE) {
                *state = 10;
            } else {
                func_02040624(func_02040440(), 1, 12);
                func_02042e94(FALSE);
                func_02042e9c(FALSE);
                wk->timeout = 100;
                *state = 8;
            }
        }
        break;
    case 8:
        wk->timeout--;
        if (func_02040664(func_02040440(), 1, 12)) {
            *state = 9;
        }
        if (wk->timeout < 0) {
            *state = 9;
        }
        break;
    case 9:
        func_020421ac(1);
        *state = 4;
        break;
    case 10: {
        ShinkaDemoParam *evolution =
            GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(ShinkaDemoParam), FALSE, "event_gtsnego.c", 204);

        evolution->gameData = wk->trade.gameData;
        evolution->party = wk->party;
        evolution->partyIndex = wk->trade.unkC;
        evolution->unkA = 0;
        evolution->unkB = wk->trade.unk10;
        evolution->unkC = 1;
        evolution->unk10 = 0;
        wk->trade.evolution = evolution;
        GSYS_QueueProc(gsys, OVERLAY_SHINKA_DEMO, SHINKA_DEMO_PROC_FUNCTIONS, evolution);
        (*state)++;
        break;
    }
    case 11:
        if (!GSYS_GetProcMgrState(gsys)) {
            GFL_HeapFree(wk->trade.evolution);
            if (!func_02042788()) {
                wk->login.unk14 = 1;
                *state = 2;
            } else {
                wk->trade.next = TRADE_NEXT_EVOLVE;
                *state = 6;
            }
        }
        break;
    case 12:
        GSYS_QueueProc(gsys, OVERLAY_WIFILOGIN, WIFILOGOUT_PROC_FUNCTIONS, &wk->logout);
        (*state)++;
        break;
    case 13:
        if (!GSYS_GetProcMgrState(gsys)) {
            (*state)++;
        }
        break;
    case 14:
        GFL_HeapFree(wk->nego.playerInfo);
        GFL_HeapFree(wk->nego.playerInfo2);
        GFL_HeapFree(wk->party);
        GFL_SndBGMPlay(wk->bgm, 0xffff);
        GFL_SndBGMFadeIn(60);
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        (*state)++;
        break;
    case 15:
        (*state)++;
        break;
    case 16:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

EventGtsNego *EventGtsNego_Init(GameEvent *event, GameSystem *gsys, Field *field, u32 unk3B0) {
    EventGtsNego *wk;
    PlayerInfo *playerInfo;

    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }

    wk = GameEvent_GetData(event);
    wk->gsys = gsys;
    wk->unk3B0 = unk3B0;
    wk->party = PokeParty_Create(HEAPID_GAMEEVENT);
    wk->trade.party = wk->party;
    sys_memset(&wk->nego, 0, sizeof(GtsNegoParam));
    wk->nego.gameData = GSYS_GetGameData(gsys);
    wk->nego.playerInfo = GFL_HeapAllocate(HEAPID_GAMEEVENT, PlayerInfo_GetSize(), TRUE, "event_gtsnego.c", 291);
    wk->nego.playerInfo2 = GFL_HeapAllocate(HEAPID_GAMEEVENT, PlayerInfo_GetSize(), TRUE, "event_gtsnego.c", 292);
    playerInfo = GetGameDataPlayerInfo(GSYS_GetGameData(gsys));
    sys_memcpy(playerInfo, wk->nego.playerInfo, PlayerInfo_GetSize());

    sys_memset(&wk->login, 0, sizeof(WifiLoginParam));
    wk->login.gameData = GSYS_GetGameData(gsys);
    wk->login.unk4 = 0;
    wk->login.unk8 = 1;
    wk->logout.gameData = GSYS_GetGameData(gsys);
    wk->logout.unk4 = 0;
    wk->logout.unk8 = 1;
    return wk;
}

GameEvent *EventGtsNego_Create(GameSystem *gsys, Field *field) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventGtsNego_Callback, sizeof(EventGtsNego));

    EventGtsNego_Init(event, gsys, field, 0);
    return event;
}

// Called through GameEvent_CreateOverlayDelegate, by the NetConnectGTSNegotiation script command, which passes the
// field instead of a pointer to arguments
GameEvent *EventGtsNego_CreateFromArgs(GameSystem *gsys, Field *field) {
    return EventGtsNego_Create(gsys, field);
}
