#ifndef POKEBW2_SYSTEM_APP_COMMON_H
#define POKEBW2_SYSTEM_APP_COMMON_H

#include "types.h"

// The graphics that the game's applications share, such as the bar at the bottom of the lower screen. The ROM
// doesn't name this file

// The archive of the shared graphics
u32 getUINarcIdx(void);
// The files of the bar at the bottom of the screen: its palette, characters and screen
u32 func_0202d820(void);
u32 func_0202d824(void);
u32 func_0202d828(void);

#endif // POKEBW2_SYSTEM_APP_COMMON_H
