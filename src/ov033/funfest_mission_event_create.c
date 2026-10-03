#include "field/funfest_scripts.h"
#include "system/game_event.h"

extern GameEventReturnCode func_ov033_02176d9c(GameEvent *event, u32 *state, void *callbackData);

GameEvent *func_ov033_02176d88(GameSystem *gsys) {
    return GameEvent_Create(gsys, NULL, func_ov033_02176d9c, 4);
}
