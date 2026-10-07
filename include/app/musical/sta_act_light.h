#ifndef POKEBW2_APP_MUSICAL_STA_ACT_LIGHT_H
#define POKEBW2_APP_MUSICAL_STA_ACT_LIGHT_H

// Overlay 209's sta_act_light.c: the stage's spotlights
// Declared for their callers before the file is decompiled, with the types and names read off the calls

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

StaActLightSys *func_ov209_021bd42c(HeapID heapId, void *stage);
void func_ov209_021bd4d0(StaActLightSys *sys);
void func_ov209_021bd504(StaActLightSys *sys);
void func_ov209_021bd6c8(StaActLightSys *sys);
StaActLight *func_ov209_021bd6cc(StaActLightSys *sys, u32 type);
void func_ov209_021bd748(StaActLightSys *sys, StaActLight *light, const VecFx32 *pos);

#endif // POKEBW2_APP_MUSICAL_STA_ACT_LIGHT_H
