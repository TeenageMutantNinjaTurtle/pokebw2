#ifndef POKEBW2_APP_BOX2_UI_H
#define POKEBW2_APP_BOX2_UI_H

#include "types.h"
#include "struct_decls.h"

// The PC box's cursor and touch handling, in box2_ui.c. None of these functions has a name yet

void func_ov255_021d2478(Box2SysWork *syswk, u32 a1, u32 pos);
void func_ov255_021d24f8(Box2SysWork *syswk, u32 pos);
// The position at a touch
u32 func_ov255_021d34f0(u32 x, u32 y);
u32 func_ov255_021d3534(void);
u32 func_ov255_021d3544(void);
// The position of the box list at a touch, or BOX2_GET_NONE
u32 func_ov255_021d35c4(u32 x, u32 y);
BOOL func_ov255_021d35e8(void);
BOOL func_ov255_021d3604(void);
u32 func_ov255_021d3620(void);
BOOL func_ov255_021d3630(void);

#endif // POKEBW2_APP_BOX2_UI_H
