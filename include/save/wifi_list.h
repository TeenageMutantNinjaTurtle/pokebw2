#ifndef POKEBW2_SAVE_WIFI_LIST_H
#define POKEBW2_SAVE_WIFI_LIST_H

#include "types.h"
#include "struct_decls.h"

s32 WifiList_GetMyGSID(WifiList *wifiList);
BOOL func_0200a150(WifiList *wifiList);
void func_0200a2d4(WifiList *wifiList, u32 friendIndex, u32 wins, u32 losses, u32 draws);

#endif // POKEBW2_SAVE_WIFI_LIST_H
