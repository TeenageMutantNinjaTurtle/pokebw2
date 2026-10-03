#include "field/field_script.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/pokedex.h"
#include "system/game_data.h"

BOOL s00DE_PokeDexRegist(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    HeapID heapId = FieldScriptEnv_GetHeapID(env);
    u16 kind = ScriptReadAny(vm, env);
    u16 species = ScriptReadAny(vm, env);
    PartyPkm *pkm = PokeParty_NewTempPkm(species, 1, 0xffffffff00000000ULL, heapId);

    switch (kind) {
    case 0:
        PokeDex_RegistPkm(pokedex, pkm);
        break;
    case 1:
        break;
    }

    GFL_HeapFree(pkm);
    return FALSE;
}
