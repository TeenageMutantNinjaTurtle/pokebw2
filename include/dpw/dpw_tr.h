#ifndef POKEBW2_DPW_DPW_TR_H
#define POKEBW2_DPW_DPW_TR_H

#include "types.h"

// The Global Trade Station's server library in overlay 189. The ROM names none of it; the header and the type and
// field names are guesses after the trade library (dpw_tr) of Nintendo's Wi-Fi SDK, which this one appears to be.
// Its functions have no names yet

// What a player looks for, or wants for the Pokémon they deposit
typedef struct {
    s16 characterNo;
    s8 gender;
    s8 level_min;
    s8 level_max;
    s8 unused;
} Dpw_Tr_PokemonSearchData;

// What a deposited Pokémon is, for searches
typedef struct {
    s16 characterNo;
    s8 gender;
    s8 level;
} Dpw_Tr_PokemonDataSimple;

// A deposited Pokémon on the server
typedef struct {
    // The Pokémon, a party Pokémon
    u8 postData[0xec];
    Dpw_Tr_PokemonDataSimple postSimple;
    Dpw_Tr_PokemonSearchData wantSimple;
    // The trainer's
    u8 gender;
    u8 unkF7;
    u8 postDate[8];
    u8 tradeDate[8];
    s32 id;
    u32 trainerID;
    u16 name[8];
    u8 countryCode;
    u8 localCode;
    u8 trainerType;
    // Whether the Pokémon was traded
    s8 isTrade;
    u8 versionCode;
    u8 langCode;
    u8 unk126;
    u8 unk127;
} Dpw_Tr_Data;

// Runs the library's requests, every frame
void func_ov189_021a6d00(void);

#endif // POKEBW2_DPW_DPW_TR_H
