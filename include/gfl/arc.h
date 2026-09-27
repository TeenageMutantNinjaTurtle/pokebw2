#ifndef POKEBW2_GFL_ARC_H
#define POKEBW2_GFL_ARC_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

ArcTool *GFL_ArcSysCreateFileHandle(u32 arcId, HeapID heapId);
void GFL_ArcToolFree(ArcTool *handle);
u32 GFL_ArcToolGetDataLength(ArcTool *handle, u32 fileId);
void *GFL_ArcToolReadHeapNew(ArcTool *handle, u32 fileId, HeapID heapId);

#endif // POKEBW2_GFL_ARC_H
