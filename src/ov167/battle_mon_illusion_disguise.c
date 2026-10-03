#include "battle/btl_pokeparam.h"

// Function names from swan.
PartyPkm *GetSrcData(const void *mon) {
    return *(PartyPkm **)mon;
}

void SetIllusionDisguise(BattleMon *mon, void *disguise) {
    u8 *data;

    data = (u8 *)mon;
    *(void **)(data + 4) = disguise;
    data[0x1b] |= 0x40;
}

void func_ov167_021bb054(BattleMon *mon) {
    u8 flags;

    flags = ((u8 *)mon)[0x1b];
    *(void **)((u8 *)mon + 4) = NULL;
    ((u8 *)mon)[0x1b] = flags & ~0x40;
}

void *func_ov167_021bb064(BattleMon *mon) {
    void *disguise;

    disguise = *(void **)((u8 *)mon + 4);
    if (disguise != NULL && ((((u32)((u8 *)mon)[0x1b] << 25) >> 31) != 0)) {
        return disguise;
    }
    return *(void **)mon;
}
