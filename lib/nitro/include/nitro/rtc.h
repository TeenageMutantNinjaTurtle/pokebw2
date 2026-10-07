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

// The date, as the game last read it
void RTC_GetCachedDate(RTCDate *date);
void RTC_GetCachedTime(RTCTime *time);
void func_0207c3bc(void *date);

// NitroSDK's RTC_Init, RTC_GetDateTimeAsync, RTC_ConvertDateToDay and RTC_ConvertDateTimeToSecond
void func_0207cb88(void);
int func_0207cca4(RTCDate *date, RTCTime *time, void (*callback)(int result, void *arg), void *arg);
s32 func_0207d0b4(const RTCDate *date);
s64 func_0207d12c(const RTCDate *date, const RTCTime *time);
// The date and time a number of seconds since 2000 make
void func_0207d244(RTCDate *date, RTCTime *time, s64 seconds);

#endif // POKEBW2_NITRO_RTC_H
