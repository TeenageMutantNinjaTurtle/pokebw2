#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"
#include "system/gf_font.h"
#include "system/printsys.h"

// app_taskmenu.c: the menus of buttons on the lower screen of the game's applications

typedef struct {
    StrBuf *str;
    u16 color;
    u32 type;
} AppTaskMenuItem;

typedef struct {
    u32 heapId;
    u8 itemCount;
    AppTaskMenuItem *items;
    u32 posType;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} AppTaskMenuParam;

AppTaskMenu *func_0202d974(const AppTaskMenuParam *param, AppTaskMenuRes *res);
void func_0202def8(AppTaskMenu *menu, u32 pos);
// The resources the menus share: their graphics, font and print queue
AppTaskMenuRes *func_0202e168(u16 bg, u16 palette, Font *font, PrintQueue *queue, HeapID heapId);
void func_0202e1dc(AppTaskMenuRes *res);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
