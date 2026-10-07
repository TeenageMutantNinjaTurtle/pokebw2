#ifndef POKEBW2_SYSTEM_APP_COMMON_H
#define POKEBW2_SYSTEM_APP_COMMON_H

#include "types.h"

// The graphics that the apps share, in one archive. The ROM doesn't name the file that holds these; they return
// the archive and its file IDs, some of them by the OBJ mapping mode passed

BOOL func_0202d7d8(void);
void func_0202d7dc(void);
u32 getUINarcIdx(void);
// The files of the Pokémon types' icons: their palette, the characters and palette number of a type, and their cells
// and animations for an OBJ mapping
u32 func_0202d7e4(void);
u8 func_0202d7e8(u8 type);
u32 func_0202d7f4(u8 type);
u32 func_0202d7f8(u32 mapping);
u32 func_0202d7fc(u32 mapping);
u32 func_0202d810(void);
u32 func_0202d814(void);
u32 func_0202d818(u32 mapping);
u32 func_0202d81c(u32 mapping);
u32 func_0202d820(void);
u32 func_0202d824(void);
u32 func_0202d828(void);
u32 func_0202d82c(void);
u32 func_0202d890(void);
u32 func_0202d894(void);
u32 func_0202d898(u32 mapping);
u32 func_0202d89c(u32 mapping);
u32 func_0202d8b0(void);
u32 func_0202d8b4(void);
u32 func_0202d8b8(u32 mapping);
u32 func_0202d8bc(u32 mapping);
// The files of a Poké Ball's icon: palette, characters, cells and animations
u32 func_0202d91c(u32 ball);
u32 func_0202d928(u32 ball);
u32 func_0202d934(u32 ball, u32 mapping);
u32 func_0202d93c(u32 ball, u32 mapping);
u32 func_0202d944(void);
u32 func_0202d948(u32 mapping);
u32 func_0202d94c(u32 mapping);
u32 func_0202d950(u32 mapping);
u32 func_0202d954(void);
u32 func_0202d958(u32 mapping);
u32 func_0202d95c(u32 mapping);
u32 func_0202d960(u32 mapping);
u32 func_0202d964(void);
u32 func_0202d968(u32 mapping);
u32 func_0202d96c(u32 mapping);
u32 func_0202d970(u32 mapping);

#endif // POKEBW2_SYSTEM_APP_COMMON_H
