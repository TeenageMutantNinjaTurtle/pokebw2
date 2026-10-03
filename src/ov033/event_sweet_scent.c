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

GameEvent *EventSweetScent_Create(Field *field, GameSystem *gsys) {
    return func_ov033_021785d4(gsys, field, 0xff);
}

GameEvent *func_ov033_021785d4(GameSystem *gsys, Field *field, u8 partySlot) {
    GameEvent *event;
    SweetScentEventData *data;

    event = GameEvent_Create(gsys, NULL, EventSweetScent_Callback, sizeof(SweetScentEventData));
    data = GameEvent_GetData(event);
    sys_memset(data, 0, sizeof(SweetScentEventData));
    data->partySlot = partySlot;
    data->gsys = gsys;
    data->field = field;
    data->player = Field_GetPlayer(field);
    data->gameData = GSYS_GetGameData(gsys);
    return event;
}

GameEventReturnCode EventSweetScent_Callback(GameEvent *event, u32 *state, void *data) {
    SweetScentEventData *work;
    GameEvent *next;

    work = data;
    switch (*state) {
    case 0:
        if (work->partySlot >= 6) {
            *state = 5;
            break;
        }
        FieldPlayer_SetSpecialSeq(work->player, 0x80);
        (*state)++;
    case 1:
        if (func_ov036_0219a580(work->player) != TRUE) {
            break;
        }
        FldAct_SetAcmd(FieldPlayer_GetActor(work->player), 0xa2);
        (*state)++;
        break;
    case 2:
        if (func_ov012_02166ef8(FieldPlayer_GetActor(work->player)) != TRUE) {
            break;
        }
        next = EventFieldEffect_CreatePokeSprite(work->gsys, Field_Get3DCi(work->field), work->partySlot);
        if (next != NULL) {
            GameEvent_ChainNext(event, next);
        }
        (*state)++;
        break;
    case 3:
        FieldPlayer_SetSpecialSeq(work->player, 8);
        (*state)++;
    case 4:
        if (func_ov036_0219a580(work->player) == TRUE) {
            *state = 5;
        }
        break;
    case 5:
        if (func_ov033_02178730(work) == 0) {
            *state = 8;
            break;
        }
        func_ov033_02178748(event, work->gsys, work->field);
        *state = 6;
        break;
    case 6:
        next = EventWildBattleCall_CreateRandom(Field_GetEncountSystem(work->field), 2);
        if (next == NULL) {
            *state = 7;
            break;
        }
        GameEvent_ChainNext(event, next);
        *state = 9;
        break;
    case 7:
        EventScriptCall_Start(event, 0x2793, NULL, NULL, 0x15);
        *state = 9;
        break;
    case 8:
        EventScriptCall_Start(event, 0x2794, NULL, NULL, 0x15);
        *state = 9;
        break;
    case 9:
        EnableAllActorsMovement(Field_GetActorSystem(work->field));
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

BOOL func_ov033_02178730(SweetScentEventData *work) {
    if (func_ov036_02199220(Field_GetWeatherSystem(work->field)) == 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov033_02178748(GameEvent *event, GameSystem *gsys, Field *field) {
    GameEvent *next;
    SweetScentScreenWork *data;

    next = GameEvent_Create(gsys, NULL, func_ov033_02178788, sizeof(SweetScentScreenWork));
    data = GameEvent_GetData(next);
    data->bgId = 3;
    data->alpha = 0;
    data->step = 2;
    data->timer = 0;
    data->displayControl = FieldG2D_GetDispControl(field);
    GameEvent_ChainNext(event, next);
}

GameEventReturnCode func_ov033_02178788(GameEvent *event, u32 *state, void *data) {
    SweetScentScreenWork *work;

    work = data;
    switch (*state) {
    case 0:
        func_ov033_0217884c(work);
        GFL_SndSEPlay(0x683);
        (*state)++;
        break;
    case 1:
        if (work->timer++ >= work->step) {
            work->alpha++;
            FieldDispControl_ReqAdjustAlphaA(work->displayControl, work->alpha, 16 - work->alpha);
            work->timer = 0;
        }
        if (work->alpha >= 8) {
            (*state)++;
        }
        break;
    case 2:
        if (work->timer++ < 30) {
            (*state)++;
        }
        break;
    case 3:
        if (work->timer++ >= work->step) {
            work->alpha--;
            FieldDispControl_ReqAdjustAlphaA(work->displayControl, work->alpha, 16 - work->alpha);
            work->timer = 0;
        }
        if (work->alpha == 0) {
            (*state)++;
        }
        break;
    case 4:
        FieldDispControl_ReqSetAlphaA(work->displayControl, 0, 0, 0, 0x1f);
        FieldDispControl_ReqSetBGEnabled(work->displayControl, work->bgId, FALSE);
        (*state)++;
        break;
    default:
        func_ov033_021788c4(work);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

void func_ov033_0217884c(SweetScentScreenWork *work) {
    SweetScentPalette palette = data_ov033_0217c484;
    GFL_BGSysSetBGEnabled(work->bgId, FALSE);
    GFL_BGSysUploadStdPalette(work->bgId, &palette, 8, 0x20);
    GFL_BGSysFillChar(work->bgId, 1, 1, 0x100);
    GFL_BGSysFillScrArea(work->bgId, 0x100, 0, 0, 0x20, 0x20, 1);
    GFL_BGSysLoadScr(work->bgId);
    FieldDispControl_ReqSetAlphaA(work->displayControl, 8, 0x37, work->alpha, 16 - work->alpha);
    FieldDispControl_ReqSetBGEnabled(work->displayControl, work->bgId, TRUE);
}

void func_ov033_021788c4(SweetScentScreenWork *work) {
    u16 palette[2] = { 0, 0 };

    GFL_BGSysUploadStdPalette(work->bgId, palette, 8, 0x20);
    GFL_BGSysFillScrArea(work->bgId, 0, 0, 0, 0x20, 0x20, 1);
    GFL_BGSysLoadScr(work->bgId);
    GFL_BGSysFreeFilledChar(work->bgId, 1, 0x100);
}
