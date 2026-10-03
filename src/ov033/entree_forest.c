#include "types.h"
#include "field/entree_forest.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/zone.h"
#include "gfl/random.h"
#include "pml/poke_graphic.h"
#include "struct_decls.h"

typedef struct {
    u32 species : 11;
    u32 unknown : 10;
    u32 sex : 2;
    u32 form : 6;
    u32 actorType : 3;
} EntreeForestPokemonActor;

typedef struct {
    u16 moveCode;
    u8 areaW;
    u8 areaH;
} EntreeForestActorAppearance;

typedef struct {
    u16 x;
    u16 z;
    s32 y;
} EntreeForestActorGridPosition;

extern const EntreeForestActorAppearance data_ov033_0217c354[];

extern const ZoneNPC data_ov033_0217c374;

struct EntreeForestPokemon {
    u32 species : 11;
    u32 other : 21;
};

FieldActor *EntreeForest_SpawnPkmActor(EntreeForestSpawnContext *context, const u32 *pokemon, u16 index, u16 x, u16 z,
                                      s32 y) {
    const EntreeForestPokemonActor *mon;
    const EntreeForestActorAppearance *appearance;
    MMSys *actorSystem;
    u16 zoneId;
    ZoneNPC npc;
    EntreeForestActorGridPosition *position;
    u32 actorIdBase;

    mon = (const EntreeForestPokemonActor *)pokemon;
    appearance = &data_ov033_0217c354[mon->actorType];
    actorSystem = Field_GetActorSystem(context->field);
    zoneId = Field_GetPlayerStateZoneID(context->field);
    npc = data_ov033_0217c374;
    npc.uid = index;
    npc.modelId = GetPokemonFieldOBJCODE(context->pokemonData, mon->species, mon->sex, mon->form);
    npc.moveCode = appearance->moveCode;
    actorIdBase = context->actorIdBase;
    npc.areaW = appearance->areaW;
    npc.areaH = appearance->areaH;
    npc.param0 = actorIdBase + index;
    npc.param1 = *pokemon;
    npc.param2 = *pokemon >> 16;
    position = (EntreeForestActorGridPosition *)&npc.pos.grid;
    position->x = x;
    position->z = z;
    position->y = y;
    return CreateNewActorByEntityNoWKOBJCODE(actorSystem, &npc, zoneId);
}

void GetEntreeForestActorParamBits(u32 *paramBits, FieldActor *actor) {
    u32 low = GetActorUserParam(actor, 1);
    u32 high = GetActorUserParam(actor, 2);

    *paramBits = low | (high << 16);
}

u16 GetActorUserParam0(FieldActor *actor) {
    return GetActorUserParam(actor, 0);
}

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
