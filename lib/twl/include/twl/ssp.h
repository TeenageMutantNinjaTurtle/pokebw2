#ifndef POKEBW2_TWL_SSP_H
#define POKEBW2_TWL_SSP_H

#include "types.h"

// TwlSDK's JPEG encoder and decoder (the SSP library), linked into the Xtransceiver's overlay

#define SSP_JPEG_RGB555 0x4
#define SSP_JPEG_OUTPUT_YUV422 1

u32 SSP_GetJpegEncoderBufferSize(u32 width, u32 height, u32 sampling, u32 option);
u32 SSP_StartJpegEncoder(const void *src, u8 *dst, u32 limit, u8 *work, u32 width, u32 height, u32 quality,
                         u32 sampling, u32 option);
BOOL SSP_StartJpegDecoder(const u8 *data, u32 size, void *dst, s16 *width, s16 *height, u32 option);

#endif // POKEBW2_TWL_SSP_H
