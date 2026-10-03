#include "field/field_script.h"
#include "field/mystery_gift_script.h"
#include "gfl/str.h"
#include "save/mystery_gift.h"
#include "save/player_info.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

u32 func_ov033_021782f0(void) {
    return 1;
}

void func_ov033_021782f4(u32 arg0, GameData *gameData, void *gift) {
    PlayerInfo *playerInfo;
    TrainerCardSave *card;
    u32 kind;
    u32 i;

    playerInfo = GetGameDataPlayerInfo(gameData);
    card = getTrainerCardDataBlkAddress(gameData);
    kind = func_ov033_021782d0(gift);
    for (i = 0; i < 8; i += 2) {
        if (data_ov033_0217c404[i] == kind) {
            setOneShotDRObtained(card, data_ov033_0217c404[i + 1], playerInfo);
            return;
        }
    }
}

u32 func_ov033_02178334(void) {
    return 6;
}

u32 func_ov033_02178338(WordSet *wordSet, void *gift, FieldScriptEnv *env) {
    PlayerInfo *playerInfo;
    u32 kind;

    playerInfo = GetGameDataPlayerInfo(FieldScriptEnv_GetGameData(env));
    FieldScriptEnv_GetHeapID(env);
    kind = func_ov033_021782d0(gift);
    copyVarForText(wordSet, 0, playerInfo);
    func_02024868(wordSet, 1, kind, 0);
    return 12;
}

u32 func_ov033_02178374(WordSet *wordSet, void *gift, FieldScriptEnv *env) {
    PlayerInfo *playerInfo;
    u32 kind;

    playerInfo = GetGameDataPlayerInfo(FieldScriptEnv_GetGameData(env));
    kind = func_ov033_021782d0(gift);
    copyVarForText(wordSet, 0, playerInfo);
    loadPassPowerToStrbuf(wordSet, 1, kind);
    return 13;
}

void *func_ov033_021783a8(void *save, u32 slot, void *gift) {
    u8 kind;

    if (!func_0200a800(save, slot)) {
        return NULL;
    }
    if (func_0200a820(save, slot) == 1) {
        return NULL;
    }
    if (!func_0200a71c(save, slot, gift)) {
        return NULL;
    }
    kind = *((u8 *)gift + 0xb3);
    if (kind == 0) {
        return NULL;
    }
    if (kind >= 5) {
        gift = NULL;
    }
    return gift;
}

void *func_ov033_021783f8(void *save, u32 *slot, void *gift) {
    s32 i;
    void *result;

    for (i = 0; i < 12; i++) {
        result = func_ov033_021783a8(save, i, gift);
        if (result != NULL) {
            *slot = i;
            return gift;
        }
    }
    return NULL;
}

void func_ov033_02178420(void *save, u32 slot) {
    func_0200a858(save, slot);
}

u32 func_ov033_02178428(void *save) {
    u32 slot;
    u8 gift[0xcc];
    void *result;

    result = func_ov033_021783f8(save, &slot, gift);
    if (result == NULL) {
        return 0;
    }
    return *((u8 *)result + 0xb3);
}
