#include "battle/btl_pokeparam.h"

// Function name from swan.
BOOL IsSemiInvulnMove(BattleMon *mon) {
    if (func_ov167_021bb408(mon) != 0x10) {
        return TRUE;
    }
    return FALSE;
}
