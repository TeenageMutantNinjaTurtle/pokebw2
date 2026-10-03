#include "field/event_field_trade.h"
#include "system/game_data.h"
#include "system/game_system.h"

struct EventFieldTradeWork {
    GameSystem *gameSystem;
    GameData *gameData;
    PokeParty *party;
    u8 offerIndex;
    u8 partyIndex;
    u8 unkE[0x4a];
    void *evolutionParam;
};

GameEvent *EventFieldTrade_Create(GameSystem *gsys, u8 offerIndex, u8 partyIndex) {
    GameData *gameData = GSYS_GetGameData(gsys);
    PokeParty *party = GameData_GetParty(gameData);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventFieldTrade_Callback, sizeof(struct EventFieldTradeWork));
    struct EventFieldTradeWork *work = GameEvent_GetData(event);

    work->gameSystem = gsys;
    work->gameData = gameData;
    work->party = party;
    work->offerIndex = offerIndex;
    work->partyIndex = partyIndex;
    work->evolutionParam = NULL;
    return event;
}
