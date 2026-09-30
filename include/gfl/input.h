#ifndef POKEBW2_GFL_INPUT_H
#define POKEBW2_GFL_INPUT_H

#include "types.h"

#define PAD_BUTTON_A 0x1
#define PAD_BUTTON_B 0x2
#define PAD_BUTTON_SELECT 0x4
#define PAD_BUTTON_START 0x8
#define PAD_KEY_RIGHT 0x10
#define PAD_KEY_LEFT 0x20
#define PAD_KEY_UP 0x40
#define PAD_KEY_DOWN 0x80
#define PAD_BUTTON_R 0x100
#define PAD_BUTTON_L 0x200
#define PAD_BUTTON_X 0x400
#define PAD_BUTTON_Y 0x800

// Called on a soft reset, before the game restarts
typedef void (*SoftResetCallback)(void *work);

u32 GCTX_HIDGetHeldKeys(void);
void GCTX_HIDSetSoftResetCallback(SoftResetCallback callback, void *work);
u32 GCTX_HIDGetPressedKeys(void);
// The touch screen, read through the same instance as the keys: whether it is touched, and whether it was touched
// this frame
BOOL func_0203da2c(void);
BOOL func_0203da48(void);

// A rectangle of the touch screen, in pixels. A table of them ends with top TOUCH_RECT_END
typedef struct {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} TouchRect;

#define TOUCH_RECT_END 0xff
#define TOUCH_RECT_NONE (-1)

// Returns the rectangle that was touched this frame, or TOUCH_RECT_NONE
s32 func_0203da0c(const TouchRect *rects);

#endif // POKEBW2_GFL_INPUT_H
