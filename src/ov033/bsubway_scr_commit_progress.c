#include "field/bsubway_scr.h"
#include "save/bsubway_save.h"

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
