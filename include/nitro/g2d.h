#ifndef POKEBW2_NITRO_G2D_H
#define POKEBW2_NITRO_G2D_H

#include "types.h"

typedef struct {
    u32 format;
    u32 extendedPalette;
    u32 size;
    void *rawData;
} NNSG2dPaletteData;

typedef struct {
    u16 height;
    u16 width;
    u32 pixelFormat;
    u32 mappingType;
    u32 characterFormat;
    u32 size;
    void *rawData;
} NNSG2dCharacterData;

typedef struct {
    u16 width;
    u16 height;
    u16 colorMode;
    u16 format;
    u32 size;
    u32 rawData[1];
} NNSG2dScreenData;

// The palettes present in a palette file that holds only some of them
typedef struct {
    u16 numPalette;
    u16 pad;
    void *paletteIndexTable;
} NNSG2dPaletteCompressInfo;

typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;
typedef struct NNSG2dAnimBankData NNSG2dAnimBankData;
typedef struct NNSG2dMultiCellDataBank NNSG2dMultiCellDataBank;

// Prepare the contents of a loaded graphics file in place: NNS_G2dGetUnpackedBGCharacterData,
// NNS_G2dGetUnpackedCharacterData, NNS_G2dGetUnpackedScreenData and NNS_G2dGetUnpackedPaletteData, and the rest. Each
// returns FALSE if the file is not of its kind
BOOL NNS_G2DPrepareBGChar(void *file, NNSG2dCharacterData **character);
BOOL NNS_G2DPrepareObjChar(void *file, NNSG2dCharacterData **character);
BOOL NNS_G2DPrepareScreen(void *file, NNSG2dScreenData **screen);
BOOL RelocatePaletteResGetDataPtr(void *file, NNSG2dPaletteData **palette);
BOOL NNS_G2dGetUnpackedPaletteCompressInfo(void *file, NNSG2dPaletteCompressInfo **info);
BOOL NNS_G2dGetUnpackedCellBank(void *file, NNSG2dCellDataBank **cells);
BOOL NNS_G2dGetUnpackedAnimBank(void *file, NNSG2dAnimBankData **anims);
BOOL NNS_G2dGetUnpackedMultiCellBank(void *file, NNSG2dMultiCellDataBank **cells);
BOOL NNS_G2dGetUnpackedMCAnimBank(void *file, NNSG2dAnimBankData **anims);

#endif // POKEBW2_NITRO_G2D_H
