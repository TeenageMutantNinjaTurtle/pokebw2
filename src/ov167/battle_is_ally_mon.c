#include "battle/btl_main.h"

// Function name from swan.
BOOL IsAllyMonID(u8 monId1, u8 monId2) {
    return GetSideFromMonID(monId1) == GetSideFromMonID(monId2);
}
