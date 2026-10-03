#include "field/field_script.h"
#include "pml/poke_party.h"
#include "save/pokedex.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s0117_PokePartySetForme(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 forme = ScriptReadAny(vm, env);
    FieldScriptEnv_GetScriptWork(env);
    GameData *gameData = GSYS_GetGameData(FieldScriptEnv_GetGameSystem(env));
    PartyPkm *pkm = PokeParty_GetPkm(GameData_GetParty(gameData), index);
    PokeParty_ChangeForme(pkm, forme);
    PokeDex_RegistPkm(GameData_GetPokedex(gameData), pkm);
    return FALSE;
}

BOOL s011C_PokePartyChangeRotomForme(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 forme = ScriptReadAny(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    FieldScriptEnv_GetScriptWork(env);
    GameData *gameData = GSYS_GetGameData(FieldScriptEnv_GetGameSystem(env));
    PartyPkm *pkm = PokeParty_GetPkm(GameData_GetParty(gameData), index);
    PML_PkmChangeRotomForme(pkm, slot, forme);
    PokeDex_RegistPkm(GameData_GetPokedex(gameData), pkm);
    return FALSE;
}
