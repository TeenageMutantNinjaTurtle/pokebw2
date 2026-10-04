#ifndef POKEBW2_SYSTEM_APP_COMMON_H
#define POKEBW2_SYSTEM_APP_COMMON_H

#include "types.h"

// The graphics that the apps share, in one archive. The ROM doesn't name the file that holds these; they return
// the archive and its file IDs, some of them by the OBJ mapping mode passed

u32 getUINarcIdx(void);
u32 func_0202d810(void);
u32 func_0202d814(void);
u32 func_0202d818(u32 mapping);
u32 func_0202d81c(u32 mapping);
u32 func_0202d820(void);
u32 func_0202d824(void);
u32 func_0202d82c(void);
u32 func_0202d890(void);
u32 func_0202d894(void);
u32 func_0202d898(u32 mapping);
u32 func_0202d89c(u32 mapping);
u32 func_0202d8b0(void);
u32 func_0202d8b4(void);
u32 func_0202d8b8(u32 mapping);
u32 func_0202d8bc(u32 mapping);
u32 func_0202d954(void);
u32 func_0202d958(u32 mapping);
u32 func_0202d95c(u32 mapping);
u32 func_0202d960(u32 mapping);

#endif // POKEBW2_SYSTEM_APP_COMMON_H
