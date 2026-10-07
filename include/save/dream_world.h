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
void SetDreamRadarFlag(DreamRadarSave *save, u32 flag, u32 value);
void func_0200c6f0(HighLinkSave *highLink, PlayTime *playTime, u32 a2);

#endif // POKEBW2_SAVE_DREAM_WORLD_H
