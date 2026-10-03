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

u32 func_ov012_0215aa68(u32 index) {
    return data_ov012_0216cb74[index];
}

BOOL func_ov012_0215aa74(FieldMenuWork *work, FieldMenuWork *context) {
    FieldSubscreen *subscreen = Field_GetSubscreen(context->field);

    if (work->prevScreenId == 0) {
        func_ov036_0219886c(subscreen, context->unk10);
    }
    return TRUE;
}

BOOL func_ov012_0215aa90(void) {
    return TRUE;
}

BOOL func_ov012_0215aa94(FieldMenuWork *work, FieldMenuWork *context) {
    GameData *gameData = GSYS_GetGameData(context->gameSystem);
    u32 value;

    switch (work->prevScreenId) {
    case 4:
        value = 6;
        break;
    case 0:
        value = 1;
        break;
    case 5:
        value = 0;
        break;
    case 1:
    case 2:
    case 3:
        value = (u8)context->screenId;
        break;
    default:
        goto finish;
    }
    GameData_SetLastSubscreen(gameData, value);
finish:
    return TRUE;
}

BOOL IsExistAnyYShortcut(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    SaveControl *save = GameData_GetSaveControl(gameData);
    ShortcutSave *shortcutSave = SaveControl_GetShortcutSave(save);

    return ShortcutSave_GetShortcutCount(shortcutSave) != 0;
}

u32 ShortcutMenu_SetKeyItemID(ShortcutMenuContext *context, u32 item) {
    switch (item) {
    case 0:
        context->kind = 0;
        return 1;
    case 1:
        context->action = 8;
        return 0;
    case 2:
        context->action = 12;
        return 0;
    case 3:
        context->action = 9;
        return 0;
    case 4:
        context->kind = 4;
        return 1;
    case 5:
        context->kind = 5;
        return 1;
    case 6:
        context->action = 0;
        context->param = 466;
        return 0;
    case 7:
        context->action = 0;
        context->param = 628;
        return 0;
    case 8:
        context->action = 0;
        context->param = 629;
        return 0;
    case 9:
        context->action = 7;
        context->param = 0;
        return 0;
    case 10:
        context->action = 7;
        context->param = 1;
        return 0;
    case 11:
        context->action = 7;
        context->param = 2;
        return 0;
    case 12:
        context->action = 2;
        context->param = 0;
        return 0;
    case 13:
        context->action = 2;
        context->param = 1;
        return 0;
    case 14:
        context->action = 2;
        context->param = 2;
        return 0;
    case 15:
        context->action = 2;
        context->param = 3;
        return 0;
    case 16:
        context->action = 2;
        context->param = 4;
        return 0;
    case 17:
        context->action = 2;
        context->param = 5;
        return 0;
    case 18:
        context->action = 1;
        context->param = 1;
        return 0;
    case 19:
        context->action = 1;
        context->param = 6;
        return 0;
    case 20:
        context->action = 1;
        context->param = 2;
        return 0;
    case 21:
        context->action = 1;
        context->param = 3;
        return 0;
    case 22:
        context->action = 1;
        context->param = 4;
        return 0;
    case 23:
        context->action = 1;
        context->param = 5;
        return 0;
    case 31:
        context->action = 1;
        context->param = 7;
        return 0;
    case 32:
        context->action = 1;
        context->param = 8;
        return 0;
    case 24:
        context->action = 3;
        context->param = 1;
        return 0;
    case 25:
        context->action = 3;
        context->param = 2;
        return 0;
    case 26:
        context->action = 3;
        context->param = 3;
        return 0;
    case 27:
        context->action = 5;
        return 0;
    case 28:
        context->action = 13;
        return 0;
    case 29:
        context->action = 14;
        return 0;
    case 30:
        context->action = 0;
        context->param = -1;
        return 0;
    case 33:
        context->action = 0;
        context->param = 638;
        return 0;
    default:
        context->action = 1;
        return 0;
    }
}

BOOL ShortcutMenu_GetActionFromKeyItem(s32 item, u32 *action, u32 *invalid) {
    *invalid = 0;
    switch (item) {
    case 0:
        *action = 0;
        return TRUE;
    case 1:
        *action = 1;
        return TRUE;
    case 2:
        *action = 6;
        return TRUE;
    case 3:
        *action = 2;
        return TRUE;
    case 4:
        *action = 5;
        return TRUE;
    case 5:
        *action = 9;
        return TRUE;
    case 28:
        *action = 10;
        return TRUE;
    case 29:
        *action = 11;
        return TRUE;
    case 6:
    case 7:
    case 8:
    case 33:
        return FALSE;
    default:
        *invalid = 1;
        return FALSE;
    }
}

void func_ov012_0215b284(u32 arg0, ShortcutMenuWork *work) {
    GameData *gameData;
    void *param;

    if (work->app == NULL && work->done == 0) {
        GFL_BGSysSetBGEnabled(1, 0);
        if (Field_GetMsgBGSys(work->field)) {
            func_ov036_02187834();
        }
        gameData = GSYS_GetGameData(work->gameSystem);
        param = func_02017670(gameData);
        work->app = func_ov036_021bedd8(gameData, arg0, (u32)param, 0x50, 0x15);
    }
}

BOOL func_ov012_0215b2d0(ShortcutMenuWork *work) {
    if (work->done == 0) {
        switch (work->state) {
        case 0:
            if (work->app) {
                GFL_BGSysSetBGEnabled(1, 0);
                func_ov036_021bf004(work->app);
                work->app = NULL;
                work->state = 1;
            } else {
                work->state = 2;
            }
            break;
        case 1:
            Field_GetMsgBGSys(work->field);
            func_ov036_02187888();
            work->state = 2;
            break;
        case 2:
            work->state = 0;
            return TRUE;
        }
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov012_0215b32c(ShortcutMenuContext *context, ShortcutMenuWork *work) {
    GameData *gameData;
    SaveControl *save;
    ShortcutSave *shortcut;

    gameData = GSYS_GetGameData(work->gameSystem);
    save = GameData_GetSaveControl(gameData);
    shortcut = SaveControl_GetShortcutSave(save);
    switch (work->state) {
    case 0:
        if (ShortcutSave_GetShortcutCount(shortcut) == 0) {
            work->done = 1;
            work->state = 2;
        } else if (context->type == 1 || context->type == 3 || context->type == 2 || context->type == 5) {
            work->state = 2;
        } else {
            func_ov012_0215b284(1, work);
            work->state = 1;
        }
        break;
    case 1:
        if (func_ov036_021bf198(work->app)) {
            work->state = 2;
        }
        break;
    case 2:
        work->state = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov012_0215b39c(u32 unused, ShortcutMenuWork *work) {
    return func_ov012_0215b2d0(work);
}

void EventFieldItemUseBlock_Call(GameEvent *parent, GameSystem *gsys, u32 action, u32 kind) {
    u32 param = 0;
    u32 item = 0;
    GameEvent *event;

    if (kind == 1) {
        param = 3;
        switch (action) {
        case 0:
            item = 0x1c2;
            break;
        case 2:
            item = 0x4e;
            break;
        case 4:
            item = 0x1bf;
            break;
        }
    } else if (action == 0) {
        GameData *gameData = GSYS_GetGameData(gsys);
        PlayerState *state = GameData_GetPlayerState(gameData);

        if (FieldPlayerState_GetExState(state) == 1) {
            param = 1;
        }
    }
    event = EventFieldItemUseBlock_Create(gsys, param, item);
    GameEvent_ChainNext(parent, event);
}

GameEvent *EventFieldItemUseBlock_Create(GameSystem *gsys, u32 arg1, u32 arg2) {
    GameEvent *event = EventScriptCall_Create(gsys, 0x7d6, NULL, 0x15);
    ScriptWork *work = EventScriptCall_GetWork(event);

    ScriptWork_SetParams(work, arg1, arg2, 0, 0);
    return event;
}

BOOL CheckAnyRibbon(ShortcutMenuWork *work) {
    GameData *gameData = GSYS_GetGameData(work->gameSystem);
    PokeParty *party = GameData_GetParty(gameData);
    int i;

    for (i = 0; i < PokeParty_GetPkmCount(party); i++) {
        PartyPkm *pkm = PokeParty_GetPkm(party, i);

        if (PokeParty_GetParam(pkm, PKM_PARAM_SPECIES_VALID, NULL) != 0 && PokeParty_CheckAnyRibbon(pkm) != 0) {
            return TRUE;
        }
    }
    return FALSE;
}
