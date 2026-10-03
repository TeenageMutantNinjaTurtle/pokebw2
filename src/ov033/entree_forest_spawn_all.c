#include "field/entree_forest.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "gfl/random.h"
#include "pml/poke_graphic.h"
#include "struct_decls.h"

struct EntreeForestPokemon {
    u32 species : 11;
    u32 other : 21;
};

void EntreeForest_SpawnAllPokemon(Field *field, u32 actorIdBase, const u32 *pokemon, u32 unused, void *forestState) {
    const u8 *positions;
    EntreeForestSpawnContext context;
    FieldActor *playerActor;
    u16 playerX;
    u16 playerZ;
    s32 i;
    s32 offsetX;
    s32 offsetZ;
    s32 x;
    s32 z;

    if (func_ov012_02160974(forestState)) {
        positions = data_ov033_0217c3c0;
    } else if (func_ov012_0216099c(forestState)) {
        positions = data_ov033_0217c340;
    } else {
        positions = data_ov033_0217c398;
    }
    context.pokemonData = LoadTPokeData(Field_GetHeapID(field));
    context.field = field;
    context.actorIdBase = actorIdBase;
    playerActor = FieldPlayer_GetActor(Field_GetPlayer(field));
    playerX = GetGPosX(playerActor);
    playerZ = GetGPosZ(playerActor);
    for (i = 0; i < 20; i++) {
        if (((const EntreeForestPokemon *)pokemon)[i].species != 0) {
            offsetX = GFL_RandomLCAlt(2) - 1;
            offsetZ = GFL_RandomLCAlt(2) - 1;
            x = positions[i * 2] + offsetX;
            z = positions[i * 2 + 1] + offsetZ;
            if (playerX == x && playerZ == z) {
                if (offsetX != 0) {
                    x -= offsetX;
                } else if (offsetZ != 0) {
                    z -= offsetZ;
                } else {
                    x++;
                }
            }
            EntreeForest_SpawnPkmActor(&context, &pokemon[i], i, x, z, 0);
        }
    }
    FreeTPokeData(context.pokemonData);
}
