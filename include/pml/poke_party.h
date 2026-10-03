#ifndef POKEBW2_PML_POKE_PARTY_H
#define POKEBW2_PML_POKE_PARTY_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "nitro/rtc.h"
#include "struct_decls.h"

PokeParty *PokeParty_Create(HeapID heapId);
u32 PML_GenPID(u32 seed, u16 species, u16 form, u32 sex, u32 ability, u32 a5);
void PokeParty_CreatePkm(PartyPkm *pkm, u16 species, u16 level, u32 a3, u32 a4, s32 a5, u32 pid, u32 a7);
void PokeParty_SetHiddenAbil(PartyPkm *pkm, u32 species, u32 form);
void FriendshipManagerCalc(PartyPkm *pkm, u32 reason, u16 zoneId, u16 heapId);
// Read and write a field of a Pokémon, PKM_PARAM_*. Fields that are not numbers go through the buffer
// A field of a Pokémon, PKM_PARAM_*. The functions take it as an enum, swan's PkmField, and MWCC doesn't share a sum
// that makes one between two calls, as it would an integer
typedef enum {
    PKM_PARAM_COUNT = 0xb4,
} PkmField;

u32 PokeParty_GetParam(PartyPkm *pkm, PkmField param, void *buffer);
// A field that is not a number takes a pointer to its value
void PokeParty_SetParam(PartyPkm *pkm, PkmField param, u32 value);
u32 PokeParty_GetSex(PartyPkm *pkm);
BOOL PokeParty_IsRare(PartyPkm *pkm);
// Decrypt a Pokémon for a series of reads and writes, and return whether it was encrypted, which is what the
// encryption afterwards takes
BOOL PokeParty_DecryptPkm(PartyPkm *pkm);
void PokeParty_EncryptPkm(PartyPkm *pkm, BOOL wasEncrypted);
u32 PML_PkmGetParam(BoxPkm *pkm, u32 param, void *buffer);
BOOL PML_PkmDecrypt(BoxPkm *pkm);
void PML_PkmReEncrypt(BoxPkm *pkm, BOOL wasEncrypted);
BOOL PML_PkmIsRare(BoxPkm *pkm);
// The size of a Pokémon's data
u32 PokeParty_GetPkmRawSize(void);
void copyPartyPkm(const PartyPkm *src, PartyPkm *dest);
void copyPkmIntoPartyBlk(PokeParty *party, u32 index, const PartyPkm *pkm);
// Changes a Pokémon into another species, as evolution does
void setChangedPkmSpecies(PartyPkm *pkm, u32 species);
// Hatches an egg, recording where and by whom
void hatchEgg(PartyPkm *pkm, PlayerInfo *playerInfo, u16 placeName, HeapID heapId);
void PokeParty_Init(PokeParty *party);
void PokeParty_Copy(const PokeParty *src, PokeParty *dest);
void PokeParty_InitCore(PokeParty *party, u32 capacity);
// Records how and where the Pokémon was met, with the player as its Trainer
void PokeParty_SetupMetData(PartyPkm *pkm, u32 a1, PlayerInfo *playerInfo, u16 placeName, HeapID heapId);
void PokeParty_ClearPkm(PartyPkm *pkm);
// Restores a Pokémon's HP and PP and cures its status
void PokeParty_Recover(PartyPkm *pkm);
void PokeParty_RecalcStats(PartyPkm *pkm);
void setLevel(PartyPkm *pkm, u32 level);
void setPkmBattleData(PartyPkm *pkm, u32 param, u32 value);
// A species with its form and sex in one u16
u16 func_02021204(u32 species, u32 form, u32 sex);
// The level, 0 to 4, of a Pokémon's Pokéstar fame
int func_0201f010(u8 fame);
PartyPkm *PokeParty_GetPkm(PokeParty *party, u32 index);
int PokeParty_GetPkmCount(PokeParty *party);
u32 PokeParty_GetFirstBattleReady(PokeParty *party);
u32 isEggInParty(PokeParty *party);
int howManyPartyPokesAreNotEggs(PokeParty *party);
int PokeParty_GetCapacity(PokeParty *party);
BOOL PokeParty_AddPkm(PokeParty *party, PartyPkm *pkm);
void PokeParty_RemovePkm(PokeParty *party, u32 index);
void PokeParty_RecoverAll(PokeParty *party);
void PokeParty_SetMove(PartyPkm *pkm, u32 move, u32 slot);
// The next move that a Pokémon learns at its level, going on from *index: 0 once there are none left, 0xfffe for one
// it already knows, and the move with 0x8000 set when it has no free slot for it
u16 func_0201d358(PartyPkm *pkm, u32 *index, HeapID heapId);
// Allocates a Pokémon that is not in a party. What the 64-bit argument sets is not known yet; 0 is one of the values
// that PML_CreatePkm treats specially
PartyPkm *PokeParty_NewTempPkm(u16 species, u16 level, u64 a2, HeapID heapId);
// The species names, which stay loaded
extern MsgData *g_PMLSpeciesNamesResident;

void TransformVsPokePartyBySeason(GameData *gameData, PokeParty *party, u8 season);
BOOL func_ov012_021643f0(GameData *gameData, PokeParty *party, RTCTime *time, u8 season);
u32 func_ov012_02164428(GameData *gameData, PokeParty *party);

#endif // POKEBW2_PML_POKE_PARTY_H
