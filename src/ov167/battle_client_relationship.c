#include "battle/btl_main.h"

// Function name from swan.
u8 GetPlayerClientID(BtlMainModule *mainModule) {
    return mainModule->playerClientId;
}

u8 func_ov167_0219c86c(BtlMainModule *mainModule) {
    return func_ov167_0219c87c(mainModule, mainModule->playerClientId);
}

u8 func_ov167_0219c87c(BtlMainModule *mainModule, u8 clientId) {
    u8 allyId = (clientId + 2) & 3;

    if (!DoesClientExist(mainModule, allyId)) {
        allyId = 4;
    }
    return allyId;
}

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

u8 func_ov167_0219c8b8(BtlMainModule *mainModule, u8 other) {
    return func_ov167_0219c8d0(mainModule, mainModule->playerClientId, other);
}

u32 func_ov167_0219c8d0(BtlMainModule *mainModule, u8 clientId, u8 other) {
    u8 oppositeSide = clientId;
    oppositeSide &= 1;
    oppositeSide ^= 1;

    if (other != 0) {
        u8 candidate = oppositeSide + ((other & 1) << 1);
        if (DoesClientExist(mainModule, candidate)) {
            oppositeSide = candidate;
        }
    }
    return oppositeSide;
}
