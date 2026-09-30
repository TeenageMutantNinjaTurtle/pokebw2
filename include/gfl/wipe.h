#ifndef POKEBW2_GFL_WIPE_H
#define POKEBW2_GFL_WIPE_H

#include "types.h"
#include "gfl/heap.h"

// Screen wipes, which fade the screens in a pattern

void GFL_WipeSet(u32 a0, u32 a1, u32 a2, u32 a3, s32 frames, u32 a5, HeapID heapId);
BOOL GFL_WipeIsFinished(void);

#endif // POKEBW2_GFL_WIPE_H
