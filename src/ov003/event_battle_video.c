#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

// The proc is in the main program, so no overlay is loaded for it
#define OVERLAY_NONE 0xffffffff

// Passed to the Battle Video proc
typedef struct {
    GameData *gameData;
    u32 mode;
} BattleVideoParam;

typedef struct {
    u32 bgm;
    GameSystem *gsys;
    Field *field;
    BattleVideoParam param;
    u32 mode;
    u32 unk18;
} EventBattleVideo;

typedef struct {
    Field *field;
    u32 mode;
} EventBattleVideoArgs;

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern BOOL GameCommSys_BootCheck(void *comm);
extern void GameCommSys_ExitReq(void *comm);
extern u32 GFL_SndBGMGetID(void);
extern void GFL_SndBGMFadeOut(u32 frames);
extern void GFL_SndBGMPlay(u32 bgm, u32 a1);
extern void GFL_SndBGMFadeIn(u32 frames);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern void GSYS_QueueProc(GameSystem *gsys, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GSYS_GetProcMgrState(GameSystem *gsys);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern const u8 BATTLE_VIDEO_PROC_FUNCTIONS[];

GameEventReturnCode EventBattleVideo_Callback(GameEvent *event, u32 *state, EventBattleVideo *wk) {
    GameSystem *gsys = wk->gsys;

    switch (*state) {
    case 0:
        // Wait for the comm system to shut down
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
            wk->bgm = GFL_SndBGMGetID();
            GFL_SndBGMFadeOut(6);
            (*state)++;
        }
        break;
    case 1:
        GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, wk->field));
        *state = 2;
        break;
    case 2:
        wk->param.gameData = GSYS_GetGameData(gsys);
        wk->param.mode = wk->mode;
        GSYS_QueueProc(gsys, OVERLAY_NONE, BATTLE_VIDEO_PROC_FUNCTIONS, &wk->param);
        (*state)++;
        break;
    case 3:
        if (!GSYS_GetProcMgrState(gsys)) {
            (*state)++;
        }
        break;
    case 4:
        (*state)++;
        break;
    case 5:
        GFL_SndBGMPlay(wk->bgm, 0xffff);
        GFL_SndBGMFadeIn(60);
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        (*state)++;
        break;
    case 6:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventBattleVideo_Create(GameSystem *gsys, Field *field, u32 mode) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventBattleVideo_Callback, sizeof(EventBattleVideo));
    EventBattleVideo *wk;

    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }

    wk = GameEvent_GetData(event);
    wk->gsys = gsys;
    wk->field = field;
    wk->mode = mode;
    return event;
}

// Called through GameEvent_CreateOverlayDelegate, by the NetConnectBattleVideo script command
GameEvent *EventBattleVideo_CreateFromArgs(GameSystem *gsys, EventBattleVideoArgs *args) {
    return EventBattleVideo_Create(gsys, args->field, args->mode);
}
