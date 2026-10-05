#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

// app_taskmenu.c of ARM9 main, after its embedded name: a menu of a few options, such as yes and no. Only the
// declarations overlay 12's report_event.c needs, with names from their use there

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

typedef struct AppTaskMenu AppTaskMenu;
typedef struct AppTaskMenuRes AppTaskMenuRes;

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
} AppTaskMenuInit;

AppTaskMenu *func_0202da48(const AppTaskMenuInit *init, AppTaskMenuRes *res);
void func_0202da54(AppTaskMenu *menu);
void func_0202db70(AppTaskMenu *menu);
// Whether an option has been picked, and which
BOOL func_0202dbe4(AppTaskMenu *menu);
u32 func_0202dc00(AppTaskMenu *menu);
// The graphics the menus share
AppTaskMenuRes *func_0202e168(u8 bg, u8 palette, Font *font, void *a3, HeapID heapId);
void func_0202e1dc(AppTaskMenuRes *res);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
