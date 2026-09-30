#ifndef POKEBW2_GFL_STD_H
#define POKEBW2_GFL_STD_H

#include "types.h"

void sys_memcpy(const void *src, void *dest, u32 size);
void sys_memcpy16(const void *src, void *dest, u32 size);
void sys_memset(void *dest, u32 value, u32 size);
void sys_memset32_fast(u32 value, void *dest, u32 size);

#endif // POKEBW2_GFL_STD_H
