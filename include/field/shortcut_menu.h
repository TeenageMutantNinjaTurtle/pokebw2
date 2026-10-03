#ifndef POKEBW2_FIELD_SHORTCUT_MENU_H
#define POKEBW2_FIELD_SHORTCUT_MENU_H

#include "types.h"
#include "struct_decls.h"

struct ShortcutMenuWork {
    GameEvent *event;
    GameSystem *gameSystem;
    u8 unk08[0x1C];
};

BOOL IsExistAnyYShortcut(GameSystem *gsys);
BOOL CheckAnyRibbon(ShortcutMenuWork *work);

#endif // POKEBW2_FIELD_SHORTCUT_MENU_H
