#ifndef POKEBW2_SYSTEM_CURSOR_MOVE_H
#define POKEBW2_SYSTEM_CURSOR_MOVE_H

#include "types.h"
#include "struct_decls.h"

// cursor_move.c: a cursor that moves between the positions of a table by key or touch

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
