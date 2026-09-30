#ifndef POKEBW2_GFL_FADE_H
#define POKEBW2_GFL_FADE_H

#include "types.h"

// Screen fades. Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

// The screens a fade applies to. A negative brightness fades to white instead
#define FADE_ENGINE_A_BLACK 0x1
#define FADE_ENGINE_B_BLACK 0x2
#define FADE_ENGINE_A_WHITE 0x4
#define FADE_ENGINE_B_WHITE 0x8

void GFL_FadeSet(u32 mode, s32 brightnessStart, s32 brightnessEnd, s32 slowness);
BOOL GFL_FadeIsRunning(void);

#endif // POKEBW2_GFL_FADE_H
