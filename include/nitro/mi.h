#ifndef POKEBW2_NITRO_MI_H
#define POKEBW2_NITRO_MI_H

#include "types.h"

#define reg_MI_EXMEMCNT (*(vu16 *)0x04000204)
#define REG_MI_EXMEMCNT_EP_MASK 0x8000
#define REG_MI_EXMEMCNT_EP_SHIFT 15

typedef enum {
    MI_PROCESSOR_ARM9,
    MI_PROCESSOR_ARM7,
} MIProcessor;

// Copies 36 bytes, a 3x3 matrix
void MI_Copy36B(const void *src, void *dest);

// Which processor has priority on the main memory
static inline void MI_SetMainMemoryPriority(MIProcessor proc) {
    reg_MI_EXMEMCNT = (u16)((reg_MI_EXMEMCNT & ~REG_MI_EXMEMCNT_EP_MASK) | (proc << REG_MI_EXMEMCNT_EP_SHIFT));
}

// Decompresses LZ77 data, which starts with a word holding its decompressed size in its upper 24 bits.
// NitroSDK's MI_UncompressLZ8
void sys_uncomp_lz1x(const void *src, void *dest);

static inline u32 MI_GetUncompressedSize(const void *src) {
    return *(u32 *)src >> 8;
}

#endif // POKEBW2_NITRO_MI_H
