#include "types.h"
#include "field/field.h"

typedef struct {
    u8 pad[0x34];
    u32 visible;
    u8 rest[8];
} EffectCell;

typedef struct {
    s32 row;
    s32 delay;
    u16 width;
    u16 height;
} EffectGridTail;

typedef struct {
    EffectCell cells[192];
    EffectGridTail tail;
} EffectGrid;

typedef struct {
    u8 pad0[0x1c];
    s32 offset;
    u8 pad1[0x10];
    s32 frame;
    u8 pad2[4];
    u32 done;
} EffectState;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    void (*update)(EffectGrid *grid);
    u32 (*finished)(EffectState *state);
} EffectParam;

extern void func_ov036_021c5ea0(EncEff *effect);
extern void *func_ov148_021f59e0(void *event, const u32 *params, void (*init)(EffectState *), void (*render)(void *));
extern void func_ov150_021f5da0(EffectState *state, const EffectParam *params, int mode);
extern void func_ov150_021f5fac(void *state);

void *func_ov152_021f6200(void *event, Field *field);
void func_ov152_021f623c(EffectState *state);
void func_ov152_021f6264(EffectGrid *grid);
u32 func_ov152_021f62a4(EffectState *state);

void *func_ov152_021f6200(void *event, Field *field) {
    u32 params[3] = {0, 0, 0x108000};
    func_ov036_021c5ea0(Field_GetEncEff(field));
    return func_ov148_021f59e0(event, params, func_ov152_021f623c, func_ov150_021f5fac);
}

void func_ov152_021f623c(EffectState *state) {
    EffectParam params;
    params.a = 4;
    params.b = 4;
    params.c = 0;
    params.update = func_ov152_021f6264;
    params.finished = func_ov152_021f62a4;
    func_ov150_021f5da0(state, &params, 0);
}

void func_ov152_021f6264(EffectGrid *grid) {
    u8 *bytes = (u8 *)grid;
    u32 *state = (u32 *)(bytes + 0x3000);
    if ((s32)state[0] < *(u16 *)(bytes + 0x3008) * *(u16 *)(bytes + 0x300a)) {
        if (state[1] == 0) {
            grid->cells[state[0]].visible = 1;
            state[0]++;
            state[1] = 0;
        } else {
            state[1]--;
        }
    }
}

u32 func_ov152_021f62a4(EffectState *state) {
    if (state->frame < 1) {
        state->offset += 0x1000;
        if (state->offset >= 0x10000) {
            state->offset -= 0x10000;
            state->frame++;
        }
    } else if (state->frame == 1) {
        state->offset += 0x1000;
        if (state->offset >= 0x8000) {
            state->offset = 0x8000;
            state->frame++;
        }
    } else {
        state->done = 1;
    }
    return state->done;
}
