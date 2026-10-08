#ifndef POKEBW2_FIELD_FIELD_RAIL_H
#define POKEBW2_FIELD_FIELD_RAIL_H

// The rail system of the no-grid maps, where the player moves along rails. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

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

FieldRailSystem *FieldNoGridMapper_GetRailSystem(NoGridMapper *mapper);
// Makes the camera follow the rail system's camera, or not
void FieldNoGridMapper_SetCameraParent(NoGridMapper *mapper, void *parent);
void FieldNoGridMapper_ClearCameraParent(NoGridMapper *mapper);
// Finds where the segment from start to end meets a rail
BOOL CalculateRailCurves(FieldRailSystem *rail, const VecFx32 *start, const VecFx32 *end, RailPosition *railPos,
                         VecFx32 *hit);
BOOL func_ov036_021b068c(FieldRailSystem *rail, const RailPosition *railPos, u32 railDir, RailPosition *next);
// The world position of the rail position
void func_ov036_021b06ec(FieldRailSystem *rail, const RailPosition *railPos, VecFx32 *pos);
void func_ov036_021b0774(RailUnit *unit, RailPosition *pos);
s32 func_ov036_021b0704(FieldRailSystem *rail, const RailPosition *pos);
void RailUnit_GetCalcPos(RailUnit *unit, VecFx32 *pos);
// Writes the unit's rail position to three script variables, or sets it from three values
void SetWkToActorRailPos(RailUnit *unit, u16 *a1, u16 *a2, u16 *a3);
void func_ov036_021b0e38(RailUnit *unit, u16 a1, u16 a2, u16 a3);
NoGridMapper *FieldNoGridMapper_Create(HeapID heapId, FieldCamera *camera, void *sceneArea, void *sceneAreaLoader);
void FieldNoGridMapper_Free(NoGridMapper *mapper);
void FieldNoGridMapper_LoadByHeader(NoGridMapper *mapper, u32 railId, HeapID heapId);
void FieldNoGridMapper_UpdateCamera(NoGridMapper *mapper);
void FieldNoGridMapper_ForceUpdateCamera(NoGridMapper *mapper);
u32 FieldNoGridMapper_GetTileAtPos(NoGridMapper *mapper, const RailPosition *pos);
void FieldNoGridMapper_SetPlayerPos(NoGridMapper *mapper, const RailPosition *pos);

#endif // POKEBW2_FIELD_FIELD_RAIL_H
