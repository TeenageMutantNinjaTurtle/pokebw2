#ifndef POKEBW2_SYSTEM_BGWINFRM_H
#define POKEBW2_SYSTEM_BGWINFRM_H

#include "types.h"
#include "gfl/bmpwin.h"
#include "struct_decls.h"

// bgwinfrm.c: frames of BG screen data that slide in and out. gfl/bmpwin.h declares the rest of them, taking the
// frames as a void pointer: loading, placing, removing and moving a frame, where it is and whether it moves

// Sets a frame's screen data from a buffer
void func_020331d4(BGWinFrame *frames, u32 index, u16 *screen);
// Moves a frame a step; FALSE once it has arrived
BOOL func_020334dc(BGWinFrame *frames, u32 index);
// Sets the palette of an area of a frame's screen data
void func_02033558(BGWinFrame *frames, u32 index, u8 x, u8 y, u8 width, u8 height, u8 palette);
// The BG a frame is on
u8 func_02033694(BGWinFrame *frames, u32 index);
// A frame's size, in tiles; either pointer may be NULL
void func_020336c8(BGWinFrame *frames, u32 index, u16 *width, u16 *height);

#endif // POKEBW2_SYSTEM_BGWINFRM_H
