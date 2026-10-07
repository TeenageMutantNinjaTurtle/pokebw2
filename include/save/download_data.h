#ifndef POKEBW2_SAVE_DOWNLOAD_DATA_H
#define POKEBW2_SAVE_DOWNLOAD_DATA_H

// The data the save keeps at 0x68 of SaveControl, which looks like what the game downloads: entries of 0x18 bytes with
// an 8-character name, flags and values, and the musical program and props, of ARM9 main. The name is descriptive

#include "types.h"
#include "struct_decls.h"

void *func_020074d8(SaveControl *save);
// The data of a kind, copied to dest for some kinds: the musical program's number for kind 0, and the address of the
// musical props' flags for kind 0xb
u32 func_02010b0c(void *data, u32 kind, void *dest);
BOOL func_02010b90(void *data, u32 index);
u16 func_02010bc0(void *data, u32 index);
// An entry's two values and name
u8 func_02010bcc(void *data, u32 index);
u8 func_02010bd8(void *data, u32 index);
const u16 *func_02010be4(void *data, u32 index);

#endif // POKEBW2_SAVE_DOWNLOAD_DATA_H
