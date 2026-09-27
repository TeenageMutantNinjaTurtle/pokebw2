#include "types.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct GameData GameData;
typedef struct Field Field;
typedef struct SaveControl SaveControl;
typedef struct RecordSave RecordSave;

typedef u32 GameEventReturnCode;
#define GAMEEVENT_CONTINUE 0
#define GAMEEVENT_DONE 1

#define HEAPID_GAMEEVENT 0x4

// Passed to the Wi-Fi battle match proc
typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} WifiBattleMatchParam;

typedef struct {
    u32 bgm;
    GameSystem *gsys;
    Field *field;
    WifiBattleMatchParam *param;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    // Never set, so the field transitions are skipped
    BOOL useTransitions;
} EventWifiBattleMatch;

typedef struct {
    Field *field;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} EventWifiBattleMatchArgs;

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
extern void *GFL_HeapAllocate(u16 heapId, u32 size, BOOL clear, const char *file, u32 line);
extern void GFL_HeapFree(void *ptr);
extern GameEvent *CallFieldMapEntranceOutTransitionDefault(GameSystem *gsys, Field *field, u32 type, u32 a3);
extern GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4, u32 a5,
                                                  u32 a6);
extern GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
extern void GSYS_QueueProc(GameSystem *gsys, u32 overlayId, const void *procFunctions, void *param);
extern BOOL GSYS_GetProcMgrState(GameSystem *gsys);
extern GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern RecordSave *getRecordBlkAddress(SaveControl *save);
// Clears the flag that is set, with the console's MAC address and the time, while a match is in progress
extern void RecordSave_ClearMatchInProgress(RecordSave *record);
extern const u8 WIFIBATTLEMATCH_PROC_FUNCTIONS[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_290_ID[];
#define OVERLAY_WIFIBATTLEMATCH ((u32)OVERLAY_290_ID)

GameEvent *EventWifiBattleMatch_Create(GameSystem *gsys, Field *field, u32 unk10, u32 unk14, u32 unk18);

GameEventReturnCode EventWifiBattleMatch_Callback(GameEvent *event, u32 *state, EventWifiBattleMatch *wk) {
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
        if (wk->useTransitions) {
            GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, wk->field, 0, 0));
        }
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, wk->field));
        (*state)++;
        break;
    case 3: {
        WifiBattleMatchParam *param =
            GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(WifiBattleMatchParam), TRUE, "event_wifibattlematch.c", 135);

        wk->param = param;
        param->unk8 = wk->unk10;
        param->gameData = GSYS_GetGameData(gsys);
        param->unk4 = wk->unk18;
        param->unkC = wk->unk14;
        GSYS_QueueProc(gsys, OVERLAY_WIFIBATTLEMATCH, WIFIBATTLEMATCH_PROC_FUNCTIONS, wk->param);
        (*state)++;
        break;
    }
    case 4:
        if (!GSYS_GetProcMgrState(gsys)) {
            GFL_HeapFree(wk->param);
            (*state)++;
        }
        break;
    case 5:
        RecordSave_ClearMatchInProgress(getRecordBlkAddress(GameData_GetSaveControl(GSYS_GetGameData(gsys))));
        (*state)++;
        break;
    case 6:
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        GFL_SndBGMPlay(wk->bgm, 0xffff);
        GFL_SndBGMFadeIn(60);
        (*state)++;
        break;
    case 7:
        if (wk->useTransitions) {
            GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, wk->field, 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 8:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventWifiBattleMatch_Create(GameSystem *gsys, Field *field, u32 unk10, u32 unk14, u32 unk18) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventWifiBattleMatch_Callback, sizeof(EventWifiBattleMatch));
    EventWifiBattleMatch *wk;

    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(gsys))) {
        GameCommSys_ExitReq(GSYS_GetGameCommSystem(gsys));
    }

    wk = GameEvent_GetData(event);
    wk->gsys = gsys;
    wk->field = field;
    wk->unk10 = (u16)unk10;
    wk->unk14 = unk14;
    wk->unk18 = unk18;
    wk->useTransitions = FALSE;
    return event;
}

// Called through GameEvent_CreateOverlayDelegate, by the NetConnectWiFiBattle script command
GameEvent *EventWifiBattleMatch_CreateFromArgs(GameSystem *gsys, EventWifiBattleMatchArgs *args) {
    return EventWifiBattleMatch_Create(gsys, args->field, args->unk4, args->unk8, args->unkC);
}
