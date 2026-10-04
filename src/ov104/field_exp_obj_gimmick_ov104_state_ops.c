#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "system/gf_font.h"

void func_ov104_021efc6c(FieldExpObjGimmickOv104State *state, FieldExpObjGimmickOv104MessageArg *arg) {
    if (state->capacity > state->count) {
        state->messages[state->count] = func_ov104_021efe88(state, arg, state->count);
        state->count++;
    }
}

void func_ov104_021efc8c(FieldExpObjGimmickOv104State *state) {
    s32 i;

    GFL_FontFree(state->font);
    for (i = 0; i < state->count; i++) {
        func_ov104_021f0080(state->messages[i]);
    }
    GFL_HeapFree(state->messages);
    GFL_HeapFree(state->flags);
    GFL_HeapFree(state);
}

void func_ov104_021efcc4(FieldExpObjGimmickOv104State *state, u32 amount) {
    s32 i;

    for (i = 0; i < state->count; i++) {
        func_ov104_021f00bc(state, state->messages[i], amount);
    }
    state->current += amount;
}

s32 func_ov104_021efcf0(FieldExpObjGimmickOv104State *state) {
    return state->current;
}

u16 func_ov104_021efcf4(FieldExpObjGimmickOv104State *state) {
    return state->heapId;
}

u8 func_ov104_021efcf8(FieldExpObjGimmickOv104State *state) {
    return state->count;
}
