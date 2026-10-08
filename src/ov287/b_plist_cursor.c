#include "battle/b_plist_cursor.h"
#include "battle/b_app_tool.h"
#include "battle/b_plist_main.h"
#include "system/cursor_move.h"

// The battle party list's key cursor: a CursorMove on the page's table of positions, whose callbacks move and show
// overlay 285's cursor. The file name is our guess, after the ROM's b_plist_main.c and b_plist_anm.c and the
// b_plist_* files of the earlier games.

static void BPlistCursor_SetVisible(BPlistWork *work, BOOL visible);
static void BPlistCursor_Put(BPlistWork *work, int pos);
static void BPlistCursor_CallbackCursorOn(void *work, int pos, int prevPos);
static void BPlistCursor_CallbackCursorOff(void *work, int pos, int prevPos);
static void BPlistCursor_CallbackTouch(void *work, int pos, int prevPos);
static void BPlistCursor_CallbackMove(void *work, int pos, int prevPos);

// The positions of each page; pages 0 and 8 share the party's
static const CursorMoveData data_ov287_021fb78c[8] = {
    { 64, 24, 132, 50, 6, 2, 6, 1, { 0, 47, 0, 127 } },       { 192, 32, 132, 50, 4, 3, 0, 2, { 8, 55, 128, 255 } },
    { 64, 72, 132, 50, 0, 4, 1, 3, { 48, 95, 0, 127 } },      { 192, 80, 132, 50, 1, 5, 2, 4, { 56, 103, 128, 255 } },
    { 64, 120, 132, 50, 2, 1, 3, 5, { 96, 143, 0, 127 } },    { 192, 128, 132, 50, 3, 6, 4, 6, { 104, 151, 128, 255 } },
    { 236, 172, 40, 40, 5, 0, 5, 0, { 152, 191, 216, 255 } }, { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb630[5] = {
    { 128, 80, 164, 116, 0, CURSOR_MOVE_LINK_RETURN | 1, 0, 0, { 24, 131, 52, 203 } },
    { 52, 172, 104, 40, 0, 1, 1, 2, { 152, 191, 0, 103 } },
    { 156, 172, 104, 40, 0, 2, 1, 3, { 152, 191, 104, 207 } },
    { 236, 172, 40, 40, 0, 3, 2, 3, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb66c[5] = {
    { 16, 174, 36, 36, 0, 0, 0, 1, { 152, 191, 0, 39 } },     { 56, 174, 36, 36, 1, 1, 0, 2, { 152, 191, 40, 79 } },
    { 148, 172, 104, 40, 2, 2, 1, 3, { 152, 191, 96, 199 } }, { 236, 172, 40, 40, 3, 3, 2, 3, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb7ec[9] = {
    { 64, 72, 128, 48, 0, 2, 0, 1, { 48, 95, 0, 127 } },
    { 192, 72, 128, 48, 1, 3, 0, 1, { 48, 95, 128, 255 } },
    { 64, 120, 128, 48, 0, CURSOR_MOVE_LINK_RETURN | 4, 2, 3, { 96, 143, 0, 127 } },
    { 192, 120, 128, 48, 1, CURSOR_MOVE_LINK_RETURN | 7, 2, 3, { 96, 143, 128, 255 } },
    { 16, 174, 36, 36, 2, 4, 4, 5, { 152, 191, 0, 39 } },
    { 56, 174, 36, 36, 2, 5, 4, 6, { 152, 191, 40, 79 } },
    { 148, 172, 104, 40, 3, 6, 5, 7, { 152, 191, 96, 199 } },
    { 236, 172, 40, 40, 3, 7, 6, 7, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb6a8[6] = {
    { 108, 160, 52, 32, 0, 2, 0, 1, { 152, 167, 88, 127 } },
    { 148, 160, 52, 32, 1, 3, 0, 4, { 152, 167, 128, 167 } },
    { 108, 176, 52, 32, 0, 2, 2, 3, { 168, 183, 88, 127 } },
    { 148, 176, 52, 32, 1, 3, 2, 4, { 168, 183, 128, 167 } },
    { 236, 172, 40, 40, 4, 4, CURSOR_MOVE_LINK_RETURN | 3, 4, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb6f0[6] = {
    { 64, 72, 128, 48, 0, 2, 0, 1, { 48, 95, 0, 127 } },
    { 192, 72, 128, 48, 1, 3, 0, 1, { 48, 95, 128, 255 } },
    { 64, 120, 128, 48, 0, 4, 2, 3, { 96, 143, 0, 127 } },
    { 192, 120, 128, 48, 1, 4, 2, 3, { 96, 143, 128, 255 } },
    { 236, 172, 40, 40, CURSOR_MOVE_LINK_RETURN | 3, 4, 4, 4, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb738[7] = {
    { 64, 72, 128, 48, 0, 2, 0, 1, { 48, 95, 0, 127 } },      { 192, 72, 128, 48, 1, 3, 0, 1, { 48, 95, 128, 255 } },
    { 64, 120, 128, 48, 0, 4, 2, 3, { 96, 143, 0, 127 } },    { 192, 120, 128, 48, 1, 5, 2, 3, { 96, 143, 128, 255 } },
    { 128, 168, 128, 48, 2, 4, 4, 5, { 144, 191, 64, 191 } }, { 236, 172, 40, 40, 3, 5, 4, 5, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData data_ov287_021fb5e8[3] = {
    { 104, 172, 200, 40, 0, 0, 0, 1, { 152, 191, 0, 207 } },
    { 236, 172, 40, 40, 1, 1, 0, 1, { 152, 191, 216, 255 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, { TOUCH_RECT_END, 0, 0, 0 } },
};

static const CursorMoveData *const data_ov287_021fb60c[9] = {
    data_ov287_021fb78c, data_ov287_021fb630, data_ov287_021fb66c, data_ov287_021fb7ec, data_ov287_021fb6a8,
    data_ov287_021fb6f0, data_ov287_021fb738, data_ov287_021fb5e8, data_ov287_021fb78c,
};

static const CursorMoveCallbacks data_ov287_021fb5d8 = {
    BPlistCursor_CallbackCursorOn,
    BPlistCursor_CallbackCursorOff,
    BPlistCursor_CallbackMove,
    BPlistCursor_CallbackTouch,
};

void BPlistCursor_Create(BPlistWork *work, u8 page, int pos) {
    work->cursorMove = CursorMove_Create(data_ov287_021fb60c[page], &data_ov287_021fb5d8, work, work->cursorVisible,
                                         pos, work->param->heapId);
    CursorMove_SetHideOnTouch(work->cursorMove);
    CursorMove_SetBOnlyShowsCursor(work->cursorMove);
    BPlistCursor_Put(work, pos);
}

void BPlistCursor_Delete(BPlistWork *work) {
    CursorMove_Delete(work->cursorMove);
}

void BPlistCursor_ChangePage(BPlistWork *work, u8 page, int pos) {
    BPlistCursor_Delete(work);
    BPlistCursor_Create(work, page, pos);
}

static void BPlistCursor_SetVisible(BPlistWork *work, BOOL visible) {
    work->cursorVisible = visible;
    BAppCursor_SetVisible(work->cursor, visible);
}

static void BPlistCursor_Put(BPlistWork *work, int pos) {
    BAppCursor_SetPos(work->cursor, CursorMove_GetData(work->cursorMove, pos));
}

static void BPlistCursor_CallbackCursorOn(void *work, int pos, int prevPos) {
    BPlistCursor_Put(work, pos);
    BPlistCursor_SetVisible(work, TRUE);
}

static void BPlistCursor_CallbackCursorOff(void *work, int pos, int prevPos) {
    BPlistCursor_SetVisible(work, FALSE);
}

static void BPlistCursor_CallbackTouch(void *work, int pos, int prevPos) {
    BPlistCursor_SetVisible(work, FALSE);
}

static void BPlistCursor_CallbackMove(void *work, int pos, int prevPos) {
    BPlistCursor_Put(work, pos);
}
