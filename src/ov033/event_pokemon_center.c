#include "field/event_pokemon_center.h"
#include "field/field_prop.h"

void EventPokeCenHeal_StartAnimations(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->animationCount; i++) {
        FieldPropHandle_CallAnmCmd(work->ballHandles[i], 0, 0);
    }
    if (work->centerProp != NULL) {
        FieldChunkPropHolder_CallAnmCmd(work->propHolder, work->centerProp, 0, 0);
    }
}

void EventPokeCenHeal_PauseAnimation(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->animationCount; i++) {
        FieldPropHandle_CallAnmCmd(work->ballHandles[i], 0, 3);
    }
}

BOOL EventPokeCenHeal_IsAnimationDone(EventPokeCenHealData *work) {
    s32 i;

    for (i = 0; i < work->animationCount; i++) {
        if (FieldPropHandle_IsAnmIdle(work->ballHandles[i], 0) != TRUE) {
            return FALSE;
        }
    }
    return TRUE;
}
