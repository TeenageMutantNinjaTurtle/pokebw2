#include "battle/btl_ability.h"

// Function names from swan.
BOOL HandlerDampSkipCheck(void *a, void *b, u32 c, void *d, u16 move) {
    if (c == 4) {
        if (move == 0x6a) {
            return TRUE;
        }
    }
    return FALSE;
}
