#ifndef POKEBW2_GFL_BMPWIN_H
#define POKEBW2_GFL_BMPWIN_H

#include "types.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Windows on a BG that are drawn to as bitmaps

typedef struct BmpWin BmpWin;
typedef struct GFLBitmap GFLBitmap;

void BmpWin_InitAllocator(HeapID heapId);
void BmpWin_FreeAllocator(void);
BmpWin *BmpWin_CreateDynamic(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palette, u8 a6);
void BmpWin_Free(BmpWin *window);
GFLBitmap *BmpWin_GetBitmap(BmpWin *window);
u8 BmpWin_GetBGIndex(BmpWin *window);
void BmpWin_FlushChar(BmpWin *window);
void BmpWin_FlushMap(BmpWin *window);
// Loads a window frame's characters at the end of a BG's characters. The result is their position in the low 16 bits
// and their size in the high 16, as GFL_BGSysFreeCharMemory takes them
u32 LoadCursorImageEndOfHeap(u32 bg, u32 a1, u32 a2, HeapID heapId);
#define CHAR_POS(chars) ((chars) & 0xffff)
#define CHAR_SIZE(chars) ((chars) >> 16)
// Clears the window's area of its BG's screen
void func_020484b4(BmpWin *window);

// Screens made from windows: func_020330c8 creates count of them, func_02033150 sets the size of one, func_020335c4 its
// window, and func_0203368c returns its screen data
void *func_020330c8(u32 a0, u32 count, HeapID heapId);
void func_02033120(void *a0);
void func_02033150(void *a0, u32 index, u32 a2, u32 width, u32 height);
void func_020335c4(void *a0, u32 index, BmpWin *window);
u16 *func_0203368c(void *a0, u32 index);
void BmpWin_DrawFrame(BmpWin *window, u8 a1, u16 frameChar, u8 framePalette);
void func_02024eec(BmpWin *window, u32 a1);
// Loads a window frame's characters and palette for BmpWin_DrawFrame
void LoadSysMsgBox(u8 bg, u16 frameChar, u8 framePalette, u8 type, HeapID heapId);

// A bitmap of tiles, tileWidth by tileHeight, with bytesPerTile bytes to a tile
GFLBitmap *GFL_BitmapCreate(u32 tileWidth, u32 tileHeight, u32 bytesPerTile, HeapID heapId);
void GFL_BitmapFree(GFLBitmap *bitmap);
u8 *GFL_BitmapGetPixelData(GFLBitmap *bitmap);
// Rearranges the pixels from tiles into rows
GFLBitmap *GFL_BitmapMakeLinear(GFLBitmap *bitmap, BOOL keepAsNew, HeapID heapId);
void GFL_BitmapFill(GFLBitmap *bitmap, u8 fillIndex);
u32 GFL_BitmapGetWidth(GFLBitmap *bitmap);
void GFL_TextRendererDrawToBitmap(GFLBitmap *bitmap, u32 x, u32 y, const StrBuf *strbuf, Font *font);
// Draws in a color that PRINT_COLOR makes
void GFL_TextRendererDrawToBitmapEx(GFLBitmap *bitmap, s16 x, s16 y, const StrBuf *strbuf, Font *font, u16 color);

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
