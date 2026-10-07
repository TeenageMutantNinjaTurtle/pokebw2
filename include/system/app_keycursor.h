#ifndef POKEBW2_SYSTEM_APP_KEYCURSOR_H
#define POKEBW2_SYSTEM_APP_KEYCURSOR_H

#include "types.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "system/printsys.h"

typedef struct KeyCursor KeyCursor;

// The cursor (app_keycursor.c) that shows while a message waits for a button
KeyCursor *func_0202e7a4(u32 a0, u32 a1, u32 a2, HeapID heapId);
void func_0202e818(KeyCursor *cursor);
// Clear the cursor, and draw it, in a bitmap whose background is the color given
void func_0202e82c(KeyCursor *cursor, GFLBitmap *bitmap, u32 color);
void func_0202e870(KeyCursor *cursor, GFLBitmap *bitmap, u32 color);
void func_0202e8d8(KeyCursor *cursor, PrintStream *stream, BmpWin *window);

#endif // POKEBW2_SYSTEM_APP_KEYCURSOR_H
