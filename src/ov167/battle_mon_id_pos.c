#include "battle/btl_main.h"

// Function name from swan.
u8 MonIDToBattlePos(BtlMainModule *mainModule, BtlPokeCon *pokeCon, u8 monId) {
    u8 clientId;
    s32 slot;
    u8 pos;

    clientId = MonIDToClientID(monId);
    slot = func_ov167_0219d140(pokeCon, clientId, monId);
    if (slot >= 0) {
        pos = func_ov167_0219c458(mainModule, clientId, slot);
        if (pos != 6) {
            return pos;
        }
    }
    return 6;
}
