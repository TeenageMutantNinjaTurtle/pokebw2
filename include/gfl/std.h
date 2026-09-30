#ifndef POKEBW2_GFL_STD_H
#define POKEBW2_GFL_STD_H

#include "types.h"

void sys_memcpy(const void *src, void *dest, u32 size);
void sys_memcpy16(const void *src, void *dest, u32 size);
void sys_memset(void *dest, u32 value, u32 size);
void sys_memset32(u32 value, void *dest, u32 size);
void sys_memset32_fast(u32 value, void *dest, u32 size);
void *sys_memcpy32(const void *src, void *dest, u32 size);

// A failed assertion. The game's are built without the file and line, and keep the expression
void GFL_DebugAssertFail(const char *file, u32 line, const char *expression);
#define GFL_ASSERT(expression)                              \
    do {                                                    \
        if (!(expression)) {                                \
            GFL_DebugAssertFail("", 0, #expression);        \
        }                                                   \
    } while (0)

#endif // POKEBW2_GFL_STD_H
