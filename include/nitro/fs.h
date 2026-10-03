#ifndef POKEBW2_NITRO_FS_H
#define POKEBW2_NITRO_FS_H

#include "types.h"

// NitroSDK's file system, under swan's names: FS_InitFile, FS_OpenFile, FS_GetLength, FS_ReadFile, FS_CloseFile,
// FS_SeekFile, and FS_CreateFileFromMemory, which opens a file over memory

typedef struct {
    u8 data[0x48];
} FSFile;

void finit(FSFile *file);
BOOL romfs_fopen(FSFile *file, const char *path);
u32 GetFileSize(FSFile *file);
s32 romfs_fread(FSFile *file, void *dest, s32 size);
BOOL romfs_fclose(FSFile *file);
BOOL romfs_fseek(FSFile *file, s32 offset, int whence);
BOOL extfs_fopen(FSFile *file, const void *data, u32 size);

#define FS_SEEK_SET 0

#endif // POKEBW2_NITRO_FS_H
