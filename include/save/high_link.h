#ifndef POKEBW2_SAVE_HIGH_LINK_H
#define POKEBW2_SAVE_HIGH_LINK_H

#include "types.h"
#include "struct_decls.h"

u32 func_0200c678(HighLinkSave *save, int index);
u32 func_0200c6a0(HighLinkSave *save, u32 id);
u32 PassPower_GetUsedIDByEffect(int effect);
u32 PassPower_GetRemainingSeconds(int effect);

#endif // POKEBW2_SAVE_HIGH_LINK_H
