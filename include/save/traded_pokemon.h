#ifndef POKEBW2_SAVE_TRADED_POKEMON_H
#define POKEBW2_SAVE_TRADED_POKEMON_H

// The Pokémon traded in game, in save block 0x41 (GetTradedPokemonBlock), 0x20 bytes for each, of ARM9 main

#include "types.h"

// Whether the trade of the index is done
BOOL func_0200efd4(void *block, u32 index);
// The level, from 65 to 100
u8 func_0200efe0(void *block, u32 index);
// Whether it has its own ability, and the ability
BOOL func_0200f000(void *block, u32 index);
u8 func_0200f014(void *block, u32 index);
// The species of the index
u32 func_0200f01c(void *block, u32 index, u32 a2);
u32 func_0200f058(void *block, u32 index);
// Its nickname, as characters
void *func_0200f060(void *block, u32 index);
u32 func_0200f068(void *block, u32 index);

#endif // POKEBW2_SAVE_TRADED_POKEMON_H
