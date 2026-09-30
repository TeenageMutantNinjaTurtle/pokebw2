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

// Returns the wait between characters for the text speed in the save data
s32 func_02017bcc(void);

PrintQueue *func_02021998(HeapID heapId);
void func_02021a18(PrintQueue *queue);
void func_02021a3c(PrintQueue *queue);

// Prints a string into a window a character at a time
PrintStream *func_02022268(BmpWin *window, u32 x, u32 y, const StrBuf *strbuf, Font *font, s32 wait,
                           TCBExManager *tcbManager, u32 a7, HeapID heapId, u16 a9);
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

#endif // POKEBW2_GFL_PRINT_H
