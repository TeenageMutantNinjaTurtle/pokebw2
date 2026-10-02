#include "battle/btl_main.h"

// Layout reconstructed from the party accessors in the game code.
struct BattleParty {
    u8 unk00[0x1c];
};

struct BtlPokeCon {
    u32 unk00;
    BattleParty parties[6];
};

// Function names from swan.
BattleParty *GetPartyData(BtlPokeCon *pokeCon, u8 clientId) {
    return &pokeCon->parties[clientId];
}

BattleParty *GetClientParty(BtlPokeCon *pokeCon, u8 clientId) {
    return &pokeCon->parties[clientId];
}
