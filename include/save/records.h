#ifndef POKEBW2_SAVE_RECORDS_H
#define POKEBW2_SAVE_RECORDS_H

#include "types.h"
#include "struct_decls.h"

// RecordSave is the block that getRecordBlkAddress returns. The encrypted records that GameData_GetRecords returns
// are GameRecords

// The record counters, encrypted from large[1] on with a key drawn when the game begins
struct GameRecords {
    u32 large[0x47];
    u16 small[0x60];
    u16 checksum;
    u16 key;
}; // size: 0x1e0

// Clears the flag that is set, with the console's MAC address and the time, while a match is in progress
void RecordSave_ClearMatchInProgress(RecordSave *record);

// The size of the records
u32 func_020093d0(void);
void initTrainerCardInfoBlk(GameRecords *records);
// Sets a record to value, up to the record's maximum, and returns what it holds
u32 func_020094cc(GameRecords *records, u32 id, u32 value);
// Sets a record to value if that is higher, up to the record's maximum, and returns what it holds
u32 func_02009508(GameRecords *records, u32 id, u32 value);
u32 RecordAdd(GameRecords *records, u32 id, u32 value);
u32 RecordAddOne(GameRecords *records, u32 id);
u32 RecordGet(GameRecords *records, u32 id);
// Folds each current streak into its best record and starts the streak again
void func_020095e0(GameRecords *records);
// The Trial House's best rank and best points
void func_02009618(GameRecords *records, u8 rank);
u8 func_02009628(GameRecords *records);
void func_02009638(GameRecords *records, u32 points);
u32 func_02009650(GameRecords *records);
RecordSave *func_0200f2bc(SaveControl *save);
// The results of the random matches
void *func_0200f2d4(RecordSave *record);
void func_0200f2dc(RecordSave *record);
u8 func_0200f300(RecordSave *record);
u32 func_0200f308(RecordSave *record);
u32 func_0200f334(RecordSave *record);
void func_0200f37c(RecordSave *record, u32 value);
u8 func_0200f384(RecordSave *record);

#endif // POKEBW2_SAVE_RECORDS_H
