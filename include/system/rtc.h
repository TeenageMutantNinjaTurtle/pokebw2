#ifndef POKEBW2_SYSTEM_RTC_H
#define POKEBW2_SYSTEM_RTC_H

#include "types.h"
#include "nitro/rtc.h"

// The clock as GFL caches it is in gfl/rtc_cache.h
void func_0207cc10(RTCDate *date);
u16 GetRealTimeDayPeriod(u8 season);
// The hour a season's day period starts at
u8 GetLightChangeHoursForSeasons(u32 season, u32 period);
u32 RTC_ConvertDaySecondsCached(void);

#endif // POKEBW2_SYSTEM_RTC_H
