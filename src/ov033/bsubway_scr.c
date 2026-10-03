#include "battle/btl_setup.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "field/player_state.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "save/records.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov033_0217b468(GameSystem *gsys) {
    func_02017954(GSYS_GetGameData(gsys), 0);
}

BSubwayScrWork *func_ov033_0217b478(GameSystem *gsys, u16 a1, u16 a2) {
    GameData *gameData;
    PlayerInfo *playerInfo;
    SaveControl *save;
    BSubwayScrWork *bsw;
    s32 i;
    u8 value;
    u32 count;
    u32 score;
    u32 level;
    u32 teamIndex;
    u8 mode;

    gameData = GSYS_GetGameData(gsys);
    playerInfo = GetGameDataPlayerInfo(gameData);
    save = GameData_GetSaveControl(gameData);
    bsw = GFL_HeapAllocate(4, 0x7f0, 1, data_ov033_0217c640, 0x5f);
    *(u32 *)((u8 *)bsw + 4) = 4;
    *(u32 *)bsw = 0x12345678;
    bsw->gameData = gameData;
    bsw->unkA[0] = getTrainerGender(playerInfo);
    bsw->unk70 = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_PLAY);
    bsw->unk74 = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_SCORE);
    *(void **)bsw->unk78 = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_3A);
    func_0200e100(bsw->unk70, 0);
    func_02017954(gameData, (u32)bsw);
    if (a1 == 0) {
        bsw->playMode = a2;
        bsw->unk0[8] = func_ov033_0217bdc0(bsw->playMode);
        for (i = 0; i < 4; i++) bsw->unk1E[i] = 0xff;
        for (i = 0; i < 14; i++) bsw->unk32[i] = 0xffff;
        func_0200e0f4(bsw->unk70);
        func_0200e2ac(bsw->unk70);
        if (func_0200e3dc(bsw->unk74, bsw->playMode) == 1) {
            score = func_0200e35c(bsw->unk74, bsw->playMode);
            func_ov033_0217bd88(bsw, score);
        }
        value = bsw->playMode;
        func_0200e1ac(bsw->unk70, 0, &value);
    } else {
        bsw->playMode = func_0200e11c(bsw->unk70, 0, NULL);
        bsw->unk0[8] = func_ov033_0217bdc0(bsw->playMode);
        if (func_0200e11c(bsw->unk70, 10, NULL) != 0) {
            func_ov033_0217bd34(bsw);
        }
        func_0200e11c(bsw->unk70, 5, bsw->unk1E);
        func_0200e11c(bsw->unk70, 8, bsw->unk32);
        if (bsw->playMode == 2 || bsw->playMode == 7) {
            bsw->unkC_5 = (u8)func_0200e11c(bsw->unk70, 9, NULL);
            func_0200e11c(bsw->unk70, 6, bsw->unk628 + 20 * bsw->unkC_5);
            level = 303;
            if (getTrainerGender(&GameData_GetPlayerState(gameData)->playerInfo) != 0) {
                level -= 3;
            }
            teamIndex = bsw->unkC_5;
            count = func_0200e11c(bsw->unk70, 7, NULL);
            func_ov033_0217c2c4(bsw, bsw->unk2C8 + 0x120 * teamIndex, (u16)(level + teamIndex),
                                count, (BSubwayTeamConfig *)(bsw->unk628 + 20 * teamIndex), *(u32 *)((u8 *)bsw + 4));
        }
        mode = bsw->playMode;
        if (func_0200e3dc(bsw->unk74, mode) == 1) {
            count = func_0200e2ec(bsw->unk70);
            score = func_0200e418(bsw->unk74, mode);
            func_ov033_0217bda8(bsw, score, count);
        }
    }
    return bsw;
}

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

u16 func_ov033_0217b8ec(BSubwayScrWork *bsw) {
    u16 count;
    u16 countIndex;
    s32 index;
    u16 category;
    u16 reward;
    SaveControl *save;
    const u8 *row;

    if (bsw->playMode == 4) {
        reward = 0;
        if ((u16)func_0200e11c(bsw->unk70, 11, NULL) == 1) {
            index = (s8)func_0200e4a0(bsw->unk74);
            if (index < 0) {
                index = 0;
            } else if (index >= 10) {
                index = 9;
            }
            reward = data_ov033_0217c5ac[index];
        } else {
            reward = 5;
        }
    } else {
        reward = 0;
        count = func_0200e418(bsw->unk74, bsw->playMode);
        switch (bsw->playMode) {
        case 0:
            category = 0;
            break;
        case 5:
            category = 1;
            reward = 1;
            break;
        case 1:
            category = 2;
            break;
        case 6:
            category = 3;
            reward = 1;
            break;
        case 2:
            category = 4;
            break;
        case 3:
            category = 4;
            break;
        case 7:
            category = 5;
            reward = 1;
            break;
        case 8:
            category = 5;
            reward = 1;
            break;
        case 4:
            category = 6;
            break;
        default:
            category = 0;
            break;
        }
        countIndex = count - 1;
        if ((s16)countIndex < 0) {
            countIndex = 0;
        } else if (countIndex >= 10) {
            countIndex = 9;
        }
        if (bsw->unkC_1 != 0) {
            if (reward == 1) {
                reward = 30;
            } else {
                reward = 10;
            }
        } else {
            row = data_ov033_0217c570 + 10 * category;
            reward = row[countIndex];
        }
    }
    if (reward == 0) {
        reward = 1;
    }
    func_0200e318(bsw->unk74, reward);
    if (reward != 0) {
        save = GameData_GetSaveControl(bsw->gameData);
        RecordAdd(getTrainerCardInfoBlkAddress(save), 0x21, reward);
    }
    return reward;
}

void func_ov033_0217b9dc(BSubwayScrWork *bsw) {
    u8 mode;
    u16 level;
    u16 choice;
    s32 i;

    mode = bsw->playMode;
    level = func_ov033_0217be1c(func_ov033_0217bd84(bsw));
    if (mode == 2 || mode == 3 || mode == 7 || mode == 8) {
        if (level < *(u16 *)((u8 *)bsw + 0x18)) {
            level = *(u16 *)((u8 *)bsw + 0x18);
        }
        for (i = 0; i < 14; i++) {
            do {
                choice = func_ov033_0217c11c(bsw, level, (u8)(i / 2), mode, (u8)(i & 1));
            } while (func_ov033_0217bdf4(bsw->unk32, choice, i));
            bsw->unk32[i] = choice;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                choice = func_ov033_0217c11c(bsw, level, (u8)i, bsw->playMode, 0);
            } while (func_ov033_0217bdf4(bsw->unk32, choice, i));
            bsw->unk32[i] = choice;
        }
    }
}

u16 func_ov033_0217ba94(BSubwayScrWork *bsw, GameSystem *gsys) {
    PokeParty *party;
    PartyPkm *pkm;
    u16 i;
    u8 *entry;
    u8 *slot;

    if (*(u16 *)((u8 *)bsw + 0x84) != 0 || (u16)(*(u16 *)((u8 *)bsw + 0x82) + 0xfff9) <= 1) {
        return 0;
    }
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < bsw->unk0[8]; i++) {
        entry = (u8 *)bsw + i;
        if (entry[0x7c] - 1 >= 6) {
            entry[0x7c] = 1;
        }
        entry[0x1e] = entry[0x7c] - 1;
        pkm = PokeParty_GetPkm(party, entry[0x1e]);
        slot = (u8 *)bsw + 2 * i;
        *(u16 *)(slot + 0x22) = PokeParty_GetParam(pkm, (PkmField)5, NULL);
        *(u16 *)(slot + 0x2a) = PokeParty_GetParam(pkm, (PkmField)6, NULL);
    }
    return 1;
}

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

void func_ov033_0217be88(BSubwayScrWork *bsw, u8 variant) {
    u32 base;
    s32 index;
    u8 result;
    u32 second;
    u32 first;

    base = 0x12c;
    if (variant != 0) {
        base += 3;
    }
    first = (u32)bsw->unk22;
    second = (u32)&bsw->unk22[4];
    for (index = 0; index < 3; index++) {
        result = (u32)func_ov033_0217c264(bsw, bsw->unk2C8 + 0x120 * index, base + index, bsw->unk0[8],
                                            first, second, (u32)(bsw->unk628 + 0x14 * index),
                                            *(u32 *)&bsw->unk0[4]);
        bsw->unk664[index] = result;
    }
}

void func_ov033_0217bf04(u8 *dst, PartyPkm *pkm) {
    u32 value;
    u8 *ppFlags;
    u8 packed;
    s32 i;
    s32 j;

    ((SubwayPackedSpecies *)dst)->species = PokeParty_GetParam(pkm, (PkmField)5, NULL);
    ((SubwayPackedSpecies *)dst)->form = PokeParty_GetParam(pkm, (PkmField)0x6f, NULL);
    *(u16 *)(dst + 2) = PokeParty_GetParam(pkm, (PkmField)6, NULL);

    for (i = 0; i < 4; i++) {
        value = PokeParty_GetParam(pkm, (PkmField)(0x36 + i), NULL);
        ((u16 *)dst)[i + 2] = value;
        value = PokeParty_GetParam(pkm, (PkmField)(0x3e + i), NULL);
        packed = value << (2 * i);
        ppFlags = dst + 0x1e;
        *ppFlags |= packed;
    }
    dst[0x1f] = PokeParty_GetParam(pkm, (PkmField)0xc, NULL);
    *(u32 *)(dst + 0xc) = PokeParty_GetParam(pkm, (PkmField)7, NULL);
    *(u32 *)(dst + 0x10) = PokeParty_GetParam(pkm, (PkmField)0, NULL);
    *(u32 *)(dst + 0x14) = PokeParty_GetParam(pkm, (PkmField)0xac, NULL);
    for (j = 0; j < 6; j++) {
        dst[0x18 + j] = PokeParty_GetParam(pkm, (PkmField)(0xd + j), NULL);
    }
    dst[0x20] = PokeParty_GetParam(pkm, (PkmField)0xa, NULL);
    dst[0x21] = PokeParty_GetParam(pkm, (PkmField)9, NULL);
    PokeParty_GetParam(pkm, (PkmField)0x74, dst + 0x22);
}

void func_ov033_0217c010(BSubwayScrWork *bsw, SaveControl *save, u32 flag) {
    void *team;
    PokeParty *party;
    s32 i;
    u16 heapId;

    heapId = *(u32 *)((u8 *)bsw + 4);
    team = GFL_HeapAllocate((heapId & 0x7fff) | 0x8000, 0xb4, FALSE, data_ov033_0217c640, 0x8a1);
    sys_memset(team, 0, 0xb4);
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < 3; i++) {
        func_ov033_0217bf04((u8 *)team + 0x3c * i, PokeParty_GetPkm(party, bsw->unk1E[i]));
    }
    func_0200e4e8(bsw->unk74, flag, team);
    sys_memset(team, 0, 0xb4);
    GFL_HeapFree(team);
}
