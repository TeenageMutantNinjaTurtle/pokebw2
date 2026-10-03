#ifndef POKEBW2_FIELD_ENTREE_FOREST_H
#define POKEBW2_FIELD_ENTREE_FOREST_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// Function names from swan.
void GetEntreeForestActorParamBits(u32 *paramBits, FieldActor *actor);
u16 GetActorUserParam0(FieldActor *actor);
void func_ov012_02153608(GameCommSys *commSys);
GameEvent *EventEntreeForestWarp_Create(GameSystem *gsys, u32 mode, const VecFx32 *position, u32 arg3, u32 arg4);
GameEvent *CheckEntralinkForestFirstWarpEvent(Field *field, GameSystem *gsys, FieldPlayer *player);

extern const VecFx32 data_ov033_0217c3e8;

#endif // POKEBW2_FIELD_ENTREE_FOREST_H
