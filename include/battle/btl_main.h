#ifndef POKEBW2_BATTLE_BTL_MAIN_H
#define POKEBW2_BATTLE_BTL_MAIN_H

#include "types.h"
#include "constants/battle.h"
#include "struct_decls.h"

// The battle positions, 0 to 5. Even positions are on one side and odd positions on the other
#define BTL_POS_MAX 6

struct BtlMainModule {
    BtlSetup *setup;
    u8 unk04[0x424];
    u8 posClientIds[6];
    u8 unk42e[0x3a];
    u16 heapId;
    u8 unk46a[2];
    u8 playerClientId;
};

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
u32 BtlSetup_IsBattleType(BtlMainModule *mainModule, u32 flag);
u8 func_ov167_0219bee4(BtlMainModule *mainModule);
u32 func_ov167_0219c988(BtlMainModule *mainModule);
BOOL IsSwitchMode(BtlMainModule *mainModule);
u32 GetValidPosMax(BtlMainModule *mainModule);
u32 GetRunMode(BtlMainModule *mainModule);
void *GetFieldEffectData(BtlMainModule *mainModule);

// The position at index on the same side as pos
u8 GetPosOnSameSide(u8 pos, u8 index);
BOOL DoesClientExist(BtlMainModule *mainModule, u8 clientId);
u8 GetClientSide(BtlMainModule *mainModule, u8 clientId);
BOOL AreClientsOnOppositeSides(BtlMainModule *mainModule, u8 clientId1, u8 clientId2);
u8 BattlePosToClientID(BtlMainModule *mainModule, u8 pos);
// First four bytes are the starting mon ID for each client.
extern const u8 data_ov167_021d6c24[4];
u8 MonIDToClientID(u8 monId);
u8 func_ov167_0219c458(BtlMainModule *mainModule, u8 clientId, u8 slot);
s32 func_ov167_0219d140(BtlPokeCon *pokeCon, u8 clientId, u8 monId);
u8 MonIDToBattlePos(BtlMainModule *mainModule, BtlPokeCon *pokeCon, u8 monId);
u8 func_ov167_0219c648(u8 monIndex);
u8 func_ov167_0219c658(BtlMainModule *mainModule, u8 pos);
u8 GetPlayerClientID(BtlMainModule *mainModule);
BOOL IsAllyClientID(u8 clientId1, u8 clientId2);
void BattleClient_SubItem(BtlMainModule *mainModule, u8 clientId, u16 item);
void BattleClient_AddItem(BtlMainModule *mainModule, u8 clientId, u16 item);
void ChangeFriendshipWhenFainted(BtlMainModule *mainModule, BattleMon *mon, BOOL reason);
void ChangeFriendship(BtlMainModule *mainModule, BattleMon *mon, u32 reason);
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
BOOL IsAllyMonID(u8 monId1, u8 monId2);
u8 GetSideFromMonID(u8 monId);
u8 GetSideFromOpposingMonID(u8 monId);
u8 func_ov167_0219d338(u8 side);
// Returns the opponent-position lookup entry for a battle position.
const void *func_ov167_0219d2bc(u8 pos);
// Whether pos2 is an opponent next to pos1 in a triple battle
BOOL IsAdjacentOpponent(u8 pos1, u8 pos2);
BattleParty *GetClientParty(BtlPokeCon *pokeCon, u8 clientId);
BattleParty *GetPartyData(BtlPokeCon *pokeCon, u8 clientId);

s32 FindPartyMon(BattleParty *party, BattleMon *mon);
s32 GetPartyPkmnEligibleForBattle(PokeParty *party);
void AddBattleMonToParty(BattleParty *party, BattleMon *mon);
void func_ov167_0219d454(BattleParty *party);
u8 func_ov167_0219d4b8(BattleParty *party, s32 index);
BattleMon *func_ov167_0219d4e4(BattleParty *party, u32 index);
void func_ov167_0219d518(BattleParty *party, u8 index);
BattleMon *GetBattleMonFromParty(BattleParty *party, u8 index);
u8 GetNumMonsInParty(BattleParty *party);
u8 GetAlivePartyCount(BattleParty *party);

#endif // POKEBW2_BATTLE_BTL_MAIN_H
