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

// Copy or fill size bytes a halfword or a word at a time: NitroSDK's MIi_CpuCopy16, MIi_CpuClear16 and MIi_CpuClear32
void sys_memcpy16(const void *src, void *dest, u32 size);
void sys_memset16(u16 value, void *dest, u32 size);
void sys_memset32(u32 value, void *dest, u32 size);

// NitroSDK's MI_CpuCopy16, an inline over sys_memcpy16 (MIi_CpuCopy16). MWCC evaluates an inline call's arguments
// from the last, so the size is read before a destination that a call gives
static inline void MI_CpuCopy16(const void *src, void *dest, u32 size) {
    sys_memcpy16(src, dest, size);
}

static inline void MI_CpuFill16(void *dest, u16 data, u32 size) {
    sys_memset16(data, dest, size);
}

static inline void MI_CpuFill32(void *dest, u32 data, u32 size) {
    sys_memset32(data, dest, size);
}

static inline void MI_CpuClear32(void *dest, u32 size) {
    sys_memset32(0, dest, size);
}

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
