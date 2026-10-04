#ifndef POKEBW2_APP_BOX2_BMP_H
#define POKEBW2_APP_BOX2_BMP_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The PC box's windows. The ROM doesn't name this file; box2_bmp.c is a guess after box2_main.c. None of these
// functions has a name yet

// Creates and frees the windows
void func_ov255_021cdf18(Box2SysWork *syswk);
void func_ov255_021cdf5c(Box2SysWork *syswk);
// Sends the characters of the printed windows to VRAM
void func_ov255_021cdf9c(Box2AppWork *app);
// Runs the print queue, and sends the characters of the windows it has finished
void func_ov255_021cdfe8(Box2AppWork *app);
void func_ov255_021ce140(Box2SysWork *syswk);
void func_ov255_021ce198(Box2SysWork *syswk);
// Shows a Pokémon's data on the upper screen, or clears it
void func_ov255_021ce798(Box2SysWork *syswk, Box2PokeInfo *info);
void func_ov255_021ce81c(Box2AppWork *app);
// Makes the frames of the menu's buttons and of the buttons on the lower screen
void func_ov255_021cec40(Box2AppWork *app);
void func_ov255_021cec98(Box2SysWork *syswk);
void func_ov255_021cecc4(Box2SysWork *syswk);
// Shows a box's name on a text object
void func_ov255_021ced54(Box2SysWork *syswk, u32 tray, u32 index);
void func_ov255_021ced6c(Box2SysWork *syswk);
void func_ov255_021ced8c(Box2SysWork *syswk, u32 mv);
// Shows how many Pokémon a box holds on a text object
void func_ov255_021cedb4(Box2SysWork *syswk, u32 tray, u32 index);
void func_ov255_021ceea4(Box2SysWork *syswk);
// Opens a menu of items
void func_ov255_021ceed0(Box2SysWork *syswk, const Box2MenuItem *items, u32 count);
void func_ov255_021cefa4(Box2AppWork *app, u32 index);
void func_ov255_021cefb8(Box2AppWork *app, u32 index);
// The messages of the message window
void func_ov255_021cf028(Box2SysWork *syswk, u32 index);
void func_ov255_021cf044(Box2SysWork *syswk, u32 item, u32 index);
void func_ov255_021cf068(Box2SysWork *syswk, u32 index);
void func_ov255_021cf074(Box2SysWork *syswk, u32 index);
void func_ov255_021cf080(Box2SysWork *syswk, u32 item, u32 index);
void func_ov255_021cf0a4(Box2SysWork *syswk, u32 index);
void func_ov255_021cf0b0(Box2SysWork *syswk, u32 item, u32 index);
void func_ov255_021cf108(Box2SysWork *syswk, u32 index);
void func_ov255_021cf114(Box2SysWork *syswk, u32 type, u32 index);
void func_ov255_021cf17c(Box2SysWork *syswk, u32 type, u32 index);
void func_ov255_021cf1ac(Box2SysWork *syswk, u32 pos, u32 type, u32 index);
void func_ov255_021cf208(Box2SysWork *syswk, u32 type, u32 index);
void func_ov255_021cf270(Box2SysWork *syswk, u32 type, u32 index);
void func_ov255_021cf2a4(Box2SysWork *syswk);
void func_ov255_021cf2cc(Box2SysWork *syswk, u32 a1);
// Shows how many Pokémon the picked range holds
void func_ov255_021cf2e8(Box2SysWork *syswk);

#endif // POKEBW2_APP_BOX2_BMP_H
