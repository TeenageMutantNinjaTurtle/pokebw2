#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "system/game_data.h"

u32 func_ov033_0217bca0(BSubwayScrWork *bsw, u16 index) {
    return func_ov012_02162b38(*(u16 *)((u8 *)bsw + 0x8c + 0x120 * index));
}

u16 func_ov033_0217bcb4(BSubwayScoreData *score, GameSystem *gsys, u32 op) {
    u8 value;
    u32 limit;

    value = func_0200e4a0(score);
    switch (op) {
    case 0:
        return value;
    case 3:
        func_0200e438(score, 0, 2);
        if (value == 10) {
            return 0;
        }
        func_0200e488(score);
        return 1;
    case 4:
        limit = func_0200e4a4(score, 3);
        if (value == 1) {
            return 0;
        }
        if (limit >= data_ov033_0217c564[value - 1]) {
            func_0200e494(score);
            func_0200e4a4(score, 2);
            func_0200e438(score, 0, 2);
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}

void func_ov033_0217bd34(BSubwayScrWork *bsw) {
    if (bsw->allocatedBuffer != NULL) {
        GFL_HeapFree(bsw->allocatedBuffer);
    }
    bsw->allocatedBuffer =
        convertBoxedPokeSetToParty(getBattleBox(GameData_GetSaveControl(bsw->gameData)), HEAPID_GAMEEVENT);
}

PokeParty *func_ov033_0217bd60(BSubwayScrWork *bsw) {
    if (func_0200e11c(bsw->unk70, 10, NULL) == 0) {
        return GameData_GetParty(bsw->gameData);
    }
    return bsw->allocatedBuffer;
}

u16 func_ov033_0217bd84(BSubwayScrWork *bsw) {
    return bsw->unkE;
}

void func_ov033_0217bd88(BSubwayScrWork *bsw, u32 value) {
    bsw->unkE = value;
}

void func_ov033_0217bd8c(BSubwayScrWork *bsw) {
    if (bsw->unkE < 0xffff) {
        bsw->unkE++;
    }
}

void func_ov033_0217bda0(BSubwayScrWork *bsw) {
    bsw->unkE = 0;
}