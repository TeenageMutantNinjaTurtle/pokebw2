#include "types.h"
#include "app/box2.h"
#include "app/box2_bgwfrm.h"
#include "app/box2_bmp.h"
#include "app/box2_main.h"
#include "app/box2_obj.h"
#include "constants/arc.h"
#include "gfl/bg_sys.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "system/bgwinfrm.h"

// The PC box's frames of BG screen data that slide in and out (bgwinfrm.c): the party, the box menu and the
// marking frame. The ROM doesn't name this file; box2_bgwfrm.c is a guess after box2_main.c. None of these functions
// has a name yet

static void func_ov255_021d36f4(BGWinFrame *frames, u32 index, u32 datId);
static void func_ov255_021d3898(BGWinFrame *frames);
static void func_ov255_021d3a08(Box2SysWork *syswk);

void func_ov255_021d364c(Box2SysWork *syswk) {
    Box2AppWork *app = syswk->app;

    app->bgWinFrame = func_020330c8(2, 12, HEAPID_BOX2_APP);
    func_ov255_021cec40(app);
    func_ov255_021d3a08(syswk);
    func_ov255_021cec98(syswk);
    func_ov255_021cecc4(syswk);

    func_02033150(app->bgWinFrame, 8, 1, 11, 15);
    if (syswk->param->mode == 4) {
        func_ov255_021d36f4(app->bgWinFrame, 8, 8);
    } else {
        func_ov255_021d36f4(app->bgWinFrame, 8, 9);
    }

    func_02033150(app->bgWinFrame, 7, 1, 11, 15);
    func_ov255_021d36f4(app->bgWinFrame, 7, 10);
    func_ov255_021ceea4(syswk);

    func_02033150(app->bgWinFrame, 9, 1, 11, 21);
    func_ov255_021d36f4(app->bgWinFrame, 9, 11);

    func_ov255_021d3898(app->bgWinFrame);
}

void func_ov255_021d36e8(Box2AppWork *app) {
    func_02033120(app->bgWinFrame);
}

static void func_ov255_021d36f4(BGWinFrame *frames, u32 index, u32 datId) {
    func_020331f4(frames, index, ARCID_BOX2, datId, TRUE);
}

void func_ov255_021d3704(BGWinFrame *frames) {
    func_02033254(frames, 8, 2, 6);
}

void func_ov255_021d3714(BGWinFrame *frames) {
    func_02033254(frames, 8, 21, 6);
}

void func_ov255_021d3724(BGWinFrame *frames) {
    func_02033254(frames, 8, 2, 24);
}

void func_ov255_021d3734(BGWinFrame *frames) {
    func_02033254(frames, 8, 21, 24);
}

void func_ov255_021d3744(BGWinFrame *frames) {
    s8 x, y;

    func_020336a0(frames, 8, &x, &y);
    if (y != 6) {
        func_0203346c(frames, 8, 0, -1, y - 6);
    }
}

void func_ov255_021d3778(BGWinFrame *frames) {
    s8 x, y;

    func_020336a0(frames, 8, &x, &y);
    if (y != 24) {
        func_0203346c(frames, 8, 0, 1, 24 - y);
    }
}

void func_ov255_021d37b0(BGWinFrame *frames) {
    func_0203346c(frames, 8, 1, 0, 19);
}

void func_ov255_021d37c4(BGWinFrame *frames) {
    func_0203346c(frames, 8, -1, 0, 19);
}

BOOL func_ov255_021d37d8(Box2SysWork *syswk) {
    s8 prevX, prevY, x, y;
    BOOL moving;
    BOOL ret;

    func_020336a0(syswk->app->bgWinFrame, 8, &prevX, &prevY);
    moving = func_020334dc(syswk->app->bgWinFrame, 8);
    func_020336a0(syswk->app->bgWinFrame, 8, &x, &y);
    if (prevX != x || prevY != y) {
        func_ov255_021d00d4(syswk);
    }
    ret = FALSE;
    if (moving) {
        ret = TRUE;
    }
    return ret;
}

BOOL func_ov255_021d3834(BGWinFrame *frames) {
    s8 x, y;

    func_020336a0(frames, 8, &x, &y);
    if (x == 21 && y == 6) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov255_021d3858(BGWinFrame *frames) {
    s8 x, y;

    func_020336a0(frames, 8, &x, &y);
    if (x == 2 && y == 6) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov255_021d387c(BGWinFrame *frames) {
    s8 x, y;

    func_020336a0(frames, 8, &x, &y);
    if (y == 6) {
        return TRUE;
    }
    return FALSE;
}

static void func_ov255_021d3898(BGWinFrame *frames) {
    u32 i;

    for (i = 0; i < 6; i++) {
        func_02033254(frames, i, 32, i * 3 + 2);
    }
}

void func_ov255_021d38bc(BGWinFrame *frames) {
    u32 i;

    for (i = 0; i < 6; i++) {
        func_02033254(frames, i, 21, i * 3 + 2);
    }
}

void func_ov255_021d38e0(BGWinFrame *frames) {
    u32 i;

    for (i = 0; i < 6; i++) {
        func_02033378(frames, i);
        func_02033254(frames, i, 32, i * 3 + 2);
    }
}

void func_ov255_021d390c(BGWinFrame *frames) {
    s8 x, y;
    u16 i = 0;

    func_020336a0(frames, 0, &x, &y);
    if (x != 21) {
        for (; i < 6; i++) {
            func_0203346c(frames, i, -1, 0, x - 21);
        }
    }
}

void func_ov255_021d3954(BGWinFrame *frames) {
    s8 x, y;
    u16 i = 0;

    func_020336a0(frames, 0, &x, &y);
    if (x != 32) {
        for (; i < 6; i++) {
            func_0203346c(frames, i, 1, 0, 32 - x);
        }
    }
}

BOOL func_ov255_021d399c(BGWinFrame *frames) {
    BOOL moving = FALSE;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (func_020334dc(frames, i) == TRUE) {
            moving = TRUE;
        }
    }
    return moving;
}

BOOL func_ov255_021d39c0(BGWinFrame *frames) {
    s8 x, y;
    BOOL ret = FALSE;

    func_020336a0(frames, 0, &x, &y);
    if (x != 32) {
        ret = TRUE;
    }
    return ret;
}

BOOL func_ov255_021d39e4(BGWinFrame *frames) {
    s8 x, y;
    BOOL ret = FALSE;

    func_020336a0(frames, 0, &x, &y);
    if (x == 21) {
        ret = TRUE;
    }
    return ret;
}

static void func_ov255_021d3a08(Box2SysWork *syswk) {
    u16 *screen = GFL_BGSysIsScrHeapExists(0);

    func_02033150(syswk->app->bgWinFrame, 6, 0, 32, 3);
    func_020331d4(syswk->app->bgWinFrame, 6, screen + 32 * 21);
}

void func_ov255_021d3a38(BGWinFrame *frames) {
    func_02033254(frames, 6, 0, 21);
}

void func_ov255_021d3a48(Box2AppWork *app) {
    func_02033254(app->bgWinFrame, 10, 0, 21);
}

void func_ov255_021d3a58(Box2AppWork *app) {
    func_02033378(app->bgWinFrame, 10);
}

void func_ov255_021d3a64(Box2AppWork *app) {
    func_02033254(app->bgWinFrame, 11, 0, 21);
}

void func_ov255_021d3a74(Box2AppWork *app) {
    func_02033378(app->bgWinFrame, 11);
}

void func_ov255_021d3a80(BGWinFrame *frames) {
    func_02033254(frames, 7, 21, 24);
    func_0203346c(frames, 7, 0, -1, 19);
}

void func_ov255_021d3aa4(BGWinFrame *frames) {
    func_0203346c(frames, 7, 0, 1, 19);
}

BOOL func_ov255_021d3ab8(Box2SysWork *syswk) {
    s8 prevX, prevY, x, y;
    BOOL moving;

    func_020336a0(syswk->app->bgWinFrame, 7, &prevX, &prevY);
    moving = func_020334dc(syswk->app->bgWinFrame, 7);
    func_020336a0(syswk->app->bgWinFrame, 7, &x, &y);
    if (prevX != x || prevY != y) {
        func_ov255_021d1364(syswk);
    }
    return moving;
}

void func_ov255_021d3b10(BGWinFrame *frames) {
    func_02033254(frames, 9, 32, 0);
    func_0203346c(frames, 9, -1, 0, 11);
}

void func_ov255_021d3b34(BGWinFrame *frames) {
    func_0203346c(frames, 9, 1, 0, 11);
}

BOOL func_ov255_021d3b48(BGWinFrame *frames) {
    s8 x, y;

    func_020336a0(frames, 9, &x, &y);
    if (x == 21) {
        return TRUE;
    }
    return FALSE;
}
