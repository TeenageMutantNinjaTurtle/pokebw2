// The Battle Subway's events: picking the Pokémon to enter, the battle, the trainers' and leaders' messages, and its
// records screen. The name is descriptive
//
// Not written yet: func_ov012_02166428, the battle's event, reads the battle's music from a BtlSetup field that
// battle/btl_setup.h does not have yet, so it is declared here without static until it is written
#include "types.h"
#include "app/ov141.h"
#include "app/pokelist.h"
#include "app/ov207.h"
#include "battle/battle_proc.h"
#include "battle/btl_setup.h"
#include "battle/regulation.h"
#include "field/bsubway_scr.h"
#include "field/event_battle.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_camera.h"
#include "field/field_event.h"
#include "gfl/heap.h"
#include "gfl/key.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/net_command.h"
#include "gfl/net_handle.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "pml/poke_party.h"
#include "save/bsubway_save.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/pms.h"

#define SEQ_SE_MESSAGE 0x547
// The timing the partners synchronize at before the battle
#define BSUBWAY_COMM_TIMING_BATTLE 200

typedef struct {
    GameSystem *gsys;
    Field *field;
    Ov207Param summaryParam;
    PokeListParam partyParam;
    u16 *result;
    u16 *choice;
    u8 *picked;
    u32 unkE4;
} BSubwayPokeSelectData;

typedef struct {
    GameSystem *gsys;
    u32 unk04;
    VecFx32 pos;
    void *msgWin;
    StrBuf *strbuf;
    u16 actorId;
    u8 unk1E[0xca];
} BSubwayTrainerMsgData;

typedef struct {
    Field *field;
    GameSystem *gsys;
    Ov141Param param;
} BSubwayRecordsData;

typedef struct {
    GameProcManager *procManager;
} BSubwayCommBattleWork;

typedef struct {
    GameData *gameData;
    BtlSetup *setup;
    void *unk08;
} BSubwayCommBattleParam;

typedef struct {
    GameSystem *gsys;
    BtlSetup *setup;
    void *unk08;
    BSubwayCommBattleParam param;
    u8 unk18[0x24];
} BSubwayCommBattleData;

typedef struct {
    GameSystem *gsys;
    Field *field;
    BtlSetup *setup;
    void *unk0C;
} BSubwayBattleData;

typedef struct {
    GameSystem *gsys;
    u32 unk04;
    VecFx32 pos;
    void *msgWin;
    StrBuf *strbuf;
} BSubwayLeaderMsgData;

// A leader of the Battle Subway, as the save keeps it
typedef struct {
    PMSData message;
    u8 unk08[0x1a];
} BSubwayLeader;

typedef struct {
    u8 unk00[0x18];
    BSubwayLeader leaders[];
} BSubwayLeaderData;

static BOOL func_ov012_021662bc(GameProc *proc, u32 *state, void *param, void *work);
static BOOL func_ov012_021662e4(GameProc *proc, u32 *state, void *param, void *work);
static BOOL func_ov012_02166300(GameProc *proc, u32 *state, void *param, void *work);

static const GameProcFunctions data_ov012_0216dc5c = {
    func_ov012_021662bc,
    func_ov012_02166300,
    func_ov012_021662e4,
};

GameEventReturnCode func_ov012_02166428(GameEvent *event, u32 *state, void *work);
static GameEvent *func_ov012_02166508(BSubwayScrWork *bsw, GameSystem *gsys, Field *field);

static GameEventReturnCode func_ov012_02165eb8(GameEvent *event, u32 *state, void *work) {
    BSubwayPokeSelectData *data = work;
    GameSystem *gsys = data->gsys;

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, CallFieldMapEntranceOutTransitionDefault(gsys, data->field, 0, 0));
        (*state)++;
        break;
    case 1:
        GameEvent_ChainNext(event, CreateFieldCloseEvent(gsys, data->field));
        (*state)++;
        break;
    case 2:
        GameEvent_ChainNext(event, EventPokeList_Create(gsys, data->field, &data->partyParam, &data->summaryParam));
        (*state)++;
        break;
    case 3:
        GameEvent_ChainNext(event, EventFieldOpen_CreateHeadless(gsys));
        (*state)++;
        break;
    case 4:
        GameEvent_ChainNext(event, CallFieldMapEntranceInTransition(gsys, data->field, 0, 0, 1, 0, 0));
        sys_memcpy(data->partyParam.picked, data->picked, sizeof(data->partyParam.picked));
        *data->choice = data->partyParam.index;
        *data->result = data->partyParam.result;
        GFL_HeapFree(data->partyParam.regulation);
        (*state)++;
        break;
    case 5:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov012_02165f70(BSubwayScrWork *bsw, GameSystem *gsys, u8 rental) {
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_02165eb8, sizeof(BSubwayPokeSelectData));
    BSubwayPokeSelectData *data = GameEvent_GetData(event);
    PokeParty *party;
    u32 regulationId;
    PokeListParam *partyParam;
    u32 mode;
    Ov207Param *summaryParam;
    PokeDexSave *pokedex;

    data->gsys = gsys;
    data->field = field;
    data->picked = bsw->memberChoices;
    data->choice = &bsw->unk82;
    data->result = &bsw->unk84;
    if (rental == FALSE) {
        party = GameData_GetParty(gameData);
    } else {
        party = bsw->allocatedBuffer;
    }
    regulationId = 20;
    partyParam = &data->partyParam;
    mode = 0;
    switch (bsw->playMode) {
    case 1:
    case 6:
        regulationId = 21;
        mode = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        regulationId = 22;
        mode = 2;
        break;
    }
    func_02034bd8(partyParam, gameData, 0x16, party);
    partyParam->regulation = func_0201f734(regulationId, HEAPID_GAMEEVENT);
    summaryParam = &data->summaryParam;
    partyParam->unk48 = mode;
    pokedex = GameData_GetPokedex(gameData);
    sys_memset(summaryParam, 0, sizeof(Ov207Param));
    data->summaryParam.party = party;
    summaryParam->unkC = 1;
    summaryParam->partyCount = PokeParty_GetPkmCount(party);
    summaryParam->unkD = 0;
    summaryParam->unk10 = 0;
    summaryParam->gameData = gameData;
    summaryParam->isNationalDex = PokeDex_IsNationalObtained(pokedex);
    return event;
}

GameEvent *func_ov012_02166070(BSubwayScrWork *bsw, GameSystem *gsys, Field *field) {
    func_0200bb24(HEAPID_GAMEEVENT);
    bsw->btlSetup = func_ov033_0217c094(bsw, gsys);
    if (bsw->playMode == 3 || bsw->playMode == 8) {
        return func_ov012_02166508(bsw, gsys, field);
    }
    return func_ov012_0216881c(gsys, field, bsw->btlSetup);
}

static GameEventReturnCode func_ov012_021660b0(GameEvent *event, u32 *state, void *work) {
    BSubwayTrainerMsgData *data = work;

    switch (*state) {
    case 0:
        if (!func_ov036_02188884(data->msgWin)) {
            break;
        }
        (*state)++;
        // fallthrough
    case 1:
        func_ov036_021889c8(data->msgWin);
        if (GCTX_HIDGetPressedKeys() & (PAD_BUTTON_A | PAD_BUTTON_B)) {
            GFL_SndSEPlay(SEQ_SE_MESSAGE);
            func_ov036_021887d4(data->msgWin);
            (*state)++;
        }
        break;
    case 2:
        if (func_ov036_021887f4(data->msgWin) == TRUE) {
            GFL_StrBufFree(data->strbuf);
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov012_02166118(BSubwayScrWork *bsw, GameSystem *gsys, u16 index, u16 actorId, u8 winPos) {
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);
    void *msgBGSys = Field_GetMsgBGSys(field);
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_021660b0, sizeof(BSubwayTrainerMsgData));
    BSubwayTrainerMsgData *data = GameEvent_GetData(event);
    MsgData *msgData;
    u16 messageId;
    FieldCamera *camera;
    VecFx32 offset;
    u32 winX;
    u32 winY;

    data->gsys = gsys;
    data->actorId = actorId;
    if (bsw->trainers[index].message.sentenceType == 0xffff) {
        data->strbuf = GFL_StrBufCreate(0x300, HEAPID_GAMEEVENT);
        msgData = GFL_MsgSysLoadData(FALSE, 2, 0x178, HEAPID_GAMEEVENT);
        messageId = bsw->trainers[index].message.sentenceId;
        if (messageId >= 0x3ae) {
            messageId = 0;
        }
        GFL_MsgDataLoadStrbuf(msgData, messageId, data->strbuf);
        GFL_MsgDataFree(msgData);
    } else {
        data->strbuf = func_02029c80(&bsw->trainers[index].message, HEAPID_GAMEEVENT);
    }
    CopyActorWPos(FindFieldActor(GameData_GetMMSys(gameData), data->actorId), &data->pos);
    camera = Field_GetCameraSystem(field);
    func_ov036_021a8bec(&data->pos, &offset, FieldCamera_GetG3DCamera(camera), camera, winPos);
    data->pos.x += offset.x;
    data->pos.y += offset.y;
    data->pos.z += offset.z;
    func_ov036_021a8c00(winPos, &winX, &winY);
    data->msgWin = ActorMsgWin_CheckAndCreate(msgBGSys, winX, &data->pos, data->strbuf, 0, winY);
    return event;
}

static GameEventReturnCode func_ov012_02166230(GameEvent *event, u32 *state, void *work) {
    BSubwayRecordsData *data = work;
    void *bsubwaySave;

    switch (*state) {
    case 0:
        data->param.gameData = GSYS_GetGameData(data->gsys);
        bsubwaySave = func_02017968(data->param.gameData);
        data->param.unk04 = func_0200e7d8(bsubwaySave);
        data->param.unk08 = func_0200e7e4(bsubwaySave);
        GameEvent_ChainNext(event, EventFieldSubprocessTransition_Create(data->gsys, data->field, OVERLAY_ID(141),
                                                                         &data_ov141_0219df2c, &data->param));
        (*state)++;
        break;
    case 1:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov012_02166294(GameSystem *gsys) {
    Field *field = GSYS_GetField(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_02166230, sizeof(BSubwayRecordsData));
    BSubwayRecordsData *data = GameEvent_GetData(event);

    data->gsys = gsys;
    data->field = field;
    return event;
}

static BOOL func_ov012_021662bc(GameProc *proc, u32 *state, void *param, void *work) {
    BSubwayCommBattleWork *procWork;

    GFL_HeapCreateChild(HEAPID_USER, 0x76, 0x4000);
    procWork = GFL_ProcInitSubsystem(proc, sizeof(BSubwayCommBattleWork), 0x76);
    procWork->procManager = CreateGameProcManager(0x76);
    return TRUE;
}

static BOOL func_ov012_021662e4(GameProc *proc, u32 *state, void *param, void *work) {
    BSubwayCommBattleWork *procWork = work;

    FreeGameProcManager(procWork->procManager);
    GFL_ProcReleaseSubsystem(proc);
    GFL_HeapDelete(0x76);
    return TRUE;
}

static BOOL func_ov012_02166300(GameProc *proc, u32 *state, void *param, void *work) {
    BSubwayCommBattleParam *battleParam = param;
    BSubwayCommBattleWork *procWork = work;
    BOOL running = GFL_ProcMgrUpdate(procWork->procManager);

    switch (*state) {
    case 0:
        GFL_OvlLoad(OVERLAY_ID(167));
        func_02040c20(0x100, data_ov167_021d7448, 9, NULL);
        func_02042d04(func_02040440(), BSUBWAY_COMM_TIMING_BATTLE);
        *state = 1;
        break;
    case 1:
        if (GFL_NetErrCheck()) {
            *state = 4;
        } else if (func_02042d0c(func_02040440(), BSUBWAY_COMM_TIMING_BATTLE)) {
            *state = 2;
        }
        break;
    case 2:
        QueueGameProc(procWork->procManager, -1, &data_ov167_021d6ce0, battleParam->setup);
        *state = 3;
        break;
    case 3:
        if (running != TRUE) {
            *state = 4;
        }
        break;
    case 4:
        func_02040c64(0x100);
        GFL_OvlUnload(OVERLAY_ID(167));
        *state = 5;
        break;
    case 5:
        return TRUE;
    }
    return FALSE;
}

static GameEventReturnCode func_ov012_021663ac(GameEvent *event, u32 *state, void *work) {
    BSubwayCommBattleData *data = work;
    GameSystem *gsys = data->gsys;
    BSubwayCommBattleParam *param;

    switch (*state) {
    case 0:
        param = &data->param;
        data->param.gameData = GSYS_GetGameData(gsys);
        param->setup = data->setup;
        param->unk08 = data->unk08;
        GSYS_QueueProc(gsys, -1, &data_ov012_0216dc5c, param);
        (*state)++;
        break;
    case 1:
        if (GSYS_GetProcMgrState(gsys) == FALSE) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

static GameEvent *func_ov012_02166400(GameSystem *gsys, BtlSetup *setup, void *a2) {
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_021663ac, sizeof(BSubwayCommBattleData));
    BSubwayCommBattleData *data = GameEvent_GetData(event);

    data->gsys = gsys;
    data->setup = setup;
    data->unk08 = a2;
    return event;
}

static GameEvent *func_ov012_021664dc(GameSystem *gsys, Field *field, BtlSetup *setup, void *a3) {
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_02166428, sizeof(BSubwayBattleData));
    BSubwayBattleData *data = GameEvent_GetData(event);

    data->gsys = gsys;
    data->setup = setup;
    data->unk0C = a3;
    data->field = field;
    return event;
}

static GameEvent *func_ov012_02166508(BSubwayScrWork *bsw, GameSystem *gsys, Field *field) {
    return func_ov012_021664dc(gsys, field, bsw->btlSetup, func_ov033_0217c110(bsw));
}

static GameEventReturnCode func_ov012_02166528(GameEvent *event, u32 *state, void *work) {
    BSubwayLeaderMsgData *data = work;

    switch (*state) {
    case 0:
        if (func_ov036_02188884(data->msgWin) == TRUE) {
            (*state)++;
        }
        break;
    case 1:
        if (GCTX_HIDGetPressedKeys() & (PAD_BUTTON_A | PAD_BUTTON_B)) {
            func_ov036_021887d4(data->msgWin);
            (*state)++;
        }
        break;
    case 2:
        if (func_ov036_021887f4(data->msgWin) == TRUE) {
            GFL_StrBufFree(data->strbuf);
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov012_0216657c(GameSystem *gsys, u16 index, u16 actorId) {
    GameData *gameData = GSYS_GetGameData(gsys);
    Field *field = GSYS_GetField(gsys);
    void *msgBGSys = Field_GetMsgBGSys(field);
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_02166528, sizeof(BSubwayLeaderMsgData));
    BSubwayLeaderMsgData *data = GameEvent_GetData(event);
    MMSys *actorSystem;
    FieldActor *player;
    u8 winPos;
    FieldCamera *camera;
    VecFx32 offset;
    BSubwayLeaderData *leaderData;
    u32 winX;
    u32 winY;

    data->gsys = gsys;
    actorSystem = GameData_GetMMSys(gameData);
    player = FindPlayerFieldActor(actorSystem);
    CopyActorWPos(FindFieldActor(actorSystem, actorId), &data->pos);
    winPos = ActorMsgWin_CalcWinPosAuto(player, &data->pos);
    camera = Field_GetCameraSystem(field);
    func_ov036_021a8bec(&data->pos, &offset, FieldCamera_GetG3DCamera(camera), camera, winPos);
    data->pos.x += offset.x;
    data->pos.y += offset.y;
    data->pos.z += offset.z;
    leaderData = func_0200e7f0(SaveControl_GetBlockPtr(GameData_GetSaveControl(gameData), 0x3a), HEAPID_GAMEEVENT);
    data->strbuf = func_02029c80(&leaderData->leaders[index].message, HEAPID_GAMEEVENT);
    GFL_HeapFree(leaderData);
    func_ov036_021a8c00(winPos, &winX, &winY);
    data->msgWin = ActorMsgWin_CheckAndCreate(msgBGSys, winX, &data->pos, data->strbuf, 0, winY);
    return event;
}
