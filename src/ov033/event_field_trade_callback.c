#include "demo/shinka_demo.h"
#include "field/event_field_trade.h"
#include "field/field_event.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "pml/evolution.h"
#include "pml/poke_party.h"
#include "save/pokedex.h"
#include "system/game_data.h"
#include "system/game_system.h"

GameEventReturnCode EventFieldTrade_Callback(GameEvent *event, u32 *state, void *data) {
    EventFieldTradeWork *work;
    GameSystem *gsys;
    GameData *gameData;
    PokeParty *party;
    Field *field;
    PartyPkm *pkm;
    PokeDexSave *pokedex;
    ShinkaDemoParam *evolutionParam;
    u32 species;
    u32 method;

    work = data;
    gsys = work->gameSystem;
    gameData = work->gameData;
    party = work->party;
    field = GSYS_GetField(gsys);
    pkm = PokeParty_GetPkm(party, work->partyIndex);

    switch (*state) {
    case 0:
        work->input = FieldTradeInput_Create(HEAPID_GAMEEVENT, work->offerIndex);
        EventFieldTrade_CreatePkm(gameData, HEAPID_GAMEEVENT, work->input->tradeData, work->input->offerData,
                                  work->offerIndex);
        EventFieldTrade_DebugLogPkm(work->input->tradeData);
        func_ov033_0217a864(work->input->offerData);
        *state = 1;
        break;
    case 1:
        field = GSYS_GetField(gsys);
        work->transitionGameData = gameData;
        work->playerInfo = GetGameDataPlayerInfo(gameData);
        work->partyPkm = pkm;
        work->tradeTrainer = work->input->trainer;
        work->tradePkm = work->input->tradeData;
        GameEvent_ChainNext(event, EventFieldSubprocessTransition_Create(gsys, field, OVERLAY_ID(194),
                                                                         &data_ov194_021c63ac, work->subprocessData));
        *state = 2;
        break;
    case 2:
        copyPkmIntoPartyBlk(party, work->partyIndex, work->input->tradeData);
        pokedex = GameData_GetPokedex(gameData);
        PokeDex_RegistPkm(pokedex, work->input->tradeData);
        addPkmToDex(pokedex, work->input->tradeData);
        *state = 4;
        break;
    case 3:
        species = CheckEvolveSpecies(party, pkm, 1, 0, GameData_GetSeason(gameData), &method, HEAPID_GAMEEVENT);
        if (species != 0) {
            evolutionParam =
                GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(ShinkaDemoParam), FALSE, data_ov033_0217c624, 0x1ff);
            evolutionParam->gameData = gameData;
            evolutionParam->party = party;
            evolutionParam->species = species;
            evolutionParam->partyIndex = work->partyIndex;
            evolutionParam->method = method;
            evolutionParam->unkC = 1;
            evolutionParam->canCancel = FALSE;
            work->evolutionParam = evolutionParam;
            GameEvent_ChainNext(event, EventFieldSubprocessTransition_Create(
                                           gsys, field, OVERLAY_ID(284), &SHINKA_DEMO_PROC_FUNCTIONS, evolutionParam));
        }
        *state = 4;
        break;
    case 4:
        if (work->evolutionParam != NULL) {
            GFL_HeapFree(work->evolutionParam);
        }
        FieldTradeInput_Free(work->input);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
