#include "battle/btl_main.h"
#include "battle/btl_setup.h"
#include "save/config.h"

// Function names from swan.
u32 BtlSetup_GetBattleStyle(BtlMainModule *mainModule) {
    return mainModule->setup->battleStyle;
}

u32 func_ov167_0219bd88(BtlMainModule *mainModule) {
    return ((u32)((u8 *)mainModule)[0x473] << 29) >> 31;
}

u8 func_ov167_0219bd98(BtlMainModule *mainModule) {
    return ((u8 *)mainModule->setup)[0x98];
}

// Function name from swan.
BOOL IsSwitchMode(BtlMainModule *mainModule) {
    if (BtlSetup_GetBattleType(mainModule) == 1 && BtlSetup_GetBattleStyle(mainModule) == 0 &&
        func_ov167_0219bee4(mainModule) == 0 && func_ov167_0219c988(mainModule) == 0 &&
        func_02008a68(mainModule->setup->config) == 0) {
        return TRUE;
    }
    return FALSE;
}
