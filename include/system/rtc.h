#ifndef POKEBW2_SYSTEM_RTC_H
#define POKEBW2_SYSTEM_RTC_H

#include "types.h"
#include "nitro/rtc.h"

// The clock as GFL caches it is in gfl/rtc_cache.h
void func_0207cc10(RTCDate *date);
u16 GetRealTimeDayPeriod(u8 season);

#endif // POKEBW2_SYSTEM_RTC_H
