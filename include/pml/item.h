#ifndef POKEBW2_PML_ITEM_H
#define POKEBW2_PML_ITEM_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Item data

#define ITEM_PARAM_FLING_POWER 10

ArcTool *PML_ItemArcHandleCreate(HeapID heapId);
void *PML_ItemArcHandleReadFile(ArcTool *handle, u16 item, HeapID heapId);
s32 PML_ItemGetParam(void *data, u32 param);

#endif // POKEBW2_PML_ITEM_H
