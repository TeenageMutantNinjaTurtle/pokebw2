#ifndef POKEBW2_TWL_MI_H
#define POKEBW2_TWL_MI_H

#include "types.h"

// TwlSDK's memory functions for the DSi's hardware: the shared WRAM B and C, which the DSP needs, and the new DMA
// channels. They are in the LTD autoload and keep their default names until it is analyzed.

typedef enum {
    MI_WRAM_A,
    MI_WRAM_B,
    MI_WRAM_C,
} MIWram;

typedef enum {
    MI_WRAM_ARM9,
    MI_WRAM_ARM7,
    MI_WRAM_DSP,
} MIWramProc;

typedef void (*MINDmaCallback)(void *arg);

int func_02768cf8(MIWram wram, MIWramProc proc); // MI_FreeWram
int func_02769080(MIWram wram, MIWramProc proc); // MI_CancelWram
BOOL func_02768234(u32 ndmaNo);                  // MI_IsNDmaBusy
void func_02768270(u32 ndmaNo);                  // MI_StopNDma
// Receives a camera frame by NDMA, CAMERA_DmaRecvAsync's body
void func_02768378(u32 ndmaNo, void *dest, u32 unitWords, u32 length, u32 unk, MINDmaCallback callback, void *arg);

#endif // POKEBW2_TWL_MI_H
