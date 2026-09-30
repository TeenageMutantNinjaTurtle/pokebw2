#ifndef POKEBW2_GFL_PARTICLE_H
#define POKEBW2_GFL_PARTICLE_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"

// A particle system. None of these functions has a name yet

// The type of a particle system's projection
enum {
    PARTICLE_PROJECTION_PERSPECTIVE,
    PARTICLE_PROJECTION_ORTHO = 2,
};

typedef struct {
    u32 type;
    // A perspective projection's sine and cosine of half its field of view, its aspect ratio and an unused 0, or an
    // orthographic projection's top, bottom, left and right
    fx32 param1;
    fx32 param2;
    fx32 param3;
    fx32 param4;
    fx32 near;
    fx32 far;
    fx32 scaleW;
} ParticleProjection;

void func_0204f918(HeapID heapId);
// func_0204f980 with 5, 6 and 0x3f
void *func_0204f968(void *work, u32 size, BOOL a2, HeapID heapId);
void *func_0204f980(void *work, u32 size, BOOL a2, u32 a3, u32 a4, u32 a5, HeapID heapId);
void func_0204f954(void);
void func_0204fb4c(void);
void *func_0204fdf8(u32 arcId, u32 fileId, HeapID heapId);
void func_0204fe04(void *system, void *resource, BOOL a2, BOOL a3);
void func_0205006c(void *system, u32 emitter, const VecFx32 *pos);
void func_020500cc(void *system, const ParticleProjection *projection, fx32 a2, const VecFx32 *a3, const VecFx32 *a4,
                   const VecFx32 *a5, HeapID heapId);
void func_02050178(void *system);
void func_020500b0(void *system);
u8 func_020503f0(void *resource);

#endif // POKEBW2_GFL_PARTICLE_H
