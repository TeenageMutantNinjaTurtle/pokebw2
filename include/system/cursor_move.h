#ifndef POKEBW2_SYSTEM_CURSOR_MOVE_H
#define POKEBW2_SYSTEM_CURSOR_MOVE_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/touchpanel.h"
#include "struct_decls.h"

// cursor_move.c: a cursor that moves between the positions of a table by key or touch

// A position of the table: where the cursor goes, the positions it moves to by direction, and the rectangle that
// touches it. A table ends with a rect.top of TOUCH_RECT_END
typedef struct {
    u8 px;
    u8 py;
    u8 sx;
    u8 sy;
    u8 up;
    u8 down;
    u8 left;
    u8 right;
    TouchRect rect;
} CursorMoveData;

// Called when the cursor is shown, hidden, moved, and when a position is touched
typedef struct {
    void (*on)(void *work, int pos, int prevPos);
    void (*off)(void *work, int pos, int prevPos);
    void (*move)(void *work, int pos, int prevPos);
    void (*touch)(void *work, int pos, int prevPos);
} CursorMoveCallbacks;

CursorMove *func_0202b650(const CursorMoveData *data, const CursorMoveCallbacks *callbacks, void *work, BOOL visible,
                          u8 pos, HeapID heapId);
void func_0202b694(CursorMove *cursor);
void func_0202b69c(CursorMove *cursor);
// Moves the cursor by key or touch. Returns the position chosen, or one of the negative results
u32 func_0202b768(CursorMove *cursor);
// The current position
u8 func_0202ba60(CursorMove *cursor);
// Moves the cursor to a position
void func_0202ba64(CursorMove *cursor, u8 pos);
// Whether the cursor is shown, as when the keys were used last
BOOL func_0202ba70(CursorMove *cursor);
void func_0202ba74(CursorMove *cursor, BOOL visible);
// Turn a position of the table off and on
void func_0202baa4(CursorMove *cursor, u32 pos);
void func_0202bacc(CursorMove *cursor, u32 pos);

#endif // POKEBW2_SYSTEM_CURSOR_MOVE_H
