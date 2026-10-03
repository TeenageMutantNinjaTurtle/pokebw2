#ifndef POKEBW2_FIELD_UNITY_TOWER_H
#define POKEBW2_FIELD_UNITY_TOWER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/str.h"
#include "struct_decls.h"

u8 *GameData_GetUnityTowerSave(GameData *gameData);
void *UnityTower_GetVisitor(UnityTowerSurveySave *save, u32 index);
u32 UnityTowerVisitor_GetProvince(void *visitor);
u32 UnityTowerVisitor_GetCountry(PlayerInfo *playerInfo);
u32 UnityTower_GetVisitorParam(UnityTowerSurveySave *save, u32 index, u32 param);
u32 getPlayerSurveys(UnityTowerSurveySave *save);
void setPlayerSurveys(UnityTowerSurveySave *save, u32 hobby);
void func_ov033_0217aa1c(GameSystem *gsys, u32 floor, u32 value);
u16 func_ov033_0217aad8(WordSet *wordSet, GameSystem *gsys, u8 *save, u32 index, u16 param);
BOOL CountryHasProvinces(u32 country);

void LoadUnityTowerVisitorWordSet(WordSet *wordSet, GameData *gameData, u32 index);

#endif // POKEBW2_FIELD_UNITY_TOWER_H
