#ifndef POKEBW2_GFL_BRIGHTNESS_H
#define POKEBW2_GFL_BRIGHTNESS_H

#include "types.h"

// Brightness blending of the screens, named after pokeplatinum's brightness controller, which works the same way

#define BRIGHTNESS_MAIN_SCREEN 1
#define BRIGHTNESS_SUB_SCREEN 2
#define BRIGHTNESS_BOTH_SCREENS 3

void BrightnessController_SetScreenBrightness(s16 brightness, u32 planes, u32 screens);
void BrightnessController_StartTransition(u8 steps, s16 targetBrightness, s16 startBrightness, u32 planes,
                                          u32 screens);
BOOL BrightnessController_IsTransitionComplete(u32 screens);

#endif // POKEBW2_GFL_BRIGHTNESS_H
