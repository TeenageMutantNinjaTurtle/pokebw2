#ifndef POKEBW2_SAVE_ADVENTURE_H
#define POKEBW2_SAVE_ADVENTURE_H

#include "types.h"
#include "nitro/rtc.h"
#include "struct_decls.h"

// The game's clock, at 0x10 in the adventure data save block
struct AdventureTime {
    u32 unk0;
    // When the clock was last checked
    RTCDate date;
    RTCTime time;
    // The number of the day it was last checked on
    s32 day;
    u8 unk24[8];
    s64 seconds;
};

BOOL hasClockNotBeenTampered(AdventureSave *adventure);
void setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(AdventureSave *adventure);
void setNewDayForCountdown(AdventureTime *time);
BOOL hasFullDayMinutesPassed(AdventureTime *time);
void dayCountdownTest(AdventureTime *time);

#endif // POKEBW2_SAVE_ADVENTURE_H
