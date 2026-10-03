#include "field/unity_tower.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov033_0217aa1c(GameSystem *gsys, s32 floor, u32 value) {
    GameData *gameData;
    u8 *unityTowerSave;
    SaveControl *saveControl;

    gameData = GSYS_GetGameData(gsys);
    unityTowerSave = GameData_GetUnityTowerSave(gameData);
    if (floor < 0xe9) {
        saveControl = GameData_GetSaveControl(gameData);
        func_ov033_0217aa50(getUnityTower_SurveySaveBlkAddrress(saveControl), unityTowerSave, floor, value);
    } else {
        UnityTowerSave_Init(unityTowerSave);
    }
}
