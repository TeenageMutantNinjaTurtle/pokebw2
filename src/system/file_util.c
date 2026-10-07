#include "types.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "nitro/fs.h"
#include "system/file_util.h"

// Reading archive files without their NARC structure

void GFL_ArcSysInitRawHandle(FSFile *file, u32 arcId) {
    const char *path = GFL_ArcSysGetResourcePath(arcId);

    finit(file);
    romfs_fopen(file, path);
}

void *GFL_ArcSysReadRawResource(u32 arcId, HeapID heapId, u32 offset, u32 size) {
    FSFile file;
    void *data;

    GFL_ArcSysInitRawHandle(&file, arcId);
    if (size == 0) {
        size = GetFileSize(&file);
    }
    data = GFL_HeapAllocate(heapId, size, FALSE, "file_util.c", 178);
    romfs_fseek(&file, offset, FS_SEEK_SET);
    romfs_fread(&file, data, size);
    romfs_fclose(&file);
    return data;
}
