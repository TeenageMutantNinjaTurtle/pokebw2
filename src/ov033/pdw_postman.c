#include "types.h"
#include "app/funfest_mission.h"
#include "app/name_entry.h"
#include "battle/btl_setup.h"
#include "demo/shinka_demo.h"
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

#define MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE 0x46

FieldMoneyWindow *func_ov033_02177998(Field *field, u32 value, u32 lines) {
    u16 heapId;
    FieldMoneyWindow *work;
    s32 height;

    heapId = Field_GetHeapID(field);
    work = GFL_HeapAllocate(heapId, sizeof(FieldMoneyWindow), TRUE, "pdw_postman.c", 0x73);
    work->heapId = heapId;
    work->field = field;
    work->unk24 = value;
    work->unk20 = lines;
    work->messages = GFL_MsgSysLoadData(FALSE, 3, 0x1e0, heapId);
    work->wordSet = GFL_WordSetSystemCreateDefault(heapId);
    work->first = GFL_StrBufCreate(0x80, heapId);
    work->second = GFL_StrBufCreate(0x80, heapId);
    height = ((14 * (s32)lines + 7) & ~7) / 8;
    work->window = FieldMsgBG_CreateMoneyWin(Field_GetMsgBGSys(field), (u32)work->messages, 1, 1, 0x15, height);
    return work;
}

void func_ov033_02177a28(FieldMoneyWindow *work) {
    func_ov036_02187c7c(work->window);
    func_ov036_02187c1c(work->window);
    GFL_BGSysLoadScr(1);
    GFL_StrBufFree(work->first);
    GFL_StrBufFree(work->second);
    GFL_WordSetSystemFree(work->wordSet);
    GFL_MsgDataFree(work->messages);
    GFL_HeapFree(work);
}

void func_ov033_02177a60(FieldMoneyWindow *work) {
    MsgData *messages;
    s32 i;
    u32 y;
    s32 offset;

    messages = GFL_MsgSysLoadData(FALSE, 2, 0x40, (work->heapId & 0x7fff) | 0x8000);
    for (i = 0; i < (s32)work->unk20; i++) {
        offset = i << 2;
        GFL_MsgDataLoadStrbuf(messages, *(u16 *)((u8 *)work->unk24 + offset), work->first);
        y = 14 * i;
        func_ov036_02187c4c(work->window, 0, (u16)y, work->first);
        GFL_MsgDataLoadStrbuf(work->messages, 5, work->first);
        WordSetNumber(work->wordSet, 0, *(u16 *)((u8 *)work->unk24 + offset + 2), 2, 1, 1);
        GFL_WordSetFormatStrbuf(work->wordSet, work->second, work->first);
        func_ov036_02187c4c(work->window, 0x6c, (u16)y, work->second);
    }
    GFL_MsgDataFree(messages);
    GFL_BGSysLoadScr(BmpWin_GetBGIndex(func_ov036_02187c9c(work->window)));
}

GameEventReturnCode func_ov033_02177b08(GameEvent *unused, u32 *state, void *data) {
    FieldMoneyWindowEvent *event;
    BmpWin *bitmapWindow;
    u16 remaining;

    event = data;
    switch (*state) {
    case 0:
        remaining = event->count - event->index;
        if (remaining > 7) {
            remaining = 7;
        }
        event->window = func_ov033_02177998(event->field, (u32)&event->entries[event->index], remaining);
        func_ov033_02177a60(event->window);
        event->window->unk10 = func_ov036_02189cb0(Field_GetMsgBGSys(event->field));
        (*state)++;
        break;
    case 1:
        if (func_ov036_02187c70(event->window->window) != TRUE) {
            break;
        }
        (*state)++;
        break;
    case 2:
        bitmapWindow = func_ov036_02187c9c(event->window->window);
        func_ov036_02189de8(event->window->unk10, BmpWin_GetBitmap(bitmapWindow), 15);
        BmpWin_FlushChar(bitmapWindow);
        if (!(GCTX_HIDGetPressedKeys() & 3)) {
            break;
        }
        GFL_SndSEPlay(0x547);
        (*state)++;
        break;
    case 3:
        func_ov036_02189cd8(event->window->unk10);
        func_ov033_02177a28(event->window);
        (*state)++;
        break;
    case 4:
        if (event->index + 7 >= event->count) {
            GFL_HeapFree(event->entries);
            return TRUE;
        }
        event->index += 7;
        *state = 0;
        break;
    }
    return FALSE;
}

u32 *func_ov033_02177bd4(GameData *gameData, HeapID heapId, void *items, u32 *count) {
    u32 *result;
    BagSave *bag;
    u32 n;
    s32 i;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    result = GFL_HeapAllocate(heapId, 0x50, TRUE, "pdw_postman.c", 0x14d);
    i = 0;
    n = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == TRUE) {
            ((u16 *)result)[n * 2] = item;
            ((u16 *)result)[n * 2 + 1] = quantity;
            n++;
        }
    }
    *count = n;
    return result;
}

void func_ov033_02177c48(GameData *gameData, HeapID heapId, void *items) {
    BagSave *bag;
    u32 i;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    for (i = 0; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_AddItem(bag, item, quantity, heapId) == TRUE) {
            func_02009a6c(items, i);
        }
    }
}

u32 func_ov033_02177c8c(GameData *gameData, HeapID heapId, void *items) {
    BagSave *bag;
    u32 i;
    u32 count;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    i = 0;
    count = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == FALSE) {
            count++;
        }
    }
    return count;
}

u16 func_ov033_02177cd4(GameData *gameData, HeapID heapId, void *items, u32 position) {
    BagSave *bag;
    s32 i;
    u32 count;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    i = 0;
    count = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == FALSE) {
            if (count == position) {
                return item;
            }
            count++;
        }
    }
    return 0;
}

GameEvent *func_ov033_02177d28(GameSystem *gameSystem) {
    GameData *gameData;
    DreamWorldSave *items;
    GameEvent *event;
    FieldMoneyWindowEvent *work;

    gameData = GSYS_GetGameData(gameSystem);
    items = getDreamWorldStuffAddress(GameData_GetSaveControl(gameData));
    event = GameEvent_Create(gameSystem, NULL, func_ov033_02177b08, sizeof(FieldMoneyWindowEvent));
    work = GameEvent_GetData(event);
    work->field = GSYS_GetField(gameSystem);
    work->index = 0;
    work->entries = func_ov033_02177bd4(gameData, Field_GetHeapID(work->field), items, &work->count);
    return event;
}

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
        loadPokemonTextNameToStrbuf(wordSet, 1, NULL);
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
