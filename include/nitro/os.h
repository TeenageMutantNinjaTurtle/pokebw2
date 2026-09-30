#ifndef POKEBW2_NITRO_OS_H
#define POKEBW2_NITRO_OS_H

#include "types.h"

// The tick count of the system timer, which swan names clock
u64 clock(void);
// Restarts the game, which swan names sys_reset
void sys_reset(u32 parameter);

// The start of DTCM, where the linker places the DTCM module
extern u32 SDK_AUTOLOAD_DTCM_START[];
#define HW_DTCM ((u32)SDK_AUTOLOAD_DTCM_START)
// The interrupt flags that OS_WaitIrq checks, at the end of DTCM
#define HW_INTR_CHECK_BUF (HW_DTCM + 0x3ff8)

#define OS_IE_V_BLANK 0x1

static inline void OS_SetIrqCheckFlag(u32 interrupts) {
    *(vu32 *)HW_INTR_CHECK_BUF |= interrupts;
}

#endif // POKEBW2_NITRO_OS_H
