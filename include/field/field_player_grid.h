#ifndef POKEBW2_FIELD_FIELD_PLAYER_GRID_H
#define POKEBW2_FIELD_FIELD_PLAYER_GRID_H

// The field player's grid movement, overlay 36's field_player_grid.c. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

FieldPlayerGrid *FieldPlayerCore_InitGridCtl(FieldPlayerCore *core, HeapID heapId);
void func_ov036_0219b80c(FieldPlayerGrid *grid);
void FieldPlayerGrid_UpdateMovement(FieldPlayerGrid *grid, u32 pressedKeys, u32 heldKeys, u32 flags);
void FieldPlayerGrid_ForceBrake(FieldPlayerGrid *grid);
BOOL FieldPlayerGrid_IsConstMoving(FieldPlayerGrid *grid);
BOOL FieldPlayerGrid_IsCatwalkExiting(FieldPlayerGrid *grid);
void FieldPlayerGrid_SanitizeHeightMismatch(FieldPlayerGrid *grid);
void FieldPlayerGrid_InterruptCatwalkBalance(FieldPlayerGrid *grid, BOOL keep);
void func_ov036_0219cd84(FieldPlayerGrid *grid);
BOOL FieldPlayerGrid_GetVerticalMoveOnlyFlag(FieldPlayerGrid *grid);
void func_ov036_0219cd90(FieldPlayerGrid *grid);
BOOL func_ov036_0219cd98(FieldPlayerGrid *grid);
// Later in overlay 36, with the grid player's events
GameEvent *FieldPlayerGrid_CheckObjContactEvent(FieldPlayerGrid *grid, u32 pressedKeys, u32 heldKeys, u32 flags);

#endif // POKEBW2_FIELD_FIELD_PLAYER_GRID_H
