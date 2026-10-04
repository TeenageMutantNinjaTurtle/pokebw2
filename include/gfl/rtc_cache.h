#ifndef POKEBW2_GFL_RTC_CACHE_H
#define POKEBW2_GFL_RTC_CACHE_H

#include "types.h"
#include "nitro/rtc.h"

// The clock read every few frames: start it, step it, and the date and time it last read, in seconds since midnight
// and since 2000
void func_02044170(void);
void func_02044198(void);
void RTC_GetCachedDateTime(RTCDate *date, RTCTime *time);
int RTC_ConvertDaySecondsCached(void);
s64 RTC_ConvertSecondsCached(void);
// The day of the year, from 1
int func_02044298(const RTCDate *date);

#endif // POKEBW2_GFL_RTC_CACHE_H
