#ifndef POKEBW2_FIELD_TALKMSGWIN_H
#define POKEBW2_FIELD_TALKMSGWIN_H

#include "types.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The field's talk windows (talkmsgwin.c, overlay 36), whose frame other overlays draw around their own windows with
// overlay 36 loaded. Only the functions those overlays call are declared; their names are ours

typedef struct TalkMsgWinSys TalkMsgWinSys;

typedef struct {
    HeapID heapId;
    u32 unk4;
    Font *font;
    u16 unkC;
    u32 bg;
    u8 unk14;
    u8 unk15;
} TalkMsgWinSetup;

TalkMsgWinSys *func_ov036_0218b1f8(const TalkMsgWinSetup *setup);
void func_ov036_0218b320(TalkMsgWinSys *sys);
// Draws the talk window's frame around a window, and clears it
void func_ov036_0218b5ac(TalkMsgWinSys *sys, BmpWin *window, u32 a2);
void func_ov036_0218b5bc(TalkMsgWinSys *sys, BmpWin *window);

#endif // POKEBW2_FIELD_TALKMSGWIN_H
