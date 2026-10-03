#include "field/field_script.h"
#include "field/mystery_gift_script.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/player_info.h"
#include "system/game_data.h"

BOOL func_ov033_02178074(void *gift, u32 kind) {
    if (kind != 2) {
        return FALSE;
    }
    if (*(u16 *)((u8 *)gift + 0xb0) != 0x7fe) {
        return FALSE;
    }
    if (*(u32 *)gift == 0x23e) {
        return TRUE;
    }
    return FALSE;
}

u32 func_ov033_021780a4(FieldScriptEnv *env, void *gift, u32 kind) {
    PartyPkm *pkm;
    PlayerInfo *playerInfo;
    u32 result;

    if (kind == 1) {
        pkm = func_ov033_021780d8(env, gift);
        if (pkm != NULL) {
            playerInfo = GetGameDataPlayerInfo(FieldScriptEnv_GetGameData(env));
            result = func_02035cf8(pkm, 8, playerInfo);
            GFL_HeapFree(pkm);
            return result;
        }
    }
    return 0;
}

PartyPkm *func_ov033_021780d8(FieldScriptEnv *env, void *gift) {
    HeapID heapId;
    GameData *gameData;

    heapId = FieldScriptEnv_GetHeapID(env);
    gameData = FieldScriptEnv_GetGameData(env);
    return func_ov012_02153160(gift, heapId, gameData);
}
