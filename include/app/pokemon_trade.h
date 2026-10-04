#ifndef POKEBW2_APP_POKEMON_TRADE_H
#define POKEBW2_APP_POKEMON_TRADE_H

#include "types.h"
#include "app/gtsnego.h"
#include "demo/shinka_demo.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_POKEMONTRADE OVERLAY_ID(194)

// What to do after the trade
#define TRADE_NEXT_EVOLVE 1
#define TRADE_NEXT_NEGOTIATE 2

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 next;
    // After TRADE_NEXT_EVOLVE, the species the Pokémon evolves into and how, which the events pass to the evolution demo
    u32 evolveSpecies;
    u32 evolveMethod;
    GameData *gameData;
    GtsNegoParam *nego;
    PokeParty *party;
    // Not used by the trade, the events keep the evolution demo's parameter here
    ShinkaDemoParam *evolution;
    void *buffer;
    u32 unk28;
    u16 friendIndex;
    u16 unk2E;
} PokemonTradeParam;

// For GTS Negotiation
extern const GameProcFunctions POKEMONTRADE_PROC_FUNCTIONS;
extern const GameProcFunctions POKEMONTRADE_WIFICLUB_PROC_FUNCTIONS;
// For the infrared event
extern const GameProcFunctions data_ov194_021c63dc;

#endif // POKEBW2_APP_POKEMON_TRADE_H
