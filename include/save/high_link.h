#ifndef POKEBW2_SAVE_HIGH_LINK_H
#define POKEBW2_SAVE_HIGH_LINK_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

u32 func_0200c678(HighLinkSave *save, int index);
u32 func_0200c6a0(HighLinkSave *save, u32 id);
// Copies two bytes of the save into dest
void func_0200c6d8(HighLinkSave *save, u8 *dest, u32 a2);
u32 PassPower_GetUsedIDByEffect(int effect);
BOOL PassPower_IsBW1Compatible(u32 passPower);
u32 PassPower_GetRemainingSeconds(int effect);
u32 PassPower_ApplyPrizeMoney(u32 money);
BOOL PassPower_IsBW1Compatible(u32 passPower);
u32 PassPower_ApplyEXP(u32 exp);
u32 PassPower_ApplyCapture(u32 rate);
// The pass powers' table, read from its archive
void *PassPowerData_Create(HeapID heapId);
void PassPowerData_Free(void *data);
// Two levels of what func_02017208 returns, which the pass powers need
u16 func_0200c5dc(void *levels);
u16 func_0200c5e0(void *levels);
// The bit of a special pass power in the two bytes of func_0200c6d8, or 0xff
u32 PassPower_GetSPowerBaseID(int index);
// Overlay 12's pass_power_check.c: whether a pass power is unlocked (0), nearly (1) or not (2), and how many are
u32 CheckPassPowerUnlocked(void *data, int index, void *levels, u8 *flags);
u32 GetUnlockedPassPowerCount(void *data, void *levels, u8 *flags);

#endif // POKEBW2_SAVE_HIGH_LINK_H
