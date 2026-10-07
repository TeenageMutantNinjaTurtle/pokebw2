#ifndef POKEBW2_APP_BOX2_OBJ_H
#define POKEBW2_APP_BOX2_OBJ_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The PC box's actors, in box2_obj.c. Names are ours; none of these functions has a name yet

// The actors, by ID: those of sActorData first, then these groups
#define BOX2_ACTOR_TYPE_ICON 32
#define BOX2_ACTOR_TRAY_ICON 49
#define BOX2_ACTOR_POKEICON 55
#define BOX2_ACTOR_ITEM_OUTLINE 121
#define BOX2_ACTOR_RANGE_DOT 129
#define BOX2_ACTOR_MAX 145
// How many type icons and copies of the item icon that outline it there are
#define BOX2_TYPE_ICON_MAX 17
#define BOX2_ITEM_OUTLINE_MAX 8

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
void func_ov255_021cfc20(Box2SysWork *syswk, u32 tray, u32 pos, u32 id);
void func_ov255_021cfc74(Box2SysWork *syswk);
void func_ov255_021cfc90(Box2SysWork *syswk);
// Where an icon at a position is
void func_ov255_021cfcdc(u32 pos, s16 *x, s16 *y, u32 mode);
void func_ov255_021cfd34(Box2SysWork *syswk, BOOL hideGet);
void func_ov255_021cfdb0(Box2SysWork *syswk);
void func_ov255_021cfe0c(Box2SysWork *syswk);
void func_ov255_021cfe78(Box2SysWork *syswk);
void func_ov255_021cfee4(Box2SysWork *syswk);
void func_ov255_021cff58(Box2AppWork *app, u32 iconPos, BOOL put);
void func_ov255_021cffa8(Box2AppWork *app, u32 iconPos, u32 pos, BOOL put);
void func_ov255_021cfff4(Box2SysWork *syswk, s32 mv);
void func_ov255_021d00d4(Box2SysWork *syswk);
void func_ov255_021d013c(Box2PokeFreeWork *wk);
BOOL func_ov255_021d0184(Box2PokeFreeWork *wk);
BOOL func_ov255_021d01c8(Box2PokeFreeWork *wk);
void func_ov255_021d0214(Box2PokeFreeWork *wk);
void func_ov255_021d0228(Box2PokeFreeWork *wk);
void func_ov255_021d0310(Box2SysWork *syswk, u32 flags, BOOL blend);
void func_ov255_021d0350(Box2AppWork *app, u32 iconPos, BOOL blend);
void func_ov255_021d0374(Box2SysWork *syswk, u32 pos, int width, int height);
void func_ov255_021d045c(Box2AppWork *app, u32 pos, int width, int height);
void func_ov255_021d052c(Box2SysWork *syswk);
void func_ov255_021d0640(Box2SysWork *syswk, u32 tray, u32 pos);
void func_ov255_021d06a4(Box2SysWork *syswk, Box2PokeInfo *info, u32 id);
void func_ov255_021d0a28(Box2AppWork *app, Box2PokeInfo *info);
void func_ov255_021d0a94(Box2AppWork *app, u16 item);
void func_ov255_021d0b08(Box2AppWork *app, BOOL affine);
void func_ov255_021d0b4c(Box2AppWork *app, s16 x, s16 y);
void func_ov255_021d0b64(Box2AppWork *app, u32 pos, u32 mode);
void func_ov255_021d0b98(Box2AppWork *app, u32 pos, u32 mode);
void func_ov255_021d0bc8(Box2AppWork *app);
void func_ov255_021d0cf4(Box2AppWork *app);
void func_ov255_021d0d10(Box2AppWork *app);
void func_ov255_021d0f88(Box2SysWork *syswk, u32 set, BOOL visible);
void func_ov255_021d0ff8(Box2SysWork *syswk, u32 anim);
void func_ov255_021d101c(Box2SysWork *syswk, BOOL show);
void func_ov255_021d1048(Box2SysWork *syswk);
void func_ov255_021d1054(Box2SysWork *syswk, u32 pos);
void func_ov255_021d11a4(Box2SysWork *syswk, BOOL visible);
void func_ov255_021d121c(Box2SysWork *syswk, u32 pos);
void func_ov255_021d1284(Box2AppWork *app, u32 pos);
void func_ov255_021d1348(Box2AppWork *app, BOOL visible);
void func_ov255_021d1364(Box2SysWork *syswk);
void func_ov255_021d13c4(Box2SysWork *syswk);
void func_ov255_021d13d8(Box2SysWork *syswk, s32 mv);
void func_ov255_021d1474(Box2AppWork *app);
void func_ov255_021d1530(Box2AppWork *app, u32 row, s16 *x, s16 *y);
void func_ov255_021d1570(Box2SysWork *syswk, u32 tray);
void func_ov255_021d15dc(Box2SysWork *syswk);
void func_ov255_021d15f4(Box2SysWork *syswk, u32 tray);
void func_ov255_021d17f8(Box2SysWork *syswk, s16 mv);
void func_ov255_021d198c(Box2SysWork *syswk, s32 mv);
void func_ov255_021d1a1c(Box2SysWork *syswk);
void func_ov255_021d1ac8(Box2SysWork *syswk, u32 index, BOOL show);
void func_ov255_021d1af8(Box2SysWork *syswk, u8 button1, u8 button2, u8 button3, u8 button4);
void func_ov255_021d1c00(Box2SysWork *syswk);
void func_ov255_021d1d68(Box2AppWork *app, u32 index, BOOL visible);
BOOL func_ov255_021d1d78(Box2AppWork *app, u32 index);
void func_ov255_021d1d88(Box2AppWork *app, u32 index, u32 dir);
void func_ov255_021d1db0(Box2AppWork *app, s32 mv);
void func_ov255_021d1e2c(Box2SysWork *syswk, u32 anm);
void func_ov255_021d1e38(Box2SysWork *syswk);
void func_ov255_021d208c(Box2SysWork *syswk, int start, int end, u32 mode);
void func_ov255_021d21a4(int start, int end, u32 *width, u32 *height);
// The top left of a range
u32 func_ov255_021d21ec(int start, int end);
// The top left of a range in the party
u32 func_ov255_021d2210(int start, int end);
void func_ov255_021d2238(Box2AppWork *app, u32 pos, u32 width, u32 height, BOOL put);
void func_ov255_021d22e0(Box2AppWork *app, BOOL visible);
void func_ov255_021d22fc(Box2AppWork *app, s16 x, s16 y);
void func_ov255_021d232c(Box2SysWork *syswk, BOOL visible);

#endif // POKEBW2_APP_BOX2_OBJ_H
