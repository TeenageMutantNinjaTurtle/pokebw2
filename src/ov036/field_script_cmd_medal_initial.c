#include "field/field_script.h"
#include "field/medal.h"
#include "save/medal_box.h"
#include "system/game_data.h"

BOOL s02E1_MedalDiscoverInitial(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    SaveControl *save;
    MedalBox *box;
    HeapID heapId;

    gameData = FieldScriptEnv_GetGameData(env);
    save = GameData_GetSaveControl(gameData);
    box = SaveControl_GetMedalBox(save);
    heapId = FieldScriptEnv_GetHeapID(env);
    DiscoverInitialMedals(box, heapId);
    return FALSE;
}
