#include "field/event_mapchange.h"
#include "field/field_event.h"
#include "gfl/net.h"
#include "system/game_comm.h"
#include "system/game_event.h"
#include "system/game_system.h"

struct EntralinkWarpReturnWork {
    GameSystem *gsys;
    Field *field;
};

GameEventReturnCode func_ov033_02177370(GameEvent *event, u32 *state, void *data) {
    struct EntralinkWarpReturnWork *work;
    GameSystem *gsys;
    GameCommSys *comm;
    GameData *gameData;
    Field *field;
    GameEvent *next;

    work = data;
    gsys = work->gsys;
    comm = GSYS_GetGameCommSystem(gsys);
    gameData = GSYS_GetGameData(gsys);
    field = GSYS_GetField(gsys);
    switch (*state) {
    case 0:
        if (func_0202bde0(comm)) {
            break;
        }
        if (GameCommSys_BootCheck(comm)) {
            GameCommSys_ExitReq(comm);
            break;
        }
        next = EventEntralinkWarpIn_Create(gsys, 0x117, (VecFx32 *)&data_ov033_0217c3f4, 0);
        GameEvent_ChainNext(event, next);
        (*state)++;
        break;
    case 1:
        return GAMEEVENT_DONE;
    default:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov033_021773e4(GameSystem *gsys, void *args) {
    GameEvent *event;
    struct EntralinkWarpReturnWork *work;

    event = GameEvent_Create(gsys, NULL, func_ov033_02177370, sizeof(struct EntralinkWarpReturnWork));
    work = GameEvent_GetData(event);
    work->gsys = gsys;
    work->field = args;
    return event;
}
