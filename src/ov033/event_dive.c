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

GameEventReturnCode EventDiveIn_Callback(GameEvent *event, u32 *state, void *eventData) {
    DiveEventData *data = eventData;
    FieldTaskManager *taskManager;
    FieldTask *task;
    FieldPlayer *player;
    VecFx32 offset;
    u16 zoneId;

    switch (*state) {
    case 0:
        taskManager = Field_GetTaskManager(data->field);
        offset.x = 0;
        offset.y = -0x40000;
        offset.z = 0;
        task = FieldActorMoveTask_CreatePlayer(data->field, 0x28, &offset);
        FieldTaskManager_AddTask(taskManager, task, 0);
        data->timer = 8;
        (*state)++;
        break;
    case 1:
        if (--data->timer > 0) {
            break;
        }
        GFL_SndSEPlay(0x63c);
        (*state)++;
        break;
    case 2:
        if (GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(0x63c))) {
            break;
        }
        player = Field_GetPlayer(data->field);
        FieldPlayer_GetActor(player);
        FieldPlayer_SetSpecialState(player, 3);
        GetAbyssalRuinsDiveZoneID(data->field, &zoneId);
        GameEvent_ChainNext(event, EventMapChangeDiveIn_Create(data->gsys, zoneId));
        (*state)++;
        break;
    case 3:
        FldAct_SetAcmd(FieldPlayer_GetActor(Field_GetPlayer(data->field)), 8);
        (*state)++;
        break;
    case 4:
        if (func_ov012_02166ecc(FieldPlayer_GetActor(Field_GetPlayer(data->field)))) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode EventDiveOut_Callback(GameEvent *event, u32 *state, void *eventData) {
    DiveEventData *data = eventData;
    FieldTaskManager *taskManager = Field_GetTaskManager(data->field);
    FieldFog *fog;
    FieldTask *accelTask;
    FieldTask *spinTask;

    switch (*state) {
    case 0:
        GFL_SndSEPlay(0x63c);
        data->timer = 0x18;
        if (data->param != 0) {
            fog = Field_GetFog(data->field);
            accelTask = FieldActorSpinTask_CreatePlayerAccel(data->field, 0x14, 3);
            spinTask = FieldActorSpinTask_CreatePlayer(data->field, 0xc, 3);
            FieldTaskManager_AddTask(taskManager, accelTask, 0);
            FieldTaskManager_AddTask(taskManager, spinTask, (u32)accelTask);
            FieldFog_Animate(fog, 0x7f0f, FieldFog_GetDepthShift(fog), 0x1a);
        }
        (*state)++;
        break;
    case 1:
        FieldPlayer_SetSpecialState(Field_GetPlayer(data->field), 2);
        (*state)++;
        break;
    case 2:
        if (--data->timer > 0) {
            break;
        }
        GameEvent_ChainNext(event, EventMapChangeDiveOut_Create(data->gsys));
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventDiveIn_Create(GameSystem *gsys, Field *field) {
    GameEvent *event;
    DiveEventData *data;

    event = GameEvent_Create(gsys, NULL, EventDiveIn_Callback, sizeof(DiveEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->field = field;
    data->param = 0;
    return event;
}

GameEvent *CreateDiveOutEvent(GameSystem *gsys, Field *field, u32 param) {
    GameEvent *event;
    DiveEventData *data;

    event = GameEvent_Create(gsys, NULL, EventDiveOut_Callback, sizeof(DiveEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->field = field;
    data->param = param;
    return event;
}

GameEvent *func_ov033_0217a0f4(GameSystem *gsys, Field *field, u32 direction) {
    GameEvent *event;
    void **data;
    FieldPlayer *player;
    FieldActor *actor;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217a184, sizeof(void *));
    data = GameEvent_GetData(event);
    GFL_OvlLoad(OVERLAY_ID(131));
    player = Field_GetPlayer(field);
    actor = FieldPlayer_GetActor(player);
    FieldPlayer_SetDirection(player, direction);
    *data = func_ov131_021eec80(gsys, field, actor, TRUE);
    return event;
}

GameEvent *func_ov033_0217a148(GameSystem *gsys, Field *field, FieldActor *actor) {
    GameEvent *event;
    void **data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217a184, sizeof(void *));
    data = GameEvent_GetData(event);
    GFL_OvlLoad(OVERLAY_ID(131));
    *data = func_ov131_021eec80(gsys, field, actor, FALSE);
    return event;
}

GameEventReturnCode func_ov033_0217a184(GameEvent *event, u32 *state, void *data) {
    void **work = GameEvent_GetData(event);

    if (func_ov131_021eed2c(*work)) {
        func_ov131_021eed18(*work);
        GFL_OvlUnload(OVERLAY_ID(131));
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
