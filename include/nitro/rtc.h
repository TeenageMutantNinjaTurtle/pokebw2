#ifndef POKEBW2_NITRO_RTC_H
#define POKEBW2_NITRO_RTC_H

#include "types.h"

typedef enum {
    RTC_WEEK_SUNDAY = 0,
    RTC_WEEK_MONDAY,
    RTC_WEEK_TUESDAY,
    RTC_WEEK_WEDNESDAY,
    RTC_WEEK_THURSDAY,
    RTC_WEEK_FRIDAY,
    RTC_WEEK_SATURDAY,
} RTCWeek;

typedef struct {
    u32 year;
    u32 month;
    u32 day;
    RTCWeek week;
} RTCDate;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

#endif // POKEBW2_NITRO_RTC_H
