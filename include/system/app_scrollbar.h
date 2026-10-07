#ifndef POKEBW2_SYSTEM_APP_SCROLLBAR_H
#define POKEBW2_SYSTEM_APP_SCROLLBAR_H

#include "types.h"

// The apps' scroll bars, in the main module. The ROM doesn't name the file that holds these

// The value from 0 to max that a touch at pos on a bar from start to end picks, with a thumb of thumbSize
u32 func_020355b8(u32 max, u32 pos, u32 start, u32 end, u32 thumbSize);

#endif // POKEBW2_SYSTEM_APP_SCROLLBAR_H
