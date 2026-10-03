#ifndef POKEBW2_FIELD_EVENT_FIELD_TRADE_H
#define POKEBW2_FIELD_EVENT_FIELD_TRADE_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "field/fld_trade.h"
#include "struct_decls.h"
#include "system/game_event.h"

GameEvent *EventFieldTrade_Create(GameSystem *gsys, u8 offerIndex, u8 partyIndex);
GameEventReturnCode EventFieldTrade_Callback(GameEvent *event, u32 *state, void *data);
void EventFieldTrade_CreatePkm(GameData *gameData, HeapID heapId, PartyPkm *pkm, const FieldTradeOfferData *offer,
                               u32 offerIndex);
void EventFieldTrade_DebugLogPkm(PartyPkm *pkm);

#endif // POKEBW2_FIELD_EVENT_FIELD_TRADE_H
