#include "battle/btl_main.h"
#include "battle/btl_setup.h"

// Function names from swan.
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

u32 func_ov167_0219be8c(BtlMainModule *mainModule) {
    switch (mainModule->setup->battleStyle) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 1;
    default:
        return 1;
    }
}

BOOL func_ov167_0219bebc(BtlMainModule *mainModule, u32 pos) {
    return pos < func_ov167_0219be8c(mainModule) * 2;
}

u32 BtlSetup_GetBattleType(BtlMainModule *mainModule) {
    return mainModule->setup->battleType;
}

u8 func_ov167_0219bedc(BtlMainModule *mainModule) {
    return ((u8 *)mainModule->setup)[0x22];
}

u8 func_ov167_0219bee4(BtlMainModule *mainModule) {
    return ((u8 *)mainModule->setup)[0x20];
}

BOOL func_ov167_0219beec(BtlMainModule *mainModule) {
    return ((u8 *)mainModule->setup)[0x22] != 0;
}

u16 func_ov167_0219bf00(BtlMainModule *mainModule) {
    return *(u16 *)((u8 *)mainModule->setup + 0x1a);
}

u16 func_ov167_0219bf08(BtlMainModule *mainModule) {
    return *(u16 *)((u8 *)mainModule->setup + 0x138);
}

u16 func_ov167_0219bf14(BtlMainModule *mainModule) {
    return *(u16 *)((u8 *)mainModule->setup + 0x13a);
}

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
