#ifndef POKEBW2_FIELD_FIELD_RAIL_H
#define POKEBW2_FIELD_FIELD_RAIL_H

// The rail system of the no-grid maps, where the player moves along rails. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0), except FieldRailSystem_Free, FieldRailSystem_Reset and
// FieldRailSystem_SetLineEnabled

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// rail_attr.c: the tile attributes of the rail lines
typedef struct RailAttr RailAttr;

RailAttr *AllocateRailAttrBlock(u32 heapId);
void func_ov036_021b3a58(RailAttr *attr);
void FieldRailTilemap_Load(RailAttr *attr, u32 fileId, u32 heapId);
void func_ov036_021b3ad0(RailAttr *attr);
u32 FieldRailTilemap_GetTileAtPos(RailAttr *attr, const RailPosition *pos);
// Whether a tile class is one of the rails' special tiles
BOOL func_ov036_021b3b3c(u16 tileClass);
BOOL func_ov036_021b3b54(u32 tileClass);
BOOL func_ov036_021b3b64(u32 tileClass);
BOOL func_ov036_021b3b70(u32 tileClass);
BOOL func_ov036_021b3b7c(u32 tileClass);
BOOL func_ov036_021b3b88(u32 tileClass);
BOOL func_ov036_021b3b94(u32 tileClass);
BOOL func_ov036_021b3ba0(u32 tileClass);

// field_rail.c: the rail system
FieldRailSystem *FieldRailSystem_Create(HeapID heapId, u32 unitCount, FieldCamera *camera);
void FieldRailSystem_Free(FieldRailSystem *rail);
// Starts on the rail data, with every line on
void FieldRailSystem_Load(FieldRailSystem *rail, RailDataHandle *data);
void FieldRailSystem_Reset(FieldRailSystem *rail);
BOOL FieldRailSystem_HasData(FieldRailSystem *rail);
RailUnit *FieldRailSystem_AcquireUnit(FieldRailSystem *rail);
void FieldRailSystem_ReleaseUnit(FieldRailSystem *rail, RailUnit *unit);
void FieldRailSystem_SetCameraParent(FieldRailSystem *rail, RailUnit *unit);
void FieldRailSystem_ClearCameraParent(FieldRailSystem *rail);
// Does nothing: what is left of a check whether the rails are loaded and active
void func_ov036_021b0398(FieldRailSystem *rail);
// Updates the camera from its parent unit when the unit asks for it, the camera is dirty or force is set
BOOL FieldRailSystem_UpdateCamera(FieldRailSystem *rail, BOOL force);
// Turns a line on or off: the system keeps up to 18 lines that are off, and finds no line where one of them is
void FieldRailSystem_SetLineEnabled(FieldRailSystem *rail, u32 lineId, BOOL enabled);
// Sets pos to line componentId of the rail data, front steps along it and side steps from its edge
void FieldRailSystem_NormalizePos(FieldRailSystem *rail, RailDataHandle *data, u16 componentId, u16 front, u16 side,
                                  RailPosition *pos);
void FieldRailSystem_SetPlayerPos(FieldRailSystem *rail, const RailPosition *pos);
// Finds where the segment from start to end meets a rail
BOOL CalculateRailCurves(FieldRailSystem *rail, const VecFx32 *start, const VecFx32 *end, RailPosition *railPos,
                         VecFx32 *hit);
BOOL func_ov036_021b068c(FieldRailSystem *rail, const RailPosition *railPos, u32 railDir, RailPosition *next);
// The world position of the rail position
void func_ov036_021b06ec(FieldRailSystem *rail, const RailPosition *railPos, VecFx32 *pos);
// The length of a step on the rails
fx32 func_ov036_021b05ec(FieldRailSystem *rail);
void func_ov036_021b0774(RailUnit *unit, RailPosition *pos);
s32 func_ov036_021b0704(FieldRailSystem *rail, const RailPosition *pos);
void RailUnit_GetCalcPos(RailUnit *unit, VecFx32 *pos);
// Writes the unit's rail position to three script variables, or sets it from three values
void SetWkToActorRailPos(RailUnit *unit, u16 *a1, u16 *a2, u16 *a3);
void func_ov036_021b0e38(RailUnit *unit, u16 a1, u16 a2, u16 a3);

#endif // POKEBW2_FIELD_FIELD_RAIL_H
