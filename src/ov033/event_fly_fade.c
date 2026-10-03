#include "field/event_fly.h"
#include "gfl/fade.h"
#include "system/game_system.h"

GameEventReturnCode func_ov033_02178c6c(GameEvent *event, u32 *state, void *data) {
    GameSystem *gsys;

    gsys = GameEvent_GetGameSystem(event);
    GSYS_GetField(gsys);
    switch (*state) {
    case 0:
        GFL_FadeSet(3, 16, 0, 0);
        ++*state;
        break;
    case 1:
        if (!GFL_FadeIsRunning()) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
