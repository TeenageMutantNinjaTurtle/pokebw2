#ifndef POKEBW2_SYSTEM_GAME_DATA_H
#define POKEBW2_SYSTEM_GAME_DATA_H

#include "types.h"
#include "struct_decls.h"

// The city of the player's version, which a key from Unova Link can switch
#define CITY_BLACK_CITY 0
#define CITY_WHITE_FOREST 1

struct CityState {
    u16 initialized;
    u16 city;
};

BOOL GameData_CheckPairFlag(GameData *gameData);
BagSave *GameData_GetBag(GameData *gameData);
BoxSaveAccessor *GameData_GetBoxSaveAccessor(GameData *gameData);
ZoneSpawnInfo *GameData_GetEntralinkParentSpawnInfo(GameData *gameData);
ZoneSpawnInfo *GameData_GetEscapeRopeZone(GameData *gameData);
EventData *GameData_GetEventData(GameData *gameData);
EventWork *GameData_GetEventWork(GameData *gameData);
// The Royal Unova's cruise while the player is aboard, or NULL
PleasureBoat **GameData_GetPleasureBoatPtr(GameData *gameData);
FieldSound *GameData_GetFieldSoundSystem(GameData *gameData);
FieldStatus *GameData_GetFieldStatus(GameData *gameData);
GimmickState *GameData_GetGimmickState(GameData *gameData);
JoinAvenuePersonList **GameData_GetJoinAvenuePersonListPtr(GameData *gameData);
u32 GameData_GetLastSubscreen(GameData *gameData);
MMSys *GameData_GetMMSys(GameData *gameData);
CityState *GameData_GetMyCityState(GameData *gameData);
u16 func_02017220(GameData *gameData);
// Save block 0x39
void *func_0201795c(GameData *gameData);
u8 func_02017b8c(GameData *gameData);
void func_02017bb4(GameData *gameData);
MusicalSave *getMusicalInfoBlkAddress(GameData *gameData);
ZoneSpawnInfo *GameData_GetNextZone(GameData *gameData);
PokeParty *GameData_GetParty(GameData *gameData);
PlayerState *GameData_GetPlayerState(GameData *gameData);
PokeDexSave *GameData_GetPokedex(GameData *gameData);
GameRecords *GameData_GetRecords(GameData *gameData);
SaveControl *GameData_GetSaveControl(GameData *gameData);
u8 GameData_GetSeason(GameData *gameData);
void GameData_GetSeasons(GameData *gameData, u16 *prevSeason, u16 *season);
WifiList *GameData_GetWifiList(GameData *gameData);
void GameData_InitEncountTerrain(GameData *gameData, Field *field);
BOOL GameData_IsForceSeasonSync(GameData *gameData);
BOOL GameData_IsLensFlareRequested(GameData *gameData);
void GameData_RestoreCGearPowerRequest(GameData *gameData);
void GameData_SaveCGearPowerRequest(GameData *gameData);
void GameData_SetEntralinkParentSpawnInfo(GameData *gameData, ZoneSpawnInfo *spawn);
void GameData_SetEscapeRopeZone(GameData *gameData, ZoneSpawnInfo *spawn);
void GameData_SetForceSeasonSync(GameData *gameData, BOOL force);
void GameData_SetLastSubscreen(GameData *gameData, u32 subscreen);
void GameData_SetLensFlareRequested(GameData *gameData, BOOL requested);
void GameData_SetNextZone(GameData *gameData, ZoneSpawnInfo *spawn);
ZoneSpawnInfo *GetGameDataNowSpawnZone(GameData *gameData);
PlayerInfo *GetGameDataPlayerInfo(GameData *gameData);
MapMatrix *GetMapMatrixSystem(GameData *gameData);
ZoneSpawnInfo *GetOutboundWarpRememberSpawnInfo(GameData *gameData);
u16 GetReturnLocationIdx(GameData *gameData);
void SetCurrentTeleportOrDeathZone(GameData *gameData, u16 respawnLocation);
void SetGameDataNowSpawnZone(GameData *gameData, ZoneSpawnInfo *spawn);
PlayerInfo *func_02017378(GameData *gameData, u32 netId);
void func_020175c4(GameData *gameData, u32 a1);
void func_020175d8(GameData *gameData, u32 a1);
void func_02017608(GameData *gameData, u32 a1);
// Where Pokéstar Studios keeps its PokewoodSystem while the player makes a movie
PokewoodSystem **func_02017a04(GameData *gameData);
u32 func_02017a40(GameData *gameData);
void func_02017b64(GameData *gameData, u8 a1);
u32 *func_02017b84(GameData *gameData);
void func_02039980(u32 *a0, u32 index, u32 value);

#endif // POKEBW2_SYSTEM_GAME_DATA_H
