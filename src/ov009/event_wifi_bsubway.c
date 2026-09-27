#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

// Also the parameter of the Wi-Fi Battle Subway proc, which sets procResult
typedef struct {
    u32 mode;
    GameSystem *gsys;
    u32 procResult;
    u16 *result;
} EventWifiBSubway;

typedef struct {
    u32 mode;
    u16 *result;
} EventWifiBSubwayArgs;

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern Field *GSYS_GetField(GameSystem *gsys);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern BOOL GameCommSys_BootCheck(void *comm);
extern void GameCommSys_ExitReq(void *comm);
extern GameEvent *CallFieldMapEntranceOutTransitionDefault(GameSystem *gsys, Field *field, u32 type, u32 a3);
extern GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4, u32 a5,
                                                  u32 a6);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern void GSYS_QueueProc(GameSystem *gsys, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GSYS_GetProcMgrState(GameSystem *gsys);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern const u8 WIFI_BSUBWAY_PROC_FUNCTIONS[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_191_ID[];
#define OVERLAY_WIFI_BSUBWAY ((u32)OVERLAY_191_ID)

GameEvent *EventWifiBSubway_Create(GameSystem *gsys, u32 mode, u16 *result);
GameEventReturnCode EventWifiBSubway_Callback(GameEvent *event, u32 *state, EventWifiBSubway *wk);

// Called through GameEvent_CreateOverlayDelegate, by a script command in overlay 50
GameEvent *EventWifiBSubway_CreateFromArgs(GameSystem *gsys, EventWifiBSubwayArgs *args) {
    return EventWifiBSubway_Create(gsys, args->mode, args->result);
}

GameEvent *EventWifiBSubway_Create(GameSystem *gsys, u32 mode, u16 *result) {
    GameData *gameData = GSYS_GetGameData(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventWifiBSubway_Callback, sizeof(EventWifiBSubway));
    EventWifiBSubway *wk = GameEvent_GetData(event);

    wk->mode = mode;
    wk->gsys = gsys;
    wk->result = result;
    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }
    return event;
}

GameEventReturnCode EventWifiBSubway_Callback(GameEvent *event, u32 *state, EventWifiBSubway *wk) {
    GameSystem *gsys = wk->gsys;
    Field *field = GSYS_GetField(gsys);

    switch (*state) {
    case 0:
        // Wait for the comm system to shut down
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
            (*state)++;
        }
        break;
    case 1:
        GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, field, 0, 0));
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, field));
        (*state)++;
        break;
    case 3:
        GSYS_QueueProc(gsys, OVERLAY_WIFI_BSUBWAY, WIFI_BSUBWAY_PROC_FUNCTIONS, wk);
        (*state)++;
        break;
    case 4:
        if (!GSYS_GetProcMgrState(gsys)) {
            if (wk->procResult == 0) {
                *wk->result = TRUE;
            } else {
                *wk->result = FALSE;
            }
            (*state)++;
        }
        break;
    case 5:
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        (*state)++;
        break;
    case 6:
        GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 7:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
