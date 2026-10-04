#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_party.h"
#include "field/field_script.h"
#include "field/mystery_gift_delivery.h"
#include "field/mystery_gift_script.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/high_link.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "system/game_data.h"

u32 func_ov033_02177ed0(u32 index, u32 arg1, u32 arg2, u32 arg3) {
    u32 (*handler)(u32, u32, u32);

    handler = *(u32(**)(u32, u32, u32))(data_ov033_0217c410 + 24 * index);
    if (arg3 != 0 && handler != NULL) {
        return handler(arg1, arg2, arg3);
    }
    return 0;
}

u32 func_ov033_02177ef4(u32 index, u32 arg1, FieldScriptEnv *env) {
    WordSet *words;
    u32 (*handler)(WordSet *, u32, FieldScriptEnv *);

    words = ScriptWork_GetWordSet(FieldScriptEnv_GetScriptWork(env));
    handler = *(u32(**)(WordSet *, u32, FieldScriptEnv *))(data_ov033_0217c41c + 24 * index);
    if (arg1 != 0 && handler != NULL) {
        return handler(words, arg1, env);
    }
    return 7;
}

u32 func_ov033_02177f28(u32 index, u32 arg1, FieldScriptEnv *env) {
    WordSet *words;
    u32 (*handler)(WordSet *, u32, FieldScriptEnv *);

    words = ScriptWork_GetWordSet(FieldScriptEnv_GetScriptWork(env));
    handler = *(u32(**)(WordSet *, u32, FieldScriptEnv *))(data_ov033_0217c420 + 24 * index);
    if (arg1 != 0 && handler != NULL) {
        return handler(words, arg1, env);
    }
    return 8;
}

BOOL func_ov033_02177f5c(u32 index, u32 arg1, u32 arg2, u32 arg3) {
    void (*handler)(u32, u32, u32);

    handler = *(void (**)(u32, u32, u32))(data_ov033_0217c414 + 24 * index);
    if (arg3 != 0 && handler != NULL) {
        handler(arg1, arg2, arg3);
        return TRUE;
    }
    return FALSE;
}

u32 func_ov033_02177f84(u32 index, u32 arg1, u32 arg2, u32 arg3) {
    u32 (*handler)(u32, u32, u32);

    handler = *(u32(**)(u32, u32, u32))(data_ov033_0217c418 + 24 * index);
    if (arg3 != 0 && handler != NULL) {
        return handler(arg1, arg2, arg3);
    }
    return 0;
}

#define MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE 0x46

u16 GetActorIDOfMysteryGiftDeliveryMan(Field *field, GameData *gameData) {
    FieldActor *actor = FindMysteryGiftDeliveryManActor(field);
    if (actor != NULL) {
        return GetActorUID(actor);
    }

    s32 npcID = FindMysteryGiftDeliveryManNPCID(gameData);
    if (npcID >= 0) {
        return npcID;
    }
    return 0;
}

u16 IsMysteryGiftDeliveryManActorAvailable(Field *field) {
    return FindMysteryGiftDeliveryManActor(field) != NULL;
}

FieldActor *FindMysteryGiftDeliveryManActor(Field *field) {
    u32 index = 0;
    FieldActor *actor;
    MMSys *actorSystem = Field_GetActorSystem(field);

    while (NextActor(actorSystem, &actor, &index) == TRUE) {
        if (FldAct_GetObjCode(actor) == MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE) {
            return actor;
        }
    }
    return NULL;
}

s32 FindMysteryGiftDeliveryManNPCID(GameData *gameData) {
    EventData *eventData;
    ZoneNPC *npcs;
    s32 count;
    s32 i;

    eventData = GameData_GetEventData(gameData);
    npcs = GetZoneNPCs(eventData);
    count = GetZoneNPCsCount(eventData);

    if (npcs == NULL || count == 0) {
        return -1;
    }
    for (i = 0; i < count; i++) {
        if (npcs[i].modelId == MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE) {
            return *(u16 *)((u8 *)npcs + i * sizeof(ZoneNPC));
        }
    }
    return -1;
}

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

BOOL doesPartyHaveSpace(void *context, GameData *gameData) {
    return PokeParty_GetPkmCount(GameData_GetParty(gameData)) < 6;
}

void func_ov033_02178110(FieldScriptEnv *env, GameData *gameData, void *gift) {
    PokeParty *party;
    PartyPkm *pkm;

    party = GameData_GetParty(gameData);
    pkm = func_ov033_021780d8(env, gift);
    if (PokeParty_GetPkmCount(party) < 6 && pkm != NULL) {
        PokeParty_AddPkm(party, pkm);
        addPkmToDex(GameData_GetPokedex(gameData), pkm);
        GFL_HeapFree(pkm);
    }
}

u32 func_ov033_02178154(FieldScriptEnv *env, GameData *gameData, void *gift) {
    PartyPkm *pkm;
    u32 value;

    pkm = func_ov033_021780d8(env, gift);
    if (pkm == NULL) {
        return 1;
    }
    value = PokeParty_GetParam(pkm, (PkmField)0x4c, NULL);
    GFL_HeapFree(pkm);
    if (value == 1) {
        return 2;
    }
    return 1;
}

u32 func_ov033_02178180(WordSet *wordSet, void *gift, FieldScriptEnv *env) {
    PlayerInfo *playerInfo;
    PartyPkm *pkm;
    u32 result;

    playerInfo = GetGameDataPlayerInfo(FieldScriptEnv_GetGameData(env));
    pkm = func_ov033_021780d8(env, gift);
    result = 5;
    copyVarForText(wordSet, 0, playerInfo);
    if (pkm == NULL) {
        loadPokemonTextNameToStrbuf(wordSet, 1, 0);
    } else {
        if (PokeParty_GetParam(pkm, (PkmField)0x4c, NULL) == 1) {
            result = 11;
        } else {
            loadPokemonSpeciesTextNameToStrbuf(wordSet, 1, pkm);
        }
        GFL_HeapFree(pkm);
    }
    return result;
}

u32 func_ov033_021781e0(void) {
    return 6;
}

u32 func_ov033_021781e4(void) {
    return 1;
}

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