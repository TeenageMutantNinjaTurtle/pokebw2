#include "types.h"
#include "app/funfest_mission.h"
#include "app/name_entry.h"
#include "battle/btl_setup.h"
#include "demo/shinka_demo.h"
#include "constants/pokemon.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "field/encounter.h"
#include "field/encounter_effect.h"
#include "field/entree_forest.h"
#include "field/entree_scripts.h"
#include "field/event_abyssal_ruins.h"
#include "field/event_cgear_shutdown.h"
#include "field/event_chatot.h"
#include "field/event_dendou_machine.h"
#include "field/event_dive.h"
#include "field/event_field_trade.h"
#include "field/event_fishing.h"
#include "field/event_fly.h"
#include "field/event_funfest_mission.h"
#include "field/event_game_manual.h"
#include "field/event_mapchange.h"
#include "field/event_phrase_input.h"
#include "field/event_pokemon_center.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wild_battle.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_actor_animation.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_event.h"
#include "field/field_fog.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_money_window.h"
#include "field/field_move_scripts.h"
#include "field/field_move_tcb.h"
#include "field/field_party.h"
#include "field/field_player.h"
#include "field/field_prop.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_surf.h"
#include "field/field_task.h"
#include "field/field_visuals.h"
#include "field/fld_trade.h"
#include "field/funfest_scripts.h"
#include "field/mystery_gift_delivery.h"
#include "field/mystery_gift_script.h"
#include "field/ov131.h"
#include "field/pc_sound.h"
#include "field/player_state.h"
#include "field/subscreen.h"
#include "field/trial_house.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/bmpwin.h"
#include "gfl/fade.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "pml/evolution.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "save/chatter.h"
#include "save/dream_world.h"
#include "save/high_link.h"
#include "save/join_avenue.h"
#include "save/mystery_gift.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/records.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "save/trial_house.h"
#include "struct_decls.h"
#include "system/aeabi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"
#include "system/vm.h"

void func_ov033_0217b468(GameSystem *gsys) {
    func_02017954(GSYS_GetGameData(gsys), NULL);
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
    bsw = GFL_HeapAllocate(4, 0x7f0, 1, "bsubway_scr.c", 0x5f);
    bsw->heapId = 4;
    bsw->magic = 0x12345678;
    bsw->gameData = gameData;
    bsw->unkA[0] = getTrainerGender(playerInfo);
    bsw->unk70 = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_PLAY);
    bsw->unk74 = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_SCORE);
    bsw->unk78 = SaveControl_GetBlockPtr(save, SAVE_BLOCK_BSUBWAY_3A);
    func_0200e100(bsw->unk70, 0);
    func_02017954(gameData, bsw);
    if (a1 == 0) {
        bsw->playMode = a2;
        bsw->memberCount = func_ov033_0217bdc0(bsw->playMode);
        for (i = 0; i < 4; i++) bsw->memberSlots[i] = 0xff;
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
        bsw->memberCount = func_ov033_0217bdc0(bsw->playMode);
        if (func_0200e11c(bsw->unk70, 10, NULL) != 0) {
            func_ov033_0217bd34(bsw);
        }
        func_0200e11c(bsw->unk70, 5, bsw->memberSlots);
        func_0200e11c(bsw->unk70, 8, bsw->unk32);
        if (bsw->playMode == 2 || bsw->playMode == 7) {
            bsw->unkC_5 = (u8)func_0200e11c(bsw->unk70, 9, NULL);
            func_0200e11c(bsw->unk70, 6, &bsw->teamConfigs[bsw->unkC_5]);
            level = 303;
            if (getTrainerGender(&GameData_GetPlayerState(gameData)->playerInfo) != 0) {
                level -= 3;
            }
            teamIndex = bsw->unkC_5;
            count = func_0200e11c(bsw->unk70, 7, NULL);
            func_ov033_0217c2c4(bsw, &bsw->unk2C8[teamIndex], level + teamIndex, count,
                                &bsw->teamConfigs[teamIndex], bsw->heapId);
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
    func_02017954(GSYS_GetGameData(gsys), NULL);
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
    func_0200e1ac(bsw->unk70, 5, bsw->memberSlots);
    func_0200e1ac(bsw->unk70, 8, bsw->unk32);
    func_0200e100(bsw->unk70, 1);
    if (bsw->playMode == 2 || bsw->playMode == 7) {
        value = bsw->unkC_5;
        func_0200e1ac(bsw->unk70, 9, &value);
        func_0200e1ac(bsw->unk70, 6, &bsw->teamConfigs[bsw->unkC_5]);
        func_0200e1ac(bsw->unk70, 7, bsw->unk664 + bsw->unkC_5);
    }
}

void func_ov033_0217b790(BSubwayScrWork *bsw, GameSystem *gsys) {
    PokeParty *party;
    PartyPkm *pkm;
    s32 i;

    bsw->memberCount = func_ov033_0217bdc0(bsw->playMode);
    func_0200e11c(bsw->unk70, 5, bsw->memberSlots);
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < bsw->memberCount; i++) {
        pkm = PokeParty_GetPkm(party, bsw->memberSlots[i]);
        bsw->memberSpecies[i] = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
        bsw->memberItems[i] = PokeParty_GetParam(pkm, PKM_PARAM_ITEM, NULL);
    }
}

void func_ov033_0217b7e8(BSubwayScrWork *bsw) {
    u8 value;

    value = bsw->playMode;
    func_0200e1ac(bsw->unk70, 0, &value);
    func_0200e2ac(bsw->unk70);
    func_0200e1ac(bsw->unk70, 5, bsw->memberSlots);
    func_0200e100(bsw->unk70, 1);
    if (bsw->playMode == 2 || bsw->playMode == 7) {
        value = bsw->unkC_5;
        func_0200e1ac(bsw->unk70, 9, &value);
        func_0200e1ac(bsw->unk70, 6, &bsw->teamConfigs[bsw->unkC_5]);
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
        if (level < bsw->unk18) {
            level = bsw->unk18;
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

    if (bsw->unk84 != 0 || bsw->unk82 == 7 || bsw->unk82 == 8) {
        return 0;
    }
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < bsw->memberCount; i++) {
        if (bsw->memberChoices[i] - 1 >= 6) {
            bsw->memberChoices[i] = 1;
        }
        bsw->memberSlots[i] = bsw->memberChoices[i] - 1;
        pkm = PokeParty_GetPkm(party, bsw->memberSlots[i]);
        bsw->memberSpecies[i] = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
        bsw->memberItems[i] = PokeParty_GetParam(pkm, PKM_PARAM_ITEM, NULL);
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
    bsw->unkC_0 = 0;
    bsw->unkC_1 = 0;
}

void func_ov033_0217bbac(BSubwayScrWork *bsw) {
    u16 ids[2];
    u16 values[2];
    s32 index;
    u32 round;
    u32 slot;

    round = func_0200e2ec(bsw->unk70);
    switch (bsw->playMode) {
    case 4:
        func_0200e740(bsw->unk78, bsw->trainers, round, bsw->heapId);
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        slot = round * 2;
        func_ov033_0217c264(bsw, &bsw->trainers[0], bsw->unk32[slot], bsw->memberCount, NULL, NULL, NULL,
                            bsw->heapId);
        for (index = 0; index < bsw->memberCount; index++) {
            ids[index] = bsw->trainers[0].pokemon[index].species;
            values[index] = bsw->trainers[0].pokemon[index].item;
        }
        func_ov033_0217c264(bsw, &bsw->trainers[1], bsw->unk32[slot + 1], bsw->memberCount, ids, values, NULL,
                            bsw->heapId);
        break;
    default:
        func_ov033_0217c264(bsw, &bsw->trainers[0], bsw->unk32[round], bsw->memberCount, NULL, NULL, NULL,
                            bsw->heapId);
        break;
    }
}

u32 func_ov033_0217bca0(BSubwayScrWork *bsw, u16 index) {
    return func_ov012_02162b38(bsw->trainers[index].trainerId);
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

    base = 0x12c;
    if (variant != 0) {
        base += 3;
    }
    for (index = 0; index < 3; index++) {
        bsw->unk664[index] = func_ov033_0217c264(bsw, &bsw->unk2C8[index], base + index, bsw->memberCount,
                                                 bsw->memberSpecies, bsw->memberItems, &bsw->teamConfigs[index],
                                                 bsw->heapId);
    }
}

void func_ov033_0217bf04(BSubwayPokemon *dst, PartyPkm *pkm) {
    s32 i;

    dst->species = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
    dst->form = PokeParty_GetParam(pkm, PKM_PARAM_FORM, NULL);
    dst->item = PokeParty_GetParam(pkm, PKM_PARAM_ITEM, NULL);
    for (i = 0; i < 4; i++) {
        dst->moves[i] = PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + i, NULL);
        dst->ppUps |= PokeParty_GetParam(pkm, PKM_PARAM_MOVE1_PP_UP + i, NULL) << (2 * i);
    }
    dst->region = PokeParty_GetParam(pkm, PKM_PARAM_REGION, NULL);
    dst->id = PokeParty_GetParam(pkm, PKM_PARAM_ID, NULL);
    dst->personality = PokeParty_GetParam(pkm, PKM_PARAM_PID, NULL);
    dst->ivs = PokeParty_GetParam(pkm, PKM_PARAM_IVS_ALL, NULL);
    for (i = 0; i < 6; i++) {
        dst->evs[i] = PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + i, NULL);
    }
    dst->ability = PokeParty_GetParam(pkm, PKM_PARAM_ABILITY, NULL);
    dst->happiness = PokeParty_GetParam(pkm, PKM_PARAM_HAPPINESS, NULL);
    PokeParty_GetParam(pkm, PKM_PARAM_NICKNAME_RAW, dst->nickname);
}

void func_ov033_0217c010(BSubwayScrWork *bsw, SaveControl *save, u32 flag) {
    BSubwayPokemon *team;
    PokeParty *party;
    s32 i;
    HeapID heapId = bsw->heapId;

    team = GFL_HeapAllocate(HEAPID_TAIL(heapId), sizeof(BSubwayPokemon) * 3, FALSE, "bsubway_scr.c", 0x8a1);
    sys_memset(team, 0, sizeof(BSubwayPokemon) * 3);
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < 3; i++) {
        func_ov033_0217bf04(&team[i], PokeParty_GetPkm(party, bsw->memberSlots[i]));
    }
    func_0200e4e8(bsw->unk74, flag, team);
    sys_memset(team, 0, sizeof(BSubwayPokemon) * 3);
    GFL_HeapFree(team);
}

BtlSetup *func_ov033_0217c094(BSubwayScrWork *bsw, GameSystem *gsys) {
    PokeParty *party;
    PokeParty *source;
    PartyPkm *pkm;
    BtlSetup *result;
    s32 i;

    party = PokeParty_Create(0x8004);
    source = func_ov033_0217bd60(bsw);
    PokeParty_InitCore(party, bsw->memberCount);
    for (i = 0; i < bsw->memberCount; i++) {
        pkm = PokeParty_GetPkm(source, bsw->memberSlots[i]);
        PokeParty_AddPkm(party, pkm);
    }
    result =
        SetupTrialHouseBattle(gsys, party, bsw->playMode, bsw->trainers, &bsw->unk2C8[bsw->unkC_5], bsw->memberCount);
    GFL_HeapFree(party);
    return result;
}

void *func_ov033_0217c110(BSubwayScrWork *bsw) {
    return bsw->unk74C;
}

BOOL func_ov033_0217c264(BSubwayScrWork *bsw, BSubwayTrainer *trainer, u16 trainerId, u32 count, const u16 *species,
                         const u16 *items, const BSubwayTeamConfig *config, HeapID heapId) {
    return func_ov012_02162864(trainer, trainerId, count, species, items, config, heapId);
}

u16 func_ov033_0217c288(u32 value) {
    if (value < 100) {
        return 3;
    }
    if (value < 120) {
        return 6;
    }
    if (value < 140) {
        return 9;
    }
    if (value < 160) {
        return 12;
    }
    if (value < 180) {
        return 15;
    }
    if (value < 200) {
        return 18;
    }
    if (value < 220) {
        return 21;
    }
    return 31;
}

void func_ov033_0217c2c4(BSubwayScrWork *bsw, BSubwayTrainer *trainer, u16 trainerId, u32 count,
                         const BSubwayTeamConfig *config, HeapID heapId) {
    u32 adjusted;
    void *temp;
    s32 i;

    temp = func_ov012_021628c0(trainer, 0xd4, trainerId, 15, heapId);
    adjusted = func_ov033_0217c288(trainerId);
    for (i = 0; i < 2; i++) {
        func_ov012_02162490(&trainer->pokemon[i], 0xd3, config->unk4[i], config->unk0, config->unk8[i], adjusted, i,
                            count, heapId);
    }
    GFL_HeapFree(temp);
}

u16 randFFFFFFFFdivFFFF(void) {
    return GFL_RandomLC(0xffffffff) / 0xffff;
}
