#ifndef POKEBW2_PML_EVOLUTION_H
#define POKEBW2_PML_EVOLUTION_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

u32 CheckEvolveSpecies(PokeParty *party, PartyPkm *pkm, u32 a2, u32 a3, u8 season, u32 *method, HeapID heapId);

#endif // POKEBW2_PML_EVOLUTION_H
