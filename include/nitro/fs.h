#ifndef POKEBW2_NITRO_FS_H
#define POKEBW2_NITRO_FS_H

#include "types.h"

// NitroSDK's file system, under swan's names: FS_InitFile, FS_OpenFile, FS_GetLength, FS_ReadFile and FS_CloseFile

typedef struct {
    u8 data[0x48];
} FSFile;

void finit(FSFile *file);
BOOL romfs_fopen(FSFile *file, const char *path);
u32 GetFileSize(FSFile *file);
s32 romfs_fread(FSFile *file, void *dest, s32 size);
BOOL romfs_fclose(FSFile *file);

#endif // POKEBW2_NITRO_FS_H
