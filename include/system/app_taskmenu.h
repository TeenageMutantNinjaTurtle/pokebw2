#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"
#include "system/gf_font.h"
#include "system/printsys.h"

// The apps' menus of buttons, in the file the ROM names app_taskmenu.c

// A menu, a menu of one button, and the graphics of the buttons that menus share. The declarations below take them
// as void pointers
typedef struct AppTaskMenu AppTaskMenu;
typedef struct AppTaskMenuWin AppTaskMenuWin;
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

void *func_0202d974(const TaskMenuSetup *setup, void *res);
void func_0202da54(void *menu);
void func_0202db70(void *menu);
// Whether an item was picked, and which
BOOL func_0202dbe4(void *menu);
u8 func_0202dc00(void *menu);
// Shows or hides the cursor on the button
void func_0202dc04(void *menu, BOOL show);
// Whether a button was touched
BOOL func_0202dc1c(void *menu);

// The graphics of the menu's buttons, loaded into a BG of the main (bg < 4) or sub engine
void *func_0202e168(u32 bg, u32 palette, Font *font, PrintQueue *printQueue, HeapID heapId);
void func_0202e1dc(void *res);
// A single button, as a battle's selection has at the bottom of the screen
void *func_0202e1f0(void *res, const TaskMenuItem *item, u32 x, u8 y, u32 a4, HeapID heapId);
// A menu of one button, at x and y with the size in tiles
void *func_0202e210(void *res, const TaskMenuItem *item, u8 x, u8 y, u8 width, u8 height, u32 a6, u32 a7,
                    HeapID heapId);
void func_0202e34c(void *button);
void func_0202e37c(void *button);
void func_0202e41c(void *button, BOOL active);
void func_0202e430(void *button, BOOL pressed);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
