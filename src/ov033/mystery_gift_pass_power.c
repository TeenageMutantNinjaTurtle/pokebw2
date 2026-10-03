#include "field/field_script.h"
#include "field/mystery_gift_script.h"
#include "gfl/str.h"
#include "save/high_link.h"
#include "save/player_info.h"
#include "save/save_control.h"
#include "system/game_data.h"

u32 func_ov033_02178278(u32 arg0, GameData *gameData, void *gift) {
    SaveControl *saveControl;
    HighLinkSave *save;

    saveControl = GameData_GetSaveControl(gameData);
    save = getHighLinkBlockAddress(saveControl);
    return func_0200c6a0(save, *(u32 *)gift);
}

u32 func_ov033_02178290(void) {
    return 5;
}

u32 func_ov033_02178294(WordSet *wordSet, void *gift, FieldScriptEnv *env) {
    GameData *gameData;
    PlayerInfo *playerInfo;
    u32 passPower;

    gameData = FieldScriptEnv_GetGameData(env);
    getHighLinkBlockAddress(GameData_GetSaveControl(gameData));
    playerInfo = GetGameDataPlayerInfo(gameData);
    passPower = *(u32 *)gift;
    copyVarForText(wordSet, 0, playerInfo);
    loadPassPowerToStrbuf(wordSet, 1, passPower);
    return 9;
}

u32 func_ov033_021782cc(void) {
    return 10;
}
