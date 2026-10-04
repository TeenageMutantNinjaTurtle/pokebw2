#ifndef POKEBW2_SYSTEM_TIME_ICON_H
#define POKEBW2_SYSTEM_TIME_ICON_H

#include "types.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "gfl/tcb.h"

typedef struct WaitIcon WaitIcon;

// An icon (time_icon.c) that shows in a window while the game is busy
WaitIcon *func_02035734(HeapID heapId);
void func_0203576c(WaitIcon *icon, TCBManager *tcbManager, BmpWin *window, u32 a3, u32 a4);
void func_0203580c(WaitIcon *icon);
// The same icon, created shown and stepped by its owner
WaitIcon *func_02035604(TCBManager *tcbManager, BmpWin *window, u32 a2, u32 a3, HeapID heapId);
void func_02035884(WaitIcon *icon);
// The icon, shown in a window by tasks of the manager
WaitIcon *func_02035660(TCBExManager *tcbManager, BmpWin *window, u32 a2, u32 a3, HeapID heapId);

#endif // POKEBW2_SYSTEM_TIME_ICON_H
