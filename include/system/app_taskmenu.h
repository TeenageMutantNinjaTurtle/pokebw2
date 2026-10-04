#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

#include "types.h"
#include "gfl/heap.h"
#include "system/gf_font.h"
#include "system/printsys.h"

// The apps' menus of buttons, in the file the ROM names app_taskmenu.c

// The graphics of the menu's buttons, loaded into a BG of the main (bg < 4) or sub engine
void *func_0202e168(u32 bg, u32 palette, Font *font, PrintQueue *printQueue, HeapID heapId);
void func_0202e1dc(void *res);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
