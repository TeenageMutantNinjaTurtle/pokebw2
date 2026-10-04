#include "types.h"
#include "field/encounter_effect.h"
#include "field/event_encounter_cutin.h"
#include "field/field.h"
#include "gfl/fade.h"
#include "system/game_event.h"
#include "system/game_system.h"

struct EncounterCutinWork {
    s32 state;
    u32 selection;
    u32 param;
};

// The create functions of the encounter effects that show a cut-in, by the cut-in they show
GameEvent *func_ov146_021f59e0(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 1, param);
}

GameEvent *func_ov146_021f59ec(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 2, param);
}

GameEvent *func_ov146_021f59f8(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 3, param);
}

GameEvent *func_ov146_021f5a04(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 4, param);
}

GameEvent *func_ov146_021f5a10(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 5, param);
}

GameEvent *func_ov146_021f5a1c(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 6, param);
}

GameEvent *func_ov146_021f5a28(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 7, param);
}

GameEvent *func_ov146_021f5a34(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 8, param);
}

GameEvent *func_ov146_021f5a40(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 9, param);
}

GameEvent *func_ov146_021f5a4c(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 10, param);
}

GameEvent *func_ov146_021f5a58(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 11, param);
}

GameEvent *func_ov146_021f5a64(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 12, param);
}

GameEvent *func_ov146_021f5a70(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 0, param);
}

GameEvent *func_ov146_021f5a7c(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 15, param);
}

GameEvent *func_ov146_021f5a88(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 14, param);
}

GameEvent *func_ov146_021f5a94(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 16, param);
}

GameEvent *func_ov146_021f5aa0(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 13, param);
}

GameEvent *func_ov146_021f5aac(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 17, param);
}

GameEvent *func_ov146_021f5ab8(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 18, param);
}

GameEvent *func_ov146_021f5ac4(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 19, param);
}

GameEvent *func_ov146_021f5ad0(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 20, param);
}

GameEvent *func_ov146_021f5adc(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 21, param);
}

GameEvent *func_ov146_021f5ae8(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 22, param);
}

GameEvent *func_ov146_021f5af4(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 23, param);
}

GameEvent *func_ov146_021f5b00(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 24, param);
}

GameEvent *func_ov146_021f5b0c(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 25, param);
}

GameEvent *func_ov146_021f5b18(GameSystem *gsys, Field *field, u32 param) {
    return EventEncountEffectCutin_Create(gsys, field, 26, param);
}

GameEvent *EventEncountEffectCutin_Create(GameSystem *gsys, Field *field, u32 selection, u32 param) {
    EncounterCutinWork *work;

    work = EncEff_AllocWorkArea(Field_GetEncEff(GSYS_GetField(gsys)), 0xc, 0x50);
    work->state = 0;
    work->selection = selection;
    work->param = param;
    return GameEvent_Create(gsys, NULL, EventEncountEffectCutin_Callback, 0);
}

GameEventReturnCode EventEncountEffectCutin_Callback(GameEvent *event, u32 *state, void *data) {
    GameSystem *gsys;
    Field *field;
    EncounterCutinWork *work;
    GameEvent *next;

    gsys = GameEvent_GetGameSystem(event);
    field = GSYS_GetField(gsys);
    work = EncEff_GetWorkArea(Field_GetEncEff(field));

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
