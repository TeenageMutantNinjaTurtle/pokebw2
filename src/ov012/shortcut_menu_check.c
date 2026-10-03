#include "field/shortcut_menu.h"
#include "save/shortcut.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL IsExistAnyYShortcut(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    SaveControl *save = GameData_GetSaveControl(gameData);
    ShortcutSave *shortcutSave = SaveControl_GetShortcutSave(save);

    return ShortcutSave_GetShortcutCount(shortcutSave) != 0;
}
