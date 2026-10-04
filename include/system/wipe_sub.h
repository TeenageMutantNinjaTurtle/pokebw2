#ifndef POKEBW2_SYSTEM_WIPE_SUB_H
#define POKEBW2_SYSTEM_WIPE_SUB_H

#include "types.h"
#include "system/wipe.h"

// The wipe patterns (wipe_sub.c): each runs a frame of a screen's wipe and returns TRUE when it is done. The even ones
// cover the screen and the odd ones uncover it

// Master brightness fades
BOOL func_02028004(WipeScreen *screen);
BOOL func_02028020(WipeScreen *screen);
// Scanline wipes
BOOL func_02028040(WipeScreen *screen);
BOOL func_0202807c(WipeScreen *screen);
BOOL func_020280b4(WipeScreen *screen);
BOOL func_020280f0(WipeScreen *screen);
// Window rectangles
BOOL func_02028128(WipeScreen *screen);
BOOL func_02028154(WipeScreen *screen);
// H-blank circles
BOOL func_02028180(WipeScreen *screen);
BOOL func_020281ac(WipeScreen *screen);
// Window rectangles
BOOL func_020281d8(WipeScreen *screen);
BOOL func_02028204(WipeScreen *screen);

#endif // POKEBW2_SYSTEM_WIPE_SUB_H
