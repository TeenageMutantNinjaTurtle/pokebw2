#include "types.h"
#include "field/encounter_effect.h"
#include "field/event_encounter_cutin.h"
#include "field/field.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *EventEncountEffectCutin_Create(GameSystem *gsys, u32 unused, u32 selection, u32 param) {
    EncounterCutinWork *work = EncEff_AllocWorkArea(Field_GetEncEff(GSYS_GetField(gsys)), 0xc, 0x50);
    work->state = 0;
    work->selection = selection;
    work->param = param;
    return GameEvent_Create(gsys, NULL, EventEncountEffectCutin_Callback, 0);
}
