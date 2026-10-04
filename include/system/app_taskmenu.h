#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "system/gf_font.h"
#include "system/printsys.h"

// app_taskmenu.c: the touch menus of the lower screen, a column of buttons such as Yes and No. None of these
// functions has a name yet

// The graphics that menus share
typedef struct AppTaskMenuRes AppTaskMenuRes;
typedef struct AppTaskMenu AppTaskMenu;

typedef struct {
    StrBuf *str;
    // The text's color, a packed print color
    u32 msgColor;
    u32 type;
} AppTaskMenuItem;

typedef struct {
    // A full word, unlike a HeapID
    u32 heapId;
    u8 itemCount;
    AppTaskMenuItem *items;
    u32 posType;
    // Where the menu is and how big its buttons are, in characters
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} AppTaskMenuInit;

AppTaskMenu *func_0202d974(const AppTaskMenuInit *init, AppTaskMenuRes *res);
void func_0202da54(AppTaskMenu *menu);
void func_0202db70(AppTaskMenu *menu);
// Whether an item was chosen, and which
BOOL func_0202dbe4(AppTaskMenu *menu);
u32 func_0202dc00(AppTaskMenu *menu);

AppTaskMenuRes *func_0202e168(u8 frame, u8 palette, Font *font, PrintQueue *queue, HeapID heapId);
void func_0202e1dc(AppTaskMenuRes *res);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
