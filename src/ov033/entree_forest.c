#include "types.h"
#include "app/funfest_mission.h"
#include "app/name_entry.h"
#include "battle/btl_setup.h"
#include "demo/shinka_demo.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "field/encounter.h"
#include "field/encounter_effect.h"
#include "field/entree_forest.h"
#include "field/entree_scripts.h"
#include "field/event_abyssal_ruins.h"
#include "field/event_cgear_shutdown.h"
#include "field/event_chatot.h"
#include "field/event_dendou_machine.h"
#include "field/event_dive.h"
#include "field/event_field_trade.h"
#include "field/event_fishing.h"
#include "field/event_fly.h"
#include "field/event_funfest_mission.h"
#include "field/event_game_manual.h"
#include "field/event_mapchange.h"
#include "field/event_phrase_input.h"
#include "field/event_pokemon_center.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wild_battle.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_actor_animation.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_event.h"
#include "field/field_fog.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_money_window.h"
#include "field/field_move_scripts.h"
#include "field/field_move_tcb.h"
#include "field/field_party.h"
#include "field/field_player.h"
#include "field/field_prop.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_surf.h"
#include "field/field_task.h"
#include "field/field_visuals.h"
#include "field/fld_trade.h"
#include "field/funfest_scripts.h"
#include "field/mystery_gift_delivery.h"
#include "field/mystery_gift_script.h"
#include "field/ov131.h"
#include "field/pc_sound.h"
#include "field/player_state.h"
#include "field/subscreen.h"
#include "field/trial_house.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/bmpwin.h"
#include "gfl/fade.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "pml/evolution.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "save/chatter.h"
#include "save/dream_world.h"
#include "save/high_link.h"
#include "save/join_avenue.h"
#include "save/mystery_gift.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/records.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "save/trial_house.h"
#include "struct_decls.h"
#include "system/aeabi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"
#include "system/vm.h"

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

extern u16 GetPokemonFieldOBJCODE(void *pokemonData, u16 species, u16 sex, u16 form);

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
