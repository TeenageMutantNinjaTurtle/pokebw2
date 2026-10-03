#include "field/unity_tower.h"
#include "save/player_info.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

u32 func_ov033_0217aac4(u8 *output, u32 index) {
    u32 result;

    result = 0xff;
    if (index < 5 && index < output[1]) {
        output += index;
        result = output[8];
    }
    return result;
}

u32 func_ov033_0217aad8(WordSet *wordSet, GameSystem *gsys, u8 *save, s32 index, u32 param) {
    GameData *gameData;
    UnityTowerSurveySave *surveySave;
    PlayerInfo *visitor;
    u32 visitorIndex;
    u32 gender;
    u32 id;
    u32 province;
    u32 hasProvince;
    u8 *entry;

    hasProvince = 0;
    gameData = GSYS_GetGameData(gsys);
    surveySave = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(gameData));
    if (index >= 5) {
        return 4;
    }
    entry = save + index;
    visitorIndex = entry[8];
    LoadUnityTowerVisitorWordSet(wordSet, gameData, visitorIndex);
    visitor = UnityTower_GetVisitor(surveySave, visitorIndex);
    gender = getTrainerGender(visitor);
    province = UnityTower_GetVisitorParam(surveySave, visitorIndex, 4);
    id = getIDAsUInt(visitor);
    if (CountryHasProvinces(GameData_GetUnityTowerSave(gameData)[0]) != 0) {
        hasProvince = 1;
    }
    return func_ov033_0217ab58(gender, id, province, param, hasProvince);
}