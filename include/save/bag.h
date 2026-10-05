#ifndef POKEBW2_SAVE_BAG_H
#define POKEBW2_SAVE_BAG_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

BOOL BagSave_AddItem(BagSave *bag, u16 item, u16 count, u32 heapId);
// BagSave_AddItem, putting the item first in its pocket
BOOL BagSave_AddItemAsFirst(BagSave *bag, u32 item, u32 count, u32 heapId);
// Whether count of an item fit in the bag
BOOL BagSave_CheckAvailItemSpace(BagSave *bag, u16 item, u16 count, HeapID heapId);
// The pocket an item goes in
u32 BagSave_GetActualItemPocket(BagSave *bag, u16 item);
u16 BagSave_GetItemCountByID(BagSave *bag, u16 item, HeapID heapId);
// Whether the bag holds at least count of an item
BOOL BagSave_CheckAmount(BagSave *bag, u32 item, u32 count, u32 heapId);
BOOL BagSave_SubItem(BagSave *bag, u32 item, u32 count, u32 heapId);
void BagSave_Init(BagSave *bag);
void func_020088ec(void *data, u32 value);

#endif // POKEBW2_SAVE_BAG_H
