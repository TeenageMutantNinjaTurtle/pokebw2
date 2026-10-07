#ifndef POKEBW2_APP_RESEARCH_RADAR_RESEARCH_COMMON_H
#define POKEBW2_APP_RESEARCH_RADAR_RESEARCH_COMMON_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Research Radar's work shared by its screens (research_common.c)
// The names of these functions and types are ours

ResearchCommon *ResearchCommon_Create(HeapID heapId, GameSystem *gsys);
void ResearchCommon_Delete(ResearchCommon *common);
HeapID ResearchCommon_GetHeapID(ResearchCommon *common);
// Records the screen being shown, and keeps the one before it
void ResearchCommon_SetSeq(ResearchCommon *common, u32 seq);
void func_ov310_021a4414(ResearchCommon *common);

#endif // POKEBW2_APP_RESEARCH_RADAR_RESEARCH_COMMON_H
