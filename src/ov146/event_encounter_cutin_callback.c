#include "types.h"
#include "field/encounter_effect.h"
#include "field/event_encounter_cutin.h"
#include "field/field.h"
#include "gfl/fade.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEventReturnCode EventEncountEffectCutin_Callback(GameEvent *event, u32 *state, void *data) {
    GameSystem *gsys = GameEvent_GetGameSystem(event);
    Field *field = GSYS_GetField(gsys);
    EncounterCutinWork *work = EncEff_GetWorkArea(Field_GetEncEff(field));
    GameEvent *next;

    switch (*state) {
    case 0:
        GFL_FadeSet(4, 0, 0x10, 0);
        (*state)++;
        // Fall through to check the fade in the same frame.
    case 1:
        if (!GFL_FadeIsRunning()) {
            GFL_FadeSet(4, 0x10, 0, 0);
            (*state)++;
        }
        break;
    case 2:
        if (!GFL_FadeIsRunning()) {
            work->state++;
            if (work->state < 2) {
                GFL_FadeSet(4, 0, 0x10, 0);
                *state = 1;
            } else {
                next = EventFieldEffect_CreateBattleCutin(gsys, Field_Get3DCi(field), work->selection, work->param);
                if (next != NULL) {
                    GameEvent_ChainNext(event, next);
                } else {
                    next = GameEvent_Create(gsys, event, EventEncountEffectCutinFallback_Callback, 0);
                    GameEvent_ChainNext(event, next);
                }
                (*state)++;
            }
        }
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
