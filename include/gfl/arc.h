#ifndef POKEBW2_GFL_ARC_H
#define POKEBW2_GFL_ARC_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

ArcTool *GFL_ArcSysCreateFileHandle(u32 arcId, HeapID heapId);
u32 GFL_ArcToolGetDataMax(ArcTool *handle);
void GFL_ArcToolFree(ArcTool *handle);
void GFL_ArcToolRead(ArcTool *handle, u32 fileId, void *dest);
void GFL_ArcToolReadRange(ArcTool *handle, u32 fileId, u32 offset, u32 size, void *dest);
void GFL_ArcSysRead(void *dest, u32 arcId, u32 fileId);
void GFL_ArcSysReadRange(void *dest, u32 arcId, u32 fileId, u32 offset, u32 size);
void *GFL_ArcSysReadHeapNew(u32 arcId, u32 fileId, HeapID heapId);
void *GFL_ArcSysReadHeapNewLZGetLen(u32 arcId, u32 fileId, u32 a2, HeapID heapId, u32 *size);
void *GFL_ArcSysReadHeapNewLZ(u32 arcId, u32 fileId, u32 a2, HeapID heapId);
// The count of files in the archive
u32 GFL_ArcSysGetDataMax(u32 arcId);
void *GFL_ArcSysReadHeapNewRange(u32 arcId, u32 fileId, HeapID heapId, u32 offset, u32 size);
u32 GFL_ArcToolGetDataLength(ArcTool *handle, u32 fileId);
void *GFL_ArcToolReadHeapNew(ArcTool *handle, u32 fileId, HeapID heapId);
// Read an archive's files in pieces: the offset of a file in the archive, and seeking to an offset and reading from it
u32 GFL_ArcToolGetDataOfs(ArcTool *handle, u32 fileId);
void GFL_ArcToolSeek(ArcTool *handle, u32 offset);
void GFL_ArcToolReadRaw(ArcTool *handle, u32 size, void *dest);

#endif // POKEBW2_GFL_ARC_H
