#ifndef POKEBW2_NITRO_PM_H
#define POKEBW2_NITRO_PM_H

#include "types.h"

// NitroSDK's power management: PM_GetBackLight, PM_SetBackLight, PM_GetBattery, the DSi's PM_GetBatteryLevel and
// PM_GoSleepMode. They return PM_RESULT_SUCCESS, or another result when the ARM7 is busy

#define PM_RESULT_SUCCESS 0

#define PM_LCD_ALL 2
#define PM_BACKLIGHT_OFF 0

#define PM_BATTERY_HIGH 0

// What wakes the system: opening the lid, or the Game Pak being pulled
#define PM_TRIGGER_COVER_OPEN 0x04
#define PM_TRIGGER_CARTRIDGE 0x08

u32 PM_GetBackLight(u32 *top, u32 *bottom);
u32 PM_SetBackLight(u32 target, u32 backlight);
u32 PM_GetBattery(u32 *battery);
u32 PM_GetBatteryLevel(u16 *level);
void PM_GoSleepMode(u32 trigger, u32 logic, u16 keyPattern);

#endif // POKEBW2_NITRO_PM_H
