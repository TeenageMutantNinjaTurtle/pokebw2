#ifndef POKEBW2_SAVE_WORLDTRADE_DATA_H
#define POKEBW2_SAVE_WORLDTRADE_DATA_H

#include "types.h"
#include "struct_decls.h"

// The Global Trade Station's save block, which keeps the Pokémon the player deposited. The header's name is a guess

u32 func_0200b494(void);
void func_0200b498(WorldTradeData *data);
u16 func_0200b4a8(WorldTradeData *data);
void func_0200b4b0(WorldTradeData *data, u16 flag);
// Copies the deposited Pokémon out, or in
void func_0200b4b8(WorldTradeData *data, PartyPkm *pkm);
PartyPkm *func_0200b4d0(WorldTradeData *data);
void func_0200b4d4(WorldTradeData *data, PartyPkm *pkm);
void func_0200b4ec(WorldTradeData *data, u32 value);
void func_0200b4f4(WorldTradeData *data, u32 value);
u16 func_0200b4fc(WorldTradeData *data);

#endif // POKEBW2_SAVE_WORLDTRADE_DATA_H
