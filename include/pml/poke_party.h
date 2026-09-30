#ifndef POKEBW2_PML_POKE_PARTY_H
#define POKEBW2_PML_POKE_PARTY_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/rtc.h"
#include "struct_decls.h"

PokeParty *PokeParty_Create(HeapID heapId);
// Read and write a field of a Pokémon, PKM_PARAM_*. Fields that are not numbers go through the buffer
u32 PokeParty_GetParam(PartyPkm *pkm, u32 param, void *buffer);
void PokeParty_SetParam(PartyPkm *pkm, u32 param, const void *value);
// Hatches an egg, recording where and by whom
void hatchEgg(PartyPkm *pkm, PlayerInfo *playerInfo, u16 placeName, HeapID heapId);
void PokeParty_Init(PokeParty *party);
// Allocates a Pokémon that is not in a party. What the 64-bit argument sets is not known yet; 0 is one of the values
// that PML_CreatePkm treats specially
PartyPkm *PokeParty_NewTempPkm(u16 species, u16 level, u64 a2, HeapID heapId);
void TransformVsPokePartyBySeason(GameData *gameData, PokeParty *party, u8 season);
BOOL func_ov012_021643f0(GameData *gameData, PokeParty *party, RTCTime *time, u8 season);
u32 func_ov012_02164428(GameData *gameData, PokeParty *party);

#endif // POKEBW2_PML_POKE_PARTY_H
