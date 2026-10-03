#include "field/field_menu.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL func_ov012_0215aa94(FieldMenuWork *work, FieldMenuWork *context) {
    GameData *gameData = GSYS_GetGameData(context->gameSystem);
    u32 value;

    switch (work->prevScreenId) {
    case 4:
        value = 6;
        break;
    case 0:
        value = 1;
        break;
    case 5:
        value = 0;
        break;
    case 1:
    case 2:
    case 3:
        value = (u8)context->screenId;
        break;
    default:
        goto finish;
    }
    GameData_SetLastSubscreen(gameData, value);
finish:
    return TRUE;
}
