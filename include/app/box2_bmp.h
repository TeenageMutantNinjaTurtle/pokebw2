#ifndef POKEBW2_APP_BOX2_BMP_H
#define POKEBW2_APP_BOX2_BMP_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The PC box's windows. The ROM doesn't name this file; box2_bmp.c is a guess after box2_main.c. None of these
// functions has a name yet

void func_ov255_021cdf18(Box2SysWork *syswk);
void func_ov255_021cdf5c(Box2SysWork *syswk);
// Sends the characters of the printed windows to VRAM
void func_ov255_021cdf9c(Box2AppWork *app);
void func_ov255_021cdfe8(Box2AppWork *app);
void func_ov255_021ce140(Box2SysWork *syswk);
void func_ov255_021ce198(Box2SysWork *syswk);
void func_ov255_021ce798(Box2SysWork *syswk, Box2PokeInfo *info);
void func_ov255_021ce81c(Box2AppWork *app);
void func_ov255_021ced54(Box2SysWork *syswk, u32 tray, u32 frame);
void func_ov255_021ced6c(Box2SysWork *syswk);
void func_ov255_021ced8c(Box2SysWork *syswk, u32 a1);

// Opens a menu of items
void func_ov255_021ceed0(Box2SysWork *syswk, const Box2MenuItem *items, u32 count);
void func_ov255_021cefa4(Box2AppWork *app, u32 msgId);
void func_ov255_021cf1ac(Box2SysWork *syswk, u32 pos, u32 a2, u32 a3);
void func_ov255_021cf208(Box2SysWork *syswk, u32 a1, u32 a2);
void func_ov255_021cf270(Box2SysWork *syswk, u32 msg, u32 a2);
void func_ov255_021cf2cc(Box2SysWork *syswk, u32 a1);
void func_ov255_021cf2e8(Box2SysWork *syswk);

#endif // POKEBW2_APP_BOX2_BMP_H
