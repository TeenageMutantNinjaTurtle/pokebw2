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
// The Pokémon sent to the Dream World, and whether it is there
PartyPkm *func_02009998(DreamWorldSave *dreamWorld);
void func_0200999c(DreamWorldSave *dreamWorld, PartyPkm *pkm);
void func_02009a00(DreamWorldSave *dreamWorld, u8 asleep);
// The date of the last Game Sync, packed as year, month, day and weekday from the top byte down
u32 func_02009ad0(DreamWorldSave *dreamWorld);
void func_02009ad4(DreamWorldSave *dreamWorld, u32 date);
// The ID of the last result taken from the Dream World
u32 func_02009ad8(DreamWorldSave *dreamWorld);
void func_02009adc(DreamWorldSave *dreamWorld, u32 id);
// The bytes at 0x1a4, from the Dream World's result, and at 0x1a5, set once the Game Sync ID was shown
void func_020099d8(DreamWorldSave *dreamWorld, u8 value);
void func_020099e8(DreamWorldSave *dreamWorld, u8 value);
// Sets one of the 20 items sent from the Dream World, and its count
void func_02009a50(DreamWorldSave *dreamWorld, int index, u16 item, u8 count);
// Sets one of the 5 26-byte entries of the Dream World's result
void func_02009ab0(DreamWorldSave *dreamWorld, int index, const void *entry);
// The size of the Dream World save
u32 func_02009930(void);
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
