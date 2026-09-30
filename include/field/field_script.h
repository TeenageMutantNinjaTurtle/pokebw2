#ifndef POKEBW2_FIELD_FIELD_SCRIPT_H
#define POKEBW2_FIELD_FIELD_SCRIPT_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Runs a script from an event, and returns its work
ScriptWork *EventScriptCall_Start(GameEvent *event, u16 scriptId, void *a2, void *a3, HeapID heapId);
// Sets the script's parameters, which it reads from its work
void ScriptWork_SetParams(ScriptWork *work, u16 param0, u16 param1, u16 param2, u16 param3);
void FieldScript_CallOnZoneInit(GameSystem *gsys, u32 a1);
void FieldScript_CallPlayerInitSetup(GameSystem *gsys, u32 a1);
void resetRebattleTrainers(EventWork *eventWork);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_H
