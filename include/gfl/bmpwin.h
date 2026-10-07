#ifndef POKEBW2_GFL_BMPWIN_H
#define POKEBW2_GFL_BMPWIN_H

#include "types.h"
#include "gfl/bg_sys.h"
#include "gfl/bmp.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Windows on a BG that are drawn to as bitmaps (bmp_win.c). A window has a bitmap of its own characters, which
// BmpWin_FlushChar loads to the BG, and an area of the BG's screen buffer that BmpWin_FlushMap points at them. The area
// is the size of the bitmap unless BmpWin_SetHeight2 changes it

// The heap that windows are allocated from
void BmpWin_InitAllocator(HeapID heapId);
void BmpWin_FreeAllocator(void);
// A window of width by height tiles at x and y, whose characters are allocated in the BG's characters, from the end
// if fromEnd, or placed at charPos
BmpWin *BmpWin_CreateDynamic(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palette, u8 fromEnd);
BmpWin *BmpWin_CreateStatic(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palette, u32 charPos);
void BmpWin_Free(BmpWin *window);
void BmpWin_FlushChar(BmpWin *window);
void BmpWin_FlushMap(BmpWin *window);
// Draws a frame around the window on the BG's screen buffer, from the 8 characters from frameChar: the top left
// corner, top, top right corner, left, right, bottom left corner, bottom and bottom right corner
void BmpWin_MakeFrameScreen(BmpWin *window, u32 frameChar, u8 palette);
// Clears the window's area of its BG's screen
void BmpWin_ClearScreen(BmpWin *window);
u8 BmpWin_GetBGIndex(BmpWin *window);
// The size of the bitmap, and of the area of the screen, in tiles
u8 BmpWin_GetSizeX(BmpWin *window);
u8 BmpWin_GetSizeY(BmpWin *window);
u8 BmpWin_GetWidth1(BmpWin *window);
u8 BmpWin_GetHeight2(BmpWin *window);
u8 BmpWin_GetPosX(BmpWin *window);
u8 BmpWin_GetPosY(BmpWin *window);
u16 BmpWin_GetCharPos(BmpWin *window);
GFLBitmap *BmpWin_GetBitmap(BmpWin *window);
u8 BmpWin_GetPalette(BmpWin *window);
void BmpWin_SetPosX(BmpWin *window, u8 x);
void BmpWin_SetPosY(BmpWin *window, u8 y);
void BmpWin_SetHeight2(BmpWin *window, u8 height);
void BmpWin_SetPalette(BmpWin *window, u8 palette);

// Screens made from windows: func_020330c8 creates count of them, func_02033150 sets the size of one, func_020335c4 its
// window, and func_0203368c returns its screen data
void *func_020330c8(u32 a0, u32 count, HeapID heapId);
void func_02033120(void *a0);
void func_02033150(void *a0, u32 index, u32 a2, u32 width, u32 height);
void func_020335c4(void *a0, u32 index, BmpWin *window);
u16 *func_0203368c(void *a0, u32 index);
// Loads the screen of one from an archive, places it, shows or hides it, and moves it by steps
void func_020331f4(void *a0, u32 index, u32 arcId, u32 fileId, BOOL compressed);
// Loads a frame's screen data from an archive that is open
void func_02033224(void *a0, u32 index, ArcTool *arc, u32 fileId, BOOL compressed);
void func_02033254(void *a0, u32 index, s8 x, s8 y);
void func_02033360(void *a0, u32 index);
void func_02033378(void *a0, u32 index);
void func_0203346c(void *a0, u32 index, s8 moveX, s8 moveY, u8 count);
// Moves the screens, every frame
void func_0203349c(void *a0);
// Whether the screen is still moving
BOOL func_02033548(void *a0, u32 index);
void func_020336a0(void *a0, u32 index, s8 *x, s8 *y);

// Copies the window's characters and screen, the screen at the next VBlank
static inline void BmpWin_Transfer(BmpWin *window) {
    BmpWin_FlushChar(window);
    BmpWin_FlushMap(window);
    GFL_BGSysQueueScrLoad(BmpWin_GetBGIndex(window));
}

// BmpWin_Transfer with the screen copied at once
static inline void BmpWin_TransferNow(BmpWin *window) {
    BmpWin_FlushChar(window);
    BmpWin_FlushMap(window);
    GFL_BGSysLoadScr(BmpWin_GetBGIndex(window));
}

#endif // POKEBW2_GFL_BMPWIN_H
