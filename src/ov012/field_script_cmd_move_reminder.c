#include "field/field_script.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"

BOOL s01D5_MoveReminderCheckPkm(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    HeapID heapId = FieldScriptEnv_GetHeapID(env);
    PartyPkm *pkm;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        u16 *moves = PokeParty_GetRememberableMoves(pkm, heapId);
        *result = doesPkmHaveLevelMoveToLearn(moves);
        GFL_HeapFree(moves);
    }
    return FALSE;
}
