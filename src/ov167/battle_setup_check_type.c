#include "battle/btl_main.h"
#include "battle/btl_setup.h"

// Function name from swan.
u32 BtlSetup_IsBattleType(BtlMainModule *mainModule, u32 flag) {
    return BtlSetup_CheckFlag(mainModule->setup, flag);
}
