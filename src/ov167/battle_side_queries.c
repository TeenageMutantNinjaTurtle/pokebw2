#include "battle/btl_main.h"

// Function names from swan.

// Public function name from swan.
u8 GetSideFromOpposingMonID(u8 monId) {
    return func_ov167_0219d338(GetSideFromMonID(monId));
}

u8 func_ov167_0219d338(u8 side) {
    return side == 0;
}

// Layout reconstructed from the opponent-position lookup in the game code.
struct AdjacentOpponentData {
    u16 count1;
    u16 count2;
    u8 list1[3];
    u8 list2[3];
};

// Function name from swan.
BOOL IsAdjacentOpponent(u8 pos1, u8 pos2) {
    const struct AdjacentOpponentData *data;
    u32 i;

    data = func_ov167_0219d2bc(pos1);
    for (i = 0; i < data->count1; i++) {
        if (pos2 == data->list1[i]) {
            return TRUE;
        }
    }
    for (i = 0; i < data->count2; i++) {
        if (pos2 == data->list2[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
