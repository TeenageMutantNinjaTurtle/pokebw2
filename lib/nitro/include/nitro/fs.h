#ifndef POKEBW2_NITRO_FS_H
#define POKEBW2_NITRO_FS_H

#include "types.h"
#include "nitro/mi.h"

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

// Overlays: NitroSDK's FS_LoadOverlayInfo, FS_LoadOverlay, FS_UnloadOverlay and FS_SetDefaultDMA, under swan's names.
// The target is the processor, MI_PROCESSOR_ARM9 (nitro/mi.h)
#define FS_DMA_NOT_USE 0xffffffff

typedef struct {
    u32 id;
    u8 *ramAddress;
    u32 ramSize;
    u32 bssSize;
    u8 rest[0x1c];
} FSOverlayInfo;

BOOL sys_read_overlay_header(FSOverlayInfo *info, int target, u32 id);
BOOL sys_load_overlay(int target, u32 id);
BOOL sys_unload_overlay(int target, u32 id);
u32 fs_set_dma_id(u32 dma);

#endif // POKEBW2_NITRO_FS_H
