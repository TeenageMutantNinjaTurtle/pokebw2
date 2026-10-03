#include "field/event_field_trade.h"
#include "demo/shinka_demo.h"
#include "field/field_event.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "pml/evolution.h"
#include "pml/poke_party.h"
#include "save/pokedex.h"
#include "system/game_data.h"
#include "system/game_system.h"

void EventFieldTrade_DebugLogPkm(PartyPkm *pkm) {
    PokeParty_GetParam(pkm, 0, NULL);
    PokeParty_GetParam(pkm, 5, NULL);
    PokeParty_GetParam(pkm, 0x6f, NULL);
    PokeParty_GetParam(pkm, 6, NULL);
    PokeParty_GetParam(pkm, 7, NULL);
    PokeParty_GetParam(pkm, 8, NULL);
    PokeParty_GetParam(pkm, 9, NULL);
    PokeParty_GetParam(pkm, 10, NULL);
    PokeParty_GetParam(pkm, 0x6e, NULL);
    PokeParty_GetParam(pkm, 0x70, NULL);
    PokeParty_GetParam(pkm, 11, NULL);
    PokeParty_GetParam(pkm, 12, NULL);
    PokeParty_GetParam(pkm, 13, NULL);
    PokeParty_GetParam(pkm, 14, NULL);
    PokeParty_GetParam(pkm, 15, NULL);
    PokeParty_GetParam(pkm, 16, NULL);
    PokeParty_GetParam(pkm, 17, NULL);
    PokeParty_GetParam(pkm, 18, NULL);
    PokeParty_GetParam(pkm, 19, NULL);
    PokeParty_GetParam(pkm, 20, NULL);
    PokeParty_GetParam(pkm, 21, NULL);
    PokeParty_GetParam(pkm, 22, NULL);
    PokeParty_GetParam(pkm, 23, NULL);
    PokeParty_GetParam(pkm, 24, NULL);
    PokeParty_GetParam(pkm, 0x46, NULL);
    PokeParty_GetParam(pkm, 0x47, NULL);
    PokeParty_GetParam(pkm, 0x48, NULL);
    PokeParty_GetParam(pkm, 0x49, NULL);
    PokeParty_GetParam(pkm, 0x4a, NULL);
    PokeParty_GetParam(pkm, 0x4b, NULL);
    PokeParty_GetParam(pkm, 0x9a, NULL);
    PokeParty_GetParam(pkm, 0x9e, NULL);
    PokeParty_GetParam(pkm, 0x95, NULL);
}

void func_ov033_0217a864(void *param) {
}

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

GameEvent *EventFieldTrade_Create(GameSystem *gsys, u8 offerIndex, u8 partyIndex) {
    GameData *gameData = GSYS_GetGameData(gsys);
    PokeParty *party = GameData_GetParty(gameData);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventFieldTrade_Callback, sizeof(EventFieldTradeWork));
    EventFieldTradeWork *work = GameEvent_GetData(event);

    work->gameSystem = gsys;
    work->gameData = gameData;
    work->party = party;
    work->offerIndex = offerIndex;
    work->partyIndex = partyIndex;
    work->evolutionParam = NULL;
    return event;
}
