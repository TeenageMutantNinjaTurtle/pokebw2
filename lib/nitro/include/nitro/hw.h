#ifndef POKEBW2_NITRO_HW_H
#define POKEBW2_NITRO_HW_H

#include "types.h"

#define reg_OS_IME (*(vu16 *)0x04000208)
#define reg_OS_IE (*(vu32 *)0x04000210)

// The card's SPI bus to its backup memory (and the infrared chip): control and data
#define reg_MI_MCCNT0 (*(vu16 *)0x040001a0)
#define reg_MI_MCD0 (*(vu16 *)0x040001a2)
#define REG_MI_MCCNT0_E_MASK 0x8000
#define REG_MI_MCCNT0_I_MASK 0x4000
#define REG_MI_MCCNT0_SEL_MASK 0x2000
#define REG_MI_MCCNT0_BUSY_MASK 0x0080
#define REG_MI_MCCNT0_MODE_MASK 0x0040

#define reg_GX_DISPSTAT (*(vu16 *)0x04000004)
#define REG_GX_DISPSTAT_HBLK_MASK 0x0002
#define reg_GX_VCOUNT (*(vu16 *)0x04000006)
#define reg_GX_POWCNT (*(vu16 *)0x04000304)
// Swaps the screens, so that the main engine drives the top screen
#define REG_GX_POWCNT_DSEL_MASK 0x8000

#define REG_BLDCNT_ADDR 0x04000050
#define REG_DB_BLDCNT_ADDR 0x04001050
#define REG_MOSAIC_ADDR 0x0400004c
#define REG_DB_MOSAIC_ADDR 0x0400104c
#define REG_BLDALPHA_ADDR 0x04000052
#define REG_DB_BLDALPHA_ADDR 0x04001052

// Palette memory: the BG and OBJ palettes of the main and sub (DB) screens
#define HW_BG_PLTT 0x05000000
#define HW_OBJ_PLTT 0x05000200
#define HW_DB_BG_PLTT 0x05000400
#define HW_DB_OBJ_PLTT 0x05000600
// The main screen's OBJ VRAM
#define HW_OBJ_VRAM 0x06400000
#define REG_MASTER_BRIGHT_ADDR 0x0400006c
#define REG_DB_MASTER_BRIGHT_ADDR 0x0400106c

// VBlank counter in shared memory, from the DSi mirror of main memory
#define HW_VBLANK_COUNT_BUF 0x02fffc3c
// The low word of the DSi's title ID, its game code, in the system area
#define HW_TWL_TITLE_ID 0x02ffe230

static inline BOOL OS_DisableIrq(void) {
    u16 prev = reg_OS_IME;
    reg_OS_IME = 0;
    return prev;
}

static inline BOOL OS_EnableIrq(void) {
    u16 prev = reg_OS_IME;
    reg_OS_IME = 1;
    return prev;
}

#endif // POKEBW2_NITRO_HW_H
