#ifndef POKEBW2_PML_ITEM_H
#define POKEBW2_PML_ITEM_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Item data

#define ITEM_PARAM_FLING_POWER 10

ArcTool *PML_ItemArcHandleCreate(HeapID heapId);
void *PML_ItemArcHandleReadFile(ArcTool *handle, u16 item, HeapID heapId);
s32 PML_ItemGetParam(void *data, u32 param);
BOOL PML_ItemIsBerry(u16 item);
u32 GetItemParam(u16 item, u32 param, HeapID heapId);
// Reads an item's data, or its icon's or palette's for type 1 or 2
void *PML_ItemReadDataFile(u16 item, u32 type, HeapID heapId);
// The move that a TM or HM teaches
u16 PML_ItemGetTMWazaID(u16 item);
// The TM or HM's number from 0, or 0xff for another item
u8 PML_ItemGetTMBitMask(u16 item);
BOOL PML_ItemIsMail(u16 item);
// The mail of a mail item
u32 PML_ItemGetMailID(u16 item);
u32 PML_ItemGetMonsBallID(u16 item);
// An item's file in ARCID_ITEMGRA: 1 for its icon's characters and 2 for its palette
u16 GetItemGraphicsDatID(u16 item, u32 type);
// The archive of the items' icons
u32 func_02026714(void);

#endif // POKEBW2_PML_ITEM_H
