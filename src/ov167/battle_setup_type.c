#include "battle/btl_main.h"
#include "battle/btl_setup.h"

// Function name from swan.
u32 BtlSetup_GetBattleType(BtlMainModule *mainModule) {
    return mainModule->setup->battleType;
}
