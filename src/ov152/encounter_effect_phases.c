#include "types.h"
#include "field/encounter_effect.h"
#include "field/field.h"

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
