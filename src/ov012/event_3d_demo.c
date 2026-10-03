#include "types.h"
#include "field/event_3d_demo.h"
#include "gfl/std.h"
#include "nitro/rtc.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/season.h"

GameEvent *Event3DDemo_Create(GameSystem *gsys, GameEvent *parent, u32 demoId, u32 param, u32 realTime) {
    GameEvent *event = GameEvent_Create(gsys, parent, Event3DDemo_Callback, sizeof(Event3DDemoWork));
    Event3DDemoWork *work = GameEvent_GetData(event);
    sys_memset(work, 0, sizeof(Event3DDemoWork));
    work->gameSystem = gsys;
    work->gameCommSys = GSYS_GetGameCommSystem(gsys);
    work->demoId = demoId;
    if (realTime) {
        SetupPlaySequenceEventRealTime(work->sequence, gsys, demoId, param);
    } else {
        SetupPlaySequenceEventGameTime(work->sequence, gsys, demoId, param);
    }
    if (demoId == 3) {
        GameBeacon_BroadcastFerrisWheel();
    }
    return event;
}

void SetupPlaySequenceEventRealTime(void *out, GameSystem *gsys, u8 demoId, u8 param) {
    RTCTime time;
    u32 season;

    RTC_GetCachedTime(&time);
    season = Season_GetRealTime();
    CreateSeqLoadParam(out, gsys, demoId, param, 0, (u8)time.hour, (u8)time.minute, season);
}

void SetupPlaySequenceEventGameTime(void *out, GameSystem *gsys, u8 demoId, u8 param) {
    GameData *data;
    u32 hour;
    u32 minute;
    u32 season;

    data = GSYS_GetGameData(gsys);
    hour = getCurrentHour(data);
    minute = getCurrentMinute(data);
    season = GameData_GetSeason(data);
    CreateSeqLoadParam(out, gsys, demoId, param, 0, (u8)hour, (u8)minute, season);
}
