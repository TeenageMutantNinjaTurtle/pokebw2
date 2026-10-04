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

// The parties of the four clients and every BattleMon by mon ID, 0xe8 bytes as the main module holds two
struct BtlPokeCon {
    u32 unk00;
    BattleParty parties[4];
    u8 unk74[0x10];
    BattleMon *mons[24];
    u32 unkE4;
};

struct BtlMainModule {
    BtlSetup *setup;
    u8 unk04[0xc4];
    BtlPokeCon pokeCons[2];
    u8 unk298[0x190];
    u8 posClientIds[6];
    u8 unk42e[0x3a];
    u16 heapId;
    u8 unk46a[2];
    u8 playerClientId;
    u8 unk46d[6];
    u8 unk473_0 : 2;
    u8 unk473_2 : 1;
    u8 unk473_3 : 5;
};

// Swan's names for these two take the main module, whose first field points to the BtlSetup
u32 BtlSetup_GetBattleStyle(BtlMainModule *mainModule);
u32 func_ov167_0219bd88(BtlMainModule *mainModule);
u8 func_ov167_0219bd98(BtlMainModule *mainModule);
u32 BtlSetup_GetBattleType(BtlMainModule *mainModule);
u8 func_ov167_0219bedc(BtlMainModule *mainModule);
u8 func_ov167_0219bee4(BtlMainModule *mainModule);
BOOL func_ov167_0219beec(BtlMainModule *mainModule);
u16 func_ov167_0219bf00(BtlMainModule *mainModule);
u16 func_ov167_0219bf08(BtlMainModule *mainModule);
u16 func_ov167_0219bf14(BtlMainModule *mainModule);
u32 BtlSetup_IsBattleType(BtlMainModule *mainModule, u32 flag);
u8 func_ov167_0219c980(BtlMainModule *mainModule);
void func_ov167_0219c9fc(BtlMainModule *mainModule, u8 value);
void func_ov167_0219ca48(BtlMainModule *mainModule, u32 result);
u32 func_ov167_0219ca58(BtlMainModule *mainModule);
void func_ov167_0219cac0(BtlMainModule *mainModule, u32 money);
void func_ov167_0219cb10(BtlMainModule *mainModule);
void func_ov167_0219dad0(BtlMainModule *mainModule, u32 record);
BOOL func_ov167_0219df10(BtlMainModule *mainModule);
BOOL func_ov167_0219df50(BtlMainModule *mainModule);
u32 func_ov167_0219c988(BtlMainModule *mainModule);
BOOL IsSwitchMode(BtlMainModule *mainModule);
u32 GetValidPosMax(BtlMainModule *mainModule);
u32 func_ov167_0219be8c(BtlMainModule *mainModule);
BOOL func_ov167_0219bebc(BtlMainModule *mainModule, u32 pos);
u32 GetRunMode(BtlMainModule *mainModule);
BtlFieldSituation *GetFieldEffectData(BtlMainModule *mainModule);

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
u8 func_ov167_0219bfe4(BtlMainModule *mainModule, u16 posFlags, u8 *out);
u8 func_ov167_0219c4bc(BtlMainModule *mainModule, u8 pos, u32 index);
u8 func_ov167_0219c5a4(BtlMainModule *mainModule, BtlPokeCon *pokeCon, u16 posFlags, u8 *monIds);
u8 func_ov167_0219c648(u8 monIndex);
u8 func_ov167_0219c658(BtlMainModule *mainModule, u8 pos);
u8 GetPlayerClientID(BtlMainModule *mainModule);
u8 func_ov167_0219c86c(BtlMainModule *mainModule);
u8 func_ov167_0219c87c(BtlMainModule *mainModule, u8 clientId);
BOOL IsAllyClientID(u8 clientId1, u8 clientId2);
u8 func_ov167_0219c8b8(BtlMainModule *mainModule, u8 other);
u32 func_ov167_0219c8d0(BtlMainModule *mainModule, u8 clientId, u8 other);
void BattleClient_SubItem(BtlMainModule *mainModule, u8 clientId, u16 item);
void BattleClient_AddItem(BtlMainModule *mainModule, u8 clientId, u16 item);
void ChangeFriendshipWhenFainted(BtlMainModule *mainModule, BattleMon *mon, BOOL reason);
void ChangeFriendship(BtlMainModule *mainModule, BattleMon *mon, u32 reason);
u8 func_ov167_0219c650(BtlMainModule *mainModule, u8 pos);
BattleMon *func_ov167_0219d188(BtlPokeCon *pokeCon, u8 pos);
BattleMon *GetClientMonData(BtlPokeCon *pokeCon, u8 clientId, u8 monId);
BattleMon *GetPokeParam(BtlPokeCon *pokeCon, u8 monId);
const BattleMon *GetPokeParamConst(const BtlPokeCon *pokeCon, u8 monId);
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

s32 FindPartyMon(const BattleParty *party, BattleMon *mon);
s32 GetPartyPkmnEligibleForBattle(PokeParty *party);
void AddBattleMonToParty(BattleParty *party, BattleMon *mon);
void func_ov167_0219d434(BattleParty *party);
void func_ov167_0219d454(BattleParty *party);
u8 func_ov167_0219d4b8(BattleParty *party, s32 index);
BattleMon *func_ov167_0219d4e4(BattleParty *party, u32 index);
void func_ov167_0219d504(BattleParty *party, u32 first, u32 second);
void func_ov167_0219d518(BattleParty *party, u8 index);
void func_ov167_0219d544(BattleParty *party, u32 pos, BattleMon **oldOut, BattleMon **newOut);
s32 func_ov167_0219d5b0(const BattleParty *party, u32 monId);
BattleMon *func_ov167_0219d5dc(const BattleParty *party);
u32 func_ov167_0219d38c(u32 pos);
u32 func_ov167_0219d3a4(u32 pos);
BattleMon *GetBattleMonFromParty(BattleParty *party, u8 index);
u8 GetNumMonsInParty(BattleParty *party);
u8 GetAlivePartyCount(BattleParty *party);

#endif // POKEBW2_BATTLE_BTL_MAIN_H
