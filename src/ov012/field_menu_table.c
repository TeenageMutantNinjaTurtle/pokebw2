#include "field/field.h"
#include "field/field_menu.h"
#include "field/subscreen.h"
#include "system/game_data.h"
#include "system/game_system.h"

u32 func_ov012_0215aa68(u32 index) {
    return data_ov012_0216cb74[index];
}

BOOL func_ov012_0215aa74(FieldMenuWork *work, FieldMenuWork *context) {
    FieldSubscreen *subscreen = Field_GetSubscreen(context->field);

    if (work->prevScreenId == 0) {
        func_ov036_0219886c(subscreen, context->unk10);
    }
    return TRUE;
}

BOOL func_ov012_0215aa90(void) {
    return TRUE;
}

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