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

GameEvent *EventDendouMachine_Create(GameSystem *gsys, GameEvent *parent) {
    GameEvent *event;

    event = GameEvent_Create(gsys, parent, EventDendouMachine_Callback, sizeof(EventDendouMachineData));
    EventDendouMachine_Init(GameEvent_GetData(event), gsys);
    return event;
}

GameEventReturnCode EventDendouMachine_Callback(GameEvent *event, u32 *state, void *data) {
    EventDendouMachineData *work;

    work = data;
    switch (*state) {
    case 0:
        if (work->frameCounter % 20 == 0) {
            EventDendouMachine_SpawnMonsBall(work);
            if (work->ballCount <= work->spawnedCount) {
                (*state)++;
                work->frameCounter = 0;
            }
        }
        break;
    case 1:
        if (work->frameCounter > 10) {
            EventDendouMachine_StartAnimations(work);
            (*state)++;
            work->frameCounter = 0;
        }
        break;
    case 2:
        if (EventDendouMachine_IsAnimationDone(work)) {
            (*state)++;
        }
        break;
    case 3:
        EventDendouMachine_End(work);
        return GAMEEVENT_DONE;
    }
    work->frameCounter++;
    return GAMEEVENT_CONTINUE;
}

void EventDendouMachine_Init(EventDendouMachineData *work, GameSystem *gsys) {
    u32 count;
    VecFx32 playerPosition;
    FieldPropAreaBounds bounds;
    Field *field;
    G3DMapper *mapper;
    u16 heapId;
    FieldChunkPropHolder **props;

    field = GSYS_GetField(gsys);
    mapper = Field_GetG3DMapper(field);
    heapId = Field_GetHeapID(field);
    work->heapId = heapId;
    work->field = field;
    work->ballCount = countNonEggsInParty(gsys);
    work->spawnedCount = 0;
    work->propSystem = FieldG3DMapper_GetBMSystem(mapper);
    work->centerProp = NULL;
    if (work->ballCount > 6) {
        work->ballCount = 6;
    }
    FieldPlayer_GetWPos(Field_GetPlayer(work->field), &playerPosition);
    bounds.minZ = playerPosition.z - (5 << 16);
    bounds.maxZ = playerPosition.z + (5 << 16);
    bounds.minX = playerPosition.x - (5 << 16);
    bounds.maxX = playerPosition.x + (5 << 16);
    props = FieldPropSystem_FindPropsInArea(work->propSystem, &bounds, 8, &count);
    if (props != NULL) {
        work->centerProp = props[0];
        FieldChunkPropHolder_GetPosAbs(props[0], &work->basePosition);
    }
    GFL_HeapFree(props);
    if (work->centerProp != NULL) {
        work->centerHandle = FieldPropSystem_CreateHandleFromExisting(work->propSystem, work->centerProp);
    }
}

void EventDendouMachine_End(EventDendouMachineData *work) {
    if (work->centerProp != NULL) {
        FieldPropHandle_Free(work->centerHandle);
    }
}

void EventDendouMachine_SpawnMonsBall(EventDendouMachineData *work) {
    SRTMatrix transform;
    u8 index;

    index = work->spawnedCount;
    if (work->ballCount > index) {
        VEC_Set(&transform.scale, FX32_ONE, FX32_ONE, FX32_ONE);
        MAT3_RotationEulerZYX(0, 0, 0, &transform.rotation);
        VEC_Add(&work->basePosition, &data_ov033_0217c490[index], &transform.translation);
        work->ballHandles[index] = FieldPropSystem_CreateHandleNew(work->propSystem, 0x62, &transform);
        work->spawnedCount++;
        GFL_SndSEPlay(0x568);
    }
}

void EventDendouMachine_StartAnimations(EventDendouMachineData *work) {
    s32 i;

    for (i = 0; i < work->spawnedCount; i++) {
        FieldPropHandle_CallAnmCmd(work->ballHandles[i], 0, 2);
    }
    if (work->centerProp != NULL) {
        FieldPropHandle_CallAnmCmd(work->centerHandle, 0, 0);
    }
}

BOOL EventDendouMachine_IsAnimationDone(EventDendouMachineData *work) {
    if (work->centerProp != NULL) {
        return FieldPropHandle_IsAnmFinished(work->centerHandle);
    }
    return TRUE;
}

int countNonEggsInParty(GameSystem *gsys) {
    return howManyPartyPokesAreNotEggs(GameData_GetParty(GSYS_GetGameData(gsys)));
}
