#ifndef POKEBW2_FIELD_UNITY_TOWER_H
#define POKEBW2_FIELD_UNITY_TOWER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/proc.h"
#include "gfl/str.h"
#include "struct_decls.h"

// The visitors on the floor of the Unity Tower the player is on, which the game data keeps
typedef struct {
    u8 floor;
    u8 count;
    u8 value;
    // The trainer class and the index of each visitor
    u8 trainerClasses[5];
    u8 visitors[5];
} UnityTowerFloor;

UnityTowerFloor *GameData_GetUnityTowerSave(GameData *gameData);
void *UnityTower_GetVisitor(UnityTowerSurveySave *save, u32 index);
u8 UnityTowerVisitor_GetProvince(void *visitor);
u8 UnityTowerVisitor_GetCountry(PlayerInfo *playerInfo);
u32 UnityTower_GetVisitorParam(UnityTowerSurveySave *save, u32 index, u32 param);
void func_02009db4(UnityTowerSurveySave *save, u32 index, u32 param, u32 value);
void func_02009d18(UnityTowerSurveySave *save, u8 index);
// The size of the survey's block
u32 func_02009b5c(void);
u8 func_02009ca0(UnityTowerSurveySave *save);
u8 func_02009d28(UnityTowerSurveySave *save);
u32 func_02009ce4(UnityTowerSurveySave *save);
// Whether a visitor from the country has come
BOOL func_02009eb0(UnityTowerSurveySave *save, u32 country);
u32 func_02009cac(UnityTowerSurveySave *save, PlayerInfo *playerInfo, u32 index);
void func_02009c48(UnityTowerSurveySave *save);
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
void func_ov033_0217aa50(UnityTowerSurveySave *save, UnityTowerFloor *output, s32 floor, u32 value);
u32 func_ov033_0217aac4(UnityTowerFloor *output, u32 index);
u32 func_ov033_0217ab58(u32 gender, u32 id, u32 province, u32 a3, u32 hasProvince);
void UnityTowerSave_Init(UnityTowerFloor *save);
u32 func_ov033_0217aad8(WordSet *wordSet, GameSystem *gsys, UnityTowerFloor *save, s32 index, u32 param);
BOOL CountryHasProvinces(u32 country);

void LoadUnityTowerVisitorWordSet(WordSet *wordSet, GameData *gameData, u32 index);

// Overlay 12's scrcmd_unity_tower.c
BOOL func_ov012_02160cdc(VM *vm, FieldScriptEnv *env);
BOOL s01CF_UnityTowerGetStateParam(VM *vm, FieldScriptEnv *env);
BOOL s01D0_UnityTowerCallFloorSelect(VM *vm, FieldScriptEnv *env);

// Overlay 311, the floor select
extern const GameProcFunctions data_ov311_0219e440;

#endif // POKEBW2_FIELD_UNITY_TOWER_H
