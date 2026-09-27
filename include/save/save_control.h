#ifndef POKEBW2_SAVE_SAVE_CONTROL_H
#define POKEBW2_SAVE_SAVE_CONTROL_H

#include "types.h"
#include "struct_decls.h"

DreamRadarSave *GetDreamRadarSaveBlock(SaveControl *save);
JoinAvenueSave *SaveControl_GetJoinAvenue(SaveControl *save);
PlayerInfo *SaveControl_GetPlayerInfo(SaveControl *save);
void *SaveControl_GetPokePartySave(SaveControl *save);
WorldTradeData *SaveControl_GetWorldTradeData(SaveControl *save);
DreamWorldSave *getDreamWorldStuffAddress(SaveControl *save);
HighLinkSave *getHighLinkBlockAddress(SaveControl *save);
KeyInfoSave *getKeyInfoSaveBlk(SaveControl *save);
RecordSave *getRecordBlkAddress(SaveControl *save);
void *getSaveAdventureDataBlk(SaveControl *save);
void *getSaveAdventureTimeBlock(SaveControl *save);
void *getTrainerCardDataBlkAddress(GameData *gameData);
void *getTrainerCardInfoBlkAddress(SaveControl *save);
void *getTrainerDataBlkAddress(SaveControl *save);
void *getUnityTower_SurveySaveBlkAddrress(SaveControl *save);
BOOL hasClockNotBeenTampered(void *adventure);
void setAdvTimeBlkRtcOffsetOwnerMacBdayMonthDay(void *adventure);
void setNewDayForCountdown(void *adventureTime);

#endif // POKEBW2_SAVE_SAVE_CONTROL_H
