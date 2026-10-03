#include "field/field_script.h"
#include "field/mystery_gift_script.h"
#include "gfl/str.h"
#include "save/bag.h"
#include "save/player_info.h"
#include "system/game_data.h"

void func_ov033_021781e8(FieldScriptEnv *env, GameData *gameData, void *gift) {
    HeapID heapId;
    BagSave *bag;
    u16 item;

    heapId = FieldScriptEnv_GetHeapID(env);
    bag = GameData_GetBag(gameData);
    item = *(u32 *)gift;
    if (item != 0 && item <= 0x27e) {
        BagSave_AddItem(bag, item, 1, heapId);
    }
}

u32 func_ov033_02178218(u32 arg0, u32 arg1, void *gift) {
    u8 kind;

    kind = *((u8 *)gift + 0xb3);
    if (func_ov033_02178074(gift, kind) == 1) {
        return 4;
    }
    return 3;
}

u32 func_ov033_02178230(WordSet *wordSet, void *gift, FieldScriptEnv *env) {
    PlayerInfo *playerInfo;
    u16 item;

    playerInfo = GetGameDataPlayerInfo(FieldScriptEnv_GetGameData(env));
    item = *(u32 *)gift;
    copyVarForText(wordSet, 0, playerInfo);
    loadItemNameToStrbuf(wordSet, 1, item);
    return 7;
}

u32 func_ov033_02178260(WordSet *wordSet, void *gift) {
    loadItemNameToStrbuf(wordSet, 0, (u16) * (u32 *)gift);
    return 8;
}

u32 func_ov033_02178274(void) {
    return 1;
}
