#ifndef POKEBW2_GFL_STD_H
#define POKEBW2_GFL_STD_H

#include "types.h"

void sys_memcpy(const void *src, void *dest, u32 size);
void sys_memcpy32_fast(const void *src, void *dest, u32 size);
void sys_memcpy16(const void *src, void *dest, u32 size);
void sys_memset(void *dest, u32 value, u32 size);
void sys_memset_fast(void *dest, u32 value, u32 size);
void sys_memset16(u16 value, void *dest, u32 size);
void sys_memset32(u32 value, void *dest, u32 size);
void sys_memset32_fast(u32 value, void *dest, u32 size);
void *sys_memcpy32(const void *src, void *dest, u32 size);
// Compares size bytes, returning the difference of the first that differ
s32 GFL_STD_MemCmp(const void *a, const void *b, u32 size);

// A failed assertion. The game's are built without the file and line, and keep the expression
void GFL_DebugAssertFail(const char *file, u32 line, const char *expression);
void GFL_DebugAssertFailEx(const char *file, u32 line, const char *function, u32 value, u32 end);
#define GFL_ASSERT(expression)                              \
    do {                                                    \
        if (!(expression)) {                                \
            GFL_DebugAssertFail("", 0, #expression);        \
        }                                                   \
    } while (0)

#endif // POKEBW2_GFL_STD_H
