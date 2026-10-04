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

// Runs the library's requests, every frame
void func_ov189_021a6d00(void);

#endif // POKEBW2_DPW_DPW_TR_H
