#include "field/app_call.h"
#include "save/bag.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov012_0215b754(FieldAppCallWork *work) {
    GameSystem *gsys = *work->gameSystemPtr;
    GameData *gameData = GSYS_GetGameData(gsys);
    void *data = func_0201734c(gameData);

    func_020088ec(data, 0);
}
