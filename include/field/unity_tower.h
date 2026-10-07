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
void func_02009db4(UnityTowerSurveySave *save, u32 index, u32 param, u32 value);
void func_02009d18(UnityTowerSurveySave *save, u8 index);
u32 func_02009ce4(UnityTowerSurveySave *save);
u32 func_02009cac(UnityTowerSurveySave *save, PlayerInfo *playerInfo, u32 index);
u32 func_0202b5d4(u32 value);
// A country and region checked for the language, or 0 when the country isn't known
u8 func_0202b57c(u8 country, u8 region, u8 lang);
u8 func_0202b590(u8 country, u8 region, u8 lang);
// Whether a country and region were met, and records them
BOOL func_02009ba4(UnityTowerSurveySave *save, u8 country, u8 region);
void func_02009be0(UnityTowerSurveySave *save, u8 country, u8 region, u32 a3);
// Records a visitor, a trainer followed by what they traded
BOOL func_02035350(UnityTowerSurveySave *save, PlayerInfo *visitor);
u8 getPlayerSurveys(UnityTowerSurveySave *save);
u8 func_02009ca0(UnityTowerSurveySave *save);
u8 func_02009d28(UnityTowerSurveySave *save);
void setPlayerSurveys(UnityTowerSurveySave *save, u32 hobby);
void func_ov033_0217aa1c(GameSystem *gsys, s32 floor, u32 value);
void func_ov033_0217aa50(UnityTowerSurveySave *save, u8 *output, s32 floor, u32 value);
u32 func_ov033_0217aac4(u8 *output, u32 index);
u32 func_ov033_0217ab58(u32 gender, u32 id, u32 province, u32 a3, u32 hasProvince);
void UnityTowerSave_Init(u8 *save);
u32 func_ov033_0217aad8(WordSet *wordSet, GameSystem *gsys, u8 *save, s32 index, u32 param);
BOOL CountryHasProvinces(u32 country);

void LoadUnityTowerVisitorWordSet(WordSet *wordSet, GameData *gameData, u32 index);

#endif // POKEBW2_FIELD_UNITY_TOWER_H
