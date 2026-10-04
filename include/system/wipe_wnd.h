#ifndef POKEBW2_SYSTEM_WIPE_WND_H
#define POKEBW2_SYSTEM_WIPE_WND_H

#include "types.h"
#include "struct_decls.h"

// The windows the screen wipes draw with (wipe_wnd.c, a guessed name): window register writes, made at once or at the
// next VBlank

typedef struct {
    u32 visible;
    u32 screen;
} WipeWndDisp;

typedef struct {
    u32 planes;
    BOOL effect;
    u32 window;
    u32 screen;
} WipeWndIn;

typedef struct {
    u32 planes;
    BOOL effect;
    u32 screen;
} WipeWndOut;

typedef struct {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    u32 window;
    u32 screen;
} WipeWndPos;

// The window writes waiting for the VBlank, per screen and window
struct WipeWnd {
    WipeWndDisp disp[2];
    WipeWndIn in[2][2];
    u8 unk50[0x18];
    WipeWndOut out[2];
    WipeWndPos pos[2][2];
};

// Sets which windows a screen shows
void func_0202946c(u32 visible, u32 screen);

#endif // POKEBW2_SYSTEM_WIPE_WND_H
