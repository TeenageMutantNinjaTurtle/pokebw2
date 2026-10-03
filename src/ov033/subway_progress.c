#include "field/bsubway_scr.h"
#include "save/bsubway_save.h"

u16 func_ov033_0217bdc0(u16 mode) {
    switch (mode) {
    case 0:
    case 4:
    case 5:
        return 3;
    case 1:
    case 6:
        return 4;
    case 2:
    case 3:
    case 7:
    case 8:
        return 2;
    default:
        return 0;
    }
}

BOOL func_ov033_0217bdf4(const u16 *list, u16 value, u16 count) {
    u16 i;

    for (i = 0; i < count; i++) {
        if (list[i] == value) {
            return TRUE;
        }
    }
    return FALSE;
}

u16 func_ov033_0217be1c(s32 value) {
    return value / 7;
}

void func_ov033_0217be2c(BSubwayScrWork *bsw, SaveControl *save, u32 a2, u32 a3) {
    u8 mode;

    switch (bsw->playMode) {
    case 0:
        func_ov033_0217c010(bsw, save, 0);
        return;
    case 4:
        func_ov033_0217c010(bsw, save, 1);
        mode = bsw->playMode;
        func_0200e1ac(bsw->unk70, 0, &mode);
        mode = func_0200e2ec(bsw->unk70) + 1;
        func_0200e1ac(bsw->unk70, 1, &mode);
        func_0200e52c(bsw->unk74, bsw->unk70);
        return;
    case 1:
        return;
    }
}