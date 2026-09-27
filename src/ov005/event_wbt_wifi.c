#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

#define HEAPID_GAMEEVENT 0x4

// Passed to the WBT download proc, which downloads battle tournaments over Wi-Fi
typedef struct {
    GameSystem *gsys;
    GameData *gameData;
} WbtDownloadParam;

typedef struct {
    GameSystem *gsys;
    Field *field;
    WbtDownloadParam *param;
} EventWbtWifi;

extern GameEvent *GameEvent_Create(GameSystem *gsys, GameEvent *parent, void *callback, u32 size);
extern void *GameEvent_GetData(GameEvent *event);
extern void GameEvent_ChainNext(GameEvent *event, GameEvent *next);
extern GameData *GSYS_GetGameData(GameSystem *gsys);
extern Field *GSYS_GetField(GameSystem *gsys);
extern void *GSYS_GetGameCommSystem(GameSystem *gsys);
extern BOOL GameCommSys_BootCheck(void *comm);
extern void GameCommSys_ExitReq(void *comm);
extern void sys_memset(void *dest, u32 value, u32 size);
extern void *GFL_HeapAllocate(u16 heapId, u32 size, BOOL clear, const char *file, u32 line);
extern void GFL_HeapFree(void *ptr);
extern GameEvent *EventFieldSubprocessTransition_Create(GameSystem *gsys, Field *field, u32 overlayId,
                                                       const void *procFunctions, void *param);
extern const u8 WBT_DOWNLOAD_PROC_FUNCTIONS[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_327_ID[];
#define OVERLAY_WBT_DOWNLOAD ((u32)OVERLAY_327_ID)

GameEventReturnCode EventWbtWifi_Callback(GameEvent *event, u32 *state, EventWbtWifi *wk);

// Called through GameEvent_CreateOverlayDelegate, by a script command in overlay 56
GameEvent *EventWbtWifi_Create(GameSystem *gsys, void *args) {
    Field *field = GSYS_GetField(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventWbtWifi_Callback, sizeof(EventWbtWifi));
    EventWbtWifi *wk = GameEvent_GetData(event);
    WbtDownloadParam *param;

    sys_memset(wk, 0, sizeof(EventWbtWifi));
    wk->gsys = gsys;
    wk->field = field;
    wk->param = GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(WbtDownloadParam), TRUE, "event_wbt_wifi.c", 105);
    param = wk->param;
    param->gsys = gsys;
    param->gameData = GSYS_GetGameData(gsys);
    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }
    return event;
}

GameEventReturnCode EventWbtWifi_Callback(GameEvent *event, u32 *state, EventWbtWifi *wk) {
    switch (*state) {
    case 0:
        // Wait for the comm system to shut down
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(wk->gsys))) {
            *state = 1;
        }
        break;
    case 1:
        GameEvent_ChainNext(event, EventFieldSubprocessTransition_Create(wk->gsys, wk->field, OVERLAY_WBT_DOWNLOAD,
                                                                         WBT_DOWNLOAD_PROC_FUNCTIONS, wk->param));
        *state = 2;
        break;
    case 2:
        GFL_HeapFree(wk->param);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
