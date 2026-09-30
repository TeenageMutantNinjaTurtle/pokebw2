#ifndef POKEBW2_GFL_BMPWIN_H
#define POKEBW2_GFL_BMPWIN_H

#include "types.h"
#include "gfl/heap.h"

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
void BmpWin_DrawFrame(BmpWin *window, u8 a1, u16 frameChar, u8 framePalette);
void func_02024eec(BmpWin *window, u32 a1);
// Loads a window frame's characters and palette for BmpWin_DrawFrame
void LoadSysMsgBox(u8 bg, u16 frameChar, u8 framePalette, u8 type, HeapID heapId);

void GFL_BitmapFill(GFLBitmap *bitmap, u8 fillIndex);

#endif // POKEBW2_GFL_BMPWIN_H
