#include "types.h"
#include "app/musical/sta_act_effect.h"
#include "constants/arc.h"
#include "gfl/heap.h"
#include "gfl/particle.h"
#include "gfl/tcb.h"

// Overlay 209's sta_act_effect.c: the stage's particle effects

StaActEffectSys *StaActEffect_InitSystem(HeapID heapId) {
    u8 i;
    StaActEffectSys *sys = GFL_HeapAllocate(heapId, sizeof(StaActEffectSys), FALSE, "sta_act_effect.c", 76);

    sys->heapId = heapId;
    func_0204f918(heapId);
    for (i = 0; i < STA_ACT_EFFECT_MAX; i++) {
        sys->effects[i].active = FALSE;
    }
    return sys;
}

void StaActEffect_TermSystem(StaActEffectSys *sys) {
    u8 i;

    for (i = 0; i < STA_ACT_EFFECT_MAX; i++) {
        if (sys->effects[i].active == TRUE) {
            StaActEffect_DelEffect(sys, &sys->effects[i]);
        }
    }
    func_0204fb4c();
    GFL_HeapFree(sys);
}

void StaActEffect_UpdateSystem(StaActEffectSys *sys) {
    func_02050044();
}

void StaActEffect_DrawSystem(StaActEffectSys *sys) {
    func_0205001c();
}

StaActEffect *StaActEffect_AddEffect(StaActEffectSys *sys, u32 fileId) {
    u8 i;
    StaActEffect *effect = NULL;
    void *res;

    for (i = 0; i < STA_ACT_EFFECT_MAX; i++) {
        if (sys->effects[i].active == FALSE) {
            effect = &sys->effects[i];
        }
    }
    effect->ptc = func_0204f968(effect->ptcWork, sizeof(effect->ptcWork), FALSE, sys->heapId);
    res = func_0204fdf8(ARCID_MUSICAL, fileId, sys->heapId);
    func_0204fe04(effect->ptc, res, FALSE, GFL_VBlankGetTCBMgr());
    for (i = 0; i < STA_ACT_EFFECT_EMITTER_MAX; i++) {
        effect->emitters[i].emitter = NULL;
    }
    effect->active = TRUE;
    return effect;
}

void StaActEffect_DelEffect(StaActEffectSys *sys, StaActEffect *effect) {
    effect->active = FALSE;
    func_020500b0(effect->ptc);
    func_0204fa84(effect->ptc);
}

void StaActEffect_CreateEmitter(StaActEffect *effect, u16 emitterNo, VecFx32 *pos) {
    SPLEmitter *emitter = func_0205006c(effect->ptc, emitterNo, pos);

    if (emitter == NULL || emitterNo < STA_ACT_EFFECT_EMITTER_MAX) {
        effect->emitters[emitterNo].emitter = emitter;
        VEC_Set(&effect->emitters[emitterNo].pos, pos->x, pos->y, pos->z);
    }
}

void StaActEffect_DeleteEmitter(StaActEffect *effect, u16 emitterNo) {
    if (effect->emitters[emitterNo].emitter != NULL) {
        func_020500bc(effect->ptc, effect->emitters[emitterNo].emitter);
    }
}

void StaActEffect_SetPosition(StaActEffect *effect, u16 emitterNo, VecFx32 *pos) {
    if (effect->emitters[emitterNo].emitter != NULL) {
        func_02050208(effect->emitters[emitterNo].emitter, pos);
    }
}
