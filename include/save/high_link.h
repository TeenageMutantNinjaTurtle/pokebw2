#ifndef POKEBW2_SAVE_HIGH_LINK_H
#define POKEBW2_SAVE_HIGH_LINK_H

#include "types.h"
#include "struct_decls.h"

u32 func_0200c678(HighLinkSave *save, int index);
u32 func_0200c6a0(HighLinkSave *save, u32 id);
// Copies two bytes of the save into dest
void func_0200c6d8(HighLinkSave *save, u8 *dest, u32 a2);
u32 PassPower_GetUsedIDByEffect(int effect);
u32 PassPower_GetRemainingSeconds(int effect);
u32 PassPower_ApplyPrizeMoney(u32 money);
BOOL PassPower_IsBW1Compatible(u32 passPower);
u32 PassPower_ApplyEXP(u32 exp);
u32 PassPower_ApplyCapture(u32 rate);

#endif // POKEBW2_SAVE_HIGH_LINK_H
