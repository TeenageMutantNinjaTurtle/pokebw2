#ifndef POKEBW2_PML_POKE_GRAPHIC_H
#define POKEBW2_PML_POKE_GRAPHIC_H

#include "types.h"

// The files of Pokémon sprites. Each function takes the archive, as GetPokemonGraphicsARCID gives it, and the
// Pokémon's species, form, sex, whether it is shiny and two values that are not known yet

u32 GetPokemonGraphicsARCID(void);
void *LoadTPokeData(u32 heapId);
void FreeTPokeData(void *data);
// A sprite's character file, with its frames in one cell
u32 GetPokemonSingleCellCharacterDataNo(u32 arcId, u32 species, u32 form, u32 sex, BOOL rare, u32 a5, u32 a6);
u32 GetPokemonPaletteDataNo(u32 arcId, u32 species, u32 form, u32 sex, BOOL rare, u32 a5, u32 a6);

#endif // POKEBW2_PML_POKE_GRAPHIC_H
