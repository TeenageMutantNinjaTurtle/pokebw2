#ifndef POKEBW2_NITRO_WM_H
#define POKEBW2_NITRO_WM_H

#include "types.h"

// NitroSDK's wireless manager. The functions keep their default names; the comments give the SDK functions they
// appear to be

// The signal strength, 0 (none) to 3
typedef enum {
    WM_LINK_LEVEL_0,
    WM_LINK_LEVEL_1,
    WM_LINK_LEVEL_2,
    WM_LINK_LEVEL_3,
} WMLinkLevel;

WMLinkLevel func_020810fc(void); // WM_GetLinkLevel

// What the parent's callback gets when a child connects or disconnects
typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 aid;
    u16 reason;
} WMStartParentCallback;

#endif // POKEBW2_NITRO_WM_H
