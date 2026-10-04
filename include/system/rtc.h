#ifndef POKEBW2_SYSTEM_RTC_H
#define POKEBW2_SYSTEM_RTC_H

#include "types.h"
#include "nitro/rtc.h"

void func_0207cc10(RTCDate *date);
s64 RTC_ConvertSecondsCached(u32 time);
u16 GetRealTimeDayPeriod(u8 season);
u32 RTC_ConvertDaySecondsCached(void);

#endif // POKEBW2_SYSTEM_RTC_H
