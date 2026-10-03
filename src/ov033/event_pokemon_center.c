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

GameEvent *EventPokeCenHeal_Create(GameSystem *gsys, GameEvent *parent, u8 ballCount) {
    GameEvent *event;

    event = GameEvent_Create(gsys, parent, EventPokeCenHeal_Callback, sizeof(EventPokeCenHealData));
    EventPokeCenHeal_Init(GameEvent_GetData(event), gsys, ballCount);
    return event;
}

GameEventReturnCode EventPokeCenHeal_Callback(GameEvent *event, u32 *state, void *data) {
    EventPokeCenHealData *work;

    work = data;
    switch (*state) {
    case 0:
        if (work->frameCounter % 15 == 0) {
            EventPokeCenHeal_SpawnMonsBall(work);
            if (work->ballCount <= work->animationCount) {
                EventPokeCenHeal_ChangeState(work, state, 1);
            }
        }
        break;
    case 1:
        if (work->frameCounter > 10) {
            EventPokeCenHeal_StartAnimations(work);
            GameEvent_ChainNext(event, EventMEPlay_Create(Field_GetGameSystem(work->field), 0x514));
            EventPokeCenHeal_ChangeState(work, state, 2);
        }
        break;
    case 2:
        if (EventPokeCenHeal_IsAnimationDone(work)) {
            EventPokeCenHeal_PauseAnimation(work);
            EventPokeCenHeal_ChangeState(work, state, 3);
        }
        break;
    case 3:
        GameEvent_ChainNext(event, EventPushBGMFinish_Create(Field_GetGameSystem(work->field), 0, 6));
        EventPokeCenHeal_ChangeState(work, state, 4);
        break;
    case 4:
        EventPokeCenHeal_End(work);
        return GAMEEVENT_DONE;
    }
    work->frameCounter++;
    return GAMEEVENT_CONTINUE;
}

void EventPokeCenHeal_Init(EventPokeCenHealData *work, GameSystem *gsys, u8 ballCount) {
    u32 count;
    VecFx32 playerPosition;
    FieldPropAreaBounds bounds;
    Field *field;
    u16 heapId;
    G3DMapper *mapper;
    FieldChunkPropHolder **props;

    field = GSYS_GetField(gsys);
    heapId = Field_GetHeapID(field);
    mapper = Field_GetG3DMapper(field);
    work->heapId = heapId;
    work->ballCount = ballCount;
    work->field = field;
    work->animationCount = 0;
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
    props = FieldPropSystem_FindPropsInArea(work->propSystem, &bounds, 3, &count);
    if (props != NULL) {
        work->centerProp = props[0];
        FieldChunkPropHolder_GetPosAbs(props[0], &work->basePosition);
    }
    GFL_HeapFree(props);
}

void EventPokeCenHeal_End(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->ballCount; i++) {
        FieldPropHandle_Free(work->ballHandles[i]);
    }
}

void EventPokeCenHeal_ChangeState(EventPokeCenHealData *work, u32 *state, u32 newState) {
    *state = newState;
    work->frameCounter = 0;
}

void EventPokeCenHeal_SpawnMonsBall(EventPokeCenHealData *work) {
    FieldPropTransform transform;
    u8 index;

    index = work->animationCount;
    if (work->ballCount > index) {
        VEC_Set(&transform.scale, FX32_ONE, FX32_ONE, FX32_ONE);
        MAT3_RotationEulerZYX(0, 0, 0, &transform.rotation);
        VEC_Add(&work->basePosition, &POKECEN_HEAL_MONSBALL_POSITIONS[index], &transform.position);
        work->ballHandles[index] = FieldPropSystem_CreateHandleNew(work->propSystem, 0x62, &transform);
        work->animationCount++;
        GFL_SndSEPlay(0x568);
    }
}

void EventPokeCenHeal_StartAnimations(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->animationCount; i++) {
        FieldPropHandle_CallAnmCmd(work->ballHandles[i], 0, 0);
    }
    if (work->centerProp != NULL) {
        FieldChunkPropHolder_CallAnmCmd(work->propSystem, work->centerProp, 0, 0);
    }
}

void EventPokeCenHeal_PauseAnimation(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->animationCount; i++) {
        FieldPropHandle_CallAnmCmd(work->ballHandles[i], 0, 3);
    }
}

BOOL EventPokeCenHeal_IsAnimationDone(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->animationCount; i++) {
        if (FieldPropHandle_IsAnmIdle(work->ballHandles[i], 0) != TRUE) {
            return FALSE;
        }
    }
    return TRUE;
}
