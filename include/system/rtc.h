#ifndef POKEBW2_SYSTEM_RTC_H
#define POKEBW2_SYSTEM_RTC_H

#include "types.h"
#include "nitro/rtc.h"

// The clock as GFL caches it is in gfl/rtc_cache.h
void func_0207cc10(RTCDate *date);
u16 GetRealTimeDayPeriod(u8 season);
// The period of the day at the hour, in the season
u16 GetDayPeriod(u8 season, u32 hour);
// The hour of one of the changes of light in the season, such as 0 for the morning and 3 for the night
int GetLightChangeHoursForSeasons(u32 season, u32 index);

#endif // POKEBW2_SYSTEM_RTC_H
