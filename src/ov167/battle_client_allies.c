#include "battle/btl_main.h"

// Function name from swan.
BOOL IsAllyClientID(u8 clientId1, u8 clientId2) {
    if (clientId1 == clientId2) {
        return TRUE;
    }
    if (clientId1 == (u8)((clientId2 + 2) & 3)) {
        return TRUE;
    }
    return FALSE;
}
