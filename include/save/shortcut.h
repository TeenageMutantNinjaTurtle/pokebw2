#ifndef POKEBW2_SAVE_SHORTCUT_H
#define POKEBW2_SAVE_SHORTCUT_H

#include "types.h"
#include "struct_decls.h"

ShortcutSave *SaveControl_GetShortcutSave(SaveControl *save);
u32 ShortcutSave_GetShortcutCount(ShortcutSave *shortcutSave);
u8 ShortcutSave_GetRegistItem(ShortcutSave *shortcutSave, u32 index);
// Replaces shortcut 7 (DNA Splicers that fuse) with 8 (that separate), or 8 with 7
void func_0200cc34(ShortcutSave *shortcutSave, u32 shortcut);

#endif // POKEBW2_SAVE_SHORTCUT_H
