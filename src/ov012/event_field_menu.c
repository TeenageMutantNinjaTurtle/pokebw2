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

GameEvent *EventFieldMenu_Create(GameSystem *gsys, Field *field, u16 param) {
    FieldSubscreen *subscreen = Field_GetSubscreen(field);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventFieldMenu_Callback, sizeof(FieldMenuWork));
    FieldMenuWork *work = GameEvent_GetData(event);
    u32 screenId;

    sys_memset(work, 0, sizeof(FieldMenuWork));
    work->gameSystem = gsys;
    work->event = event;
    work->field = field;
    work->code = param;
    work->unk14 = 0;
    work->gameSystem2 = gsys;
    work->field2 = field;
    work->event2 = event;
    work->callback34 = func_ov012_0215aa74;
    work->callback38 = func_ov012_0215aa90;
    work->callback3C = func_ov012_0215aa94;
    work->self = work;
    work->unk30 = -1;
    screenId = FieldSubscreen_GetScreenID(subscreen);
    switch (screenId) {
    case 4:
        work->screenId = 4;
        break;
    case 10:
        work->screenId = 10;
        break;
    default:
        work->screenId = FieldSubscreen_GetIDForChange(Field_GetSubscreen(work->field), 0);
        break;
    }
    work->prevScreenId = work->screenId;
    func_0203d564(TRUE);
    return event;
}

GameEvent *EventFieldMenu_CreateUnionRoom(GameSystem *gsys, Field *field, u16 param) {
    GameEvent *event = EventFieldMenu_Create(gsys, field, param);
    FieldMenuWork *work = GameEvent_GetData(event);
    u16 zoneId = Field_GetPlayerStateZoneID(field);

    if (IsZone150Or151(zoneId) == 1) {
        work->screenId = 5;
    } else {
        work->screenId = 2;
    }
    return event;
}
