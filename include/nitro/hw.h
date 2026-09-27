#ifndef POKEBW2_NITRO_HW_H
#define POKEBW2_NITRO_HW_H

#include "types.h"

#define reg_OS_IME (*(vu16 *)0x04000208)

#define reg_GX_POWCNT (*(vu16 *)0x04000304)
// Swaps the screens, so that the main engine drives the top screen
#define REG_GX_POWCNT_DSEL_MASK 0x8000

#define REG_BLDCNT_ADDR 0x04000050
#define REG_MASTER_BRIGHT_ADDR 0x0400006c
#define REG_DB_MASTER_BRIGHT_ADDR 0x0400106c

// VBlank counter in shared memory, from the DSi mirror of main memory
#define HW_VBLANK_COUNT_BUF 0x02fffc3c

static inline BOOL OS_EnableIrq(void) {
    u16 prev = reg_OS_IME;
    reg_OS_IME = 1;
    return prev;
}

#endif // POKEBW2_NITRO_HW_H
