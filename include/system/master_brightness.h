#ifndef POKEBW2_SYSTEM_MASTER_BRIGHTNESS_H
#define POKEBW2_SYSTEM_MASTER_BRIGHTNESS_H

#include "types.h"

// The master brightness of each engine's screen. The names are swan's

// Sets the brightness of the main engine (0) or the sub engine
void setBrightnessForEngine(u32 engine, s32 brightness);
// Sets the engine's brightness to 0
void killBrightnessEitherEngine(u32 engine);
void func_02027b64(u32 engine, u32 a1);

#endif // POKEBW2_SYSTEM_MASTER_BRIGHTNESS_H
