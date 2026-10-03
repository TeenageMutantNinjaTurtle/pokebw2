#include "types.h"
#include "battle/battle_result.h"
#include "battle/trainer_data.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/app_call.h"
#include "field/black_tower_gimmick.h"
#include "field/day_care.h"
#include "field/encounter.h"
#include "field/event_3d_demo.h"
#include "field/event_action_call.h"
#include "field/event_actor_move.h"
#include "field/event_battle_lose.h"
#include "field/event_battle_video.h"
#include "field/event_chatot.h"
#include "field/event_data.h"
#include "field/event_fly.h"
#include "field/event_game_clear.h"
#include "field/event_irc.h"
#include "field/event_mapchange.h"
#include "field/event_save.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wifibattlematch.h"
#include "field/field.h"
#include "field/field_acmd.h"
#include "field/field_actor.h"
#include "field/field_chunk.h"
#include "field/field_event.h"
#include "field/field_map.h"
#include "field/field_menu.h"
#include "field/field_player.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_script_plugin.h"
#include "field/field_script_supervisor.h"
#include "field/field_sound.h"
#include "field/field_status.h"
#include "field/field_visuals.h"
#include "field/hidden_event.h"
#include "field/item_use_block.h"
#include "field/player_action.h"
#include "field/player_state.h"
#include "field/pleasure_boat.h"
#include "field/script_network.h"
#include "field/shortcut_menu.h"
#include "field/skill_map_effect.h"
#include "field/stadium_script.h"
#include "field/subscreen.h"
#include "field/trainer_script.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/fx.h"
#include "nitro/os.h"
#include "nitro/rtc.h"
#include "pml/item.h"
#include "pml/move_reminder.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/config.h"
#include "save/encounter.h"
#include "save/event_work.h"
#include "save/medal_box.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "save/shortcut.h"
#include "save/trainer_card.h"
#include "system/dsi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/season.h"
#include "system/version.h"
#include "system/vm.h"

GameEvent *EventFieldAppCall_Create(FieldAppCallInput *input, u16 code) {
    GameEvent *event = GameEvent_Create(input->gameSystem, input->parent, EventFieldAppCall_Callback, sizeof(FieldAppCallWork));
    FieldAppCallWork *work = GameEvent_GetData(event);

    sys_memset(work, 0, sizeof(FieldAppCallWork));
    work->code = code;
    work->input = input;
    work->unk10 = 4;
    work->event = event;
    work->callback04 = input->context;
    work->callback08 = input->context;
    work->callback0C = input->context;
    work->flag68 = 0;
    work->value6A = 0;
    work->unk70 = 0;
    func_ov012_0215b76c(&work->params, work->input, work->input->canRetry, work->input->callback1,
                          work->input->callback2, work->input->arg);
    PlayerActionPerms_Create(&work->perms, work->input->gameSystem, work->input->field);
    CalcPlayerActionPossibilities(work->input->field, &work->action);
    return event;
}

void EventFieldAppCall_ConvAppResultToEventType(u32 result, u32 *eventType) {
    switch (result) {
    case 0:
        *eventType = 0;
        break;
    case 1:
        *eventType = 1;
        break;
    case 3:
        *eventType = 3;
        break;
    case 2:
        *eventType = 2;
        break;
    case 5:
        *eventType = 5;
        break;
    default:
        break;
    }
}

void func_ov012_0215b754(FieldAppCallWork *work) {
    GameSystem *gsys = work->input->gameSystem;
    GameData *gameData = GSYS_GetGameData(gsys);
    void *data = func_0201734c(gameData);

    func_020088ec(data, 0);
}

void func_ov012_0215b76c(FieldAppCallParam *param, void *context, FieldAppCallPredicate canRetry,
                         FieldAppCallPredicate callback1, FieldAppCallPredicate callback2, void *arg) {
    sys_memset(param, 0, sizeof(FieldAppCallParam));
    param->canRetry = canRetry;
    param->callback1 = callback1;
    param->callback2 = callback2;
    param->arg = arg;
    param->context = context;
}

BOOL FieldAppCallParam_CanRetry(FieldAppCallParam *param) {
    if (param->canRetry != NULL) {
        return param->canRetry(param->context, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7a8(FieldAppCallParam *param) {
    if (param->callback1 != NULL) {
        return param->callback1(param->context, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7c0(FieldAppCallParam *param) {
    if (param->callback2 != NULL) {
        return param->callback2(param->context, param->arg);
    }
    return TRUE;
}
