#ifndef POKEBW2_APP_BOX2_OBJ_H
#define POKEBW2_APP_BOX2_OBJ_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The first actor of the Pokémon icons, one per entry of pokeIconId
#define BOX2_ACTOR_POKEICON 55

// The PC box's actors. The ROM doesn't name this file; box2_obj.c is a guess after box2_main.c. None of these
// functions has a name yet

// Sets an actor's animation
void func_ov255_021cf3c0(Box2SysWork *syswk);
void func_ov255_021cf414(Box2AppWork *app);
void func_ov255_021cf5b0(Box2AppWork *app);
// Sets an actor's animation
void func_ov255_021cf5e4(Box2AppWork *app, u32 id, u32 anim);
void func_ov255_021cf608(Box2AppWork *app, u32 id, u32 anim);
BOOL func_ov255_021cf628(Box2AppWork *app, u32 id);
void func_ov255_021cf63c(Box2AppWork *app, u32 id, BOOL visible);
BOOL func_ov255_021cf658(Box2AppWork *app, u32 id);
void func_ov255_021cf6c8(Box2AppWork *app, u32 id, s16 x, s16 y, u16 surface);
// Where an actor is
void func_ov255_021cf6ec(Box2AppWork *app, u32 id, s16 *x, s16 *y, u16 surface);
void func_ov255_021cf9c8(Box2SysWork *syswk, u32 tray);
void func_ov255_021cfc74(Box2SysWork *syswk);
void func_ov255_021cfc90(Box2SysWork *syswk);
void func_ov255_021cfc20(Box2SysWork *syswk, u32 tray, u32 pos, u32 id);
// Where an icon at a position is
void func_ov255_021cfcdc(u32 pos, s16 *x, s16 *y, u32 mode);
void func_ov255_021cfd34(Box2SysWork *syswk, u32 a1);
void func_ov255_021cfdb0(Box2SysWork *syswk);
void func_ov255_021cff58(Box2AppWork *app, u32 iconPos, u32 a2);
void func_ov255_021cfff4(Box2SysWork *syswk, s32 mv);
void func_ov255_021cffa8(Box2AppWork *app, u32 iconPos, u32 pos, BOOL a3);
void func_ov255_021d0374(Box2SysWork *syswk, u32 pos, u32 a2, u32 a3);
void func_ov255_021d045c(Box2AppWork *app, u32 pos, u32 width, u32 height);
void func_ov255_021d06a4(Box2SysWork *syswk, Box2PokeInfo *info, u32 a2);
void func_ov255_021d0310(Box2SysWork *syswk, u32 a1, u32 a2);
void func_ov255_021d052c(Box2SysWork *syswk);
void func_ov255_021d0a28(Box2AppWork *app, Box2PokeInfo *info);
void func_ov255_021d0b08(Box2AppWork *app, BOOL a1);
void func_ov255_021d0b4c(Box2AppWork *app, s16 x, s16 y);
void func_ov255_021d0b64(Box2AppWork *app, u32 pos, u32 mode);
void func_ov255_021d0b98(Box2AppWork *app, u32 pos, u32 mode);
void func_ov255_021d0bc8(Box2AppWork *app);
void func_ov255_021d0cf4(Box2AppWork *app);
void func_ov255_021d0d10(Box2AppWork *app);
void func_ov255_021d121c(Box2SysWork *syswk, u32 pos);
void func_ov255_021d1284(Box2AppWork *app, u32 a1);
void func_ov255_021d0f88(Box2SysWork *syswk, u32 a1, u32 a2);
void func_ov255_021d0ff8(Box2SysWork *syswk, u32 anim);
void func_ov255_021d101c(Box2SysWork *syswk, u32 a1);
void func_ov255_021d11a4(Box2SysWork *syswk, u32 a1);
void func_ov255_021d1348(Box2AppWork *app, u32 a1);
void func_ov255_021d13c4(Box2SysWork *syswk);
void func_ov255_021d13d8(Box2SysWork *syswk, s32 mv);
void func_ov255_021d1474(Box2AppWork *app);
void func_ov255_021d1530(Box2AppWork *app, u32 a1, s16 *x, s16 *y);
void func_ov255_021d1570(Box2SysWork *syswk, u32 tray);
void func_ov255_021d15f4(Box2SysWork *syswk, u32 tray);
void func_ov255_021d15dc(Box2SysWork *syswk);
void func_ov255_021d17f8(Box2SysWork *syswk, s16 mv);
void func_ov255_021d198c(Box2SysWork *syswk, u32 a1);
void func_ov255_021d1a1c(Box2SysWork *syswk);
void func_ov255_021d1ac8(Box2SysWork *syswk, u32 a1, u32 a2);
void func_ov255_021d1af8(Box2SysWork *syswk, u8 a1, u8 a2, u8 a3, u8 a4);
void func_ov255_021d1d68(Box2AppWork *app, u32 frame, BOOL a2);
BOOL func_ov255_021d1d78(Box2AppWork *app, u32 frame);
void func_ov255_021d1d88(Box2AppWork *app, u32 frame, u32 dir);
void func_ov255_021d1db0(Box2AppWork *app, s32 mv);
void func_ov255_021d1e38(Box2SysWork *syswk);
void func_ov255_021d1e2c(Box2SysWork *syswk, u32 a1);
void func_ov255_021d208c(Box2SysWork *syswk, u32 start, u32 end, u32 a3);
void func_ov255_021d21a4(u32 start, u32 end, u32 *width, u32 *height);
// The top left of a range
u8 func_ov255_021d21ec(u32 start, u32 end);
// The top left of a range in the party
u8 func_ov255_021d2210(u32 start, u32 end);
void func_ov255_021d2238(Box2AppWork *app, u32 pos, u32 width, u32 height, u32 a4);
void func_ov255_021d22e0(Box2AppWork *app, u32 a1);
void func_ov255_021d22fc(Box2AppWork *app, s16 x, s16 y);
void func_ov255_021d232c(Box2SysWork *syswk, u32 a1);

#endif // POKEBW2_APP_BOX2_OBJ_H
