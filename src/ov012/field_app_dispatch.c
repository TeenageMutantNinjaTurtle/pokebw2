#include "constants/pokemon.h"
#include "field/app_call.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/item_use_block.h"
#include "field/player_action.h"
#include "field/player_state.h"
#include "field/shortcut_menu.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

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

GameEvent *EventFieldAppCall_Create(FieldAppCallInput *input, u16 code) {
    GameEvent *event =
        GameEvent_Create(input->gameSystem, input->parent, EventFieldAppCall_Callback, sizeof(FieldAppCallWork));
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
