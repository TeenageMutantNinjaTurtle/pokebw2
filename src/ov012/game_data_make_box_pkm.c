#include "field/player_state.h"
#include "field/zone.h"
#include "pml/item.h"
#include "pml/poke_party.h"
#include "save/player_info.h"
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
