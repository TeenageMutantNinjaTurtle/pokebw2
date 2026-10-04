#ifndef POKEBW2_BATTLE_TRAINER_DATA_H
#define POKEBW2_BATTLE_TRAINER_DATA_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

u32 TrainerData_GetParam(u32 trainerId, u32 param);
u32 GetTrainerClassBGMGroupId(u32 trainerClass);
BOOL TrainerMsg_CheckExists(u32 trainerId, u32 msgId, HeapID heapId);
void TrainerMsg_Load(u32 trainerId, u32 msgId, StrBuf *strbuf, HeapID heapId);

#endif // POKEBW2_BATTLE_TRAINER_DATA_H
