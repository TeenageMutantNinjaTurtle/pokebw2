#include "battle/btl_main.h"

// Function names from swan.
BOOL DoesClientExist(BtlMainModule *mainModule, u8 clientId) {
    u32 i;

    if (clientId < 4) {
        for (i = 0; i < 6; i++) {
            if (mainModule->posClientIds[i] == clientId) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

u8 GetClientSide(BtlMainModule *mainModule, u8 clientId) {
    return clientId & 1;
}
