#ifndef POKEBW2_APP_OV165_H
#define POKEBW2_APP_OV165_H

#include "types.h"
#include "struct_decls.h"

// Overlay 165's party screen, which EventPokeList_Create runs, showing overlay 207's summary screen for a Pokémon
// when asked to

typedef struct {
    u8 unk0[0x14];
    Regulation *regulation;
    void *unk18;
    u8 unk1c[0x2c];
    u32 unk48;
    // The Pokémon whose summary to show, when result is 1
    u32 index;
    // 0 once the screen is done, and 1 to show a summary
    u32 result;
    u8 unk54[5];
    // The party slots, from 1, of the Pokémon picked
    u8 picked[6];
} Ov165Param;

void func_02034bd8(Ov165Param *param, GameData *gameData, u32 a2, PokeParty *party);

#endif // POKEBW2_APP_OV165_H
