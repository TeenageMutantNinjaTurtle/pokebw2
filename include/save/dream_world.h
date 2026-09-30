#ifndef POKEBW2_SAVE_DREAM_WORLD_H
#define POKEBW2_SAVE_DREAM_WORLD_H

#include "types.h"
#include "struct_decls.h"

BOOL DreamWorldSave_IsPokemonAsleep(DreamWorldSave *dreamWorld);
u8 func_020099f4(DreamWorldSave *dreamWorld);
void SetDreamRadarFlag(DreamRadarSave *save, u32 flag, u32 value);
void func_0200c6f0(HighLinkSave *highLink, u32 a1, u32 a2);

#endif // POKEBW2_SAVE_DREAM_WORLD_H
