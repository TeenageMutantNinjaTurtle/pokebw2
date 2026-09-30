#ifndef POKEBW2_GFL_PARTICLE_H
#define POKEBW2_GFL_PARTICLE_H

#include "types.h"
#include "gfl/g3d.h"
#include "gfl/heap.h"
#include "nitro/fx.h"

// A particle system. None of these functions has a name yet

void func_0204f918(HeapID heapId);
// func_0204f980 with 5, 6 and 0x3f
void *func_0204f968(void *work, u32 size, BOOL a2, HeapID heapId);
void *func_0204f980(void *work, u32 size, BOOL a2, u32 a3, u32 a4, u32 a5, HeapID heapId);
void func_0204f954(void);
void func_0204fb4c(void);
void *func_0204fdf8(u32 arcId, u32 fileId, HeapID heapId);
void func_0204fe04(void *system, void *resource, BOOL a2, BOOL a3);
void func_0205006c(void *system, u32 emitter, const VecFx32 *pos);
// Sets the camera that the particles are drawn with
void func_020500cc(void *system, const G3DCameraProjection *projection, fx32 a2, const VecFx32 *position,
                   const VecFx32 *upVector, const VecFx32 *target, HeapID heapId);
void func_02050178(void *system);
void func_020500b0(void *system);
u8 func_020503f0(void *resource);

#endif // POKEBW2_GFL_PARTICLE_H
