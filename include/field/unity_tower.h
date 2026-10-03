#ifndef POKEBW2_FIELD_UNITY_TOWER_H
#define POKEBW2_FIELD_UNITY_TOWER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/str.h"
#include "struct_decls.h"

u8 *GameData_GetUnityTowerSave(GameData *gameData);
void *UnityTower_GetVisitor(UnityTowerSurveySave *save, u32 index);
u32 UnityTowerVisitor_GetProvince(void *visitor);
u32 UnityTower_GetVisitorParam(UnityTowerSurveySave *save, u32 index, u32 param);
u32 getPlayerSurveys(UnityTowerSurveySave *save);
BOOL CountryHasProvinces(u32 country);

void LoadUnityTowerVisitorWordSet(WordSet *wordSet, GameData *gameData, u32 index);

#endif // POKEBW2_FIELD_UNITY_TOWER_H
