#ifndef POKEBW2_FIELD_ENCOUNTER_EFFECT_H
#define POKEBW2_FIELD_ENCOUNTER_EFFECT_H

#include "types.h"
#include "struct_decls.h"

// Shared work layout for the encounter transition effects in overlays 152 and 153.
struct EffectCell {
    u8 pad[0x34];
    u32 visible;
    u8 rest[8];
};

struct EffectGridTail {
    s32 row;
    s32 delay;
    u16 width;
    u16 height;
};

struct EffectGrid {
    EffectCell cells[192];
    EffectGridTail tail;
};

struct EffectState {
    u8 pad0[0x1c];
    s32 offset;
    u8 pad1[0x10];
    s32 frame;
    u8 pad2[4];
    u32 done;
};

struct EffectParam {
    u32 a;
    u32 b;
    u32 c;
    void (*update)(EffectGrid *grid);
    u32 (*finished)(EffectState *state);
};

void func_ov036_021c5ea0(EncEff *effect);
void *func_ov148_021f59e0(void *event, const u32 *params, void (*init)(EffectState *), void (*render)(void *));
void func_ov150_021f5da0(EffectState *state, const EffectParam *params, int mode);
void func_ov150_021f5fac(void *state);

void *func_ov152_021f6200(void *event, Field *field);
void func_ov152_021f623c(EffectState *state);
void func_ov152_021f6264(EffectGrid *grid);
u32 func_ov152_021f62a4(EffectState *state);

void *func_ov153_021f6200(void *event, Field *field);
void func_ov153_021f623c(EffectState *state);
void func_ov153_021f6268(EffectGrid *grid);
u32 func_ov153_021f62c4(EffectState *state);

#endif // POKEBW2_FIELD_ENCOUNTER_EFFECT_H
