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
#include "field/pdw_postman.h"
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

void func_ov033_0217aa1c(GameSystem *gsys, s32 floor, u32 value) {
    GameData *gameData;
    u8 *unityTowerSave;
    SaveControl *saveControl;

    gameData = GSYS_GetGameData(gsys);
    unityTowerSave = GameData_GetUnityTowerSave(gameData);
    if (floor < 0xe9) {
        saveControl = GameData_GetSaveControl(gameData);
        func_ov033_0217aa50(getUnityTower_SurveySaveBlkAddrress(saveControl), unityTowerSave, floor, value);
    } else {
        UnityTowerSave_Init(unityTowerSave);
    }
}

void func_ov033_0217aa50(UnityTowerSurveySave *survey, u8 *output, s32 floor, u32 value) {
    void *visitor;
    u32 visitorValue;
    s32 country;
    s32 index;

    output[0] = floor;
    output[2] = value;
    output[1] = 0;
    for (index = 0; index < 20; index++) {
        if ((u8)UnityTower_GetVisitorParam(survey, index, 6) == 0) {
            continue;
        }
        visitor = UnityTower_GetVisitor(survey, index);
        if (visitor == NULL) {
            continue;
        }
        country = UnityTowerVisitor_GetCountry(visitor);
        if (country == floor) {
            visitorValue = func_02008bf4(visitor);
            if (visitorValue > 15) {
                visitorValue = getTrainerGender(visitor) != 0 ? 15 : 11;
            }
            output[8 + output[1]] = index;
            output[3 + output[1]] = func_0202b5d4(visitorValue);
            output[1]++;
            if (output[1] >= 5) {
                break;
            }
        }
    }
}

u32 func_ov033_0217aac4(u8 *output, u32 index) {
    u32 result;

    result = 0xff;
    if (index < 5 && index < output[1]) {
        output += index;
        result = output[8];
    }
    return result;
}

u32 func_ov033_0217aad8(WordSet *wordSet, GameSystem *gsys, u8 *save, s32 index, u32 param) {
    GameData *gameData;
    UnityTowerSurveySave *surveySave;
    PlayerInfo *visitor;
    u32 visitorIndex;
    u32 gender;
    u32 id;
    u32 province;
    u32 hasProvince;
    u8 *entry;

    hasProvince = 0;
    gameData = GSYS_GetGameData(gsys);
    surveySave = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(gameData));
    if (index >= 5) {
        return 4;
    }
    entry = save + index;
    visitorIndex = entry[8];
    LoadUnityTowerVisitorWordSet(wordSet, gameData, visitorIndex);
    visitor = UnityTower_GetVisitor(surveySave, visitorIndex);
    gender = getTrainerGender(visitor);
    province = UnityTower_GetVisitorParam(surveySave, visitorIndex, 4);
    id = getIDAsUInt(visitor);
    if (CountryHasProvinces(GameData_GetUnityTowerSave(gameData)[0]) != 0) {
        hasProvince = 1;
    }
    return func_ov033_0217ab58(gender, id, province, param, hasProvince);
}

u32 func_ov033_0217ab58(u32 gender, u32 id, u32 province, u32 a3, u32 hasProvince) {
    u32 messageId;

    if (hasProvince != 0) {
        messageId = 4;
    } else {
        messageId = 0x44;
    }
    if (province < 5) {
        messageId += province * 12;
    }
    if (gender != 0) {
        messageId += 6;
    }
    if (a3 == 0) {
        messageId++;
        messageId += (u32)(__aeabi_uidivmod(id, 5) >> 32);
    }
    return messageId;
}

void LoadUnityTowerVisitorWordSet(WordSet *wordSet, GameData *gameData, u32 index) {
    SaveControl *save;
    UnityTowerSurveySave *survey;
    u8 *towerSave;
    u8 country;
    void *visitor;
    u32 value;
    u8 hobby;

    save = GameData_GetSaveControl(gameData);
    survey = getUnityTower_SurveySaveBlkAddrress(save);
    towerSave = GameData_GetUnityTowerSave(gameData);
    country = towerSave[0];
    visitor = UnityTower_GetVisitor(survey, index);
    loadCountryToStrbuf(wordSet, 0, country);
    if (CountryHasProvinces(country)) {
        loadCountryAreaToStrbuf(wordSet, 1, country, UnityTowerVisitor_GetProvince(visitor));
    }
    copyVarForText(wordSet, 3, GetGameDataPlayerInfo(gameData));
    WordSet_LoadSpeciesName(wordSet, 5, (u16)UnityTower_GetVisitorParam(survey, index, 0));
    loadHobbyNameToStrbuf(wordSet, 6, getPlayerSurveys(survey));
    copyVarForText(wordSet, 7, visitor);
    value = UnityTower_GetVisitorParam(survey, index, 3);
    if (value == 0) {
        value = 1;
    }
    WordSetNumber(wordSet, 8, value, 3, 0, 1);
    WordSet_LoadSpeciesName(wordSet, 9, (u16)UnityTower_GetVisitorParam(survey, index, 1));
    hobby = UnityTower_GetVisitorParam(survey, index, 2);
    loadHobbyNameToStrbuf(wordSet, 10, hobby);
}
