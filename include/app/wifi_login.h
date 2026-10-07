#ifndef POKEBW2_APP_WIFI_LOGIN_H
#define POKEBW2_APP_WIFI_LOGIN_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_WIFILOGIN OVERLAY_ID(190)

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    void *buffer;
    // Set to log in again after an error
    u32 unk14;
    u32 unk18;
    u32 result;
    u32 unk20;
    u32 unk24;
} WifiLoginParam;

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} WifiLogoutParam;

extern const GameProcFunctions WIFILOGIN_PROC_FUNCTIONS;
extern const GameProcFunctions WIFILOGOUT_PROC_FUNCTIONS;

// The login's messages, for the callbacks of WifiLoginParam: print one and wait for it
void func_ov190_021b48a4(void *msgWork, MsgData *msgData, u32 msgNo);
BOOL func_ov190_021b49b8(void *msgWork);

#endif // POKEBW2_APP_WIFI_LOGIN_H
