#ifndef POKEBW2_FIELD_FIELD_SCRIPT_EVENT_H
#define POKEBW2_FIELD_FIELD_SCRIPT_EVENT_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

GameEvent *EventScriptCall_Create(GameSystem *gsys, u16 scriptId, void *param, HeapID heapId);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_EVENT_H
