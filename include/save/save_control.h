#ifndef POKEBW2_SAVE_SAVE_CONTROL_H
#define POKEBW2_SAVE_SAVE_CONTROL_H

#include "types.h"
#include "struct_decls.h"

SaveControl *SaveControl_GetInstance(void);
BOOL SaveControl_IsDataAlreadyPresent(SaveControl *save);

// Saving a step at a time: func_020073ac starts, func_020073c4 continues and returns the status, and func_02007424
// cancels
void func_020073ac(SaveControl *save);
u32 func_020073c4(SaveControl *save);
void func_02007424(SaveControl *save);
// Four flags of the save control, at 4 to 7
u8 func_0200748c(SaveControl *save);
void func_02007490(SaveControl *save, u32 value);
u8 func_02007494(SaveControl *save);
void func_02007498(SaveControl *save, u32 value);
u8 func_020074dc(SaveControl *save);
void func_020074e0(SaveControl *save, u32 value);
u8 func_020074e4(SaveControl *save);
void func_020074e8(SaveControl *save, u32 value);
void func_02008e04(SaveControl *save);
// Nonzero while the card is being accessed
u32 getLockIDStatus_inline_stub(void);

DreamRadarSave *GetDreamRadarSaveBlock(SaveControl *save);
JoinAvenueSave *SaveControl_GetJoinAvenue(SaveControl *save);
PlayerInfo *SaveControl_GetPlayerInfo(SaveControl *save);
PokeParty *SaveControl_GetPokePartySave(SaveControl *save);
WorldTradeData *SaveControl_GetWorldTradeData(SaveControl *save);
DreamWorldSave *getDreamWorldStuffAddress(SaveControl *save);
HighLinkSave *getHighLinkBlockAddress(SaveControl *save);
KeyInfoSave *getKeyInfoSaveBlk(SaveControl *save);
RecordSave *getRecordBlkAddress(SaveControl *save);
AdventureSave *getSaveAdventureDataBlk(SaveControl *save);
AdventureTime *getSaveAdventureTimeBlock(SaveControl *save);
TrainerCardSave *getTrainerCardDataBlkAddress(GameData *gameData);
// The same block as GameData_GetRecords
GameRecords *getTrainerCardInfoBlkAddress(SaveControl *save);
// PlayerInfo is at 4 in this block
TrainerDataSave *getTrainerDataBlkAddress(SaveControl *save);
UnityTowerSurveySave *getUnityTower_SurveySaveBlkAddrress(SaveControl *save);

#endif // POKEBW2_SAVE_SAVE_CONTROL_H
