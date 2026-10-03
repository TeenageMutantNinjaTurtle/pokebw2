#ifndef POKEBW2_FIELD_EVENT_ENCOUNTER_CUTIN_H
#define POKEBW2_FIELD_EVENT_ENCOUNTER_CUTIN_H

// Event function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0).

#include "types.h"
#include "system/game_event.h"

GameEvent *EventFieldEffect_CreateBattleCutin(GameSystem *gsys, void *field3d, u32 selection, u32 param);

GameEvent *EventEncountEffectCutin_Create(GameSystem *gsys, u32 unused, u32 selection, u32 param);
GameEventReturnCode EventEncountEffectCutin_Callback(GameEvent *event, u32 *state, void *data);
GameEventReturnCode EventEncountEffectCutinFallback_Callback(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_EVENT_ENCOUNTER_CUTIN_H
