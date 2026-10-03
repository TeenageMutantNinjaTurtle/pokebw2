#ifndef POKEBW2_NITRO_MI_H
#define POKEBW2_NITRO_MI_H

#include "types.h"

// Copies 36 bytes, a 3x3 matrix
void MI_Copy36B(const void *src, void *dest);

// Decompresses LZ77 data, which starts with a word holding its decompressed size in its upper 24 bits.
// NitroSDK's MI_UncompressLZ8
void sys_uncomp_lz1x(const void *src, void *dest);

static inline u32 MI_GetUncompressedSize(const void *src) {
    return *(u32 *)src >> 8;
}

#endif // POKEBW2_NITRO_MI_H
