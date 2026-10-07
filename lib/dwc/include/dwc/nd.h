#ifndef POKEBW2_DWC_ND_H
#define POKEBW2_DWC_ND_H

#include "types.h"

// NitroDWC's download library (DWC_Nd), in overlay 189, which Mystery Gift receives Wi-Fi gifts with. The ROM names
// none of it; the comments give the NitroDWC function each one appears to be, from the calls

// A file the server offers, 0xb0 bytes
typedef struct {
    u8 unk0[0x88];
    char param1[11];
    // Mystery Gift's gifts give the games they are for here, as a hexadecimal mask of 1 << GAME_VERSION
    char param2[11];
    char param3[11];
    u8 unkA9[3];
    u32 size;
} DWCNdFileInfo;

// The callback of every asynchronous call, with its result
typedef void (*DWCNdCallback)(u32 reason, u32 error);

// DWC_NdInitAsync
BOOL func_ov189_021a5674(DWCNdCallback callback, const char *gameCode, const char *password);
// DWC_NdProcess
void func_ov189_021a5768(void);
// DWC_NdCleanupAsync
BOOL func_ov189_021a57dc(void);
// DWC_NdSetAttr
BOOL func_ov189_021a5830(const char *attr1, const char *attr2, const char *attr3);
// DWC_NdGetFileListAsync
BOOL func_ov189_021a5850(DWCNdFileInfo *files, u32 offset, u32 count);
// DWC_NdGetFileAsync
BOOL func_ov189_021a58c8(DWCNdFileInfo *file, void *buffer, u32 size);
// DWC_NdCancelAsync
BOOL func_ov189_021a5938(void);
// DWC_NdGetProgress
BOOL func_ov189_021a5980(u32 *received, u32 *contentLength);

#endif // POKEBW2_DWC_ND_H
