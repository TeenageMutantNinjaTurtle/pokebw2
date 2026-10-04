#ifndef POKEBW2_SYSTEM_BMP_CURSOR_H
#define POKEBW2_SYSTEM_BMP_CURSOR_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"
#include "system/printsys.h"

// BmpCursor_Create is swan's name (https://github.com/ds-pokemon-hacking/swan, GPL-3.0). The others are named with
// bmp_cursor.c

// The cursor menus draw before their selected option (bmp_cursor.c)

BmpCursor *BmpCursor_Create(u32 heapId);
void func_0202654c(BmpCursor *cursor);
// Prints the cursor at x and y into the window
void func_0202656c(BmpCursor *cursor, u8 x, u8 y, PrintWindow *printWindow, PrintQueue *queue, Font *font);
// Loads the cursor's string
void func_020265d8(BmpCursor *cursor, u32 heapId);

#endif // POKEBW2_SYSTEM_BMP_CURSOR_H
