#ifndef POKEBW2_FIELD_FIELD_SCRIPT_H
#define POKEBW2_FIELD_FIELD_SCRIPT_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

void EventScriptCall_Start(GameEvent *event, u16 scriptId, void *a2, void *a3, HeapID heapId);
void FieldScript_CallOnZoneInit(GameSystem *gsys, u32 a1);
void FieldScript_CallPlayerInitSetup(GameSystem *gsys, u32 a1);
void resetRebattleTrainers(EventWork *eventWork);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_H
