#ifndef POKEBW2_SYSTEM_BGWINFRM_H
#define POKEBW2_SYSTEM_BGWINFRM_H

#include "types.h"
#include "struct_decls.h"

// bgwinfrm.c: frames of BG screen data that slide in and out

// Where a frame is, in tiles; either pointer may be NULL
void func_020336a0(BGWinFrame *frames, u32 index, s8 *x, s8 *y);
// A frame's size, in tiles; either pointer may be NULL
void func_020336c8(BGWinFrame *frames, u32 index, u16 *width, u16 *height);
// The BG a frame is on
u8 func_02033694(BGWinFrame *frames, u32 index);

#endif // POKEBW2_SYSTEM_BGWINFRM_H
