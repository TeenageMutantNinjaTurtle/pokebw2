#include "field/bsubway_scr.h"
#include "save/bsubway_save.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

u16 func_ov033_0217b86c(GameSystem *gsys) {
    SaveControl *save;
    BSubwayPlayData *play;
    BSubwayScoreData *score;
    u8 mode;

    save = GameData_GetSaveControl(GSYS_GetGameData(gsys));
    play = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_PLAY);
    score = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_SCORE);
    mode = func_0200e11c(play, 0, NULL);
    func_0200e2ac(play);
    func_0200e3b4(score, mode);
    return mode;
}

void func_ov033_0217b8ac(GameSystem *gsys, BSubwayScrWork *bsw) {
    u16 value;
    u8 mode;
    BSubwayScoreData *score;

    value = bsw->unkE;
    mode = bsw->playMode;
    score = bsw->unk74;
    func_0200e3a0(score, mode, value);
    func_0200e384(score, mode, value);
    func_ov033_0217be2c(bsw, GameData_GetSaveControl(bsw->gameData), 1, value);
    func_0200e3b4(bsw->unk74, mode);
    func_0200e2ac(bsw->unk70);
}
