#ifndef POKEBW2_SAVE_BAG_H
#define POKEBW2_SAVE_BAG_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

BOOL BagSave_AddItem(BagSave *bag, u32 item, u32 count, u32 heapId);
void BagSave_Init(BagSave *bag);

#endif // POKEBW2_SAVE_BAG_H
