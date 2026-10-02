#include "battle/btl_main.h"

// Function names from swan.
BattleParty *GetPartyData(BtlPokeCon *pokeCon, u8 clientId) {
    return &pokeCon->parties[clientId];
}

BattleParty *GetClientParty(BtlPokeCon *pokeCon, u8 clientId) {
    return &pokeCon->parties[clientId];
}
