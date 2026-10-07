#ifndef POKEBW2_APP_RESEARCH_RADAR_PALETTE_ANIME_H
#define POKEBW2_APP_RESEARCH_RADAR_PALETTE_ANIME_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Animates colors of a palette in palette RAM, such as the flashing of a selected button (palette_anime.c)
// The names of these functions and types are ours

PaletteAnime *PaletteAnime_Create(HeapID heapId);
void PaletteAnime_Delete(PaletteAnime *anime);
// Animates count colors at dst, from the colors at src, which it copies
void PaletteAnime_Setup(PaletteAnime *anime, u16 *dst, const u16 *src, u8 count);
void PaletteAnime_Update(PaletteAnime *anime);
void PaletteAnime_Start(PaletteAnime *anime, u32 mode, u16 speed);
void PaletteAnime_Stop(PaletteAnime *anime);
// Puts back the colors that were copied
void PaletteAnime_Restore(PaletteAnime *anime);
BOOL PaletteAnime_IsActive(PaletteAnime *anime);

#endif // POKEBW2_APP_RESEARCH_RADAR_PALETTE_ANIME_H
