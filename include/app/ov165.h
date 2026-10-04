#ifndef POKEBW2_APP_OV165_H
#define POKEBW2_APP_OV165_H

#include "types.h"
#include "gfl/heap.h"
#include "field/player_action.h"
#include "struct_decls.h"

// Overlay 165's party screen, which EventPokeList_Create runs, showing overlay 207's summary screen for a Pokémon
// when asked to

// 0xa8 bytes, which func_02034bd8 fills in
typedef struct {
    PokeParty *party;
    void *bag;
    void *unk08;
    TrainerDataSave *trainerData;
    void *unk10;
    Regulation *regulation;
    void *unk18;
    void *pokedex;
    void *shortcut;
    void *trainerCard;
    PlayerInfo *playerInfo;
    PlayerActionPossibilities action;
    u16 zoneId;
    // What the screen is for, func_02034bd8's a2
    u32 mode;
    u32 unk48;
    // The Pokémon whose summary to show, when result is 1
    u32 index;
    // 0 once the screen is done, and 1 to show a summary
    u32 result;
    u16 item;
    u16 move;
    u8 unk58;
    // The party slots, from 1, of the Pokémon picked
    u8 picked[6];
    u32 unk60;
    u8 unk64[0xa];
    u8 unk6E;
    u8 season;
    u8 unk70[0x35];
    // Whether key item 0x1e is registered to Y, and whether it is to be, once the screen is done
    u8 keyItemRegistered;
    u8 unkA6[2];
} Ov165Param;

void func_02034bd8(Ov165Param *param, GameData *gameData, u32 a2, PokeParty *party);
// Allocates the parameters and fills them in with func_02034bd8
Ov165Param *func_02034c54(GameData *gameData, u32 a1, PokeParty *party, HeapID heapId);
GameEvent *EventPokeList_Create(GameSystem *gsys, Field *field, Ov165Param *param, void *summaryParam);

#endif // POKEBW2_APP_OV165_H
