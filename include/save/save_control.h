#ifndef POKEBW2_SAVE_SAVE_CONTROL_H
#define POKEBW2_SAVE_SAVE_CONTROL_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

SaveControl *SaveControl_GetInstance(void);
u32 SaveControl_GetStatus(SaveControl *save);
u32 func_02007464(SaveControl *save);
void func_0200749c(SaveControl *save);
void func_02007324(SaveControl *save);
TrainerGameInfoSave *getTrainerGameInfoAddress(SaveControl *save);

// Where the player saved
typedef struct {
    u16 zoneId;
    VecFx32 pos;
    u32 unk10;
    u32 unk14;
    s16 unk18;
} SaveLocation;

void func_02008fb8(SaveControl *save, SaveLocation *location);
// Save block 0x42, which keeps the rival's name
RivalDataSave *getHollow_RivalData(SaveControl *save);
void copyRivalNameIntoHollowBlock(RivalDataSave *data, const u16 *name);
u32 func_0200ca64(TrainerGameInfoSave *info);
void func_0200ca6c(TrainerGameInfoSave *info, u32 value);
u32 func_0200ca74(TrainerGameInfoSave *info);
void func_0200ca78(TrainerGameInfoSave *info, u32 value);
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
// Used to delete the save data: func_020074ec tells whether a block is in the save, and func_020076a4 clears it
void func_020074ac(SaveControl *save);
BOOL func_020074ec(SaveControl *save, u32 block, HeapID heapId);
void func_020076a4(SaveControl *save, u32 block, HeapID heapId);
void freeIntermediateSaveExtraBlksAfterLoad(SaveControl *save, u32 block);
void func_02011558(HeapID heapId);
// In overlay 331, which has to be loaded
void func_ov331_021bede0(HeapID heapId);
void *func_ov331_021bea20(HeapID heapId);
void func_ov331_021bec1c(void *a0);
BOOL func_ov331_021bed54(void *a0);
void func_ov331_021bed78(void *a0, SaveControl *save);
void func_ov331_021bee24(HeapID heapId);
BOOL func_ov331_021bee68(void *a0);
void func_ov331_021bee88(void *a0, SaveControl *save);
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
