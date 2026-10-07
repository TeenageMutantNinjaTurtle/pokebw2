#ifndef POKEBW2_SAVE_DREAM_WORLD_H
#define POKEBW2_SAVE_DREAM_WORLD_H

#include "types.h"
#include "struct_decls.h"

BOOL DreamWorldSave_IsPokemonAsleep(DreamWorldSave *dreamWorld);
// Whether a species' bit is set in a list of species flags
BOOL func_020099b4(const u8 *flags, int species);
u8 func_020099f4(DreamWorldSave *dreamWorld);
u8 func_020099e0(DreamWorldSave *dreamWorld);
// The items sent from the Dream World, 20 of them
u16 func_02009a18(DreamWorldSave *dreamWorld, u32 index);
u16 func_02009a38(DreamWorldSave *dreamWorld, u32 index);
// How many items the Dream World sent
s32 func_02009a78(DreamWorldSave *dreamWorld);
void func_02009a6c(DreamWorldSave *dreamWorld, u32 index);
u16 *func_02009a98(DreamWorldSave *dreamWorld, u32 index);
u32 func_02009ae0(DreamWorldSave *dreamWorld);
u32 func_02009b20(DreamWorldSave *dreamWorld);
void func_02009b30(DreamWorldSave *dreamWorld, u32 value);
void func_02009af8(DreamWorldSave *dreamWorld, u32 value);
// The Dream Radar's values in the save: 0 whether it was read, 1 the seed of the data, 2 the Pokémon received
u32 GetDreamRadarFlag(DreamRadarSave *save, u32 flag);
void SetDreamRadarFlag(DreamRadarSave *save, u32 flag, u32 value);
// The data that Pokémon Dream Radar writes to the card, read into a buffer of func_02011510's
void *func_02011510(HeapID heapId);
void func_02011528(void *buffer);
void ReadDreamRadarSaveData(void *buffer);
void *func_02011588(void *buffer);
// Writes the data back to the card
void func_02011544(void);
// Checks the data and decodes its 32 words with the seed. Returns 2 when the data is valid
u32 func_02011400(void *data, u32 seed, u32 *words);
// Marks the data read with a new seed and the Pokémon received
void func_020113c4(void *data, u32 seed, u32 received);
// The Pokémon that a word of the data names, if any: its bit in the Pokémon received, its species, form and sex
BOOL func_020115fc(u32 word);
u32 func_0201167c(u32 word);
void func_02011624(u32 word, u16 *species, u8 *form, u8 *sex);
void func_0200c6f0(HighLinkSave *highLink, PlayTime *playTime, u32 a2);

#endif // POKEBW2_SAVE_DREAM_WORLD_H
