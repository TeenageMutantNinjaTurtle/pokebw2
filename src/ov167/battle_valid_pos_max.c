#include "battle/btl_main.h"
#include "battle/btl_setup.h"

// Function name from swan.
u32 GetValidPosMax(BtlMainModule *mainModule) {
    switch (mainModule->setup->battleStyle) {
    case 0:
        return 1;
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 5;
    default:
        return 5;
    }
}
