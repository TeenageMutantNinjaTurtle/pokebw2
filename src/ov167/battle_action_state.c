#include "battle/btl_action.h"

struct BtlActionState {
    u32 useItemNo : 10;
    u32 unk10 : 18;
    u32 prevResult : 1;
    u32 result : 1;
    u32 used : 1;
    u32 unk31 : 1;
};

// Function names from swan.
void PopState(BtlActionState *state, u32 value) {
    *(u32 *)state = value;
}

u16 GetUseItemNo(BtlActionState *state) {
    return state->useItemNo;
}

BOOL IsUsed(BtlActionState *state) {
    return state->used;
}

void SetResult(BtlActionState *state, BOOL result) {
    if (result) {
        state->prevResult = 1;
        state->result = 1;
    } else {
        *(u32 *)state &= ~(1u << 28);
    }
    state->used = 1;
}

BOOL GetPrevResult(BtlActionState *state) {
    return state->prevResult;
}
