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

#endif // POKEBW2_NITRO_WM_H
