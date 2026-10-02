#include "battle/btl_main.h"

// Function names from swan.
BattleMon *GetClientMonData(BtlPokeCon *pokeCon, u8 clientId, u8 monId) {
    return GetBattleMonFromParty(&pokeCon->parties[clientId], monId);
}

void *GetPokeParam(void *params, u8 index) {
    return *(void **)((u8 *)params + 0x84 + index * 4);
}

const void *GetPokeParamConst(const void *params, u8 index) {
    return *(const void *const *)((const u8 *)params + 0x84 + index * 4);
}
