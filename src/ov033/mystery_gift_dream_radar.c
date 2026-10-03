#include "field/field_script.h"
#include "field/mystery_gift_script.h"
#include "gfl/str.h"
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
