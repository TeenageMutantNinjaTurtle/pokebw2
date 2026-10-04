#ifndef POKEBW2_GFL_BMP_MENU_H
#define POKEBW2_GFL_BMP_MENU_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"
#include "system/bmp_menuwork.h"

// Menus of text options in a window

typedef struct BmpMenuList BmpMenuList;

// Called as the cursor moves to an option, and to print more of an option at a row of the window
typedef void (*BmpMenuListCursorCallback)(BmpMenuList *list, s32 value, u8 a2);
typedef void (*BmpMenuListPrintCallback)(BmpMenuList *list, s32 value, u8 y);

// BmpMenuList_Update's results when nothing was chosen and when the menu was cancelled
#define BMPMENULIST_NULL (-1)
#define BMPMENULIST_CANCEL (-2)

typedef struct {
    ListMenuOption *options;
    BmpMenuListCursorCallback cursorCallback;
    BmpMenuListPrintCallback printCallback;
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
    // For the callbacks, which func_0202651c returns
    void *work;
    u16 unk1C;
    u16 unk1E;
    u32 unk20;
    void *unk24;
    void *unk28;
    Font *font;
    u32 unk30;
} BmpMenuListHeader;

BmpMenuList *BmpMenuList_Create(const BmpMenuListHeader *header, s16 a1, s16 a2, u32 heapId);
void BmpMenuList_Free(BmpMenuList *list, u16 *a1, u16 *a2);
s32 BmpMenuList_Update(BmpMenuList *list);
void func_02026510(BmpMenuList *list, u32 heapId);
void func_02026520(BmpMenuList *list, u32 a1);
// Redraws the list
void func_02025a38(BmpMenuList *list);
// The list's first shown option and the cursor's row
void func_02025b04(BmpMenuList *list, u16 *top, u16 *cursor);
// A parameter of the list's header
u32 func_02025b58(BmpMenuList *list, u32 param);
// The header's work
void *func_0202651c(BmpMenuList *list);
// The index of the option under the cursor
void func_02025af4(BmpMenuList *list, u16 *index);

#endif // POKEBW2_GFL_BMP_MENU_H
