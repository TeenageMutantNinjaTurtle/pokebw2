#include "types.h"
#include "field/event_encounter_cutin.h"
#include "gfl/fade.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEventReturnCode EventEncountEffectCutinFallback_Callback(GameEvent *event, u32 *state, void *data) {
    GSYS_GetField(GameEvent_GetGameSystem(event));
    switch (*state) {
    case 0:
        GFL_FadeSet(3, 0, 0x10, 3);
        (*state)++;
        break;
    case 1:
        if (!GFL_FadeIsRunning()) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
