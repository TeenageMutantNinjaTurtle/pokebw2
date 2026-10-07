#ifndef POKEBW2_TWL_MIC_H
#define POKEBW2_TWL_MIC_H

#include "types.h"

// A DSi-only setting of the microphone's input in the LTD autoload, which takes a table of six coefficients, perhaps
// a filter. It keeps its default name until the LTD autoload is analyzed
void func_027047c0(int unk, const u16 *coefficients);

#endif // POKEBW2_TWL_MIC_H
