#ifndef POKEBW2_SAVE_RECORDS_H
#define POKEBW2_SAVE_RECORDS_H

#include "types.h"
#include "struct_decls.h"

// RecordSave is the block that getRecordBlkAddress returns. The encrypted records that GameData_GetRecords returns
// are GameRecords

// Clears the flag that is set, with the console's MAC address and the time, while a match is in progress
void RecordSave_ClearMatchInProgress(RecordSave *record);

void RecordAddOne(GameRecords *records, u32 id);
u32 RecordGet(GameRecords *records, u32 id);
void RecordAdd(GameRecords *records, u32 id, u32 value);
// Sets a record to value if that is higher, up to the record's maximum
void func_02009508(GameRecords *records, u32 id, u32 value);
// The Trial House's best rank and best points
void func_02009618(GameRecords *records, u8 rank);
void func_02009638(GameRecords *records, u32 points);
RecordSave *func_0200f2bc(SaveControl *save);
void func_0200f2dc(RecordSave *record);
u8 func_0200f300(RecordSave *record);
u32 func_0200f308(RecordSave *record);
u32 func_0200f334(RecordSave *record);
void func_0200f37c(RecordSave *record, u32 value);
u8 func_0200f384(RecordSave *record);

#endif // POKEBW2_SAVE_RECORDS_H
