#include "field/event_fly.h"
#include "field/zone.h"
#include "gfl/std.h"
#include "save/player_info.h"
#include "system/game_data.h"
#include "system/game_system.h"

typedef struct {
    GameSystem *gsys;
    u32 unk4;
    u32 zoneId;
    ZoneSpawnInfo spawn;
    u32 musicOut;
    u32 musicIn;
} FlyEventWork;

GameEvent *func_ov033_02178908(GameSystem *gsys, void *unused, u32 zoneId) {
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
