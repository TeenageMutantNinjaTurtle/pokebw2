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

#endif // POKEBW2_NITRO_G2D_H
