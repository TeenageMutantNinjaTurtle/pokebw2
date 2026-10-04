#ifndef POKEBW2_SPL_INTERNAL_H
#define POKEBW2_SPL_INTERNAL_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/spl.h"

// What SPL's files share among themselves

// A linear congruential generator, its high bits the random value
extern u32 gSPLRandomState;

static inline u32 SPLRandom_Next(void) {
    gSPLRandomState = gSPLRandomState * 0x5eedf715 + 0x1b0cb173;
    return gSPLRandomState;
}

// The top bits of the next value, as a signed fixed-point number: a fraction of [-1, 1) for 24 bits
static inline fx32 SPLRandom_Fx32(u32 bits) {
    return (fx32)SPLRandom_Next() >> (32 - bits);
}

// A random value in [-range, range), range an integer or a fixed-point number. A macro, as the library reads range
// after drawing the number
#define SPLRandom_Range(range) (((range) * (s32)(SPLRandom_Next() >> 23) - ((range) << 8)) >> 8)

// value, more or less by a random part of up to variance out of 255
#define SPLRandom_Vary(value, variance)                                                                               \
    (((value) * (255 + (variance) - (((variance) * (s32)(SPLRandom_Next() >> 24)) >> 7))) >> 8)

// A random unit vector, or one in the xy plane
void SPLRandom_VecFx32(VecFx32 *vec);
void SPLRandom_VecFx32_XY(VecFx32 *vec);

// Emit the emitter's particles for this frame, or a particle's children, taking them from the free list
void SPLEmitter_EmitParticles(SPLEmitter *emitter, SPLList *freeList);
void SPLEmitter_EmitChildren(SPLParticle *parent, SPLEmitter *emitter, SPLList *freeList);

#endif // POKEBW2_SPL_INTERNAL_H
