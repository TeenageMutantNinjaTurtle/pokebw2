#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "save/pokedex.h"
#include "system/game_data.h"

BOOL GameData_AddBoxPkm(GameData *gameData, BoxPkmCreateParams *params) {
    BoxSaveAccessor *boxes;
    PartyPkm *pkm;
    BoxPkm *boxPkm;
    PokeDexSave *dex;

    boxes = GameData_GetBoxSaveAccessor(gameData);
    if ((int)howManyTotalPokesAreInBoxes(boxes) >= 720) {
        return FALSE;
    }
    pkm = GameData_MakeBoxPkm(gameData, params);
    boxPkm = func_0201d624(pkm);
    BoxSaveAccessor_InsertPkm(boxes, boxPkm);
    dex = GameData_GetPokedex(gameData);
    addPkmToDex(dex, pkm);
    GFL_HeapFree(pkm);
    return TRUE;
}

BOOL addPkmToParty(GameData *gameData, BoxPkmCreateParams *params) {
    PokeParty *party;
    int capacity;
    PartyPkm *pkm;
    PokeDexSave *dex;

    party = GameData_GetParty(gameData);
    capacity = PokeParty_GetCapacity(party);
    if (capacity <= PokeParty_GetPkmCount(party)) {
        return FALSE;
    }
    pkm = GameData_MakeBoxPkm(gameData, params);
    PokeParty_AddPkm(party, pkm);
    dex = GameData_GetPokedex(gameData);
    addPkmToDex(dex, pkm);
    GFL_HeapFree(pkm);
    return TRUE;
}
