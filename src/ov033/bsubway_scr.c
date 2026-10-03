#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "save/box.h"
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

struct SubwayPackedSpecies {
    u16 species : 11;
    u16 form : 5;
};

void func_ov033_0217bbac(BSubwayScrWork *bsw) {
    u16 ids[2];
    u16 values[2];
    s32 index;
    u32 round;
    u32 slot;

    round = func_0200e2ec(bsw->unk70);
    switch (bsw->playMode) {
    case 4:
        func_0200e740(*(void **)bsw->unk78, bsw->unk88, round, *(u32 *)&bsw->unk0[4]);
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        index = 0;
        slot = round * 2;
        func_ov033_0217c264(bsw, bsw->unk88, bsw->unk32[slot], bsw->unk0[8], index, index, index,
                            *(u32 *)&bsw->unk0[4]);
        for (; index < bsw->unk0[8]; index++) {
            ids[index] = ((SubwayPackedSpecies *)((u8 *)bsw + 0xb8 + index * 0x3c))->species;
            values[index] = *(u16 *)((u8 *)bsw + 0xba + index * 0x3c);
        }
        func_ov033_0217c264(bsw, bsw->unk88 + 0x120, bsw->unk32[slot + 1], bsw->unk0[8], (u32)ids,
                            (u32)values, 0, *(u32 *)&bsw->unk0[4]);
        break;
    default:
        func_ov033_0217c264(bsw, bsw->unk88, bsw->unk32[round], bsw->unk0[8], 0, 0, 0,
                            *(u32 *)&bsw->unk0[4]);
        break;
    }
}

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

void func_ov033_0217bda8(BSubwayScrWork *bsw, u32 count, u32 extra) {
    u32 value;

    value = count * 7;
    value += extra;

    if (value > 0xffff) {
        value = 0xffff;
    }
    bsw->unkE = value;
}

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
