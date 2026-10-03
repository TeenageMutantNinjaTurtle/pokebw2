#include "field/trial_house.h"
#include "save/trial_house.h"
#include "system/game_data.h"
#include "system/game_system.h"

struct TrialHouseSave {
    u8 flag0;
    u8 pad1[0x13];
    u8 flag14;
    u8 pad15[0x13];
    u8 bits[16];
};

u32 func_ov033_0217b32c(GameSystem *gsys) {
    TrialHouseSave *save;

    save = func_0200f1b8(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    if (save->flag0) {
        if (save->flag14) {
            return 3;
        }
        return 1;
    }
    if (save->flag14) {
        return 2;
    }
    return 0;
}

u8 func_ov033_0217b35c(void *savePtr, u32 index) {
    TrialHouseSave *save;
    u8 byte;
    u8 bit;

    save = savePtr;
    if (index < 128) {
        byte = save->bits[(u8)(index >> 3)];
        bit = index & 7;
        return (byte >> bit) & 1;
    }
    return TRUE;
}

void func_ov033_0217b384(void *savePtr, u32 index) {
    TrialHouseSave *save;
    u8 byteIndex;
    u8 bit;
    u8 mask;

    save = savePtr;
    if (index < 128) {
        byteIndex = index >> 3;
        bit = index & 7;
        mask = 1 << bit;
        save->bits[byteIndex] |= mask;
    }
}
