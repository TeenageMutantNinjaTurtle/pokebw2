#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/item_use_block.h"
#include "system/game_event.h"

GameEvent *EventFieldItemUseBlock_Create(GameSystem *gsys, u32 arg1, u32 arg2) {
    GameEvent *event = EventScriptCall_Create(gsys, 0x7d6, NULL, 0x15);
    ScriptWork *work = EventScriptCall_GetWork(event);

    ScriptWork_SetParams(work, arg1, arg2, 0, 0);
    return event;
}
