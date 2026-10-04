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
// The size of the survey's block
u32 func_02009b5c(void);
// Whether the survey has met a country and province, and recording it
BOOL func_02009ba4(UnityTowerSurveySave *save, u32 country, u32 province);
void func_02009be0(UnityTowerSurveySave *save, u32 country, u32 province, BOOL met);
u8 func_02009ca0(UnityTowerSurveySave *save);
u8 func_02009d28(UnityTowerSurveySave *save);
u32 func_02009ce4(UnityTowerSurveySave *save);
u32 func_02009cac(UnityTowerSurveySave *save, PlayerInfo *playerInfo, u32 index);
u32 func_0202b5d4(u32 value);
// The country and province if the region has them, else 0
u32 func_0202b57c(u32 country, u32 province, u32 region);
u32 func_0202b590(u32 country, u32 province, u32 region);
// Records a visitor from another country
void func_02035350(UnityTowerSurveySave *save, PlayerInfo *info);
u8 getPlayerSurveys(UnityTowerSurveySave *save);
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
