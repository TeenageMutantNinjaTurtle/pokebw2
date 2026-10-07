#ifndef POKEBW2_PML_POKE_GRAPHIC_H
#define POKEBW2_PML_POKE_GRAPHIC_H

#include "types.h"
#include "gfl/arc.h"
#include "nnsys/g2d.h"
#include "struct_decls.h"

// The files of Pokémon sprites. Each function takes the archive, as GetPokemonGraphicsARCID gives it, and the
// Pokémon's species, form, sex, whether it is shiny and two values that are not known yet

u32 GetPokemonGraphicsARCID(void);
ArcTool *MakePokeGraArcHandle(HeapID heapId);
u32 func_02033f90(ArcTool *arc, BoxPkm *pkm, u32 a2, u32 a3, HeapID heapId);
u32 func_02033f2c(ArcTool *arc, BoxPkm *pkm, u32 a2, u32 a3, u32 a4, HeapID heapId);
// Loads a Pokémon's front sprite as characters, returning the buffer to free
void *func_02033d50(NNSG2dCharacterData **charData, BoxPkm *pkm, u32 a2, HeapID heapId);
u32 func_02034000(BoxPkm *pkm, u32 a1, u32 a2, u32 a3, HeapID heapId);
void *LoadTPokeData(u32 heapId);
void FreeTPokeData(void *data);
// A sprite's character file, with its frames in one cell
u32 GetPokemonSingleCellCharacterDataNo(u32 arcId, u32 species, u32 form, u32 sex, BOOL rare, u32 a5, u32 a6);
u32 GetPokemonPaletteDataNo(u32 arcId, u32 species, u32 form, u32 sex, BOOL rare, u32 a5, u32 a6);
// Load a Pokémon's palette, its characters (with a Spinda's spots drawn from personality) and its cells with their
// animations as cell actor resources
u32 func_02033e34(ArcTool *arc, u32 species, u32 form, u32 sex, BOOL rare, u32 a5, u32 a6, u32 vramType, u16 offset,
                  HeapID heapId);
u32 func_02033e78(ArcTool *arc, u32 species, u32 form, u32 sex, BOOL rare, u32 a5, u32 a6, u32 personality,
                  u32 vramType, HeapID heapId);
u32 func_02033ef4(u32 species, u32 form, u32 sex, BOOL rare, u32 a4, u32 a5, u32 a6, u32 vramType, HeapID heapId);

#endif // POKEBW2_PML_POKE_GRAPHIC_H
