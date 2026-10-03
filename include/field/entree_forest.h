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
typedef struct {
    void *pokemonData;
    Field *field;
    u32 actorIdBase;
} EntreeForestSpawnContext;

BOOL func_ov012_02160974(void *forestState);
BOOL func_ov012_0216099c(void *forestState);
FieldActor *EntreeForest_SpawnPkmActor(EntreeForestSpawnContext *context, const u32 *pokemon, u16 index, u16 x, u16 z,
                                       s32 y);
void EntreeForest_SpawnAllPokemon(Field *field, u32 actorIdBase, const u32 *pokemon, u32 unused, void *forestState);

extern const u8 data_ov033_0217c340[];
extern const u8 data_ov033_0217c398[];
extern const u8 data_ov033_0217c3c0[];

extern const VecFx32 data_ov033_0217c3e8;

#endif // POKEBW2_FIELD_ENTREE_FOREST_H
