#include "types.h"
#include "demo/intro.h"
#include "gfl/particle.h"

// The particles of the intro

#define INTRO_PARTICLE_BUFFER_SIZE 0x4800

struct IntroParticle {
    HeapID heapId;
    IntroGraphic *graphic;
    void *system;
    u8 buffer[INTRO_PARTICLE_BUFFER_SIZE];
};

// The camera: its up vector, position and target
static VecFx32 sCameraVectors[3] = {
    { 0, FX32_ONE, 0 },
    { 0, 0, FX32_CONST(70) },
    { 0, 0, -FX32_ONE },
};

IntroParticle *IntroParticle_Create(IntroGraphic *graphic, HeapID heapId) {
    IntroParticle *particle;
    ParticleProjection projection;

    func_0204f918(heapId);
    particle = GFL_HeapAllocate(heapId, sizeof(IntroParticle), TRUE, "intro_particle.c", 86);
    particle->system = func_0204f968(particle->buffer, INTRO_PARTICLE_BUFFER_SIZE, TRUE, heapId);
    particle->graphic = graphic;
    particle->heapId = heapId;
    projection.type = PARTICLE_PROJECTION_ORTHO;
    projection.param1 = FX32_CONST(4);
    projection.param2 = -FX32_CONST(4);
    projection.param3 = -FX32_CONST(3);
    projection.param4 = FX32_CONST(3);
    projection.near = FX32_ONE;
    projection.far = FX32_CONST(1024);
    projection.scaleW = FX32_ONE;
    func_02050178(particle->system);
    func_020500cc(particle->system, &projection, FX32_CONST(2), &sCameraVectors[1], &sCameraVectors[0],
                  &sCameraVectors[2], particle->heapId);
    func_0204fe04(particle->system, func_0204fdf8(6, 6, particle->heapId), TRUE, FALSE);
    return particle;
}

void IntroParticle_Free(IntroParticle *particle) {
    func_0204fb4c();
    GFL_HeapFree(particle);
}

void IntroParticle_Update(IntroParticle *particle) {
    func_0204f954();
}

void IntroParticle_SetPos(IntroParticle *particle, fx32 x, fx32 y, fx32 z) {
    VecFx32 pos = { 0, 0, 0 };

    pos.x = x;
    pos.y = y;
    pos.z = z;
    func_0205006c(particle->system, 0, &pos);
    func_0205006c(particle->system, 1, &pos);
    func_0205006c(particle->system, 2, &pos);
}
