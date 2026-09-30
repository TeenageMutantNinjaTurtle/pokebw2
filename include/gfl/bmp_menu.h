#ifndef POKEBW2_GFL_BMP_MENU_H
#define POKEBW2_GFL_BMP_MENU_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Menus of text options in a window

typedef struct BmpMenuList BmpMenuList;

typedef struct {
    StrBuf *text;
    s32 value;
} ListMenuOption;

// BmpMenuList_Update's results when nothing was chosen and when the menu was cancelled
#define BMPMENULIST_NULL (-1)
#define BMPMENULIST_CANCEL (-2)

typedef struct {
    ListMenuOption *options;
    void *unk4;
    void *unk8;
    u16 count;
    u16 unkE;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13_0 : 4;
    u8 unk13_4 : 4;
    u8 unk14_0 : 4;
    u8 unk14_4 : 4;
    u16 unk16_0 : 3;
    u16 unk16_3 : 4;
    u16 unk16_7 : 2;
    u16 unk16_9 : 6;
    u16 unk16_15 : 1;
    u32 unk18;
    u16 unk1C;
    u16 unk1E;
    u32 unk20;
    void *unk24;
    void *unk28;
    Font *font;
    u32 unk30;
} BmpMenuListHeader;

ListMenuOption *ListMenuCore_CreateOptionList(u32 count, HeapID heapId);
void ListMenuCore_AppendStrBufOption(ListMenuOption *options, const StrBuf *text, s32 value, HeapID heapId);
void ListMenuCore_FreeOptionList(ListMenuOption *options);

BmpMenuList *BmpMenuList_Create(const BmpMenuListHeader *header, s16 a1, s16 a2, HeapID heapId);
void BmpMenuList_Free(BmpMenuList *list, u16 *a1, u16 *a2);
s32 BmpMenuList_Update(BmpMenuList *list);
void func_02026510(BmpMenuList *list, HeapID heapId);
void func_02026520(BmpMenuList *list, u32 a1);

#endif // POKEBW2_GFL_BMP_MENU_H
