#ifndef POKEBW2_SYSTEM_RTC_H
#define POKEBW2_SYSTEM_RTC_H

#include "types.h"

s64 RTC_ConvertSecondsCached(u32 time);
u16 GetRealTimeDayPeriod(u8 season);

#endif // POKEBW2_SYSTEM_RTC_H
