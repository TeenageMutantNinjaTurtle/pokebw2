#include "field/field.h"
#include "field/field_money_window.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *func_ov033_02177d28(GameSystem *gameSystem) {
    GameData *gameData;
    DreamWorldSave *items;
    GameEvent *event;
    FieldMoneyWindowEvent *work;

    gameData = GSYS_GetGameData(gameSystem);
    items = getDreamWorldStuffAddress(GameData_GetSaveControl(gameData));
    event = GameEvent_Create(gameSystem, NULL, func_ov033_02177b08, sizeof(FieldMoneyWindowEvent));
    work = GameEvent_GetData(event);
    work->field = GSYS_GetField(gameSystem);
    work->index = 0;
    work->entries = func_ov033_02177bd4(gameData, Field_GetHeapID(work->field), items, &work->count);
    return event;
}
