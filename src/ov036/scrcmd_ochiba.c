#include "types.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/field_pokemon_form.h"
#include "field/field_script.h"
#include "field/medal.h"
#include "field/unity_tower.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL s02DE_UnityTowerSetHobby(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u8 hobby;
    UnityTowerSurveySave *save;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    hobby = ScriptReadAny(vm, env);
    save = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    setPlayerSurveys(save, hobby);
    return FALSE;
}

BOOL s02DF_UnityTowerGetHobby(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 *result;
    UnityTowerSurveySave *save;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    result = ScriptReadVar(vm, env);
    save = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    *result = getPlayerSurveys(save);
    return FALSE;
}

BOOL s02DB_UnityTowerSetFloor(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 floor;
    u16 value;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    floor = ScriptReadAny(vm, env);
    value = ScriptReadAny(vm, env);
    func_ov033_0217aa1c(gsys, floor, value);
    return FALSE;
}

BOOL s02DC_UnityTowerInitVisitorMessage(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u8 *save;
    WordSet *wordSet;
    u16 index;
    u16 param;
    u16 *result;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    save = GameData_GetUnityTowerSave(GSYS_GetGameData(gsys));
    wordSet = ScriptWork_GetWordSet(work);
    index = ScriptReadAny(vm, env);
    param = VM_Read16(vm);
    result = ScriptReadVar(vm, env);
    *result = func_ov033_0217aad8(wordSet, gsys, save, index, param);
    return FALSE;
}

BOOL func_ov036_021c9d24(VM *vm, FieldScriptEnv *env) {
    u16 *result;
    GameSystem *gsys;

    result = ScriptReadVar(vm, env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    *result = UnityTowerVisitor_GetCountry(GetGameDataPlayerInfo(GSYS_GetGameData(gsys))) != 0;
    return FALSE;
}

void DiscoverInitialMedals(MedalBox *box, HeapID heapId) {
    DiscoverInitialMedalsCore(box, heapId);
}

void CheckResetKeldeoOrdinaryForme(GameSystem *gsys) {
    GameData *gameData;
    PokeParty *party;
    PartyPkm *pkm;
    s32 count;
    s32 index;
    s32 moveIndex;
    u32 species;
    u32 move;

    gameData = GSYS_GetGameData(gsys);
    party = GameData_GetParty(gameData);
    count = PokeParty_GetPkmCount(party);
    index = 0;
    while (index < count) {
        pkm = PokeParty_GetPkm(party, index);
        move = PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_SPECIES, NULL);
        species = (u16)move;
        if (PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_IS_EGG, NULL) == 0 && species == SPECIES_KELDEO &&
            PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_FORM, NULL) == 1) {
            for (moveIndex = 0; moveIndex < 4; moveIndex++) {
                if (PokeParty_GetParam(pkm, (PkmField)(PKM_PARAM_MOVE1 + moveIndex), NULL) == MOVE_SECRET_SWORD) {
                    break;
                }
            }
            if (moveIndex == 4) {
                PokeParty_ChangeForme(pkm, 0);
            }
        }
        if (species > SPECIES_GENESECT) {
            pkm->base.contentBuffer.chunks[0].rawData[0x16] = 0xff;
            pkm->base.contentBuffer.chunks[0].rawData[0x17] = 0xff;
        }
        index++;
    }
}
