#ifndef POKEBW2_APP_MUSICAL_STA_ACT_POKE_H
#define POKEBW2_APP_MUSICAL_STA_ACT_POKE_H

// Overlay 209's sta_act_poke.c: the Pokémon on the stage
// Declared for their callers before the file is decompiled, with the types and names read off the calls

#include "types.h"
#include "gfl/blact.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

StaActPokeSys *func_ov209_021bd8f0(HeapID heapId, StaActing *stage, MusPokeDrawSys *pokeDraw, MusItemDrawSys *itemDraw,
                                   BlActScene *blact);
void func_ov209_021bd974(StaActPokeSys *sys);
void func_ov209_021bd9b4(StaActPokeSys *sys);
void func_ov209_021bd9e0(StaActPokeSys *sys);
void func_ov209_021bddf4(StaActPokeSys *sys);
void func_ov209_021bde30(StaActPokeSys *sys, u32 a1);
StaActPoke *func_ov209_021bde60(StaActPokeSys *sys, MusicalPoke *poke);
void func_ov209_021be8a8(StaActPokeSys *sys, StaActPoke *poke, const VecFx32 *pos);
void func_ov209_021be8d8(StaActPokeSys *sys, StaActPoke *poke, const VecFx32 *ofs);
void func_ov209_021be904(StaActPokeSys *sys, StaActPoke *poke);
void func_ov209_021be898(StaActPokeSys *sys, StaActPoke *poke, VecFx32 *pos);
void func_ov209_021be9a8(StaActPokeSys *sys, StaActPoke *poke, BOOL a2);

#endif // POKEBW2_APP_MUSICAL_STA_ACT_POKE_H
