#ifndef POKEBW2_SYSTEM_BGWINFRM_H
#define POKEBW2_SYSTEM_BGWINFRM_H

#include "types.h"
#include "struct_decls.h"

// bgwinfrm.c: frames of BG screen data that slide in and out

// Sets a frame's screen data from a buffer, or from a file of an archive
void func_020331d4(BGWinFrame *frames, u32 index, u16 *screen);
void func_020331f4(BGWinFrame *frames, u32 index, u32 arcId, u32 datId, BOOL compressed);
// Puts a frame at a position, in tiles
void func_02033254(BGWinFrame *frames, u32 index, s8 x, s8 y);
// Takes a frame off its BG
void func_02033378(BGWinFrame *frames, u32 index);
// Starts moving a frame by a step of mx and my tiles a frame, for count frames
void func_0203346c(BGWinFrame *frames, u32 index, s8 mx, s8 my, u8 count);
// Sets the palette of an area of a frame's screen data
void func_02033558(BGWinFrame *frames, u32 index, u8 x, u8 y, u8 width, u8 height, u8 palette);
// Where a frame is, in tiles; either pointer may be NULL
void func_020336a0(BGWinFrame *frames, u32 index, s8 *x, s8 *y);
// A frame's size, in tiles; either pointer may be NULL
void func_020336c8(BGWinFrame *frames, u32 index, u16 *width, u16 *height);
// The BG a frame is on
u8 func_02033694(BGWinFrame *frames, u32 index);
// Whether a frame is moving
BOOL func_02033548(BGWinFrame *frames, u32 index);
// Moves a frame a step; FALSE once it has arrived
BOOL func_020334dc(BGWinFrame *frames, u32 index);

#endif // POKEBW2_SYSTEM_BGWINFRM_H
