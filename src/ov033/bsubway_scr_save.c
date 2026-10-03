#include "field/bsubway_scr.h"
#include "save/bsubway_save.h"

void func_ov033_0217b6b4(BSubwayScrWork *bsw) {
    u8 mode;
    u32 score;

    if (bsw->playMode == 2) {
        mode = 3;
    } else if (bsw->playMode == 7) {
        mode = 8;
    }
    bsw->playMode = mode;
    func_0200e1ac(bsw->unk70, 0, &mode);
    if (func_0200e3dc(bsw->unk74, bsw->playMode) == 1) {
        score = func_0200e35c(bsw->unk74, bsw->playMode);
        func_ov033_0217bd88(bsw, score);
    } else {
        func_ov033_0217bda0(bsw);
    }
}

void func_ov033_0217b708(BSubwayScrWork *bsw) {
    u8 value;

    value = bsw->playMode;
    func_0200e1ac(bsw->unk70, 0, &value);
    func_0200e1ac(bsw->unk70, 5, bsw->unk1E);
    func_0200e1ac(bsw->unk70, 8, bsw->unk32);
    func_0200e100(bsw->unk70, 1);
    if (bsw->playMode == 2 || bsw->playMode == 7) {
        value = bsw->unkC_5;
        func_0200e1ac(bsw->unk70, 9, &value);
        func_0200e1ac(bsw->unk70, 6, bsw->unk628 + 20 * bsw->unkC_5);
        func_0200e1ac(bsw->unk70, 7, bsw->unk664 + bsw->unkC_5);
    }
}
