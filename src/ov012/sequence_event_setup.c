#include "field/event_3d_demo.h"
#include "nitro/rtc.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/season.h"

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
