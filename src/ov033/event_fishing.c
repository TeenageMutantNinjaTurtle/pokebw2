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
#include "field/pdw_postman.h"
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

BOOL CreateSurfPos(void *context, Field *field, VecFx32 *position) {
    VecFx32 targetPosition;
    FieldTerrain terrain;
    VecFx32 actorPosition;
    G3DMapper *mapper;
    FieldPlayer *player;
    FieldActor *actor;
    u8 direction;
    fx32 heightDifference;

    mapper = Field_GetG3DMapper(field);
    player = Field_GetPlayer(field);
    actor = FieldPlayer_GetActor(player);
    direction = GetActorFaceDir(actor);
    FieldPlayer_GetWPosInDir(player, direction, &targetPosition);
    if (Field_GetResolvedControllerTypeID(field) == 1) {
        return FALSE;
    }
    if (FieldG3DMapper_GetTerrain(mapper, &targetPosition, &terrain) == FALSE) {
        return FALSE;
    }
    if (MapTile_IsSurfEdge(GetTileClass(terrain.tileType)) == TRUE) {
        ExpandVecInGridDir(direction, &targetPosition, 1 << 16);
        if (FieldG3DMapper_GetTerrain(mapper, &targetPosition, &terrain) == FALSE) {
            return FALSE;
        }
    }
    if (IsTileSurfWater(GetTileClass(terrain.tileType)) == FALSE) {
        return FALSE;
    }
    CopyActorWPos(actor, &actorPosition);
    heightDifference = actorPosition.y - terrain.height;
    if (heightDifference < 0 || heightDifference >= (5 << 14)) {
        return FALSE;
    }
    if (position != NULL) {
        position->x = targetPosition.x;
        position->y = terrain.height;
        position->z = targetPosition.z;
    }
    return TRUE;
}

GameEvent *EventFieldFishing_Create(Field *field, GameSystem *gsys) {
    GameEvent *event;
    FishingEventWork *work;
    VecFx32 position;
    FieldTerrain terrain;
    u32 flag;

    event = GameEvent_Create(gsys, NULL, EventFieldFishing_Callback, sizeof(FishingEventWork));
    work = GameEvent_GetData(event);
    sys_memset(work, 0, sizeof(FishingEventWork));
    work->gsys = gsys;
    work->field = field;
    work->gameData = GSYS_GetGameData(gsys);
    work->encountSystem = Field_GetEncountSystem(work->field);
    work->records = GameData_GetRecords(work->gameData);
    work->actorSystem = Field_GetActorSystem(work->field);
    work->player = Field_GetPlayer(field);
    work->actor = FieldPlayer_GetActor(work->player);
    work->faceDirection = GetActorFaceDir(work->actor);
    FieldPlayer_GetWPos(work->player, &work->playerPos);
    work->playerExState = FieldPlayer_DeriveExState(work->player);
    if (!CreateSurfPos(work, work->field, &work->fishingPos)) {
        work->noFishing = 1;
    }
    work->gridX = (work->fishingPos.x >> 4) / 4096;
    work->gridZ = (work->fishingPos.y >> 4) / 4096;
    work->gridY = (work->fishingPos.z >> 4) / 4096;
    position = work->playerPos;
    ExpandVecInGridDir(1, &position, 0x10000);
    flag = 1;
    if (FieldG3DMapper_GetTerrain(Field_GetG3DMapper(field), &position, &terrain)) {
        if (GetTileFlags(terrain.tileType) & 0x40) {
            flag = 0;
        }
    }
    work->flag5B = flag;
    work->isPhenomenon = EncountState_CheckSpecialEncountPos(work->encountSystem, &work->gridX) != 0;
    work->battleSetup = BtlSetup_CreateFishing(work->encountSystem);
    DisableAllActorsMovement(work->actorSystem);
    return event;
}

GameEventReturnCode EventFieldFishing_Callback(GameEvent *event, u32 *state, void *data) {
    FishingEventWork *work;
    PokeParty *party;
    PartyPkm *pkm;
    GameEvent *next;
    u32 result;
    u32 species;
    u8 battleMode;

    work = data;
    switch (*state) {
    case 0:
        if (work->noFishing != 0) {
            *state = 8;
            break;
        }
        FieldPlayer_SetSpecialSeq(work->player, 0x200);
        ++*state;
    case 1:
        if (func_ov036_0219a580(work->player) == 1) {
            func_ov012_021670f4(work->actor, 0);
            func_ov012_02167564(work->actor, work->flag5B);
            GFL_SndSEPlay(0x684);
            ++*state;
        }
        break;
    case 2:
        if (func_ov033_021795a4(work, 15) != 0) {
            func_ov033_02179628(work);
            if (work->battleSetup == NULL) {
                *state = 5;
            } else {
                work->timer = GFL_RandomLCAlt(90) + 30;
                ++*state;
            }
        }
        break;
    case 3:
        result = func_ov033_021795bc(work, work->timer);
        if (result == 1) {
            *state = 6;
        } else if (result == 2) {
            func_ov033_021795e8(work);
            ++*state;
        }
        break;
    case 4:
        result = func_ov033_021795bc(work, 30);
        if (result != 0) {
            func_ov033_02179614(work);
            if (result == 1) {
                func_ov033_02179650(work);
                func_ov012_021670f4(work->actor, 3);
                party = BtlSetup_GetParty(work->battleSetup, 1);
                pkm = PokeParty_GetPkm(party, 0);
                species = PokeParty_GetParam(pkm, 5, NULL);
                func_ov012_0216063c(0x1c, species);
                EventScriptCall_Start(event, 0x2796, NULL, NULL, 0x15);
                *state = 10;
            } else if (result == 2) {
                RecordAddOne(work->records, 0x50);
                *state = 7;
            }
        }
        break;
    case 5:
        result = func_ov033_021795bc(work, 120);
        if (result != 2) {
            if (result == 1) {
                *state = 6;
            }
            break;
        }
    case 6:
    case 7:
        func_ov033_02179650(work);
        if (work->battleSetup != NULL) {
            if (work->isPhenomenon == 1) {
                EncountSystem_CancelPhenomenon(work->encountSystem);
            }
            BtlSetup_Free(work->battleSetup);
        }
        func_ov012_021670f4(work->actor, 1);
        EventScriptCall_Start(event, 0x2792 + *state, NULL, NULL, 0x15);
        *state = 8;
        break;
    case 8:
        FieldPlayer_SetSpecialSeq(work->player, 8);
        *state = 9;
    case 9:
        if (func_ov036_0219a580(work->player) != 1) {
            break;
        }
        func_ov012_02167564(work->actor, 0);
        return GAMEEVENT_DONE;
    case 10:
        RecordAddOne(work->records, 8);
        func_02038bc8(13);
        battleMode = work->isPhenomenon == 1 ? 1 : 4;
        next = func_ov011_021686b8(work->gsys, work->field, work->battleSetup, 0, battleMode);
        GameEvent_Replace(event, next);
        return GAMEEVENT_CONTINUE;
    }
    return GAMEEVENT_CONTINUE;
}

u32 func_ov033_021795a4(FishingEventWork *work, u32 value) {
    u32 elapsed;

    elapsed = work->elapsed++;
    if (elapsed < value) {
        return 0;
    }
    work->elapsed = 0;
    return 1;
}

u32 func_ov033_021795bc(FishingEventWork *work, u32 value) {
    u32 elapsed;

    elapsed = work->elapsed++;
    if (elapsed < value) {
        if (GCTX_HIDGetPressedKeys() & PAD_BUTTON_A) {
            work->elapsed = 0;
            return 1;
        }
    } else {
        work->elapsed = 0;
        return 2;
    }
    return 0;
}

void func_ov033_021795e8(FishingEventWork *work) {
    void *effects;

    effects = Field_GetFieldEffects(work->field);
    func_ov012_021670f4(work->actor, 2);
    work->effect2C = func_ov036_021b3f14(effects, work->actor, 0, 1);
    func_ov036_021a5968(work->effect30, 1);
}

void func_ov033_02179614(FishingEventWork *work) {
    if (work->effect2C != NULL) {
        func_ov036_021a3a70(work->effect2C);
        work->effect2C = NULL;
    }
}

void func_ov033_02179628(FishingEventWork *work) {
    void *effects;
    u32 sameHeight;

    effects = Field_GetFieldEffects(work->field);
    sameHeight = 1;
    if (work->fishingPos.y != work->playerPos.y) {
        sameHeight = 0;
    }
    work->effect30 = func_ov036_021a58e0(effects, &work->fishingPos, work->faceDirection, sameHeight);
}

void func_ov033_02179650(FishingEventWork *work) {
    if (work->effect30 != NULL) {
        func_ov036_021a3a70(work->effect30);
        work->effect30 = NULL;
    }
}
