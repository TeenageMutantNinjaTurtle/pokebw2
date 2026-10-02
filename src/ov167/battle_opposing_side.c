#include "battle/btl_main.h"

// Public function name from swan.
u8 GetSideFromOpposingMonID(u8 monId) {
    return func_ov167_0219d338(GetSideFromMonID(monId));
}

u8 func_ov167_0219d338(u8 side) {
    return side == 0;
}
