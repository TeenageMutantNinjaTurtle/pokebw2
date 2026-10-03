#include "field/player_state.h"
#include "field/zone.h"
#include "gfl/heap.h"
#include "pml/item.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "system/game_data.h"

PartyPkm *GameData_MakeBoxPkm(GameData *gameData, BoxPkmCreateParams *params) {
    PlayerInfo *playerInfo;
    u32 trainerId;
    u32 pid;
    PartyPkm *pkm;
    u16 zoneId;
    u16 placeName;

    playerInfo = GetGameDataPlayerInfo(gameData);
    trainerId = getIDAsUInt(GetGameDataPlayerInfo(gameData));
    pid = PML_GenPID(trainerId, (u16)params->species, (u16)params->level, params->param18, params->param14,
                     params->param1C);
    pkm = PokeParty_NewPkm((u16)params->species, (u16)params->paramC, trainerId, 0, -1, pid, params->heapId);
    PokeParty_ChangeForme(pkm, (u16)params->level);
    PokeParty_SetParam(pkm, 6, params->param10);
    if (params->param24 != 0) {
        PokeParty_SetHiddenAbil(pkm, params->species, params->level);
    }
    if (GetItemParam((u16)params->param20, 15, params->heapId) == 4) {
        PokeParty_SetParam(pkm, 0x98, PML_ItemGetMonsBallID((u16)params->param20));
    }
    zoneId = PlayerState_GetZoneID(GameData_GetPlayerState(gameData));
    placeName = ZoneData_GetPlaceNameID(zoneId);
    PokeParty_SetupMetData(pkm, 0, playerInfo, placeName, params->heapId);
    PokeParty_RecalcStats(pkm);
    return pkm;
}

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