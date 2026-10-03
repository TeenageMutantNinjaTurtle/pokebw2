#include "battle/btl_setup.h"
#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "save/bsubway_save.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov033_0217b664(GameSystem *gsys, BSubwayScrWork *bsw) {
    if (bsw != NULL) {
        if (bsw->allocatedBuffer != NULL) {
            GFL_HeapFree(bsw->allocatedBuffer);
            bsw->allocatedBuffer = NULL;
        }
        if (bsw->btlSetup != NULL) {
            BtlSetup_Free(bsw->btlSetup);
            bsw->btlSetup = NULL;
        }
        sys_memset(bsw, 0, sizeof(BSubwayScrWork));
        GFL_HeapFree(bsw);
    }
    func_02017954(GSYS_GetGameData(gsys), 0);
}

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

void func_ov033_0217b790(BSubwayScrWork *bsw, GameSystem *gsys) {
    PokeParty *party;
    PartyPkm *pkm;
    s32 i;

    bsw->unk0[8] = func_ov033_0217bdc0(bsw->playMode);
    func_0200e11c(bsw->unk70, 5, bsw->unk1E);
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < bsw->unk0[8]; i++) {
        pkm = PokeParty_GetPkm(party, bsw->unk1E[i]);
        bsw->unk22[i] = PokeParty_GetParam(pkm, (PkmField)5, NULL);
        bsw->unk22[i + 4] = PokeParty_GetParam(pkm, (PkmField)6, NULL);
    }
}

void func_ov033_0217b7e8(BSubwayScrWork *bsw) {
    u8 value;

    value = bsw->playMode;
    func_0200e1ac(bsw->unk70, 0, &value);
    func_0200e2ac(bsw->unk70);
    func_0200e1ac(bsw->unk70, 5, bsw->unk1E);
    func_0200e100(bsw->unk70, 1);
    if (bsw->playMode == 2 || bsw->playMode == 7) {
        value = bsw->unkC_5;
        func_0200e1ac(bsw->unk70, 9, &value);
        func_0200e1ac(bsw->unk70, 6, bsw->unk628 + 20 * bsw->unkC_5);
        func_0200e1ac(bsw->unk70, 7, bsw->unk664 + bsw->unkC_5);
    }
}

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