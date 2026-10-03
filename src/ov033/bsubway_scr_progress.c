#include "field/bsubway_scr.h"
#include "save/bsubway_save.h"
#include "system/game_data.h"

BOOL func_ov033_0217bb20(BSubwayScrWork *bsw) {
    if (!bsw->unkC_0) {
        if (func_0200e2ec(bsw->unk70) < 7) {
            return FALSE;
        }
        bsw->unkC_0 = 1;
    }
    return TRUE;
}

void func_ov033_0217bb4c(BSubwayScrWork *bsw, GameSystem *gsys) {
    u8 mode;
    u16 value;

    mode = bsw->playMode;
    value = func_ov033_0217bd84(bsw);
    func_0200e3a0(bsw->unk74, mode, value);
    func_0200e384(bsw->unk74, mode, func_0200e35c(bsw->unk74, mode));
    func_0200e3f8(bsw->unk74, mode);
    func_ov033_0217be2c(bsw, GameData_GetSaveControl(bsw->gameData), 1, value);
    func_0200e2ac(bsw->unk70);
}

void func_ov033_0217bb98(BSubwayScrWork *bsw, GameSystem *gsys) {
    volatile BSubwayScrWork *work = bsw;

    work->unkC_0 = 0;
    work->unkC_1 = 0;
}
