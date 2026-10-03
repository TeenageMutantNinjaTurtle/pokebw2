#include "types.h"
#include "field/event_fly.h"
#include "field/zone.h"
#include "gfl/fade.h"
#include "gfl/std.h"
#include "save/player_info.h"
#include "struct_decls.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

struct FlyEventWork {
    GameSystem *gsys;
    u32 unk4;
    u32 zoneId;
    ZoneSpawnInfo spawn;
    u32 musicOut;
    u32 musicIn;
};

GameEvent *func_ov033_02178908(GameSystem *gsys, Field *field, u32 zoneId) {
    GameEvent *event;
    FlyEventWork *work;

    event = GameEvent_Create(gsys, NULL, EventFly_Callback, sizeof(FlyEventWork));
    work = GameEvent_GetData(event);
    sys_memset(work, 0, sizeof(FlyEventWork));
    work->gsys = gsys;
    work->zoneId = zoneId;
    if (getTrainerGender(GetGameDataPlayerInfo(GSYS_GetGameData(gsys))) == 0) {
        work->musicOut = 11;
        work->musicIn = 12;
    } else {
        work->musicOut = 31;
        work->musicIn = 32;
    }
    LoadZoneSpawnInfoCheckRail(&work->spawn, zoneId);
    return event;
}

GameEventReturnCode func_ov033_02178c6c(GameEvent *event, u32 *state, void *data) {
    GameSystem *gsys;

    gsys = GameEvent_GetGameSystem(event);
    GSYS_GetField(gsys);
    switch (*state) {
    case 0:
        GFL_FadeSet(3, 16, 0, 0);
        ++*state;
        break;
    case 1:
        if (!GFL_FadeIsRunning()) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
