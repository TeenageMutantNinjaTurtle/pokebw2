#ifndef POKEBW2_FIELD_FIELD_RAIL_H
#define POKEBW2_FIELD_FIELD_RAIL_H

// The rail system of the no-grid maps, where the player moves along rails. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

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
NoGridMapper *FieldNoGridMapper_Create(HeapID heapId, FieldCamera *camera, void *sceneArea, void *sceneAreaLoader);
void FieldNoGridMapper_Free(NoGridMapper *mapper);
void FieldNoGridMapper_LoadByHeader(NoGridMapper *mapper, u32 railId, HeapID heapId);
void FieldNoGridMapper_UpdateCamera(NoGridMapper *mapper);

#endif // POKEBW2_FIELD_FIELD_RAIL_H
