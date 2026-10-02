#include "battle/btl_main.h"
#include "battle/btl_setup.h"
#include "save/config.h"

// Function name from swan.
BOOL IsSwitchMode(BtlMainModule *mainModule) {
    if (BtlSetup_GetBattleType(mainModule) == 1 && BtlSetup_GetBattleStyle(mainModule) == 0 &&
        func_ov167_0219bee4(mainModule) == 0 && func_ov167_0219c988(mainModule) == 0 &&
        func_02008a68(mainModule->setup->config) == 0) {
        return TRUE;
    }
    return FALSE;
}
