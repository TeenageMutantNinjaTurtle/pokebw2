#ifndef POKEBW2_BATTLE_B_APP_TOOL_H
#define POKEBW2_BATTLE_B_APP_TOOL_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/overlay.h"
#include "system/cursor_move.h"
#include "system/printsys.h"

// Overlay 285, b_app_tool.c by the ROM's embedded string: helpers for the battle's apps, of which the battle party
// list uses the cursor and print window functions. The overlay is not decompiled yet, and every name here is ours.

#define OVERLAY_OV285 OVERLAY_ID(285)

void *func_ov285_021f4260(HeapID heapId);
void func_ov285_021f4284(void *cursor);
void func_ov285_021f428c(void *cursor, ClActUnit *unit, u32 chars, u32 palette, u32 cellAnims);
void func_ov285_021f42e4(void *cursor);
void func_ov285_021f42fc(void *cursor, BOOL visible);
void func_ov285_021f4320(void *cursor, const CursorMoveData *data); // places it at the data's corners
void func_ov285_021f439c(PrintWindow *printWindow);
void func_ov285_021f43b4(PrintWindow *windows, const u8 *list);
void func_ov285_021f43d0(PrintWindow *windows, PrintQueue *queue, u8 count);

#endif // POKEBW2_BATTLE_B_APP_TOOL_H
