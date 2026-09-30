#ifndef POKEBW2_SAVE_POKEDEX_H
#define POKEBW2_SAVE_POKEDEX_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

BOOL PokeDex_IsNationalObtained(PokeDexSave *pokedex);
BOOL PokeDex_IsCaught(PokeDexSave *pokedex, u16 species);
void PokeDex_RegistPkm(PokeDexSave *pokedex, PartyPkm *pkm);
void addPkmToDex(PokeDexSave *pokedex, PartyPkm *pkm);
// The count of seen Pokémon, in the national Pokédex once the player has it
u32 countSeenDexPokes(PokeDexSave *pokedex, HeapID heapId);

#endif // POKEBW2_SAVE_POKEDEX_H
