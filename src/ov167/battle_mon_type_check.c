#include "battle/btl_pokeparam.h"

// Function name from swan.
BOOL DoesMonHaveType(BattleMon *mon, u32 type) {
    u8 type1;
    u8 type2;

    if (type != 0x11) {
        splitTypeCore(mon, &type1, &type2);
        if (type1 == type || type2 == type) {
            return TRUE;
        }
    }
    return FALSE;
}
