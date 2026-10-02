#ifndef POKEBW2_BATTLE_BTL_MAIN_H
#define POKEBW2_BATTLE_BTL_MAIN_H

#include "types.h"
#include "constants/battle.h"
#include "struct_decls.h"

// The battle positions, 0 to 5. Even positions are on one side and odd positions on the other
#define BTL_POS_MAX 6

// Layout reconstructed from the party accessors in the game code.
struct BattleParty {
    BattleMon *mons[6];
    u8 count;
    u8 unk19[3];
};

struct BtlPokeCon {
    u32 unk00;
    BattleParty parties[6];
};

// Swan's names for these two take the main module, whose first field points to the BtlSetup
u32 BtlSetup_GetBattleStyle(BtlMainModule *mainModule);
u32 BtlSetup_GetBattleType(BtlMainModule *mainModule);

// The position at index on the same side as pos
u8 GetPosOnSameSide(u8 pos, u8 index);
BOOL AreClientsOnOppositeSides(BtlMainModule *mainModule, u8 clientId1, u8 clientId2);
u8 func_ov167_0219c650(BtlMainModule *mainModule, u8 pos);
BattleMon *func_ov167_0219d188(BtlPokeCon *pokeCon, u8 pos);
BattleMon *GetClientMonData(BtlPokeCon *pokeCon, u8 clientId, u8 monId);
void *GetPokeParam(void *params, u8 index);
const void *GetPokeParamConst(const void *params, u8 index);
// Underlying battle-type-dependent count used by GetClientBattlerCount.
s32 func_ov167_0219a180(BtlMainModule *mainModule, u8 clientId);
// How many of the client's Pokemon are in battle at once. They come first in the party, so this is also the index of
// the first Pokemon waiting to switch in
s32 GetClientBattlerCount(BtlMainModule *mainModule, u8 clientId);
// Whether pos2 is an opponent next to pos1 in a triple battle
BOOL IsAdjacentOpponent(u8 pos1, u8 pos2);
BattleParty *GetClientParty(BtlPokeCon *pokeCon, u8 clientId);
BattleParty *GetPartyData(BtlPokeCon *pokeCon, u8 clientId);

s32 FindPartyMon(BattleParty *party, BattleMon *mon);
void AddBattleMonToParty(BattleParty *party, BattleMon *mon);
BattleMon *GetBattleMonFromParty(BattleParty *party, u8 index);
u8 GetNumMonsInParty(BattleParty *party);
u8 GetAlivePartyCount(BattleParty *party);

#endif // POKEBW2_BATTLE_BTL_MAIN_H
