#ifndef POKEBW2_APP_BOX2_OBJ_H
#define POKEBW2_APP_BOX2_OBJ_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The PC box's actors. The ROM doesn't name this file; box2_obj.c is a guess after box2_main.c. None of these
// functions has a name yet

// Sets an actor's animation
void func_ov255_021cf5e4(Box2AppWork *app, u32 id, u16 anim);
void func_ov255_021cf608(Box2AppWork *app, u32 id, u32 palette);
BOOL func_ov255_021cf628(Box2AppWork *app, u32 id);
void func_ov255_021cf63c(Box2AppWork *app, u32 id, BOOL a2);
void func_ov255_021cf6c8(Box2AppWork *app, u32 id, s16 x, s16 y, u32 a4);
// Where an actor is
void func_ov255_021cf6ec(Box2AppWork *app, u32 id, s16 *x, s16 *y, u32 a4);
void func_ov255_021cf9c8(Box2SysWork *syswk, u32 tray);
void func_ov255_021cfc20(Box2SysWork *syswk, u32 tray, u32 pos, u32 id);
// Where an icon at a position is
void func_ov255_021cfcdc(u32 pos, s16 *x, s16 *y, u32 mode);
void func_ov255_021cff58(Box2AppWork *app, u32 iconPos, u32 a2);
void func_ov255_021cffa8(Box2AppWork *app, u32 iconPos, u32 pos, BOOL a3);
void func_ov255_021d045c(Box2AppWork *app, u32 pos, u32 width, u32 height);
void func_ov255_021d06a4(Box2SysWork *syswk, Box2PokeInfo *info, u32 a2);
void func_ov255_021d0a28(Box2AppWork *app, Box2PokeInfo *info);
void func_ov255_021d0b4c(Box2AppWork *app, s16 x, s16 y);
void func_ov255_021d0b64(Box2AppWork *app, u32 pos, u32 mode);
void func_ov255_021d0b98(Box2AppWork *app, u32 pos, u32 mode);
void func_ov255_021d0d10(Box2AppWork *app);
void func_ov255_021d121c(Box2SysWork *syswk, u32 pos);
void func_ov255_021d1284(Box2AppWork *app, u32 a1);
void func_ov255_021d11a4(Box2SysWork *syswk, u32 a1);
void func_ov255_021d13c4(Box2SysWork *syswk);
void func_ov255_021d1474(Box2AppWork *app);
void func_ov255_021d1530(Box2AppWork *app, u32 a1, s16 *x, s16 *y);
void func_ov255_021d1570(Box2SysWork *syswk, u32 tray);
void func_ov255_021d15f4(Box2SysWork *syswk, u32 tray);
void func_ov255_021d198c(Box2SysWork *syswk, u32 a1);
void func_ov255_021d1a1c(Box2SysWork *syswk);
void func_ov255_021d1ac8(Box2SysWork *syswk, u32 a1, u32 a2);
void func_ov255_021d1af8(Box2SysWork *syswk, u8 a1, u8 a2, u8 a3, u8 a4);
void func_ov255_021d1d68(Box2AppWork *app, u32 frame, BOOL a2);
BOOL func_ov255_021d1d78(Box2AppWork *app, u32 frame);
void func_ov255_021d1d88(Box2AppWork *app, u32 frame, u32 dir);
void func_ov255_021d22e0(Box2AppWork *app, u32 a1);
void func_ov255_021d22fc(Box2AppWork *app, s16 x, s16 y);

#endif // POKEBW2_APP_BOX2_OBJ_H
