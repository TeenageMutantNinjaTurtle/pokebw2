#ifndef POKEBW2_FIELD_FIELD_COMM_ACTOR_H
#define POKEBW2_FIELD_FIELD_COMM_ACTOR_H

// Overlay 36's actors of the other players in a field communication. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

FldCommActSys *FldCommActSys_Create(u8 a0, MMSys *actorSystem, HeapID heapId, u8 a3);
void FldCommActSys_Free(FldCommActSys *sys);
void FldCommActSys_CreateActor(FldCommActSys *sys, u32 netId, u16 a2, const u16 *dir, const VecFx32 *pos,
                               const u32 *a5);
void FldCommActSys_DeleteActor(FldCommActSys *sys, u32 netId);
u32 FldCommActSys_FindActor(FldCommActSys *sys, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

#endif // POKEBW2_FIELD_FIELD_COMM_ACTOR_H
