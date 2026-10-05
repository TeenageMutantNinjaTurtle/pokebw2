#ifndef POKEBW2_SYSTEM_APP_COMMON_H
#define POKEBW2_SYSTEM_APP_COMMON_H

#include "types.h"

// What apps share: the archive files of their common graphics, and checks they make. The name is descriptive

BOOL func_0202d7d8(void);
void func_0202d7dc(void);
// The archive of the common graphics
u32 getUINarcIdx(void);
// The files of the type icons in that archive: the palette, a type's palette slot and characters, and the cells and
// animations for a mapping mode
u32 func_0202d7e4(void);
u32 func_0202d7e8(u32 type);
u32 func_0202d7f4(u32 type);
u32 func_0202d7f8(u32 mapping);
u32 func_0202d7fc(u32 mapping);
// The files of the common OBJ sprites: the palette, the characters, and the cells and animations for a mapping mode
u32 func_0202d810(void);
u32 func_0202d814(void);
u32 func_0202d818(u32 mapping);
u32 func_0202d81c(u32 mapping);
// The files of a Poké Ball's icon: palette, characters, cells and animations
u32 func_0202d91c(u32 ball);
u32 func_0202d928(u32 ball);
u32 func_0202d934(u32 ball, u32 mapping);
u32 func_0202d93c(u32 ball, u32 mapping);

#endif // POKEBW2_SYSTEM_APP_COMMON_H
