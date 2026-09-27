#ifndef POKEBW2_PML_POKE_PARTY_H
#define POKEBW2_PML_POKE_PARTY_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

PokeParty *PokeParty_Create(HeapID heapId);
void PokeParty_Init(PokeParty *party);
void TransformVsPokePartyBySeason(GameData *gameData, void *party, u8 season);
void func_ov012_021643f0(GameData *gameData, void *party, void *hour, u8 season);
u32 func_ov012_02164428(GameData *gameData, void *party);

#endif // POKEBW2_PML_POKE_PARTY_H
