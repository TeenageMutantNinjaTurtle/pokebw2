#ifndef POKEBW2_GFL_WIPE_H
#define POKEBW2_GFL_WIPE_H

#include "types.h"
#include "gfl/heap.h"

// Screen wipes, which fade the screens in a pattern

void GFL_WipeSet(u32 a0, u32 a1, u32 a2, u32 a3, s32 frames, u32 a5, HeapID heapId);
BOOL GFL_WipeIsFinished(void);
// Turns off an engine's windows, and sets an engine's master brightness to white for 0x7fff and to black for any
// other color, 0xffff being the wipe's color
void func_02027b4c(u32 engine);
void func_02027b64(u32 engine, u32 color);

#endif // POKEBW2_GFL_WIPE_H
