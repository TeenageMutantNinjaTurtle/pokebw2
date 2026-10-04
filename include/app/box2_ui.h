#ifndef POKEBW2_APP_BOX2_UI_H
#define POKEBW2_APP_BOX2_UI_H

#include "types.h"
#include "struct_decls.h"

// The PC box's cursor and touch handling, in box2_ui.c. None of these functions has a name yet

// What func_ov255_021d2770 returns besides a position
#define CURSORMOVE_NONE 0xffffffff
#define CURSORMOVE_CANCEL 0xfffffffe
#define CURSORMOVE_CURSOR_MOVE 0xfffffffd
#define CURSORMOVE_CURSOR_ON 0xfffffffc
#define CURSORMOVE_SCROLL_R 0xfffffffb
#define CURSORMOVE_SCROLL_L 0xfffffffa
#define CURSORMOVE_UNK_7 0xfffffff9
#define CURSORMOVE_UNK_8 0xfffffff8

void func_ov255_021d23d8(Box2SysWork *syswk);
void func_ov255_021d2478(Box2SysWork *syswk, u32 a1, u32 pos);
void func_ov255_021d24f8(Box2SysWork *syswk, u32 pos);
void func_ov255_021d24e0(Box2SysWork *syswk);
u32 func_ov255_021d2770(Box2SysWork *syswk);
// The party's version of func_ov255_021d2770
u32 func_ov255_021d2a64(Box2SysWork *syswk);
void func_ov255_021d28c4(Box2SysWork *syswk, u32 pos);
u32 func_ov255_021d29e8(Box2SysWork *syswk);
u32 func_ov255_021d2b88(Box2SysWork *syswk);
void func_ov255_021d32d4(Box2AppWork *app, u32 pos, u32 curPos);
// The position at a touch
u32 func_ov255_021d34f0(u32 x, u32 y);
u32 func_ov255_021d34d0(void);
u32 func_ov255_021d34e0(void);
u32 func_ov255_021d3504(void);
u32 func_ov255_021d3514(void);
u32 func_ov255_021d3524(void);
u32 func_ov255_021d3534(void);
u32 func_ov255_021d3544(void);
BOOL func_ov255_021d3554(u32 *x, u32 *y);
BOOL func_ov255_021d357c(u32 *x, u32 *y);
int func_ov255_021d35a4(u32 x, u32 y);
// The position of the box list at a touch, or BOX2_GET_NONE
u32 func_ov255_021d35c4(u32 x, u32 y);
BOOL func_ov255_021d35e8(void);
BOOL func_ov255_021d3604(void);
u32 func_ov255_021d3620(void);
BOOL func_ov255_021d3630(void);

#endif // POKEBW2_APP_BOX2_UI_H
