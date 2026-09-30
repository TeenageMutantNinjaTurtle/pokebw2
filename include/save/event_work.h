#ifndef POKEBW2_SAVE_EVENT_WORK_H
#define POKEBW2_SAVE_EVENT_WORK_H

#include "types.h"
#include "struct_decls.h"

BOOL EventWork_FlagGet(EventWork *eventWork, u16 flag);
void EventWork_FlagReset(EventWork *eventWork, u32 flag);
u16 *EventWork_GetWkPtr(EventWork *eventWork, u32 work);

#endif // POKEBW2_SAVE_EVENT_WORK_H
