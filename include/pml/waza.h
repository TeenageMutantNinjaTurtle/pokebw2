#ifndef POKEBW2_PML_WAZA_H
#define POKEBW2_PML_WAZA_H

#include "types.h"
#include "gfl/heap.h"

// Move data

#define MOVE_PARAM_TYPE 0
#define MOVE_PARAM_CATEGORY 2
#define MOVE_PARAM_POWER 3
#define MOVE_PARAM_EFFECT 28

// How long the condition a move inflicts lasts, by its type
typedef struct {
    u16 type : 4;
    u16 min : 6;
    u16 max : 6;
} MoveConditionParam;

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
BOOL PML_MoveIsAlwaysHit(u16 move);
BOOL PML_MoveIsAlwaysCrit(u16 move);
MoveConditionParam func_020214b0(u16 move);
u32 GetMoveWeather(u16 move);
BOOL PML_MoveIsDataCachePresent(void);
void PML_MoveInitDataCache(u32 count, HeapID heapId);
void PML_MoveFreeDataCache(void);
BOOL getMoveFlag(u16 move, u32 flag);

#endif // POKEBW2_PML_WAZA_H
