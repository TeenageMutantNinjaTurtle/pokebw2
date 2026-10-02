#include "battle/btl_main.h"
#include "battle/btl_setup.h"

// Function names from swan.
u32 GetRunMode(BtlMainModule *mainModule) {
    switch (mainModule->setup->battleType) {
    case 0:
        return 0;
    case 1:
        if (func_ov167_0219c988(mainModule) == 1) {
            return 2;
        }
        return 1;
    case 2:
        return 2;
    case 3:
        return 2;
    default:
        return 1;
    }
}

void *GetFieldEffectData(BtlMainModule *mainModule) {
    return &mainModule->setup->unk8[0];
}
