#ifndef POKEBW2_SAVE_WIFI_LIST_H
#define POKEBW2_SAVE_WIFI_LIST_H

#include "types.h"
#include "struct_decls.h"

s32 WifiList_GetMyGSID(WifiList *wifiList);
BOOL func_0200a150(WifiList *wifiList);
void func_0200a2d4(WifiList *wifiList, u32 friendIndex, u32 wins, u32 losses, u32 draws);

BOOL func_0200a138(WifiList *list, u32 index);
u32 func_02009f80(WifiList *list, u32 index, u32 a2);

#endif // POKEBW2_SAVE_WIFI_LIST_H
