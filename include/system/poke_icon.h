#ifndef POKEBW2_SYSTEM_POKE_ICON_H
#define POKEBW2_SYSTEM_POKE_ICON_H

#include "types.h"
#include "struct_decls.h"

// The Pokémon icons, in archive 7. The ROM doesn't name the file that holds these

// The file of a Pokémon's icon, the female one if gender is 1 and the species has one
u32 PokeParty_GetIconIndex(u32 species, u32 form, u32 gender, BOOL egg);
// The palette of a Pokémon's icon
u32 func_02021034(u32 species, u32 form, u32 gender, BOOL egg);
// The file and palette of a Pokémon's icon
u32 func_02020f40(BoxPkm *pkm);
u32 func_020210c0(BoxPkm *pkm);
// The icons' palettes, cells and cell animations, by the main engine's OBJ mapping mode
u32 func_02021114(void);
u32 func_0202111c(void);
u32 getOBJTileMapping_MainEng(void);

#endif // POKEBW2_SYSTEM_POKE_ICON_H
