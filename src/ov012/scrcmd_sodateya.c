#include "types.h"
#include "battle/battle_result.h"
#include "battle/trainer_data.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/app_call.h"
#include "field/black_tower_gimmick.h"
#include "field/day_care.h"
#include "field/encounter.h"
#include "field/event_3d_demo.h"
#include "field/event_action_call.h"
#include "field/event_actor_move.h"
#include "field/event_battle_lose.h"
#include "field/event_battle_video.h"
#include "field/event_chatot.h"
#include "field/event_data.h"
#include "field/event_fly.h"
#include "field/event_game_clear.h"
#include "field/event_irc.h"
#include "field/event_mapchange.h"
#include "field/event_save.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wifibattlematch.h"
#include "field/field.h"
#include "field/field_acmd.h"
#include "field/field_actor.h"
#include "field/field_chunk.h"
#include "field/field_event.h"
#include "field/field_map.h"
#include "field/field_menu.h"
#include "field/field_player.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_script_plugin.h"
#include "field/field_script_supervisor.h"
#include "field/field_sound.h"
#include "field/field_status.h"
#include "field/field_visuals.h"
#include "field/hidden_event.h"
#include "field/item_use_block.h"
#include "field/player_action.h"
#include "field/player_state.h"
#include "field/pleasure_boat.h"
#include "field/script_network.h"
#include "field/shortcut_menu.h"
#include "field/skill_map_effect.h"
#include "field/stadium_script.h"
#include "field/subscreen.h"
#include "field/trainer_script.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/fx.h"
#include "nitro/os.h"
#include "nitro/rtc.h"
#include "pml/item.h"
#include "pml/move_reminder.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/config.h"
#include "save/encounter.h"
#include "save/event_work.h"
#include "save/medal_box.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "save/shortcut.h"
#include "save/trainer_card.h"
#include "system/dsi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/season.h"
#include "system/version.h"
#include "system/vm.h"

BOOL s00EB_DayCareCheckSpawnFlag(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CheckSpawnFlag(dayCare);
    return FALSE;
}

BOOL s00EC_DayCareBreed(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_Breed(dayCare, party);
    return FALSE;
}

BOOL s00ED_DayCareResetSeed(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_CheckResetSeed(dayCare);
    return FALSE;
}

BOOL s00F7_DayCareCallPokeSelect(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    GameData_GetParty(gameData);
    getDaycareBlockAddress(GameData_GetSaveControl(gameData));
    ScriptWork_CallEvent(work, EventDayCarePokeSelect_Create(gsys, field, result));
    return TRUE;
}

BOOL s00F0_DayCareDeposit(VM *vm, FieldScriptEnv *env) {
    u16 slot = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_AddPkm(dayCare, party, slot);
    return FALSE;
}

BOOL s00F1_DayCareWithdraw(VM *vm, FieldScriptEnv *env) {
    u16 slot = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_RemovePkm(dayCare, slot, party);
    return FALSE;
}

BOOL s00EE_DayCareGetPkmCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_GetPkmCount(dayCare);
    return FALSE;
}

BOOL s00EF_DayCareCalcEggSpawnChance(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CalcEggSpawnChance(dayCare);
    return FALSE;
}

BOOL s00F2_DayCareGetSpecies(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    *result = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
    return FALSE;
}

BOOL s00F3_DayCareGetForme(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    *result = PokeParty_GetParam(pkm, PKM_PARAM_FORM, NULL);
    return FALSE;
}

BOOL s00F8_DayCareGetSex(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    *result = PokeParty_GetParam(pkm, PKM_PARAM_SEX, NULL);
    return FALSE;
}

BOOL s00F4_DayCareCalcNewLevel(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CalcNewLevel(dayCare, slot);
    return FALSE;
}

BOOL s00F5_DayCareCalcLevelGain(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_GetPkm(dayCare, slot);
    *result = DayCare_CalcLevelGain(dayCare, slot);
    return FALSE;
}

BOOL s00F6_DayCareCalcWithdrawCost(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_GetPkm(dayCare, slot);
    *result = DayCare_CalcWithdrawCost(dayCare, slot);
    return FALSE;
}

BOOL s023E_DayCareGetSexForNamePrint(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    u16 *result = ScriptReadVar(vm, env);
    u16 showSex = ScriptReadAny(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    if (showSex == 0) {
        *result = getNameGenderStatus(pkm);
    } else {
        *result = 0;
    }
    return FALSE;
}

u32 getNameGenderStatus(PartyPkm *pkm) {
    u32 species = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
    u32 sex = PokeParty_GetParam(pkm, PKM_PARAM_SEX, NULL);
    if (species == SPECIES_NIDORAN_M || species == SPECIES_NIDORAN_F) {
        if (PokeParty_GetParam(pkm, 0x75, NULL) == 0) {
            return 0;
        }
    }
    switch (sex) {
    case 0:
        goto male;
    case 1:
        goto female;
    case 2:
        break;
    }
    return 0;
male:
    return 1;
female:
    return 2;
}
