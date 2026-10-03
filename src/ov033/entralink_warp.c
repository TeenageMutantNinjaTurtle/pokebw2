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

struct EntralinkWarpReturnWork {
    GameSystem *gsys;
    Field *field;
};

struct NPCGridPosition {
    u16 x;
    u16 z;
    s32 y;
};

struct NPCRailPosition {
    u16 railIndex;
    u16 frontPos;
    s16 sidePos;
};

GameEventReturnCode func_ov033_02177370(GameEvent *event, u32 *state, void *data) {
    EntralinkWarpReturnWork *work;
    GameSystem *gsys;
    GameCommSys *comm;
    GameData *gameData;
    Field *field;
    GameEvent *next;

    work = data;
    gsys = work->gsys;
    comm = GSYS_GetGameCommSystem(gsys);
    gameData = GSYS_GetGameData(gsys);
    field = GSYS_GetField(gsys);
    switch (*state) {
    case 0:
        if (func_0202bde0(comm)) {
            break;
        }
        if (GameCommSys_BootCheck(comm)) {
            GameCommSys_ExitReq(comm);
            break;
        }
        next = EventEntralinkWarpIn_Create(gsys, 0x117, (VecFx32 *)&data_ov033_0217c3f4, 0);
        GameEvent_ChainNext(event, next);
        (*state)++;
        break;
    case 1:
        return GAMEEVENT_DONE;
    default:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov033_021773e4(GameSystem *gsys, void *args) {
    GameEvent *event;
    EntralinkWarpReturnWork *work;

    event = GameEvent_Create(gsys, NULL, func_ov033_02177370, sizeof(EntralinkWarpReturnWork));
    work = GameEvent_GetData(event);
    work->gsys = gsys;
    work->field = args;
    return event;
}

BOOL EventEntralinkWarpIn_CheckAllowed(GameSystem *gsys) {
    GameData *gameData;
    EventData *eventData;
    ZoneNPC *npcs;
    Field *field;
    MMSys *actorSystem;
    NPCGridPosition *npcPosition;
    s32 npcCount;
    NPCRailPosition *npcRail;
    FieldPlayer *player;
    u32 zoneId;
    EventWork *eventWork;
    FieldActor *playerActor;
    VecFx32 worldPosition;
    s16 playerX;
    s16 playerY;
    s16 playerZ;
    RailPosition railPosition;
    u8 modelInfo[28];
    s32 i;
    ZoneNPC *npc;

    gameData = GSYS_GetGameData(gsys);
    eventData = GameData_GetEventData(gameData);
    npcs = GetZoneNPCs(eventData);
    npcCount = GetZoneNPCsCount(eventData);
    field = GSYS_GetField(gsys);
    actorSystem = Field_GetActorSystem(field);
    player = Field_GetPlayer(field);
    zoneId = Field_GetPlayerStateZoneID(field);
    if (!GetZoneFlagsEnableEntralinkWarp(zoneId)) {
        return FALSE;
    }
    if ((u32)(FieldPlayer_GetExState(player) - 2) <= 1) {
        return FALSE;
    }
    if (Field_GetResolvedControllerTypeID(field) == 0) {
        playerActor = FieldPlayer_GetActor(player);
        eventWork = GameData_GetEventWork(gameData);
        CopyActorWPos(playerActor, &worldPosition);
        if (FindCollidingZoneTriggerAtLocation(eventData, eventWork, &worldPosition)) {
            return FALSE;
        }
    }
    if ((npcs == NULL || npcCount == 0) && zoneId != 0 && zoneId != 0x1a8) {
        return TRUE;
    }
    for (i = 0; i < npcCount; i++) {
        npc = &npcs[i];
        if (npc->isRail == FALSE) {
            npcPosition = (NPCGridPosition *)&npc->pos.grid;
            GetNPCMdlInfoForOBJCODE(actorSystem, npc->modelId, modelInfo);
            FieldPlayer_GetGPos(player, &playerX, &playerY, &playerZ);
            if (npcPosition->x <= playerX && playerX < npcPosition->x + modelInfo[11] &&
                npcPosition->z - modelInfo[12] < playerZ && playerZ <= npcPosition->z) {
                return FALSE;
            }
        } else if (npc->isRail == TRUE) {
            npcRail = (NPCRailPosition *)&npc->pos.rail;
            if (Field_GetResolvedControllerTypeID(field) == 1) {
                func_ov036_0219ad24(player, &railPosition);
                if (npcRail->railIndex == railPosition.componentId && npcRail->frontPos == railPosition.posFront &&
                    npcRail->sidePos == railPosition.posSide) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}
