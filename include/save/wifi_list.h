#ifndef POKEBW2_SAVE_WIFI_LIST_H
#define POKEBW2_SAVE_WIFI_LIST_H

#include "types.h"
#include "struct_decls.h"

s32 WifiList_GetMyGSID(WifiList *wifiList);
// The player's DWC user data
void *func_02009f7c(WifiList *wifiList);
BOOL func_0200a150(WifiList *wifiList);
void func_0200a2d4(WifiList *wifiList, u32 friendIndex, u32 wins, u32 losses, u32 draws);
void func_0200a29c(WifiList *wifiList, u32 friendIndex);
// Finds the player among the friends
BOOL func_0200a438(WifiList *wifiList, PlayerInfo *info, u32 *friendIndex);

BOOL func_0200a138(WifiList *list, u32 index);
u32 func_02009f80(WifiList *list, u32 index, u32 a2);
void *getPalPadFriendListAddress(SaveControl *save);
// Records a trainer the player traded with
void func_0200a504(void *list, PlayerInfo *info);

#endif // POKEBW2_SAVE_WIFI_LIST_H
