#ifndef POKEBW2_GFL_DWC_RAP_H
#define POKEBW2_GFL_DWC_RAP_H

#include "types.h"
#include "gfl/heap.h"

// The Wi-Fi connection of the network library (dwc_rap.c and dwc_rapcommon.c, in overlay 11)

void func_ov011_021516a0(BOOL a0);
void func_ov011_021520a0(u32 a0, u32 size, HeapID heapId);
// Sets the function called when the connection is lost
void func_ov011_02152040(void (*func)(void *work, int a1, int code), void *work);
// Sets a function asked about connection events, with its work
void func_ov011_0215205c(u32 (*func)(void *work, int a1, int event), void *work);
void func_ov011_02152158(void);
void func_ov011_02152404(u32 a0, u32 a1);

#endif // POKEBW2_GFL_DWC_RAP_H
