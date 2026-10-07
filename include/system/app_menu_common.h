#ifndef POKEBW2_SYSTEM_APP_MENU_COMMON_H
#define POKEBW2_SYSTEM_APP_MENU_COMMON_H

#include "types.h"

// The graphics that many apps share, such as the touch bar at the bottom of the touch screen and its icons: the
// archive and the files in it. getUINarcIdx is swan's name. The file name is a guess

u32 getUINarcIdx(void);
// The touch bar's icons: their palette, characters, and cells and animations for an OBJ VRAM mapping mode
u32 func_0202d810(void);
u32 func_0202d814(void);
u32 func_0202d818(u32 mapping);
u32 func_0202d81c(u32 mapping);
// The touch bar's BG: its palette, characters and screen
u32 func_0202d820(void);
u32 func_0202d824(void);
u32 func_0202d828(void);

#endif // POKEBW2_SYSTEM_APP_MENU_COMMON_H
