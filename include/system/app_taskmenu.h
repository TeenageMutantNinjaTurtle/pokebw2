#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"
#include "system/gf_font.h"
#include "system/printsys.h"

// The menus of buttons on the lower screen that apps open, such as the trade's. The name is descriptive

typedef struct AppTaskMenu AppTaskMenu;
// A menu of one button
typedef struct AppTaskMenuWin AppTaskMenuWin;
// The graphics of the buttons, which menus share
typedef struct AppTaskMenuRes AppTaskMenuRes;

typedef struct {
    StrBuf *str;
    u16 color;
    // The item that B picks
    BOOL isBack;
} TaskMenuItem;

typedef struct {
    u32 heapId;
    u8 count;
    TaskMenuItem *items;
    u32 a3;
    // The menu's bottom right corner, and the size of an item, in tiles
    u8 right;
    u8 bottom;
    u8 width;
    u8 height;
} TaskMenuSetup;

AppTaskMenu *func_0202d974(const TaskMenuSetup *setup, AppTaskMenuRes *res);

// Frees the menu
void func_0202da54(AppTaskMenu *menu);
// Whether the choice's animation has ended
BOOL func_0202dbe4(AppTaskMenu *menu);
// The button that was chosen
u8 func_0202dc00(AppTaskMenu *menu);
// Shows or hides the cursor on the button
void func_0202dc04(AppTaskMenu *menu, BOOL show);
// Whether a button was touched
BOOL func_0202dc1c(AppTaskMenu *menu);
void func_0202db70(AppTaskMenu *menu);
// The graphics of the buttons, loaded into a BG of the main (bg < 4) or sub engine
AppTaskMenuRes *func_0202e168(u32 bg, u32 palette, Font *font, PrintQueue *printQueue, HeapID heapId);
void func_0202e1dc(AppTaskMenuRes *res);
// A menu of one button, at x and y with the size in tiles
AppTaskMenuWin *func_0202e210(AppTaskMenuRes *res, const TaskMenuItem *item, u8 x, u8 y, u8 width, u8 height, u32 a6,
                              u32 a7, HeapID heapId);
void func_0202e34c(AppTaskMenuWin *win);
void func_0202e37c(AppTaskMenuWin *win);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
