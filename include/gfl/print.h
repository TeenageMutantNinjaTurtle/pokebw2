#ifndef POKEBW2_GFL_PRINT_H
#define POKEBW2_GFL_PRINT_H

#include "types.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "gfl/tcb.h"
#include "struct_decls.h"

// Printing text into windows. None of these functions has a name yet

typedef struct PrintQueue PrintQueue;
typedef struct PrintStream PrintStream;
typedef struct KeyCursor KeyCursor;
typedef struct WaitIcon WaitIcon;

// func_020223b4's states
#define PRINT_STREAM_RUNNING 0
#define PRINT_STREAM_PAUSED 1
#define PRINT_STREAM_DONE 2

// Returns the wait between characters for the text speed in the save data, or for a text speed from 0 to 4
s32 func_02017bcc(void);
s32 func_02017c50(u32 speed);

PrintQueue *func_02021998(HeapID heapId);
void func_02021a18(PrintQueue *queue);
void func_02021a3c(PrintQueue *queue);
void func_02021c44(PrintQueue *queue);
// Whether the queue has printed everything, and whether it still has text to print into a bitmap
BOOL func_02021c0c(PrintQueue *queue);
BOOL func_02021c1c(PrintQueue *queue, GFLBitmap *bitmap);
// Prints a string into a bitmap through the queue, in a color made of the text, shadow and background color indices
void func_02021c7c(PrintQueue *queue, GFLBitmap *bitmap, s16 x, s16 y, const StrBuf *strbuf, Font *font, u16 color);
#define PRINT_COLOR(text, shadow, background) (((text) << 10) | ((shadow) << 5) | (background))

// A window whose text goes through a print queue, and whose characters are sent to VRAM once it is printed
typedef struct {
    BmpWin *window;
    u8 flushPending;
} PrintWindow;

static inline void PrintWindow_Print(PrintWindow *printWindow, PrintQueue *queue, s16 x, s16 y, const StrBuf *strbuf,
                                     Font *font, u16 color) {
    func_02021c7c(queue, BmpWin_GetBitmap(printWindow->window), x, y, strbuf, font, color);
    printWindow->flushPending = TRUE;
}

static inline void PrintWindow_Flush(PrintWindow *printWindow, PrintQueue *queue) {
    if (printWindow->flushPending && !func_02021c1c(queue, BmpWin_GetBitmap(printWindow->window))) {
        BmpWin_FlushChar(printWindow->window);
        printWindow->flushPending = FALSE;
    }
}

// Prints a string into a window a character at a time
PrintStream *func_02022268(BmpWin *window, u32 x, u32 y, const StrBuf *strbuf, Font *font, s32 wait,
                           TCBExManager *tcbManager, u32 a7, HeapID heapId, u16 a9);
// func_02022268 with a callback, which the stream calls with events such as the 3 and 5 of the evolution demo's
// messages, and which returns whether to wait
typedef BOOL (*PrintStreamCallback)(u32 event);
PrintStream *func_02022294(BmpWin *window, u32 x, u32 y, const StrBuf *strbuf, Font *font, s32 wait,
                           TCBExManager *tcbManager, u32 a7, HeapID heapId, u16 a9, PrintStreamCallback callback);
u32 func_020223b4(PrintStream *stream);
// Continues printing after PRINT_STREAM_PAUSED
void func_020223bc(PrintStream *stream);
void func_020223cc(PrintStream *stream);
void func_020223e0(PrintStream *stream, u32 a1);

// The cursor that shows while a message waits for a button
KeyCursor *func_0202e7a4(u32 a0, u32 a1, u32 a2, HeapID heapId);
void func_0202e818(KeyCursor *cursor);
void func_0202e8d8(KeyCursor *cursor, PrintStream *stream, BmpWin *window);

// An icon that shows in a window while the game is busy
WaitIcon *func_02035734(HeapID heapId);
void func_0203576c(WaitIcon *icon, TCBManager *tcbManager, BmpWin *window, u32 a3, u32 a4);
void func_0203580c(WaitIcon *icon);
// The same icon, created shown and stepped by its owner
WaitIcon *func_02035604(u32 a0, BmpWin *window, u32 a2, u32 a3, HeapID heapId);
void func_02035884(WaitIcon *icon);

#endif // POKEBW2_GFL_PRINT_H
