#ifndef POKEBW2_SAVE_ADVENTURE_H
#define POKEBW2_SAVE_ADVENTURE_H

#include "types.h"
#include "nitro/rtc.h"
#include "struct_decls.h"

// The game's clock, at 0x10 in the adventure data save block
struct AdventureTime {
    u32 unk0;
    RTCDate date;
    RTCTime time;
};

BOOL hasClockNotBeenTampered(AdventureSave *adventure);
void setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(AdventureSave *adventure);
void setNewDayForCountdown(AdventureTime *time);

#endif // POKEBW2_SAVE_ADVENTURE_H
