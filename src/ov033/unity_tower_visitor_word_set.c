#include "field/unity_tower.h"
#include "gfl/str.h"
#include "save/save_control.h"
#include "system/game_data.h"

void LoadUnityTowerVisitorWordSet(WordSet *wordSet, GameData *gameData, u32 index) {
    SaveControl *save;
    UnityTowerSurveySave *survey;
    u8 *towerSave;
    u8 country;
    void *visitor;
    u32 value;
    u8 hobby;

    save = GameData_GetSaveControl(gameData);
    survey = getUnityTower_SurveySaveBlkAddrress(save);
    towerSave = GameData_GetUnityTowerSave(gameData);
    country = towerSave[0];
    visitor = UnityTower_GetVisitor(survey, index);
    loadCountryToStrbuf(wordSet, 0, country);
    if (CountryHasProvinces(country)) {
        loadCountryAreaToStrbuf(wordSet, 1, country, UnityTowerVisitor_GetProvince(visitor));
    }
    copyVarForText(wordSet, 3, GetGameDataPlayerInfo(gameData));
    WordSet_LoadSpeciesName(wordSet, 5, (u16)UnityTower_GetVisitorParam(survey, index, 0));
    loadHobbyNameToStrbuf(wordSet, 6, getPlayerSurveys(survey));
    copyVarForText(wordSet, 7, visitor);
    value = UnityTower_GetVisitorParam(survey, index, 3);
    if (value == 0) {
        value = 1;
    }
    WordSetNumber(wordSet, 8, value, 3, 0, 1);
    WordSet_LoadSpeciesName(wordSet, 9, (u16)UnityTower_GetVisitorParam(survey, index, 1));
    hobby = UnityTower_GetVisitorParam(survey, index, 2);
    loadHobbyNameToStrbuf(wordSet, 10, hobby);
}
