#ifndef POKEBW2_FIELD_SHORTCUT_MENU_H
#define POKEBW2_FIELD_SHORTCUT_MENU_H

#include "types.h"
#include "struct_decls.h"

struct ShortcutMenuWork {
    GameEvent *event;
    GameSystem *gameSystem;
    Field *field;
    void *app;
    u32 unk10;
    u32 unk14;
    u32 done;
    u32 state;
};

struct ShortcutMenuContext {
    u8 unk00[0x10];
    u32 action;
    s32 param;
    u8 unk18[0x10];
    u32 type;
    u32 kind;
};

BOOL IsExistAnyYShortcut(GameSystem *gsys);
BOOL CheckAnyRibbon(ShortcutMenuWork *work);
u32 ShortcutMenu_SetKeyItemID(ShortcutMenuContext *context, u32 item);
BOOL ShortcutMenu_GetActionFromKeyItem(s32 item, u32 *action, u32 *invalid);
void func_ov012_0215b284(u32 arg0, ShortcutMenuWork *work);
BOOL func_ov012_0215b2d0(ShortcutMenuWork *work);
BOOL func_ov012_0215b32c(ShortcutMenuContext *context, ShortcutMenuWork *work);
BOOL func_ov012_0215b39c(u32 unused, ShortcutMenuWork *work);

void func_ov036_02187834(void);
void func_ov036_02187888(void);
void *func_ov036_021bedd8(GameData *gameData, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
void func_ov036_021bf004(void *app);
u32 func_ov036_021bf198(void *app);

#endif // POKEBW2_FIELD_SHORTCUT_MENU_H
