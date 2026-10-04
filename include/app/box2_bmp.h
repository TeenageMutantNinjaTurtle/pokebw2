#ifndef POKEBW2_APP_BOX2_BMP_H
#define POKEBW2_APP_BOX2_BMP_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The PC box's windows. The ROM doesn't name this file; box2_bmp.c is a guess after box2_main.c. None of these
// functions has a name yet

// Sends the characters of the printed windows to VRAM
void func_ov255_021cdf9c(Box2AppWork *app);
void func_ov255_021ce798(Box2SysWork *syswk, Box2PokeInfo *info);
void func_ov255_021ce81c(Box2AppWork *app);
void func_ov255_021ced54(Box2SysWork *syswk, u32 tray, u32 frame);
void func_ov255_021ced8c(Box2SysWork *syswk, u32 a1);

#endif // POKEBW2_APP_BOX2_BMP_H
