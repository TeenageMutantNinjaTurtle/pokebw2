#include "field/item_use_block.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/player_state.h"
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