#ifndef POKEBW2_APP_RESEARCH_RADAR_RESEARCH_LIST_RECOVERY_H
#define POKEBW2_APP_RESEARCH_RADAR_RESEARCH_LIST_RECOVERY_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// What the list of surveys keeps while another screen is shown, to come back to where it was
// (research_list_recovery.c)
// The names of these functions and types are ours

ResearchListRecovery *ResearchListRecovery_Create(HeapID heapId);
void ResearchListRecovery_Delete(ResearchListRecovery *recovery);
void ResearchListRecovery_Init(ResearchListRecovery *recovery);

#endif // POKEBW2_APP_RESEARCH_RADAR_RESEARCH_LIST_RECOVERY_H
