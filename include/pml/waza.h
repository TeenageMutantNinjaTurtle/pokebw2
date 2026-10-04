#ifndef POKEBW2_PML_WAZA_H
#define POKEBW2_PML_WAZA_H

#include "types.h"
#include "gfl/heap.h"

// Move data

#define MOVE_PARAM_TYPE 0
#define MOVE_PARAM_CATEGORY 2
#define MOVE_PARAM_POWER 3
#define MOVE_PARAM_EFFECT 28

u16 PML_MoveGetBasePower(u16 move);
BOOL getMoveFlag(u16 move, u32 flag);
BOOL PML_MoveIsDamaging(u16 move);
u8 PML_MoveGetCategory(u16 move);
s32 PML_MoveGetQuality(u16 move);
u8 PML_MoveGetType(u16 move);
u32 PML_MoveGetStatChangeStat(u16 move);
u32 PML_MoveGetStatChangeStage(u16 move, u32 index, s32 *stage);
u8 PML_MoveGetMaxPP(u16 move, u8 bonus);
s32 PML_MoveGetParam(u16 move, u32 param);
BOOL PML_MoveIsDataCachePresent(void);
void PML_MoveInitDataCache(u32 count, HeapID heapId);
void PML_MoveFreeDataCache(void);
BOOL getMoveFlag(u16 move, u32 flag);

#endif // POKEBW2_PML_WAZA_H
