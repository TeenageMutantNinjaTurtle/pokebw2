#ifndef POKEBW2_GFL_INPUT_H
#define POKEBW2_GFL_INPUT_H

#include "types.h"

#define PAD_BUTTON_A 0x1
#define PAD_BUTTON_B 0x2
#define PAD_KEY_RIGHT 0x10
#define PAD_KEY_LEFT 0x20

// Called on a soft reset, before the game restarts
typedef void (*SoftResetCallback)(void *work);

u32 GCTX_HIDGetHeldKeys(void);
void GCTX_HIDSetSoftResetCallback(SoftResetCallback callback, void *work);
u32 GCTX_HIDGetPressedKeys(void);
// The touch screen, read through the same instance as the keys: whether it is touched, and whether it was touched
// this frame
BOOL func_0203da2c(void);
BOOL func_0203da48(void);

#endif // POKEBW2_GFL_INPUT_H
