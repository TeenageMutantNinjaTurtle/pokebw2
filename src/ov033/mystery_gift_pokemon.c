#include "field/field_script.h"
#include "field/mystery_gift_script.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "pml/poke_party.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "system/game_data.h"

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
