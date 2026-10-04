#ifndef POKEBW2_NITRO_OS_H
#define POKEBW2_NITRO_OS_H

#include "types.h"
#include "nitro/hw.h"

// The tick count of the system timer, which swan names clock
u64 clock(void);
// Restarts the game, which swan names sys_reset
void sys_reset(u32 parameter);
// Stops the game after a fatal error, calling the registered handler first
void sys_exit(void);
// Stops the CPU until an interrupt, which swan names cp15_halt. NitroSDK's OS_Halt
void cp15_halt(void);
// Writes a range of the data cache back to memory, before DMA reads it. NitroSDK's DC_FlushRange
void cp15_flushDC(const void *addr, u32 size);

// The start of DTCM, where the linker places the DTCM module
extern u32 SDK_AUTOLOAD_DTCM_START[];
#define HW_DTCM ((u32)SDK_AUTOLOAD_DTCM_START)
// The interrupt flags that OS_WaitIrq checks, at the end of DTCM
#define HW_INTR_CHECK_BUF (HW_DTCM + 0x3ff8)

#define OS_IE_V_BLANK 0x1

static inline u32 OS_GetVBlankCount(void) {
    return *(vu32 *)HW_VBLANK_COUNT_BUF;
}

static inline void OS_SetIrqCheckFlag(u32 interrupts) {
    *(vu32 *)HW_INTR_CHECK_BUF |= interrupts;
}

// Fills 32 bytes with values that differ from run to run
void OS_GetLowEntropyData(u32 buffer[8]);
// NitroSDK's STD_CompareNString
int STD_CompareNString(const char *a, const char *b, int n);

// NitroSDK's OS_WaitIrq and OS_IsRunOnTwl, under swan's names
void irq_waitFor(BOOL clear, u32 interrupts);
BOOL hw_isDSi(void);

// The buttons the ARM7 reads, X, Y and the lid among them, in shared memory. NitroSDK's PAD_DetectFold
#define HW_BUTTON_XY_BUF 0x02ffffa8
#define PAD_DETECT_FOLD_MASK 0x8000
#define PAD_DETECT_FOLD_SHIFT 15

static inline BOOL PAD_DetectFold(void) {
    return (*(vu16 *)HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> PAD_DETECT_FOLD_SHIFT;
}

#endif // POKEBW2_NITRO_OS_H
