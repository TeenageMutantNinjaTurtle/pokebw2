#ifndef POKEBW2_SYSTEM_APP_COMMON_H
#define POKEBW2_SYSTEM_APP_COMMON_H

#include "types.h"

// The graphics that the game's applications share, such as the bar at the bottom of the lower screen. The ROM
// doesn't name this file

// The archive of the shared graphics
u32 getUINarcIdx(void);
// The files of the Pokémon types' icons: their palette, the characters and palette number of a type, and their cells
// and animations for an OBJ mapping
u32 func_0202d7e4(void);
u8 func_0202d7e8(u8 type);
u32 func_0202d7f4(u8 type);
u32 func_0202d7f8(u32 mapping);
u32 func_0202d7fc(u32 mapping);
// The files of the bar's icons: their palette and characters, and their cells and animations for an OBJ mapping
u32 func_0202d810(void);
u32 func_0202d814(void);
u32 func_0202d818(u32 mapping);
u32 func_0202d81c(u32 mapping);
// The files of the bar at the bottom of the screen: its palette, characters and screen
u32 func_0202d820(void);
u32 func_0202d824(void);
u32 func_0202d828(void);
// The files of another set of shared OBJs: their palette and characters, and their cells and animations for an OBJ
// mapping
u32 func_0202d944(void);
u32 func_0202d948(u32 mapping);
u32 func_0202d94c(u32 mapping);
u32 func_0202d950(u32 mapping);
// The files of a third set of shared OBJs, in the same order
u32 func_0202d964(void);
u32 func_0202d968(u32 mapping);
u32 func_0202d96c(u32 mapping);
u32 func_0202d970(u32 mapping);

#endif // POKEBW2_SYSTEM_APP_COMMON_H
