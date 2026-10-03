#include "field/event_abyssal_ruins.h"
#include "field/field.h"
#include "field/field_script_event.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

GameEvent *CheckAbyssalRuinsStepEvent(GameSystem *gsys, Field *field) {
    GameData *gameData;
    SaveControl *save;
    PlayerSave *playerSave;
    u16 stepCount;
    u32 i;

    gameData = GSYS_GetGameData(gsys);
    save = GameData_GetSaveControl(gameData);
    playerSave = SaveControl_GetPlayerSave(save);
    stepCount = PlayerSave_GetAbyssalRuinsStepCounter(playerSave);
    for (i = 0; i < 5; i++) {
        if (stepCount == ABYSSAL_RUINS_DULL_SOUND_SCRIPTS[i * 2]) {
            return EventScriptCall_Create(gsys, data_ov033_0217c522[i * 2], NULL, Field_GetHeapID(field));
        }
    }
    if (stepCount > 500) {
        return EventScriptCall_Create(gsys, 0x28eb, NULL, Field_GetHeapID(field));
    }
    return NULL;
}
