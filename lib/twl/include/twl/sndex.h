#ifndef POKEBW2_TWL_SNDEX_H
#define POKEBW2_TWL_SNDEX_H

#include "types.h"

// TwlSDK's sound extensions for the DSi (SNDEX). func_02704364 is SNDEX_Init, by its code: it sets up the PXI channel
// to the ARM7's SNDEX and its mutex, once. The game calls it only on a DSi
void func_02704364(void);

#endif // POKEBW2_TWL_SNDEX_H
